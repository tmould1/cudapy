#include <Python.h>
#include <cuda.h>

#define CU_CALL(NAME,ARGS) \
		CUresult res = NAME ARGS; \
		if( res != CUDA_SUCCESS) { \
			PyErr_SetString(CudaError, findErrorMsg(res)); \
			return NULL; \
		}


#include "cuda_enums_gen.h";
#include "cuda_objects_gen.h";

static struct {
    CUresult id;
    const char *msg;
} g_error_msg_table [] = {
    {CUDA_SUCCESS                    , "No errors"},
    {CUDA_ERROR_INVALID_VALUE        , "Invalid value"},
    {CUDA_ERROR_OUT_OF_MEMORY        , "Out of memory"},
    {CUDA_ERROR_NOT_INITIALIZED      , "Driver not initialized"},
    {CUDA_ERROR_DEINITIALIZED        , "Driver deinitialized"},

    {CUDA_ERROR_NO_DEVICE            , "No CUDA-capable device available"},
    {CUDA_ERROR_INVALID_DEVICE       , "Invalid device"},

    {CUDA_ERROR_INVALID_IMAGE        , "Invalid kernel image"},
    {CUDA_ERROR_INVALID_CONTEXT      , "Invalid context"},
    {CUDA_ERROR_CONTEXT_ALREADY_CURRENT , "Context already current"},
    {CUDA_ERROR_MAP_FAILED           , "Map failed"},
    {CUDA_ERROR_UNMAP_FAILED         , "Unmap failed"},
    {CUDA_ERROR_ARRAY_IS_MAPPED      , "Array is mapped"},
    {CUDA_ERROR_ALREADY_MAPPED       , "Already mapped"},
    {CUDA_ERROR_NO_BINARY_FOR_GPU    , "No binary for GPU"},
    {CUDA_ERROR_ALREADY_ACQUIRED     , "Already acquired"},
    {CUDA_ERROR_NOT_MAPPED           , "Not mapped"},
    {CUDA_ERROR_NOT_MAPPED_AS_ARRAY   , "Mapped resource not available for access as an array"},
    {CUDA_ERROR_NOT_MAPPED_AS_POINTER , "Mapped resource not available for access as a pointer"},

    {CUDA_ERROR_INVALID_SOURCE       , "Invalid source"},
    {CUDA_ERROR_FILE_NOT_FOUND       , "File not found"},

    {CUDA_ERROR_INVALID_HANDLE       , "Invalid handle"},

    {CUDA_ERROR_NOT_FOUND            , "Not found"},

    {CUDA_ERROR_NOT_READY            , "CUDA not ready"},

    {CUDA_ERROR_LAUNCH_FAILED        , "Launch failed"},
    {CUDA_ERROR_LAUNCH_OUT_OF_RESOURCES , "Launch exceeded resources"},
    {CUDA_ERROR_LAUNCH_TIMEOUT       , "Launch exceeded timeout"},
    {CUDA_ERROR_LAUNCH_INCOMPATIBLE_TEXTURING , "Launch with incompatible texturing"},

    {CUDA_ERROR_POINTER_IS_64BIT     , "Attempted to retrieve 64-bit pointer via 32-bit API function"},
    {CUDA_ERROR_SIZE_IS_64BIT        , "Attempted to retrieve 64-bit size via 32-bit API function"},

    {CUDA_ERROR_UNKNOWN              , "Unknown error"},
    };

static const char *findErrorMsg(CUresult target){
    unsigned int i = 0;
    while (g_error_msg_table[i].id != CUDA_ERROR_UNKNOWN){
        if (  g_error_msg_table[i].id == target)
        {
            break;
        }
        i++;
    }
    return g_error_msg_table[i].msg;
}

static PyObject *CudaError;

/* End error message handling */

/*********************************
 ** Initialization
 *********************************/
static PyObject *
cuda_cuInit(PyObject *self, PyObject *args)
{
    unsigned int flags = 0;
    if (!PyArg_ParseTuple(args, "|I", &flags))
        return NULL;
    CU_CALL(cuInit,(flags));
    Py_RETURN_NONE;
}
/*********************************
 ** Driver Version Query
 *********************************/
