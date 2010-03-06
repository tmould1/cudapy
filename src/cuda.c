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
    CUresult res = cuInit(flags);
    if(res != CUDA_SUCCESS){
    	PyErr_SetString(CudaError, findErrorMsg(res));
        return NULL;
    }
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
cuda_cuCtxAttach(PyObject *self, PyIntObject* flags){
	PyCUcontext *ctx = NEW_PyCUcontext;
	unsigned int iflags;
	if(!PyInt_Check(flags)){
		PyErr_SetString(PyExc_TypeError,"argument must be a int");
		return NULL;
	}
	iflags = PyInt_AsLong(flags);
	CU_CALL(cuCtxAttach,(&ctx->context, iflags));
	return (PyObject*)ctx;
}

static PyObject *
cuda_cuCtxDetach(PyObject *self, PyCUcontext* ctx){
	unsigned int flags;
	PyCUcontext_Check(ctx);
	CU_CALL(cuCtxDetach,(ctx->context));
	Py_RETURN_NONE;
}

static PyObject *
cuda_cuCtxPushCurrent(PyObject *self, PyCUcontext* ctx){
	unsigned int flags;
	PyCUcontext_Check(ctx);
	CU_CALL(cuCtxPushCurrent,(ctx->context));
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

    init_types(m);
    init_enums(m);
}
