static void init_enums(PyObject *m){
{
	PyObject *values;
	PyModule_AddIntConstant(m,"CU_CTX_SCHED_AUTO", CU_CTX_SCHED_AUTO);
	PyModule_AddIntConstant(m,"CU_CTX_SCHED_SPIN", CU_CTX_SCHED_SPIN);
	PyModule_AddIntConstant(m,"CU_CTX_SCHED_YIELD", CU_CTX_SCHED_YIELD);
	PyModule_AddIntConstant(m,"CU_CTX_SCHED_MASK", CU_CTX_SCHED_MASK);
	PyModule_AddIntConstant(m,"CU_CTX_BLOCKING_SYNC", CU_CTX_BLOCKING_SYNC);
	PyModule_AddIntConstant(m,"CU_CTX_MAP_HOST", CU_CTX_MAP_HOST);
	PyModule_AddIntConstant(m,"CU_CTX_LMEM_RESIZE_TO_MAX", CU_CTX_LMEM_RESIZE_TO_MAX);
	PyModule_AddIntConstant(m,"CU_CTX_FLAGS_MASK", CU_CTX_FLAGS_MASK);
	values =Py_BuildValue("ssssssss", "CU_CTX_SCHED_AUTO",
					"CU_CTX_SCHED_SPIN",
					"CU_CTX_SCHED_YIELD",
					"CU_CTX_SCHED_MASK",
					"CU_CTX_BLOCKING_SYNC",
					"CU_CTX_MAP_HOST",
					"CU_CTX_LMEM_RESIZE_TO_MAX",
					"CU_CTX_FLAGS_MASK" );
	Py_INCREF(values);
	PyModule_AddObject(m,"CUctx_flags", values);
}
{
	PyObject *values;
	PyModule_AddIntConstant(m,"CU_EVENT_DEFAULT", CU_EVENT_DEFAULT);
	PyModule_AddIntConstant(m,"CU_EVENT_BLOCKING_SYNC", CU_EVENT_BLOCKING_SYNC);
	values =Py_BuildValue("ss", "CU_EVENT_DEFAULT",
					"CU_EVENT_BLOCKING_SYNC" );
	Py_INCREF(values);
	PyModule_AddObject(m,"CUevent_flags", values);
}
{
	PyObject *values;
	PyModule_AddIntConstant(m,"CU_AD_FORMAT_UNSIGNED_INT8", CU_AD_FORMAT_UNSIGNED_INT8);
	PyModule_AddIntConstant(m,"CU_AD_FORMAT_UNSIGNED_INT16", CU_AD_FORMAT_UNSIGNED_INT16);
	PyModule_AddIntConstant(m,"CU_AD_FORMAT_UNSIGNED_INT32", CU_AD_FORMAT_UNSIGNED_INT32);
	PyModule_AddIntConstant(m,"CU_AD_FORMAT_SIGNED_INT8", CU_AD_FORMAT_SIGNED_INT8);
	PyModule_AddIntConstant(m,"CU_AD_FORMAT_SIGNED_INT16", CU_AD_FORMAT_SIGNED_INT16);
	PyModule_AddIntConstant(m,"CU_AD_FORMAT_SIGNED_INT32", CU_AD_FORMAT_SIGNED_INT32);
	PyModule_AddIntConstant(m,"CU_AD_FORMAT_HALF", CU_AD_FORMAT_HALF);
	PyModule_AddIntConstant(m,"CU_AD_FORMAT_FLOAT", CU_AD_FORMAT_FLOAT);
	values =Py_BuildValue("ssssssss", "CU_AD_FORMAT_UNSIGNED_INT8",
					"CU_AD_FORMAT_UNSIGNED_INT16",
					"CU_AD_FORMAT_UNSIGNED_INT32",
					"CU_AD_FORMAT_SIGNED_INT8",
					"CU_AD_FORMAT_SIGNED_INT16",
					"CU_AD_FORMAT_SIGNED_INT32",
					"CU_AD_FORMAT_HALF",
					"CU_AD_FORMAT_FLOAT" );
	Py_INCREF(values);
	PyModule_AddObject(m,"CUarray_format", values);
}
{
	PyObject *values;
	PyModule_AddIntConstant(m,"CU_TR_ADDRESS_MODE_WRAP", CU_TR_ADDRESS_MODE_WRAP);
	PyModule_AddIntConstant(m,"CU_TR_ADDRESS_MODE_CLAMP", CU_TR_ADDRESS_MODE_CLAMP);
	PyModule_AddIntConstant(m,"CU_TR_ADDRESS_MODE_MIRROR", CU_TR_ADDRESS_MODE_MIRROR);
	values =Py_BuildValue("sss", "CU_TR_ADDRESS_MODE_WRAP",
					"CU_TR_ADDRESS_MODE_CLAMP",
					"CU_TR_ADDRESS_MODE_MIRROR" );
	Py_INCREF(values);
	PyModule_AddObject(m,"CUaddress_mode", values);
}
{
	PyObject *values;
	PyModule_AddIntConstant(m,"CU_TR_FILTER_MODE_POINT", CU_TR_FILTER_MODE_POINT);
	PyModule_AddIntConstant(m,"CU_TR_FILTER_MODE_LINEAR", CU_TR_FILTER_MODE_LINEAR);
	values =Py_BuildValue("ss", "CU_TR_FILTER_MODE_POINT",
					"CU_TR_FILTER_MODE_LINEAR" );
	Py_INCREF(values);
	PyModule_AddObject(m,"CUfilter_mode", values);
}
{
	PyObject *values;
	PyModule_AddIntConstant(m,"CU_DEVICE_ATTRIBUTE_MAX_THREADS_PER_BLOCK", CU_DEVICE_ATTRIBUTE_MAX_THREADS_PER_BLOCK);
	PyModule_AddIntConstant(m,"CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_X", CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_X);
	PyModule_AddIntConstant(m,"CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Y", CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Y);
	PyModule_AddIntConstant(m,"CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Z", CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Z);
	PyModule_AddIntConstant(m,"CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_X", CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_X);
	PyModule_AddIntConstant(m,"CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Y", CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Y);
	PyModule_AddIntConstant(m,"CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Z", CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Z);
	PyModule_AddIntConstant(m,"CU_DEVICE_ATTRIBUTE_MAX_SHARED_MEMORY_PER_BLOCK", CU_DEVICE_ATTRIBUTE_MAX_SHARED_MEMORY_PER_BLOCK);
	PyModule_AddIntConstant(m,"CU_DEVICE_ATTRIBUTE_SHARED_MEMORY_PER_BLOCK", CU_DEVICE_ATTRIBUTE_SHARED_MEMORY_PER_BLOCK);
	PyModule_AddIntConstant(m,"CU_DEVICE_ATTRIBUTE_TOTAL_CONSTANT_MEMORY", CU_DEVICE_ATTRIBUTE_TOTAL_CONSTANT_MEMORY);
	PyModule_AddIntConstant(m,"CU_DEVICE_ATTRIBUTE_WARP_SIZE", CU_DEVICE_ATTRIBUTE_WARP_SIZE);
	PyModule_AddIntConstant(m,"CU_DEVICE_ATTRIBUTE_MAX_PITCH", CU_DEVICE_ATTRIBUTE_MAX_PITCH);
	PyModule_AddIntConstant(m,"CU_DEVICE_ATTRIBUTE_MAX_REGISTERS_PER_BLOCK", CU_DEVICE_ATTRIBUTE_MAX_REGISTERS_PER_BLOCK);
	PyModule_AddIntConstant(m,"CU_DEVICE_ATTRIBUTE_REGISTERS_PER_BLOCK", CU_DEVICE_ATTRIBUTE_REGISTERS_PER_BLOCK);
	PyModule_AddIntConstant(m,"CU_DEVICE_ATTRIBUTE_CLOCK_RATE", CU_DEVICE_ATTRIBUTE_CLOCK_RATE);
	PyModule_AddIntConstant(m,"CU_DEVICE_ATTRIBUTE_TEXTURE_ALIGNMENT", CU_DEVICE_ATTRIBUTE_TEXTURE_ALIGNMENT);
	PyModule_AddIntConstant(m,"CU_DEVICE_ATTRIBUTE_GPU_OVERLAP", CU_DEVICE_ATTRIBUTE_GPU_OVERLAP);
	PyModule_AddIntConstant(m,"CU_DEVICE_ATTRIBUTE_MULTIPROCESSOR_COUNT", CU_DEVICE_ATTRIBUTE_MULTIPROCESSOR_COUNT);
	PyModule_AddIntConstant(m,"CU_DEVICE_ATTRIBUTE_KERNEL_EXEC_TIMEOUT", CU_DEVICE_ATTRIBUTE_KERNEL_EXEC_TIMEOUT);
	PyModule_AddIntConstant(m,"CU_DEVICE_ATTRIBUTE_INTEGRATED", CU_DEVICE_ATTRIBUTE_INTEGRATED);
	PyModule_AddIntConstant(m,"CU_DEVICE_ATTRIBUTE_CAN_MAP_HOST_MEMORY", CU_DEVICE_ATTRIBUTE_CAN_MAP_HOST_MEMORY);
	PyModule_AddIntConstant(m,"CU_DEVICE_ATTRIBUTE_COMPUTE_MODE", CU_DEVICE_ATTRIBUTE_COMPUTE_MODE);
	PyModule_AddIntConstant(m,"CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_WIDTH", CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_WIDTH);
	PyModule_AddIntConstant(m,"CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_WIDTH", CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_WIDTH);
	PyModule_AddIntConstant(m,"CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_HEIGHT", CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_HEIGHT);
	PyModule_AddIntConstant(m,"CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_WIDTH", CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_WIDTH);
	PyModule_AddIntConstant(m,"CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_HEIGHT", CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_HEIGHT);
	PyModule_AddIntConstant(m,"CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_DEPTH", CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_DEPTH);
	PyModule_AddIntConstant(m,"CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_ARRAY_WIDTH", CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_ARRAY_WIDTH);
	PyModule_AddIntConstant(m,"CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_ARRAY_HEIGHT", CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_ARRAY_HEIGHT);
	PyModule_AddIntConstant(m,"CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_ARRAY_NUMSLICES", CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_ARRAY_NUMSLICES);
	values =Py_BuildValue("sssssssssssssssssssssssssssssss", "CU_DEVICE_ATTRIBUTE_MAX_THREADS_PER_BLOCK",
					"CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_X",
					"CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Y",
					"CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Z",
					"CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_X",
					"CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Y",
					"CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Z",
					"CU_DEVICE_ATTRIBUTE_MAX_SHARED_MEMORY_PER_BLOCK",
					"CU_DEVICE_ATTRIBUTE_SHARED_MEMORY_PER_BLOCK",
					"CU_DEVICE_ATTRIBUTE_TOTAL_CONSTANT_MEMORY",
					"CU_DEVICE_ATTRIBUTE_WARP_SIZE",
					"CU_DEVICE_ATTRIBUTE_MAX_PITCH",
					"CU_DEVICE_ATTRIBUTE_MAX_REGISTERS_PER_BLOCK",
					"CU_DEVICE_ATTRIBUTE_REGISTERS_PER_BLOCK",
					"CU_DEVICE_ATTRIBUTE_CLOCK_RATE",
					"CU_DEVICE_ATTRIBUTE_TEXTURE_ALIGNMENT",
					"CU_DEVICE_ATTRIBUTE_GPU_OVERLAP",
					"CU_DEVICE_ATTRIBUTE_MULTIPROCESSOR_COUNT",
					"CU_DEVICE_ATTRIBUTE_KERNEL_EXEC_TIMEOUT",
					"CU_DEVICE_ATTRIBUTE_INTEGRATED",
					"CU_DEVICE_ATTRIBUTE_CAN_MAP_HOST_MEMORY",
					"CU_DEVICE_ATTRIBUTE_COMPUTE_MODE",
					"CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_WIDTH",
					"CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_WIDTH",
					"CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_HEIGHT",
					"CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_WIDTH",
					"CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_HEIGHT",
					"CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_DEPTH",
					"CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_ARRAY_WIDTH",
					"CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_ARRAY_HEIGHT",
					"CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_ARRAY_NUMSLICES" );
	Py_INCREF(values);
	PyModule_AddObject(m,"CUdevice_attribute", values);
}
{
	PyObject *values;
	PyModule_AddIntConstant(m,"CU_FUNC_ATTRIBUTE_MAX_THREADS_PER_BLOCK", CU_FUNC_ATTRIBUTE_MAX_THREADS_PER_BLOCK);
	PyModule_AddIntConstant(m,"CU_FUNC_ATTRIBUTE_SHARED_SIZE_BYTES", CU_FUNC_ATTRIBUTE_SHARED_SIZE_BYTES);
	PyModule_AddIntConstant(m,"CU_FUNC_ATTRIBUTE_CONST_SIZE_BYTES", CU_FUNC_ATTRIBUTE_CONST_SIZE_BYTES);
	PyModule_AddIntConstant(m,"CU_FUNC_ATTRIBUTE_LOCAL_SIZE_BYTES", CU_FUNC_ATTRIBUTE_LOCAL_SIZE_BYTES);
	PyModule_AddIntConstant(m,"CU_FUNC_ATTRIBUTE_NUM_REGS", CU_FUNC_ATTRIBUTE_NUM_REGS);
	PyModule_AddIntConstant(m,"CU_FUNC_ATTRIBUTE_MAX", CU_FUNC_ATTRIBUTE_MAX);
	values =Py_BuildValue("ssssss", "CU_FUNC_ATTRIBUTE_MAX_THREADS_PER_BLOCK",
					"CU_FUNC_ATTRIBUTE_SHARED_SIZE_BYTES",
					"CU_FUNC_ATTRIBUTE_CONST_SIZE_BYTES",
					"CU_FUNC_ATTRIBUTE_LOCAL_SIZE_BYTES",
					"CU_FUNC_ATTRIBUTE_NUM_REGS",
					"CU_FUNC_ATTRIBUTE_MAX" );
	Py_INCREF(values);
	PyModule_AddObject(m,"CUfunction_attribute", values);
}
{
	PyObject *values;
	PyModule_AddIntConstant(m,"CU_MEMORYTYPE_HOST", CU_MEMORYTYPE_HOST);
	PyModule_AddIntConstant(m,"CU_MEMORYTYPE_DEVICE", CU_MEMORYTYPE_DEVICE);
	PyModule_AddIntConstant(m,"CU_MEMORYTYPE_ARRAY", CU_MEMORYTYPE_ARRAY);
	values =Py_BuildValue("sss", "CU_MEMORYTYPE_HOST",
					"CU_MEMORYTYPE_DEVICE",
					"CU_MEMORYTYPE_ARRAY" );
	Py_INCREF(values);
	PyModule_AddObject(m,"CUmemorytype", values);
}
{
	PyObject *values;
	PyModule_AddIntConstant(m,"CU_COMPUTEMODE_DEFAULT", CU_COMPUTEMODE_DEFAULT);
	PyModule_AddIntConstant(m,"CU_COMPUTEMODE_EXCLUSIVE", CU_COMPUTEMODE_EXCLUSIVE);
	PyModule_AddIntConstant(m,"CU_COMPUTEMODE_PROHIBITED", CU_COMPUTEMODE_PROHIBITED);
	values =Py_BuildValue("sss", "CU_COMPUTEMODE_DEFAULT",
					"CU_COMPUTEMODE_EXCLUSIVE",
					"CU_COMPUTEMODE_PROHIBITED" );
	Py_INCREF(values);
	PyModule_AddObject(m,"CUcomputemode", values);
}
{
	PyObject *values;
	PyModule_AddIntConstant(m,"CU_JIT_MAX_REGISTERS", CU_JIT_MAX_REGISTERS);
	PyModule_AddIntConstant(m,"CU_JIT_THREADS_PER_BLOCK", CU_JIT_THREADS_PER_BLOCK);
	PyModule_AddIntConstant(m,"CU_JIT_WALL_TIME", CU_JIT_WALL_TIME);
	PyModule_AddIntConstant(m,"CU_JIT_INFO_LOG_BUFFER", CU_JIT_INFO_LOG_BUFFER);
	PyModule_AddIntConstant(m,"CU_JIT_INFO_LOG_BUFFER_SIZE_BYTES", CU_JIT_INFO_LOG_BUFFER_SIZE_BYTES);
	PyModule_AddIntConstant(m,"CU_JIT_ERROR_LOG_BUFFER", CU_JIT_ERROR_LOG_BUFFER);
	PyModule_AddIntConstant(m,"CU_JIT_ERROR_LOG_BUFFER_SIZE_BYTES", CU_JIT_ERROR_LOG_BUFFER_SIZE_BYTES);
	PyModule_AddIntConstant(m,"CU_JIT_OPTIMIZATION_LEVEL", CU_JIT_OPTIMIZATION_LEVEL);
	PyModule_AddIntConstant(m,"CU_JIT_TARGET_FROM_CUCONTEXT", CU_JIT_TARGET_FROM_CUCONTEXT);
	PyModule_AddIntConstant(m,"CU_JIT_TARGET", CU_JIT_TARGET);
	PyModule_AddIntConstant(m,"CU_JIT_FALLBACK_STRATEGY", CU_JIT_FALLBACK_STRATEGY);
	values =Py_BuildValue("sssssssssss", "CU_JIT_MAX_REGISTERS",
					"CU_JIT_THREADS_PER_BLOCK",
					"CU_JIT_WALL_TIME",
					"CU_JIT_INFO_LOG_BUFFER",
					"CU_JIT_INFO_LOG_BUFFER_SIZE_BYTES",
					"CU_JIT_ERROR_LOG_BUFFER",
					"CU_JIT_ERROR_LOG_BUFFER_SIZE_BYTES",
					"CU_JIT_OPTIMIZATION_LEVEL",
					"CU_JIT_TARGET_FROM_CUCONTEXT",
					"CU_JIT_TARGET",
					"CU_JIT_FALLBACK_STRATEGY" );
	Py_INCREF(values);
	PyModule_AddObject(m,"CUjit_option", values);
}
{
	PyObject *values;
	PyModule_AddIntConstant(m,"CU_TARGET_COMPUTE_10", CU_TARGET_COMPUTE_10);
	PyModule_AddIntConstant(m,"CU_TARGET_COMPUTE_11", CU_TARGET_COMPUTE_11);
	PyModule_AddIntConstant(m,"CU_TARGET_COMPUTE_12", CU_TARGET_COMPUTE_12);
	PyModule_AddIntConstant(m,"CU_TARGET_COMPUTE_13", CU_TARGET_COMPUTE_13);
	PyModule_AddIntConstant(m,"CU_TARGET_COMPUTE_20", CU_TARGET_COMPUTE_20);
	values =Py_BuildValue("sssss", "CU_TARGET_COMPUTE_10",
					"CU_TARGET_COMPUTE_11",
					"CU_TARGET_COMPUTE_12",
					"CU_TARGET_COMPUTE_13",
					"CU_TARGET_COMPUTE_20" );
	Py_INCREF(values);
	PyModule_AddObject(m,"CUjit_target", values);
}
{
	PyObject *values;
	PyModule_AddIntConstant(m,"CU_PREFER_PTX", CU_PREFER_PTX);
	PyModule_AddIntConstant(m,"CU_PREFER_BINARY", CU_PREFER_BINARY);
	values =Py_BuildValue("ss", "CU_PREFER_PTX",
					"CU_PREFER_BINARY" );
	Py_INCREF(values);
	PyModule_AddObject(m,"CUjit_fallback", values);
}
{
	PyObject *values;
	PyModule_AddIntConstant(m,"CU_GRAPHICS_REGISTER_FLAGS_NONE", CU_GRAPHICS_REGISTER_FLAGS_NONE);
	values =Py_BuildValue("s", "CU_GRAPHICS_REGISTER_FLAGS_NONE" );
	Py_INCREF(values);
	PyModule_AddObject(m,"CUgraphicsRegisterFlags", values);
}
{
	PyObject *values;
	PyModule_AddIntConstant(m,"CU_GRAPHICS_MAP_RESOURCE_FLAGS_NONE", CU_GRAPHICS_MAP_RESOURCE_FLAGS_NONE);
	PyModule_AddIntConstant(m,"CU_GRAPHICS_MAP_RESOURCE_FLAGS_READ_ONLY", CU_GRAPHICS_MAP_RESOURCE_FLAGS_READ_ONLY);
	PyModule_AddIntConstant(m,"CU_GRAPHICS_MAP_RESOURCE_FLAGS_WRITE_DISCARD", CU_GRAPHICS_MAP_RESOURCE_FLAGS_WRITE_DISCARD);
	values =Py_BuildValue("sss", "CU_GRAPHICS_MAP_RESOURCE_FLAGS_NONE",
					"CU_GRAPHICS_MAP_RESOURCE_FLAGS_READ_ONLY",
					"CU_GRAPHICS_MAP_RESOURCE_FLAGS_WRITE_DISCARD" );
	Py_INCREF(values);
	PyModule_AddObject(m,"CUgraphicsMapResourceFlags", values);
}
{
	PyObject *values;
	PyModule_AddIntConstant(m,"CU_CUBEMAP_FACE_POSITIVE_X", CU_CUBEMAP_FACE_POSITIVE_X);
	PyModule_AddIntConstant(m,"CU_CUBEMAP_FACE_NEGATIVE_X", CU_CUBEMAP_FACE_NEGATIVE_X);
	PyModule_AddIntConstant(m,"CU_CUBEMAP_FACE_POSITIVE_Y", CU_CUBEMAP_FACE_POSITIVE_Y);
	PyModule_AddIntConstant(m,"CU_CUBEMAP_FACE_NEGATIVE_Y", CU_CUBEMAP_FACE_NEGATIVE_Y);
	PyModule_AddIntConstant(m,"CU_CUBEMAP_FACE_POSITIVE_Z", CU_CUBEMAP_FACE_POSITIVE_Z);
	PyModule_AddIntConstant(m,"CU_CUBEMAP_FACE_NEGATIVE_Z", CU_CUBEMAP_FACE_NEGATIVE_Z);
	values =Py_BuildValue("ssssss", "CU_CUBEMAP_FACE_POSITIVE_X",
					"CU_CUBEMAP_FACE_NEGATIVE_X",
					"CU_CUBEMAP_FACE_POSITIVE_Y",
					"CU_CUBEMAP_FACE_NEGATIVE_Y",
					"CU_CUBEMAP_FACE_POSITIVE_Z",
					"CU_CUBEMAP_FACE_NEGATIVE_Z" );
	Py_INCREF(values);
	PyModule_AddObject(m,"CUarray_cubemap_face", values);
}
}