static PyObject *
cuda_cuDriverGetVersion(PyObject *self, PyObject *args){
	int driverVersion;
	CU_CALL(cuDriverGetVersion, (&driverVersion));
	return PyInt_FromLong(driverVersion);
}

/************************************
 **
 **    Device management
 **
 ***********************************/
static PyObject *
cuda_cuDeviceGet(PyObject *self, PyObject* obj){
	PyCUdevice *dev = NEW_PyCUdevice;
	if (!dev) return NULL;
	int ordinal = PyInt_AsLong(obj);
	CU_CALL(cuDeviceGet,(&dev->device,ordinal));
	return (PyObject *)dev;
}

static PyObject *
cuda_cuDeviceGetCount(PyObject *self, PyObject *args)
{
	int count;
	CUresult res = cuDeviceGetCount(&count);
    if(res != CUDA_SUCCESS){
    	PyErr_SetString(CudaError, findErrorMsg(res));
        return NULL;
    }
    PyObject *valueobj;
    valueobj = Py_BuildValue("i",count);
    if (valueobj != NULL){
    	Py_INCREF(valueobj);
    }
    return valueobj;
}

// CUresult  CUDAAPI cuDeviceGetName(char *name, int len, CUdevice dev);
static PyObject *
cuda_cuDeviceGetName(PyObject *self, PyCUdevice* device) {
    PyCUdevice_Check(device);
    char name_buff[256] = {0};
    CU_CALL( cuDeviceGetName, (name_buff, 256, device->device));
    return PyString_FromStringAndSize(name_buff, 256);
}

static PyObject *
cuda_cuDeviceComputeCapability(PyObject *self, PyCUdevice* device) {
    int minor, mayor;

    PyCUdevice_Check(device);
    CU_CALL( cuDeviceComputeCapability, (&mayor, &minor, device->device));
    return Py_BuildValue("ii", mayor, minor);
}

//CUresult  CUDAAPI cuDeviceTotalMem(unsigned int *bytes, CUdevice dev);
static PyObject *
cuda_cuDeviceTotalMem(PyObject *self, PyCUdevice* device) {
    unsigned int bytes;
    PyCUdevice_Check(device);
    CU_CALL( cuDeviceTotalMem, (&bytes, device->device));
    return PyInt_FromLong(bytes);
}
//CUresult  CUDAAPI cuDeviceGetProperties(CUdevprop *prop, CUdevice dev);

static PyObject *
cuda_cuDeviceGetAttribute(PyObject *self, PyObject* args){
	CUdevice_attribute attrib;
	PyCUdevice *dev;
	if (!PyArg_ParseTuple(args,"iO", &attrib, &dev)){
		return NULL;
	}
    PyCUdevice_Check(dev);
	int pi;
	CU_CALL(cuDeviceGetAttribute,(&pi, attrib, dev->device));
	return PyInt_FromLong(pi);
}

/************************************
 **
 **    Context management
 **
 ***********************************/
/* CUresult  CUDAAPI cuCtxCreate(CUcontext *pctx, unsigned int flags, CUdevice dev ); */
static PyObject *
cuda_cuCtxCreate(PyObject *self, PyObject* args){
	PyCUdevice *dev;
	unsigned int flags;
	PyCUcontext *ctx = NEW_PyCUcontext;
	if (!PyArg_ParseTuple(args,"IO", &flags, &dev)){
		return NULL;
	}
    PyCUdevice_Check(dev);
	CU_CALL(cuCtxCreate,(&ctx->context, flags, dev->device));
	return (PyObject *)ctx;
}

// cuCtxDestroy( CUcontext ctx );
static PyObject *
cuda_cuCtxDestroy(PyObject *self, PyCUcontext* ctx){
	unsigned int flags;
	PyCUcontext_Check(ctx);
	CU_CALL(cuCtxDestroy,(ctx->context));
	Py_RETURN_NONE;
}

