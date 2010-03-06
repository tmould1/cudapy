#include <Python.h>
#include <cuda.h>

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


/*-----------------------------------------------------------------------------
 * cuDevice
 */

typedef struct {
    PyObject_HEAD
    /* Type-specific fields go here. */
    CUdevice device;
} cuDevice;


/*---------------------------------------------------------------------------*/
static PyObject *
cuDevice_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    cuDevice *self;

    self = (cuDevice *)type->tp_alloc(type, 0);

    return (PyObject *)self;
}
static int
cuDevice_init(cuDevice *self, PyObject *args, PyObject *kwds)
{
	int ordinal;
	if (!PyArg_ParseTuple(args,"i",&ordinal)){
		return -1;
	}

	CUresult res = cuDeviceGet(&self->device, ordinal);
	if (res != CUDA_SUCCESS){
		PyErr_SetString(CudaError, findErrorMsg(res));
		return -1;
	}
	return 0;
}
static PyObject *
cuDevice_compute_capability(cuDevice* self) {
    int minor, mayor;
    CUresult res;
    PyObject *result;
    res = cuDeviceComputeCapability(&mayor, &minor, self->device);
    if (res != CUDA_SUCCESS){
		PyErr_SetString(CudaError, findErrorMsg(res));
    }
    result  = Py_BuildValue("ii", mayor, minor);
    if (result == NULL)
    	return NULL;
    Py_INCREF(result);
    return result;
}

static PyMethodDef cuDevice_methods[] = {
    {"ComputeCapability", (PyCFunction)cuDevice_compute_capability, METH_NOARGS,
     "Return the name, combining the first and last name"
    },
    {NULL}  /* Sentinel */
};


static PyTypeObject cuda_cuDeviceType = {
    PyObject_HEAD_INIT(NULL)
    0,                         /*ob_size*/
    "cuda.CUdevice",           /*tp_name*/
    sizeof(cuDevice),/*tp_basicsize*/
    0,                         /*tp_itemsize*/
    0,                         /*tp_dealloc*/
    0,                         /*tp_print*/
    0,                         /*tp_getattr*/
    0,                         /*tp_setattr*/
    0,                         /*tp_compare*/
    0,                         /*tp_repr*/
    0,                         /*tp_as_number*/
    0,                         /*tp_as_sequence*/
    0,                         /*tp_as_mapping*/
    0,                         /*tp_hash */
    0,                         /*tp_call*/
    0,                         /*tp_str*/
    0,                         /*tp_getattro*/
    0,                         /*tp_setattro*/
    0,                         /*tp_as_buffer*/
    Py_TPFLAGS_DEFAULT| Py_TPFLAGS_BASETYPE, /*tp_flags*/
    "cuDevice     ",           /* tp_doc */
    0,		               /* tp_traverse */
    0,		               /* tp_clear */
    0,		               /* tp_richcompare */
    0,		               /* tp_weaklistoffset */
    0,		               /* tp_iter */
    0,		               /* tp_iternext */
    cuDevice_methods,                     /* tp_methods */
    0,                     /* tp_members */
    0,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc)cuDevice_init,      /* tp_init */
    0,                         /* tp_alloc */
    cuDevice_new,   /* tp_new */
};



// "Initializes the driver API and must be called before any other function from the driver API."
// "Currently, the Flags parameter must be 0. "
// "If cuInit() has not been called, any function from the driver API will return CUDA_ERROR_NOT_INITIALIZED"


static PyMethodDef CudaMethods[] = {
    {"cuInit",  cuda_cuInit, METH_VARARGS,  "Execute a shell command."},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};


PyMODINIT_FUNC
initcuda(void)
{
    PyObject *m;

    //cuDevice
    if (PyType_Ready(&cuda_cuDeviceType) < 0)
        return;

    m = Py_InitModule("cuda", CudaMethods);
    if (m == NULL)
        return;


    CudaError = PyErr_NewException("cuda.error", NULL, NULL);
    Py_INCREF(CudaError);
    PyModule_AddObject(m, "error", CudaError);

    // cuDevice
    Py_INCREF(&cuda_cuDeviceType);
    PyModule_AddObject(m, "CUdevice", (PyObject *)&cuda_cuDeviceType);
}
