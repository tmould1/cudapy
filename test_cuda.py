import cuda

import unittest

class SmokeTest(unittest.TestCase):

    def test_start(self):
        cuda.cuInit()
        print cuda.cuDriverGetVersion()
        if cuda.cuDeviceGetCount() > 0:
            dev = cuda.cuDeviceGet(0)
            print cuda.cuDeviceGetName(dev)
            print cuda.cuDeviceComputeCapability(dev)
            print cuda.cuDeviceTotalMem(dev)
            for name in cuda.CUdevice_attribute:
                value = getattr(cuda,name)
                print name,
                print cuda.cuDeviceGetAttribute(value,dev);
        
        cuda.CUcontext()
        cuda.CUmodule()
        cuda.CUfunction()
        cuda.CUarray()
        cuda.CUtexref()
        cuda.CUevent()
        cuda.CUstream()
        cuda.CUgraphicsResource()
        
class CudaTestCase(unittest.TestCase):

    def test_cuinit_throws(self):
        self.assertRaises(cuda.error, cuda.cuInit, 1)

if __name__ == '__main__':
    unittest.main()

