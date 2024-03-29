# typedef int CUdevice;                   ///< CUDA device
# typedef struct CUctx_st *CUcontext;     ///< CUDA context
# typedef struct CUmod_st *CUmodule;      ///< CUDA module
# typedef struct CUfunc_st *CUfunction;   ///< CUDA function
# typedef struct CUarray_st *CUarray;     ///< CUDA array
# typedef struct CUtexref_st *CUtexref;   ///< CUDA texture reference
# typedef struct CUevent_st *CUevent;     ///< CUDA event
# typedef struct CUstream_st *CUstream;   ///< CUDA stream
# typedef struct CUgraphicsResource_st *CUgraphicsResource; ///< CUDA graphics interop resource


structs = "CUdeviceptr CUdevice CUcontext CUmodule CUfunction CUarray CUtexref \
           CUevent CUstream CUgraphicsResource ".split()
member_structs = "CUDA_MEMCPY2D CUDA_MEMCPY3D CUDA64_MEMCPY3D CUDA_ARRAY_DESCRIPTOR CUDA_ARRAY3D_DESCRIPTOR CUdevprop".split()

structs.extend(member_structs)

TEMPLATE=    """
    /*-----------------------------------------------------------------------------*/
    typedef struct {
        PyObject_HEAD
        /* Type-specific fields go here. */
        %(name)s %(field)s;
    } Py%(name)s;

    #define Py%(name)s_Check(obj) \\
        {                             \\
        if (!PyObject_TypeCheck((PyObject *)obj, &cuda_Py%(name)sType)){ \\
            PyErr_Format(PyExc_TypeError,\"Object of type '%%s' can not be used as %(name)s\",obj->ob_type->tp_name);\\
            return NULL; \\
        } \\
        } 
    #define Py%(name)s_Test(obj) (PyObject_TypeCheck((PyObject *)obj, &cuda_Py%(name)sType))
    #define NEW_Py%(name)s ((Py%(name)s*) _PyObject_New((PyTypeObject *)&cuda_Py%(name)sType))
    
    static int Py%(name)s_Compare(PyObject *o1, PyObject *o2);

    static PyTypeObject cuda_Py%(name)sType = {
        PyObject_HEAD_INIT(NULL)
        0,                         /*ob_size*/
        \"cuda.%(name)s\",           /*tp_name*/
        sizeof(Py%(name)s),/*tp_basicsize*/
        0,                         /*tp_itemsize*/
        0,                         /*tp_dealloc*/
        0,                         /*tp_print*/
        0,                         /*tp_getattr*/
        0,                         /*tp_setattr*/
         Py%(name)s_Compare,      /*tp_compare*/
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
        "%(name)s"
    };

    static int Py%(name)s_Compare(PyObject *o1, PyObject *o2){
         if (!Py%(name)s_Test(o1) ){
             return -1;
         }
         if (!Py%(name)s_Test(o2) ){
             return -1;
         }
         int cmp = memcmp(&((Py%(name)s*)o1)->%(field)s, &((Py%(name)s*)o2)->%(field)s, sizeof(%(name)s));
         if ( cmp == 0){
             return 0;
         }
         printf(\"%%d\\n\",cmp);
         return -1;
    }    
    """
for name in structs:
    if name.lower().startswith('cuda'):
        field = name.lower()
    else:
        field = name[len('cu'):]
    print TEMPLATE % locals()

print "static void init_objects() {"
for s in structs:
    print """
    cuda_Py%(name)sType.tp_new = PyType_GenericNew; 
    if (PyType_Ready(&cuda_Py%(name)sType) < 0)     
        return;
    """ % { 'name' : s }
print "}"    


print "static void init_types (PyObject *m) {"
# for name in structs:
#     print "Py_INCREF(&cuda_Py%(name)sType);" % locals()
#     print "PyModule_AddObject(m, \"%(name)s\", (PyObject *)&cuda_Py%(name)sType);" % locals()

print "}"
