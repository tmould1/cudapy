#include <Python.h>
#include <cuda.h>

static PyObject *CudaError;

static PyObject *
cuda_cuInit(PyObject *self, PyObject *args)
{
    unsigned int flags;

    if (!PyArg_ParseTuple(args, "|u", &flags))
        return NULL;
    cuInit(flags);
    Py_RETURN_NONE;
}


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

    m = Py_InitModule("cuda", CudaMethods);
    if (m == NULL)
        return;

    CudaError = PyErr_NewException("cuda.error", NULL, NULL);
    Py_INCREF(CudaError);
    PyModule_AddObject(m, "error", CudaError);
}