static PyObject *
cuda_cuCtxAttach(PyObject *self, PyObject* flags){
	PyCUcontext *ctx = NEW_PyCUcontext;
	unsigned int iflags;
	if(!PyInt_Check(flags)){
		PyErr_SetString(PyExc_TypeError,"argument must be a int");
		return NULL;
	}
	iflags = (long)PyInt_AsLong(flags);
	CU_CALL(cuCtxAttach,(&ctx->context, iflags));
	return (PyObject*)ctx;
}

static PyObject *
cuda_cuCtxDetach(PyObject *self, PyCUcontext* ctx){
	PyCUcontext_Check(ctx);
	CU_CALL(cuCtxDetach,(ctx->context));
	Py_RETURN_NONE;
}
// CUresult  CUDAAPI cuCtxPushCurrent( CUcontext ctx );
static PyObject *
cuda_cuCtxPushCurrent(PyObject *self, PyObject* ctx){
	PyCUcontext_Check(ctx);
	CU_CALL(cuCtxPushCurrent,(((PyCUcontext*)ctx)->context));
	Py_RETURN_NONE;
}
static PyObject *
cuda_cuCtxPopCurrent(PyObject *self, PyObject* _){
	PyCUcontext *ctx = NEW_PyCUcontext;
	if (!ctx) return NULL;
	CU_CALL(cuCtxPopCurrent,(&ctx->context));
	return (PyObject*) ctx;
}

static PyObject *
cuda_cuCtxGetDevice(PyObject *self, PyObject* obj){
	PyCUdevice *dev = NEW_PyCUdevice;
	if (!dev) return NULL;
	CU_CALL(cuCtxGetDevice,(&dev->device));
	return (PyObject *)dev;
}

static PyObject *
cuda_cuCtxSynchronize(PyObject *self, PyObject* obj){
	CU_CALL(cuCtxSynchronize,());
	Py_RETURN_NONE;
}

/************************************
  **
  **    Module management
  **
  ***********************************/

 /* CUresult  CUDAAPI cuModuleLoad(CUmodule *module, const char *fname) */
static PyObject *
cuda_cuModuleLoad(PyObject *self, PyObject* fname){
	if(!PyString_Check(fname)){
		PyErr_SetString(PyExc_TypeError,"argument must be a string");
		return NULL;
	}
	PyCUmodule *mod = NEW_PyCUmodule;
	CU_CALL(cuModuleLoad, (&mod->module, PyString_AsString(fname)));
	return (PyObject*)mod;
}

/* CUresult  CUDAAPI cuModuleGetFunction(CUfunction *hfunc, CUmodule hmod, const char *name) */
static PyObject *
cuda_cuModuleGetFunction(PyObject *self, PyObject* args){
	PyCUmodule *mod;
	const char *func_name;
	if (!PyArg_ParseTuple(args,"Os", &mod, &func_name)){
		return NULL;
	}
	PyCUmodule_Check(mod);
	PyCUfunction *func = NEW_PyCUfunction;
	CU_CALL(cuModuleGetFunction, (&func->function, mod->module, func_name));
	return (PyObject*)func;
}
//CUresult  CUDAAPI cuModuleLoadDataEx(CUmodule *module, const void *image, unsigned int numOptions, CUjit_option *options, void **optionValues);
//static PyObject *
//cuda_cuModuleLoadDataEx(PyObject *self, PyObject* args){
//	PyCUmodule *mod;
//	const char *func_name;
//	if (!PyArg_ParseTuple(args,"OOOO", &mod, &func_name)){
//		return NULL;
//	}
//	PyCUmodule_Check(mod);
//	PyCUfunction *func = NEW_PyCUfunction;
//	CU_CALL(cuModuleGetFunction, (&func->function, mod->module, func_name));
//	return (PyObject*)func;
//}

/* CUresult  CUDAAPI cuModuleUnload(CUmodule hmod) */
static PyObject *
cuda_cuModuleUnload(PyObject *self, PyObject* mod){
	PyCUmodule_Check(mod);
	CU_CALL(cuModuleUnload, (((PyCUmodule*)mod)->module));
	Py_RETURN_NONE;
}

