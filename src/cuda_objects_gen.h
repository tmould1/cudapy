
    /*-----------------------------------------------------------------------------*/
    typedef struct {
        PyObject_HEAD
        /* Type-specific fields go here. */
        CUdevice device;
    } PyCUdevice;

    #define PyCUdevice_Check(obj) (PyObject_TypeCheck((PyObject *)obj, &cuda_PyCUdeviceType))

    static PyTypeObject cuda_PyCUdeviceType = {
        PyObject_HEAD_INIT(NULL)
        0,                         /*ob_size*/
        "cuda.CUdevice",           /*tp_name*/
        sizeof(PyCUdevice),/*tp_basicsize*/
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
        Py_TPFLAGS_DEFAULT, 	  /*tp_flags*/
        "CUdevice"
    };
    

    /*-----------------------------------------------------------------------------*/
    typedef struct {
        PyObject_HEAD
        /* Type-specific fields go here. */
        CUcontext context;
    } PyCUcontext;

    #define PyCUcontext_Check(obj) (PyObject_TypeCheck((PyObject *)obj, &cuda_PyCUcontextType))

    static PyTypeObject cuda_PyCUcontextType = {
        PyObject_HEAD_INIT(NULL)
        0,                         /*ob_size*/
        "cuda.CUcontext",           /*tp_name*/
        sizeof(PyCUcontext),/*tp_basicsize*/
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
        Py_TPFLAGS_DEFAULT, 	  /*tp_flags*/
        "CUcontext"
    };
    

    /*-----------------------------------------------------------------------------*/
    typedef struct {
        PyObject_HEAD
        /* Type-specific fields go here. */
        CUmodule module;
    } PyCUmodule;

    #define PyCUmodule_Check(obj) (PyObject_TypeCheck((PyObject *)obj, &cuda_PyCUmoduleType))

    static PyTypeObject cuda_PyCUmoduleType = {
        PyObject_HEAD_INIT(NULL)
        0,                         /*ob_size*/
        "cuda.CUmodule",           /*tp_name*/
        sizeof(PyCUmodule),/*tp_basicsize*/
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
        Py_TPFLAGS_DEFAULT, 	  /*tp_flags*/
        "CUmodule"
    };
    

    /*-----------------------------------------------------------------------------*/
    typedef struct {
        PyObject_HEAD
        /* Type-specific fields go here. */
        CUfunction function;
    } PyCUfunction;

    #define PyCUfunction_Check(obj) (PyObject_TypeCheck((PyObject *)obj, &cuda_PyCUfunctionType))

    static PyTypeObject cuda_PyCUfunctionType = {
        PyObject_HEAD_INIT(NULL)
        0,                         /*ob_size*/
        "cuda.CUfunction",           /*tp_name*/
        sizeof(PyCUfunction),/*tp_basicsize*/
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
        Py_TPFLAGS_DEFAULT, 	  /*tp_flags*/
        "CUfunction"
    };
    

    /*-----------------------------------------------------------------------------*/
    typedef struct {
        PyObject_HEAD
        /* Type-specific fields go here. */
        CUarray array;
    } PyCUarray;

    #define PyCUarray_Check(obj) (PyObject_TypeCheck((PyObject *)obj, &cuda_PyCUarrayType))

    static PyTypeObject cuda_PyCUarrayType = {
        PyObject_HEAD_INIT(NULL)
        0,                         /*ob_size*/
        "cuda.CUarray",           /*tp_name*/
        sizeof(PyCUarray),/*tp_basicsize*/
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
        Py_TPFLAGS_DEFAULT, 	  /*tp_flags*/
        "CUarray"
    };
    

    /*-----------------------------------------------------------------------------*/
    typedef struct {
        PyObject_HEAD
        /* Type-specific fields go here. */
        CUtexref texref;
    } PyCUtexref;

    #define PyCUtexref_Check(obj) (PyObject_TypeCheck((PyObject *)obj, &cuda_PyCUtexrefType))

    static PyTypeObject cuda_PyCUtexrefType = {
        PyObject_HEAD_INIT(NULL)
        0,                         /*ob_size*/
        "cuda.CUtexref",           /*tp_name*/
        sizeof(PyCUtexref),/*tp_basicsize*/
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
        Py_TPFLAGS_DEFAULT, 	  /*tp_flags*/
        "CUtexref"
    };
    

    /*-----------------------------------------------------------------------------*/
    typedef struct {
        PyObject_HEAD
        /* Type-specific fields go here. */
        CUevent event;
    } PyCUevent;

    #define PyCUevent_Check(obj) (PyObject_TypeCheck((PyObject *)obj, &cuda_PyCUeventType))

    static PyTypeObject cuda_PyCUeventType = {
        PyObject_HEAD_INIT(NULL)
        0,                         /*ob_size*/
        "cuda.CUevent",           /*tp_name*/
        sizeof(PyCUevent),/*tp_basicsize*/
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
        Py_TPFLAGS_DEFAULT, 	  /*tp_flags*/
        "CUevent"
    };
    

    /*-----------------------------------------------------------------------------*/
    typedef struct {
        PyObject_HEAD
        /* Type-specific fields go here. */
        CUstream stream;
    } PyCUstream;

    #define PyCUstream_Check(obj) (PyObject_TypeCheck((PyObject *)obj, &cuda_PyCUstreamType))

    static PyTypeObject cuda_PyCUstreamType = {
        PyObject_HEAD_INIT(NULL)
        0,                         /*ob_size*/
        "cuda.CUstream",           /*tp_name*/
        sizeof(PyCUstream),/*tp_basicsize*/
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
        Py_TPFLAGS_DEFAULT, 	  /*tp_flags*/
        "CUstream"
    };
    

    /*-----------------------------------------------------------------------------*/
    typedef struct {
        PyObject_HEAD
        /* Type-specific fields go here. */
        CUgraphicsResource graphicsresource;
    } PyCUgraphicsResource;

    #define PyCUgraphicsResource_Check(obj) (PyObject_TypeCheck((PyObject *)obj, &cuda_PyCUgraphicsResourceType))

    static PyTypeObject cuda_PyCUgraphicsResourceType = {
        PyObject_HEAD_INIT(NULL)
        0,                         /*ob_size*/
        "cuda.CUgraphicsResource",           /*tp_name*/
        sizeof(PyCUgraphicsResource),/*tp_basicsize*/
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
        Py_TPFLAGS_DEFAULT, 	  /*tp_flags*/
        "CUgraphicsResource"
    };
    
