from random import random
from array import array
from cuda import *

def findModulePath( name ):
    return 'sdk/' + name

def main():
    print "Vector Addition (Driver API)"
    N = 50000
    # Initialize
    cuInit(0)
    # Get number of devices supporting CUDA
    deviceCount = cuDeviceGetCount()
    if deviceCount == 0:
        print "There is no device supporting CUDA."
        return
    # Get handle for device 0
    cuDevice = cuDeviceGet(0)
    # Create context
    cuContext = cuCtxCreate( 0, cuDevice)

    # first search for the module path before we load the results
    module_path = findModulePath ("vectorAdd.cubin")

    if not module_path:
        print "> findModulePath could not find <vectorAdd> ptx or cubin"
    else:
       print "> initCUDA loading module: <%s>" % module_path

    # Create module from binary file (PTX or CUBIN)
    if 'ptx' in module_path: 
        pass
        # # in this branch we use compilation with parameters
        # jitOptions = [0,0,0]
        # jitOptionsVals = [0,0,0]
        # # set up size of compilation log buffer
        # jitOptions[0] = CU_JIT_INFO_LOG_BUFFER_SIZE_BYTES
        # jitLogBufferSize = 1024
        # jitOptVals[0] = (void *)jitLogBufferSize

        # #set up pointer to the compilation log buffer
        # jitOptions[1] = CU_JIT_INFO_LOG_BUFFER
        # jitOptVals[1] = ""

        # # set up pointer to set the Maximum num of registers for a particular kernel
        # jitOptions[2] = CU_JIT_MAX_REGISTERS;
        # jitRegCount = 32;
        # jitOptVals[2] = jitRegCount;

        # cuModuleLoadDataEx(cuModule, ptx_source, jitNumOptions, jitOptions, jitOptVals)

        # print "> PTX JIT log:\n%s", jitLogBuffer
    else:
        cuModule = cuModuleLoad(module_path)

    # Get function handle from module
    vecAdd = cuModuleGetFunction(cuModule, "VecAdd")

    # Allocate input vectors h_A and h_B in host memory
    # Initialize input vectors
    import numpy

    h_A = array('f',[ random() for _ in xrange(N)])
    h_B = numpy.ones(N,'f')
    h_C = numpy.zeros(N,'f')

    size = N * h_A.itemsize

    # Allocate vectors in device memory
    d_A = cuMemAlloc(size)
    d_B = cuMemAlloc(size)
    d_C = cuMemAlloc(size)

    #Copy vectors from host memory to device memory
    cuMemcpyHtoD(d_A, h_A)
    cuMemcpyHtoD(d_B, h_B)

    #Invoke kernel
    offset = 0
    offset += cuParamSetv(vecAdd, offset, d_A)
    offset += cuParamSetv(vecAdd, offset, d_B)
    offset += cuParamSetv(vecAdd, offset, d_C)
    offset += cuParamSeti(vecAdd, offset, N)
    cuParamSetSize(vecAdd, offset)

    threadsPerBlock = 256
    blocksPerGrid = (N + threadsPerBlock - 1) / threadsPerBlock
    cuFuncSetBlockShape(vecAdd, threadsPerBlock, 1, 1)
    try:
        cuLaunchGrid(vecAdd, blocksPerGrid, 1)
        cuCtxSynchronize()
    except error, msg:
        print msg

    # Copy result from device memory to host memory
    # h_C contains the result in host memory
    cuMemcpyDtoH(h_C, d_C)
    
    cuMemFree(d_A)
    cuMemFree(d_B)
    cuMemFree(d_C)
    
    # Verify result
    for i in xrange(N):
        sum = h_A[i] + h_B[i]
        if abs(h_C[i] - sum) > 1e-7:
            break
    else:
        print "Test %s " %  "PASSED"
        return
    print "Test FAILED "

# void Cleanup(bool noError)
# {
#     CUresult error;
        
#     // Free device memory
#     if (d_A)
#         error = cuMemFree(d_A);
#     if (d_B)
#         error = cuMemFree(d_B);
#     if (d_C)
#         error = cuMemFree(d_C);

#     // Free host memory
#     if (h_A)
#         free(h_A);
#     if (h_B)
#         free(h_B);
#     if (h_C)
#         free(h_C);
        
#     error = cuCtxDetach(cuContext);

#     if (!noError || error != CUDA_SUCCESS)
#         printf("Function call failed\nTest FAILED\n");
    
#     if (!noprompt) {
#         printf("\nPress ENTER to exit...\n");
#         fflush( stdout);
#         fflush( stderr);
#         getchar();
#     }

#     exit(0);
# }

# // Allocates an array with random float entries.
# void RandomInit(float* data, int n)
# {
#     for (int i = 0; i < n; ++i)
#         data[i] = rand() / (float)RAND_MAX;
# }

# bool inline
# findModulePath(const char *module_file, string & module_path, char **argv, string & ptx_source)
# {
#     module_path = cutFindFilePath(module_file, argv[0]);
#     if (module_path.empty()) {
#        printf("> findModulePath could not find file: <%s> \n", module_file); 
#        return false;
#     } else {
#        printf("> findModulePath found file at <%s>\n", module_path.c_str());

#        if (module_path.rfind(".ptx") != string::npos) {
#            FILE *fp = fopen(module_path.c_str(), "rb");
#            fseek(fp, 0, SEEK_END);
#            int file_size = ftell(fp);
#            ptx_source.reserve(file_size+512);
#            fseek(fp, 0, SEEK_SET);
#            fread(&ptx_source[0], sizeof(char), file_size, fp);
#            fclose(fp);
#        }
#        return true;
#     }
# }
main()

# // Parse program arguments
# void ParseArguments(int argc, char** argv)
# {
#     for (int i = 0; i < argc; ++i)
#         if (strcmp(argv[i], "--noprompt") == 0 ||
#             strcmp(argv[i], "-noprompt") == 0) 
#         {
#             noprompt = true;
#             break;
#         }
# }