/************************************
 **
 **    Memory management
 **
 ***********************************/
// CUresult CUDAAPI cuMemGetInfo(unsigned int *free, unsigned int *total);

// CUresult CUDAAPI cuMemAlloc( CUdeviceptr *dptr, unsigned int bytesize);
static PyObject *
cuda_cuMemAlloc(PyObject *self, PyObject* args){
	PyCUdeviceptr *dptr = NEW_PyCUdeviceptr;
	unsigned int value;
	if (!PyInt_Check(args)){
		PyErr_SetString(PyExc_TypeError,"argument must be an int");
		return NULL;
	}
	value = PyInt_AsLong(args);
	CU_CALL(cuMemAlloc, (&dptr->deviceptr, value));
	return (PyObject*)dptr;
}
// CUresult CUDAAPI cuMemFree(CUdeviceptr dptr);
static PyObject *
cuda_cuMemFree(PyObject *self, PyCUdeviceptr* dptr){
	PyCUdeviceptr_Check(dptr);
	CU_CALL(cuMemFree, (dptr->deviceptr));
	Py_RETURN_NONE;
}

//CUresult  CUDAAPI cuMemcpyDtoH (void *dstHost, CUdeviceptr srcDevice, unsigned int ByteCount );
static PyObject *
cuda_cuMemcpyHtoD(PyObject *self, PyObject *args){
	PyCUdeviceptr *dptr;
	PyObject *src;
	if (!PyArg_ParseTuple(args,"OO", &dptr, &src)){
		return NULL;
	}
	PyCUdeviceptr_Check(dptr);
	if (!PyObject_CheckReadBuffer(src)){
		PyErr_Format(PyExc_TypeError,"Objects of type '%s' can not "
			                             "be used as buffer",
			                              src->ob_type->tp_name);
		return NULL;
	}
	Py_ssize_t buffer_len;
	const void *buf;
	if (PyObject_AsReadBuffer(src, &buf, &buffer_len) != 0){
		return NULL;
	}
	unsigned int byte_count = (unsigned int)buffer_len;
    CU_CALL(cuMemcpyHtoD, (dptr->deviceptr, buf, byte_count));

	Py_RETURN_NONE;
}

//CUresult  CUDAAPI cuMemcpyDtoH (void *dstHost, CUdeviceptr srcDevice, unsigned int ByteCount );
static PyObject *
cuda_cuMemcpyDtoH(PyObject *self, PyObject *args){
	PyCUdeviceptr *dptr;
	PyObject *src;
	if (!PyArg_ParseTuple(args,"OO", &src, &dptr)){
		return NULL;
	}
	PyCUdeviceptr_Check(dptr);
//	if (!PyObject_Check(src)){
//		PyErr_Format(PyExc_TypeError,"Objects of type '%s' can not "
//			                             "be used as write buffer",
//			                              src->ob_type->tp_name);
//		return NULL;
//	}
	Py_ssize_t buffer_len;
	void *buf;
	if (PyObject_AsWriteBuffer(src, &buf, &buffer_len) != 0){
		return NULL;
	}
	unsigned int byte_count = (unsigned int)buffer_len;
    CU_CALL(cuMemcpyDtoH, (buf, dptr->deviceptr, byte_count));

	Py_RETURN_NONE;
}

/************************************
 **
 **    Function management
 **
 ***********************************/


//CUresult CUDAAPI cuFuncSetBlockShape (CUfunction hfunc, int x, int y, int z);
static PyObject *
cuda_cuFuncSetBlockShape(PyObject *self, PyObject* args){
	PyCUfunction *func;
	int x,y,z;
	if (!PyArg_ParseTuple(args,"Oiii", &func, &x, &y, &z)){
		return NULL;
	}
	PyCUfunction_Check(func);
	CU_CALL(cuFuncSetBlockShape, (func->function, x,y,z));
	return (PyObject*)func;
}
//CUresult CUDAAPI cuFuncSetSharedSize (CUfunction hfunc, unsigned int bytes);
//CUresult CUDAAPI cuFuncGetAttribute (int *pi, CUfunction_attribute attrib, CUfunction hfunc);

