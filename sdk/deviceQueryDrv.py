from cuda import *

if __name__ == '__main__':
    print "CUDA Device Query (Driver API) statically linked version"
    cuInit(0);
    deviceCount = cuDeviceGetCount()
    if deviceCount == 0:
        print "There is no device supporting CUDA"
    for dev in xrange(deviceCount):
        if dev == 0:
            # This function call returns 9999 for both major & minor fields, if no CUDA capable devices are present
            device = cuDeviceGet(dev);
            major,minor = cuDeviceComputeCapability(device)
            if major == 9999 and minor == 9999:
                print "There is no device supporting CUDA"
            elif deviceCount == 1:
                print "There is 1 device supporting CUDA"
            else:
                print "There are %d devices supporting CUDA" % deviceCount
        deviceName = cuDeviceGetName(device)
        print "\nDevice %d: \"%s\"" % (dev, deviceName)

    if CUDA_VERSION >= 2020:
        driverVersion = 0
        driverVersion = cuDriverGetVersion()
        print "  CUDA Driver Version:                           %d.%d" % (driverVersion/1000, driverVersion%100)

        print "  CUDA Capability Major revision number:         %d" % major
        print "  CUDA Capability Minor revision number:         %d" % minor
        totalGlobalMem = cuDeviceTotalMem(device)
        print "  Total amount of global memory:                 %u bytes" % totalGlobalMem
        
    if CUDA_VERSION >= 2000:
        multiProcessorCount = cuDeviceGetAttribute( CU_DEVICE_ATTRIBUTE_MULTIPROCESSOR_COUNT, device )
        print "  Number of multiprocessors:                     %d" % multiProcessorCount
        print "  Number of cores:                               %d" % (8 * multiProcessorCount)

        totalConstantMemory = cuDeviceGetAttribute(CU_DEVICE_ATTRIBUTE_TOTAL_CONSTANT_MEMORY, device ) 
        print "  Total amount of constant memory:               %u bytes" % totalConstantMemory
        sharedMemPerBlock = cuDeviceGetAttribute( CU_DEVICE_ATTRIBUTE_MAX_SHARED_MEMORY_PER_BLOCK, device ) 
        print "  Total amount of shared memory per block:       %u bytes" % sharedMemPerBlock
        regsPerBlock = cuDeviceGetAttribute( CU_DEVICE_ATTRIBUTE_MAX_REGISTERS_PER_BLOCK, device ) 
        print "  Total number of registers available per block: %d" % regsPerBlock
        warpSize = cuDeviceGetAttribute( CU_DEVICE_ATTRIBUTE_WARP_SIZE, device ) 
        print "  Warp size:                                     %d"   % warpSize
        maxThreadsPerBlock = cuDeviceGetAttribute( CU_DEVICE_ATTRIBUTE_MAX_THREADS_PER_BLOCK, device ) 
        print "  Maximum number of threads per block:           %d"   % maxThreadsPerBlock
        blockDim0 = cuDeviceGetAttribute( CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_X, device )
        blockDim1 = cuDeviceGetAttribute( CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Y, device )
        blockDim2 = cuDeviceGetAttribute( CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Z, device )
        print "  Maximum sizes of each dimension of a block:    %d x %d x %d" % ( blockDim0, blockDim1, blockDim2)

        gridDim0 = cuDeviceGetAttribute( CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_X, device) 
        gridDim1 = cuDeviceGetAttribute( CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Y, device)
        gridDim2 = cuDeviceGetAttribute( CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Z, device)
        print "  Maximum sizes of each dimension of a grid:     %d x %d x %d" % (gridDim0, gridDim1, gridDim2)
        memPitch = cuDeviceGetAttribute( CU_DEVICE_ATTRIBUTE_MAX_PITCH, device ) 
        print "  Maximum memory pitch:                          %u bytes" % memPitch
        textureAlign = cuDeviceGetAttribute( CU_DEVICE_ATTRIBUTE_TEXTURE_ALIGNMENT, device ) 
        print "  Texture alignment:                             %u bytes" % textureAlign
        clockRate = cuDeviceGetAttribute( CU_DEVICE_ATTRIBUTE_CLOCK_RATE, device ) 
        print "  Clock rate:                                    %.2f GHz" % ( clockRate * 1e-6)
    if CUDA_VERSION >= 2000:
        gpuOverlap = cuDeviceGetAttribute( CU_DEVICE_ATTRIBUTE_GPU_OVERLAP, device ) 
        print "  Concurrent copy and execution:                 %s" % "Yes" if gpuOverlap else "No"

    if CUDA_VERSION >= 2020:
        kernelExecTimeoutEnabled = cuDeviceGetAttribute( CU_DEVICE_ATTRIBUTE_KERNEL_EXEC_TIMEOUT, device ) 
        print "  Run time limit on kernels:                     %s" % ("Yes" if kernelExecTimeoutEnabled else "No")
        integrated = cuDeviceGetAttribute( CU_DEVICE_ATTRIBUTE_INTEGRATED, device ) 
        print "  Integrated:                                    %s" % ("Yes" if integrated else "No")
        canMapHostMemory = cuDeviceGetAttribute( CU_DEVICE_ATTRIBUTE_CAN_MAP_HOST_MEMORY, device ) 
        print "  Support host page-locked memory mapping:       %s" % ("Yes" if canMapHostMemory else "No")
        computeMode = cuDeviceGetAttribute( CU_DEVICE_ATTRIBUTE_COMPUTE_MODE, device ) 
        if computeMode == 0 :
            res = "Default (multiple host threads can use this device simultaneously)"
        elif computeMode == 1:
            res = "Exclusive (only one host thread at a time can use this device)"
        elif computeMode == 2:
            res = "Prohibited (no host thread can use this device)"
        else:
            res = "Unknown"
        print "  Compute mode:                                  %s" % res
    print "\nTest PASSED"