static void init_objects() {

    cuda_PyCUdeviceType.tp_new = PyType_GenericNew; 
    if (PyType_Ready(&cuda_PyCUdeviceType) < 0)     
        return;
    

    cuda_PyCUcontextType.tp_new = PyType_GenericNew; 
    if (PyType_Ready(&cuda_PyCUcontextType) < 0)     
        return;
    

    cuda_PyCUmoduleType.tp_new = PyType_GenericNew; 
    if (PyType_Ready(&cuda_PyCUmoduleType) < 0)     
        return;
    

    cuda_PyCUfunctionType.tp_new = PyType_GenericNew; 
    if (PyType_Ready(&cuda_PyCUfunctionType) < 0)     
        return;
    

    cuda_PyCUarrayType.tp_new = PyType_GenericNew; 
    if (PyType_Ready(&cuda_PyCUarrayType) < 0)     
        return;
    

    cuda_PyCUtexrefType.tp_new = PyType_GenericNew; 
    if (PyType_Ready(&cuda_PyCUtexrefType) < 0)     
        return;
    

    cuda_PyCUeventType.tp_new = PyType_GenericNew; 
    if (PyType_Ready(&cuda_PyCUeventType) < 0)     
        return;
    

    cuda_PyCUstreamType.tp_new = PyType_GenericNew; 
    if (PyType_Ready(&cuda_PyCUstreamType) < 0)     
        return;
    

    cuda_PyCUgraphicsResourceType.tp_new = PyType_GenericNew; 
    if (PyType_Ready(&cuda_PyCUgraphicsResourceType) < 0)     
        return;
    
}
static void init_types (PyObject *m) {
Py_INCREF(&cuda_PyCUdeviceType);
PyModule_AddObject(m, "CUdevice", (PyObject *)&cuda_PyCUdeviceType);
Py_INCREF(&cuda_PyCUcontextType);
PyModule_AddObject(m, "CUcontext", (PyObject *)&cuda_PyCUcontextType);
Py_INCREF(&cuda_PyCUmoduleType);
PyModule_AddObject(m, "CUmodule", (PyObject *)&cuda_PyCUmoduleType);
Py_INCREF(&cuda_PyCUfunctionType);
PyModule_AddObject(m, "CUfunction", (PyObject *)&cuda_PyCUfunctionType);
Py_INCREF(&cuda_PyCUarrayType);
PyModule_AddObject(m, "CUarray", (PyObject *)&cuda_PyCUarrayType);
Py_INCREF(&cuda_PyCUtexrefType);
PyModule_AddObject(m, "CUtexref", (PyObject *)&cuda_PyCUtexrefType);
Py_INCREF(&cuda_PyCUeventType);
PyModule_AddObject(m, "CUevent", (PyObject *)&cuda_PyCUeventType);
Py_INCREF(&cuda_PyCUstreamType);
PyModule_AddObject(m, "CUstream", (PyObject *)&cuda_PyCUstreamType);
Py_INCREF(&cuda_PyCUgraphicsResourceType);
PyModule_AddObject(m, "CUgraphicsResource", (PyObject *)&cuda_PyCUgraphicsResourceType);
}