/************************************
 **
 **    Parameter management
 **
 ***********************************/

//CUresult  CUDAAPI cuParamSetSize (CUfunction hfunc, unsigned int numbytes);
static PyObject *
cuda_cuParamSetSize(PyObject *self, PyObject *args){
	PyCUfunction *func;
	unsigned int numbytes;
	if (!PyArg_ParseTuple(args,"OI", &func, &numbytes)){
		return NULL;
	}
	PyCUfunction_Check(func);
	CU_CALL(cuParamSetSize, (func->function, numbytes));
	Py_RETURN_NONE;
}
//CUresult  CUDAAPI cuParamSeti    (CUfunction hfunc, int offset, unsigned int value);
static PyObject *
cuda_cuParamSeti(PyObject *self, PyObject *args){
	PyCUfunction *func;
	int offset;
	unsigned int value;
	if (!PyArg_ParseTuple(args,"OiI", &func, &offset, &value)){
		return NULL;
	}
	PyCUfunction_Check(func);
	CU_CALL(cuParamSeti, (func->function, offset, value));
	return PyInt_FromLong(sizeof(int));
}
//CUresult  CUDAAPI cuParamSetf    (CUfunction hfunc, int offset, float value);
static PyObject *
cuda_cuParamSetf(PyObject *self, PyObject *args){
	PyCUfunction *func;
	int offset;
	float value;
	if (!PyArg_ParseTuple(args,"OiI", &func, &offset, &value)){
		return NULL;
	}
	PyCUfunction_Check(func);
	CU_CALL(cuParamSetf, (func->function, offset, value));
	return PyInt_FromLong(sizeof(float));
}

// Invoke kernel
#define ALIGN_UP(offset, alignment) \
    (offset) = ((offset) + (alignment) - 1) & ~((alignment) - 1)

//CUresult  CUDAAPI cuParamSetv    (CUfunction hfunc, int offset, void *ptr, unsigned int numbytes);
static PyObject *
cuda_cuParamSetv(PyObject *self, PyObject *args){
	PyCUfunction *func;
	int offset;
	PyObject *value;

	if (!PyArg_ParseTuple(args,"OiO", &func, &offset, &value)){
		return NULL;
	}
	PyCUfunction_Check(func);

    void *ptr = (void*)(size_t)((PyCUdeviceptr*)value)->deviceptr;
    ALIGN_UP(offset, __alignof(ptr));

	if (PyCUdeviceptr_Test(value)){
		CU_CALL(cuParamSetv, (func->function, offset, &ptr , sizeof(ptr)));
	}

	return PyInt_FromLong(sizeof(ptr));
}
//CUresult  CUDAAPI cuParamSetTexRef(CUfunction hfunc, int texunit, CUtexref hTexRef);

/************************************
 **
 **    Launch functions
 **
 ***********************************/

//CUresult CUDAAPI cuLaunch ( CUfunction f );
//CUresult CUDAAPI cuLaunchGrid (CUfunction f, int grid_width, int grid_height);
//CUresult CUDAAPI cuLaunchGridAsync( CUfunction f, int grid_width, int grid_height, CUstream hStream );
static PyObject *
cuda_cuLaunchGrid(PyObject *self, PyObject *args){
	PyCUfunction *func;
	int grid_width,grid_height;
	if (!PyArg_ParseTuple(args,"Oii", &func, &grid_width, &grid_height)){
		return NULL;
	}
	PyCUfunction_Check(func);
	CU_CALL(cuLaunchGrid, (func->function,grid_width,grid_height));
	return (PyObject*)func;
}

