# Globals

from cuda import *
import random
import numpy
from time import time

sizeof_float = numpy.dtype('f').itemsize

# Thread block size
BLOCK_SIZE = 16

#Matrix dimensions
#(chosen as multiples of the thread block size for simplicity)
WA = (3 * BLOCK_SIZE) # Matrix A width
HA = (5 * BLOCK_SIZE) # Matrix A height
WB = (8 * BLOCK_SIZE) # Matrix B width
HB= WA  # Matrix B height
WC= WB  # Matrix C width 
HC= HA  # Matrix C height

def initCUDA():
    cuInit(0)
    dev = cuGetDevice(0)
    cuCtxCreate(0, dev)
    return cuModuleLoad('matrixMulDrv.cubin')

# Program main
def main():
    runTest()

# Run a simple test for CUDA
def runTest():
    # initialize CUDA
    matrixMul = initCUDA()

    # set seed for rand()
    random.seed(2006)

    # allocate host memory for matrices A and B
    # initialize host memory
    size_A = WA * HA
    size_B = WB * HB
    mem_size_A = size_A * sizeof_float
    mem_size_B = size_B * sizeof_float
    h_A = numpy.random.rand(size_A)
    h_B = numpy.random.rand(size_B)

    # allocate device memory
    d_A = cuMemAlloc( mem_size_A )
    d_B = cuMemAlloc( mem_size_B )

    # copy host memory to device
    cuMemcpyHtoD( d_A, h_A)
    cuMemcpyHtoD( d_B, h_B)

    # allocate device memory for result
    size_C = WC * HC;
    #allocate mem for the result on host side
    h_C = numpy.zeros(size_C, 'f')
    d_C = cuMemAlloc(size_C * h_C.itemsize)

    # create and start the timer
    start  = time()

    # setup execution parameters
    offset = 0
    offset += cuParamSetv( matrixMul, offset, d_C)
    offset += cuParamSetv( matrixMul, offset, d_A)
    offset += cuParamSetv( matrixMul, offset, d_B)
    offset += cuParamSetv( matrixMul, offset, d_B)
    offset += cuParamSeti( matrixMul, offset, WA )
    offset += cuParamSeti( matrixMul, offset, WB )
    cuParamSetSize( matrixMul, offset )

    cuFuncSetBlockShape( matrixMul, BLOCK_SIZE, BLOCK_SIZE, 1 )
    cuFuncSetSharedSize( matrixMul, 2*BLOCK_SIZE*BLOCK_SIZE*sizeof_float ) 

    # set execution configuration for the uLaunchGrid( matrixMul, WC / BLOCK_SIZE, HC / BLOCK_SIZE ));

    # copy result from device to host
    cuMemcpyDtoH(h_C, d_C)

    # stop and destroy timer
    stop = time()
    print "Processing time: %f (ms)" % stop - start

#     // compute reference solution
#     float* reference = (float*) malloc(mem_size_C);
#     computeGold(reference, h_A, h_B, HA, WA, WB);

#     // check result
#     CUTBoolean res = cutCompareL2fe(reference, h_C, size_C, 1e-6f);
#     printf("Test %s\n", (1 == res) ? "PASSED" : "FAILED");

#     // clean up memory
#     free(h_A);
#     free(h_B);
#     free(h_C);
#     free(reference);
#     cutilDrvSafeCallNoSync(cuMemFree(d_A));
#     cutilDrvSafeCallNoSync(cuMemFree(d_B));
#     cutilDrvSafeCallNoSync(cuMemFree(d_C));
#     cutilDrvSafeCallNoSync(cuCtxDetach(cuContext));
# }

# // Allocates a matrix with random float entries.
# void randomInit(float* data, int size)
# {
#     for (int i = 0; i < size; ++i)
#         data[i] = rand() / (float)RAND_MAX;
# }

# bool inline
# findModulePath(const char * module_file, string char **argv, string & ptx_source)
# {
# 	FILE *fp;

#     module_path = &module_path = cutFindFilePath(module_file, argv[0]
#     i (module_pat % empty
#        return false;
#     } else {
#        printf("> findModulePath found file at <%s>\n", module_path.c_str());

# 	   if (module_path.rfind(".ptx") != string::npos) {
# 		   fp = fopen(module_path.c_str(), "rb");
# 		   fseek(fp, 0, SEEK_END);
# 		   int file_size = ftell(fp);
# 		   ptx_source.reserve(file_size+512);
# 		   fseek(fp, 0, SEEK_SET);
# 		   fread(&ptx_source[0], sizeof(char), file_size, fp);
# 		   fclose(fp);
# 	   }
#        return true;
#     }
# }



main()
