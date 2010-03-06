
    /*-----------------------------------------------------------------------------*/
    typedef struct {
        PyObject_HEAD
        /* Type-specific fields go here. */
        CUdevice device;
    } PyCUdevice;

    #define PyCUdevice_Check(obj) \
        {                             \
        if (!PyObject_TypeCheck((PyObject *)obj, &cuda_PyCUdeviceType)){ \
            PyErr_SetString(PyExc_TypeError,"argument must be a CUdevice");              \
            return NULL; \
        } \
        } 
    #define NEW_PyCUdevice ((PyCUdevice*) _PyObject_New((PyTypeObject *)&cuda_PyCUdeviceType))
    
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

    #define PyCUcontext_Check(obj) \
        {                             \
        if (!PyObject_TypeCheck((PyObject *)obj, &cuda_PyCUcontextType)){ \
            PyErr_SetString(PyExc_TypeError,"argument must be a CUcontext");              \
            return NULL; \
        } \
        } 
    #define NEW_PyCUcontext ((PyCUcontext*) _PyObject_New((PyTypeObject *)&cuda_PyCUcontextType))
    
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

    #define PyCUmodule_Check(obj) \
        {                             \
        if (!PyObject_TypeCheck((PyObject *)obj, &cuda_PyCUmoduleType)){ \
            PyErr_SetString(PyExc_TypeError,"argument must be a CUmodule");              \
            return NULL; \
        } \
        } 
    #define NEW_PyCUmodule ((PyCUmodule*) _PyObject_New((PyTypeObject *)&cuda_PyCUmoduleType))
    
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

    #define PyCUfunction_Check(obj) \
        {                             \
        if (!PyObject_TypeCheck((PyObject *)obj, &cuda_PyCUfunctionType)){ \
            PyErr_SetString(PyExc_TypeError,"argument must be a CUfunction");              \
            return NULL; \
        } \
        } 
    #define NEW_PyCUfunction ((PyCUfunction*) _PyObject_New((PyTypeObject *)&cuda_PyCUfunctionType))
    
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

    #define PyCUarray_Check(obj) \
        {                             \
        if (!PyObject_TypeCheck((PyObject *)obj, &cuda_PyCUarrayType)){ \
            PyErr_SetString(PyExc_TypeError,"argument must be a CUarray");              \
            return NULL; \
        } \
        } 
    #define NEW_PyCUarray ((PyCUarray*) _PyObject_New((PyTypeObject *)&cuda_PyCUarrayType))
    
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

    #define PyCUtexref_Check(obj) \
        {                             \
        if (!PyObject_TypeCheck((PyObject *)obj, &cuda_PyCUtexrefType)){ \
            PyErr_SetString(PyExc_TypeError,"argument must be a CUtexref");              \
            return NULL; \
        } \
        } 
    #define NEW_PyCUtexref ((PyCUtexref*) _PyObject_New((PyTypeObject *)&cuda_PyCUtexrefType))
    
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

    #define PyCUevent_Check(obj) \
        {                             \
        if (!PyObject_TypeCheck((PyObject *)obj, &cuda_PyCUeventType)){ \
            PyErr_SetString(PyExc_TypeError,"argument must be a CUevent");              \
            return NULL; \
        } \
        } 
    #define NEW_PyCUevent ((PyCUevent*) _PyObject_New((PyTypeObject *)&cuda_PyCUeventType))
    
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

    #define PyCUstream_Check(obj) \
        {                             \
        if (!PyObject_TypeCheck((PyObject *)obj, &cuda_PyCUstreamType)){ \
            PyErr_SetString(PyExc_TypeError,"argument must be a CUstream");              \
            return NULL; \
        } \
        } 
    #define NEW_PyCUstream ((PyCUstream*) _PyObject_New((PyTypeObject *)&cuda_PyCUstreamType))
    
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
        CUgraphicsResource graphicsResource;
    } PyCUgraphicsResource;

    #define PyCUgraphicsResource_Check(obj) \
        {                             \
        if (!PyObject_TypeCheck((PyObject *)obj, &cuda_PyCUgraphicsResourceType)){ \
            PyErr_SetString(PyExc_TypeError,"argument must be a CUgraphicsResource");              \
            return NULL; \
        } \
        } 
    #define NEW_PyCUgraphicsResource ((PyCUgraphicsResource*) _PyObject_New((PyTypeObject *)&cuda_PyCUgraphicsResourceType))
    
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
    

    /*-----------------------------------------------------------------------------*/
    typedef struct {
        PyObject_HEAD
        /* Type-specific fields go here. */
        CUDA_MEMCPY2D cuda_memcpy2d;
    } PyCUDA_MEMCPY2D;

    #define PyCUDA_MEMCPY2D_Check(obj) \
        {                             \
        if (!PyObject_TypeCheck((PyObject *)obj, &cuda_PyCUDA_MEMCPY2DType)){ \
            PyErr_SetString(PyExc_TypeError,"argument must be a CUDA_MEMCPY2D");              \
            return NULL; \
        } \
        } 
    #define NEW_PyCUDA_MEMCPY2D ((PyCUDA_MEMCPY2D*) _PyObject_New((PyTypeObject *)&cuda_PyCUDA_MEMCPY2DType))
    
    static PyTypeObject cuda_PyCUDA_MEMCPY2DType = {
        PyObject_HEAD_INIT(NULL)
        0,                         /*ob_size*/
        "cuda.CUDA_MEMCPY2D",           /*tp_name*/
        sizeof(PyCUDA_MEMCPY2D),/*tp_basicsize*/
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
        "CUDA_MEMCPY2D"
    };
    

    /*-----------------------------------------------------------------------------*/
    typedef struct {
        PyObject_HEAD
        /* Type-specific fields go here. */
        CUDA_MEMCPY3D cuda_memcpy3d;
    } PyCUDA_MEMCPY3D;

    #define PyCUDA_MEMCPY3D_Check(obj) \
        {                             \
        if (!PyObject_TypeCheck((PyObject *)obj, &cuda_PyCUDA_MEMCPY3DType)){ \
            PyErr_SetString(PyExc_TypeError,"argument must be a CUDA_MEMCPY3D");              \
            return NULL; \
        } \
        } 
    #define NEW_PyCUDA_MEMCPY3D ((PyCUDA_MEMCPY3D*) _PyObject_New((PyTypeObject *)&cuda_PyCUDA_MEMCPY3DType))
    
    static PyTypeObject cuda_PyCUDA_MEMCPY3DType = {
        PyObject_HEAD_INIT(NULL)
        0,                         /*ob_size*/
        "cuda.CUDA_MEMCPY3D",           /*tp_name*/
        sizeof(PyCUDA_MEMCPY3D),/*tp_basicsize*/
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
        "CUDA_MEMCPY3D"
    };
    

    /*-----------------------------------------------------------------------------*/
    typedef struct {
        PyObject_HEAD
        /* Type-specific fields go here. */
        CUDA64_MEMCPY3D cuda64_memcpy3d;
    } PyCUDA64_MEMCPY3D;

    #define PyCUDA64_MEMCPY3D_Check(obj) \
        {                             \
        if (!PyObject_TypeCheck((PyObject *)obj, &cuda_PyCUDA64_MEMCPY3DType)){ \
            PyErr_SetString(PyExc_TypeError,"argument must be a CUDA64_MEMCPY3D");              \
            return NULL; \
        } \
        } 
    #define NEW_PyCUDA64_MEMCPY3D ((PyCUDA64_MEMCPY3D*) _PyObject_New((PyTypeObject *)&cuda_PyCUDA64_MEMCPY3DType))
    
    static PyTypeObject cuda_PyCUDA64_MEMCPY3DType = {
        PyObject_HEAD_INIT(NULL)
        0,                         /*ob_size*/
        "cuda.CUDA64_MEMCPY3D",           /*tp_name*/
        sizeof(PyCUDA64_MEMCPY3D),/*tp_basicsize*/
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
        "CUDA64_MEMCPY3D"
    };
    

    /*-----------------------------------------------------------------------------*/
    typedef struct {
        PyObject_HEAD
        /* Type-specific fields go here. */
        CUDA_ARRAY_DESCRIPTOR cuda_array_descriptor;
    } PyCUDA_ARRAY_DESCRIPTOR;

    #define PyCUDA_ARRAY_DESCRIPTOR_Check(obj) \
        {                             \
        if (!PyObject_TypeCheck((PyObject *)obj, &cuda_PyCUDA_ARRAY_DESCRIPTORType)){ \
            PyErr_SetString(PyExc_TypeError,"argument must be a CUDA_ARRAY_DESCRIPTOR");              \
            return NULL; \
        } \
        } 
    #define NEW_PyCUDA_ARRAY_DESCRIPTOR ((PyCUDA_ARRAY_DESCRIPTOR*) _PyObject_New((PyTypeObject *)&cuda_PyCUDA_ARRAY_DESCRIPTORType))
    
    static PyTypeObject cuda_PyCUDA_ARRAY_DESCRIPTORType = {
        PyObject_HEAD_INIT(NULL)
        0,                         /*ob_size*/
        "cuda.CUDA_ARRAY_DESCRIPTOR",           /*tp_name*/
        sizeof(PyCUDA_ARRAY_DESCRIPTOR),/*tp_basicsize*/
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
        "CUDA_ARRAY_DESCRIPTOR"
    };
    

    /*-----------------------------------------------------------------------------*/
    typedef struct {
        PyObject_HEAD
        /* Type-specific fields go here. */
        CUDA_ARRAY3D_DESCRIPTOR cuda_array3d_descriptor;
    } PyCUDA_ARRAY3D_DESCRIPTOR;

    #define PyCUDA_ARRAY3D_DESCRIPTOR_Check(obj) \
        {                             \
        if (!PyObject_TypeCheck((PyObject *)obj, &cuda_PyCUDA_ARRAY3D_DESCRIPTORType)){ \
            PyErr_SetString(PyExc_TypeError,"argument must be a CUDA_ARRAY3D_DESCRIPTOR");              \
            return NULL; \
        } \
        } 
    #define NEW_PyCUDA_ARRAY3D_DESCRIPTOR ((PyCUDA_ARRAY3D_DESCRIPTOR*) _PyObject_New((PyTypeObject *)&cuda_PyCUDA_ARRAY3D_DESCRIPTORType))
    
    static PyTypeObject cuda_PyCUDA_ARRAY3D_DESCRIPTORType = {
        PyObject_HEAD_INIT(NULL)
        0,                         /*ob_size*/
        "cuda.CUDA_ARRAY3D_DESCRIPTOR",           /*tp_name*/
        sizeof(PyCUDA_ARRAY3D_DESCRIPTOR),/*tp_basicsize*/
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
        "CUDA_ARRAY3D_DESCRIPTOR"
    };
    

    /*-----------------------------------------------------------------------------*/
    typedef struct {
        PyObject_HEAD
        /* Type-specific fields go here. */
        CUdevprop devprop;
    } PyCUdevprop;

    #define PyCUdevprop_Check(obj) \
        {                             \
        if (!PyObject_TypeCheck((PyObject *)obj, &cuda_PyCUdevpropType)){ \
            PyErr_SetString(PyExc_TypeError,"argument must be a CUdevprop");              \
            return NULL; \
        } \
        } 
    #define NEW_PyCUdevprop ((PyCUdevprop*) _PyObject_New((PyTypeObject *)&cuda_PyCUdevpropType))
    
    static PyTypeObject cuda_PyCUdevpropType = {
        PyObject_HEAD_INIT(NULL)
        0,                         /*ob_size*/
        "cuda.CUdevprop",           /*tp_name*/
        sizeof(PyCUdevprop),/*tp_basicsize*/
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
        "CUdevprop"
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
    

    cuda_PyCUDA_MEMCPY2DType.tp_new = PyType_GenericNew; 
    if (PyType_Ready(&cuda_PyCUDA_MEMCPY2DType) < 0)     
        return;
    

    cuda_PyCUDA_MEMCPY3DType.tp_new = PyType_GenericNew; 
    if (PyType_Ready(&cuda_PyCUDA_MEMCPY3DType) < 0)     
        return;
    

    cuda_PyCUDA64_MEMCPY3DType.tp_new = PyType_GenericNew; 
    if (PyType_Ready(&cuda_PyCUDA64_MEMCPY3DType) < 0)     
        return;
    

    cuda_PyCUDA_ARRAY_DESCRIPTORType.tp_new = PyType_GenericNew; 
    if (PyType_Ready(&cuda_PyCUDA_ARRAY_DESCRIPTORType) < 0)     
        return;
    

    cuda_PyCUDA_ARRAY3D_DESCRIPTORType.tp_new = PyType_GenericNew; 
    if (PyType_Ready(&cuda_PyCUDA_ARRAY3D_DESCRIPTORType) < 0)     
        return;
    

    cuda_PyCUdevpropType.tp_new = PyType_GenericNew; 
    if (PyType_Ready(&cuda_PyCUdevpropType) < 0)     
        return;
    
}
static void init_types (PyObject *m) {
}