static PyMethodDef CudaMethods[] = {
	/* Initialization */
    {"cuInit",  (PyCFunction)cuda_cuInit, METH_VARARGS,  "Execute a shell command."},
    /* Driver Version Query */
    {"cuDriverGetVersion", cuda_cuDriverGetVersion, METH_NOARGS, ""},
    /*Device Management*/
    {"cuDeviceGet", (PyCFunction)cuda_cuDeviceGet, METH_O, ""},
    {"cuDeviceGetCount", (PyCFunction)cuda_cuDeviceGetCount, METH_NOARGS, "" },
    {"cuDeviceGetName", (PyCFunction)cuda_cuDeviceGetName, METH_O, "" },
    {"cuDeviceComputeCapability", (PyCFunction)cuda_cuDeviceComputeCapability, METH_O,    ""},
    {"cuDeviceTotalMem", (PyCFunction)cuda_cuDeviceTotalMem, METH_O,    ""},
    /* TODO: cuDeviceGetProperties(CUdevprop *prop, CUdevice dev); */
    {"cuDeviceGetAttribute", (PyCFunction)cuda_cuDeviceGetAttribute, METH_VARARGS, ""},

    /* Context management */
    {"cuCtxCreate", (PyCFunction)cuda_cuCtxCreate, METH_VARARGS, ""},
    {"cuCtxDestroy", (PyCFunction)cuda_cuCtxDestroy, METH_O, ""},
    {"cuCtxAttach", (PyCFunction)cuda_cuCtxAttach, METH_O, ""},
    {"cuCtxDetach", (PyCFunction)cuda_cuCtxDetach, METH_O, ""},
    {"cuCtxPushCurrent", (PyCFunction) cuda_cuCtxPushCurrent, METH_O, "" },
    {"cuCtxPopCurrent" , (PyCFunction) cuda_cuCtxPopCurrent, METH_NOARGS, ""},
    {"cuCtxGetDevice"  , (PyCFunction) cuda_cuCtxGetDevice, METH_NOARGS, ""},
    {"cuCtxSynchronize", (PyCFunction) cuda_cuCtxSynchronize,METH_NOARGS, ""},

    /* Module Management */
    {"cuModuleLoad", (PyCFunction) cuda_cuModuleLoad, METH_O, ""},
    {"cuModuleGetFunction", (PyCFunction) cuda_cuModuleGetFunction, METH_VARARGS, ""},
    {"cuModuleUnload", (PyCFunction) cuda_cuModuleUnload, METH_O, ""},

    /* Memory Management */
    {"cuMemAlloc", (PyCFunction) cuda_cuMemAlloc, METH_O, ""},
    {"cuMemFree",  (PyCFunction) cuda_cuMemFree, METH_O,  ""},
    {"cuMemcpyHtoD", (PyCFunction) cuda_cuMemcpyHtoD, METH_VARARGS, ""},
    {"cuMemcpyDtoH", (PyCFunction) cuda_cuMemcpyDtoH, METH_VARARGS, ""},

    {"cuFuncSetBlockShape", (PyCFunction) cuda_cuFuncSetBlockShape, METH_VARARGS, "" },

    /* Parameter management */
    {"cuParamSetSize",(PyCFunction) cuda_cuParamSetSize, METH_VARARGS, ""},
    {"cuParamSeti",(PyCFunction) cuda_cuParamSeti, METH_VARARGS, ""},
    {"cuParamSetf",(PyCFunction) cuda_cuParamSetf, METH_VARARGS, ""},
    {"cuParamSetv",(PyCFunction) cuda_cuParamSetv, METH_VARARGS, ""},

    {"cuLaunchGrid", (PyCFunction)cuda_cuLaunchGrid, METH_VARARGS, ""},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};


PyMODINIT_FUNC
initcuda(void)
{
    PyObject *m;

    init_objects();

    m = Py_InitModule("cuda", CudaMethods);
    if (m == NULL)
        return;

    CudaError = PyErr_NewException("cuda.error", NULL, NULL);
    Py_INCREF(CudaError);
    PyModule_AddObject(m, "error", CudaError);

    PyModule_AddIntConstant(m,"CUDA_VERSION", CUDA_VERSION);

    init_types(m);
    init_enums(m);
}
