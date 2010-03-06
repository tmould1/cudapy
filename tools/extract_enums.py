cudevice_attribute_enum ="""
    CU_DEVICE_ATTRIBUTE_MAX_THREADS_PER_BLOCK = 1,  ///< Maximum number of threads per block
    CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_X = 2,        ///< Maximum block dimension X
    CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Y = 3,        ///< Maximum block dimension Y
    CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Z = 4,        ///< Maximum block dimension Z
    CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_X = 5,         ///< Maximum grid dimension X
    CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Y = 6,         ///< Maximum grid dimension Y
    CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Z = 7,         ///< Maximum grid dimension Z
    CU_DEVICE_ATTRIBUTE_MAX_SHARED_MEMORY_PER_BLOCK = 8,    ///< Maximum shared memory available per block in bytes
    CU_DEVICE_ATTRIBUTE_SHARED_MEMORY_PER_BLOCK = 8,    ///< Deprecated, use CU_DEVICE_ATTRIBUTE_MAX_SHARED_MEMORY_PER_BLOCK
    CU_DEVICE_ATTRIBUTE_TOTAL_CONSTANT_MEMORY = 9,  ///< Memory available on device for __constant__ variables in a CUDA C kernel in bytes
    CU_DEVICE_ATTRIBUTE_WARP_SIZE = 10,             ///< Warp size in threads
    CU_DEVICE_ATTRIBUTE_MAX_PITCH = 11,             ///< Maximum pitch in bytes allowed by memory copies
    CU_DEVICE_ATTRIBUTE_MAX_REGISTERS_PER_BLOCK = 12,   ///< Maximum number of 32-bit registers available per block
    CU_DEVICE_ATTRIBUTE_REGISTERS_PER_BLOCK = 12,   ///< Deprecated, use CU_DEVICE_ATTRIBUTE_MAX_REGISTERS_PER_BLOCK
    CU_DEVICE_ATTRIBUTE_CLOCK_RATE = 13,            ///< Peak clock frequency in kilohertz
    CU_DEVICE_ATTRIBUTE_TEXTURE_ALIGNMENT = 14,     ///< Alignment requirement for textures

    CU_DEVICE_ATTRIBUTE_GPU_OVERLAP = 15,           ///< Device can possibly copy memory and execute a kernel concurrently
    CU_DEVICE_ATTRIBUTE_MULTIPROCESSOR_COUNT = 16,  ///< Number of multiprocessors on device
    CU_DEVICE_ATTRIBUTE_KERNEL_EXEC_TIMEOUT = 17,   ///< Specifies whether there is a run time limit on kernels
    CU_DEVICE_ATTRIBUTE_INTEGRATED = 18,            ///< Device is integrated with host memory
    CU_DEVICE_ATTRIBUTE_CAN_MAP_HOST_MEMORY = 19,   ///< Device can map host memory into CUDA address space
    CU_DEVICE_ATTRIBUTE_COMPUTE_MODE = 20,          ///< Compute mode (See ::CUcomputemode for details)
    CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_WIDTH = 21, ///< Maximum 1D texture width
    CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_WIDTH = 22, ///< Maximum 2D texture width
    CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_HEIGHT = 23,///< Maximum 2D texture height
    CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_WIDTH = 24, ///< Maximum 3D texture width
    CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_HEIGHT = 25,///< Maximum 3D texture height
    CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_DEPTH = 26, ///< Maximum 3D texture depth
    CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_ARRAY_WIDTH = 27, ///< Maximum texture array width
    CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_ARRAY_HEIGHT = 28,///< Maximum texture array height
    CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_ARRAY_NUMSLICES = 29, ///< Maximum slices in a texture array

"""

enum_name = 'CUdevice_attribute'
print "{"
print "PyObject *obj;"
total = 0
enum = []
for l in cudevice_attribute_enum.split('\n'):
    l = l.strip()
    if l:
        name, doc = l.split(',',1)
        name, value = name.split('=')

        print "{"
        print "\t/*",name, value,"*/"
        print "\tobj = PyInt_FromLong((long)%s);" % name.strip()
        print "\tPy_INCREF(obj);"
        print '\tPyModule_AddObject(m,"%s", obj);'%name.strip()
        print "}"
        total += 1
        enum.append(name.strip())
print 'obj =Py_BuildValue("%s",'%('s'*len(enum)), ','.join( '\"%s\"' % e for e in enum), ');'
print "\tPy_INCREF(obj);"
print '\tPyModule_AddObject(m,"%s", obj);'% enum_name
print "}"
