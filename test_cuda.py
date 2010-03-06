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

            ctx = cuda.cuCtxCreate(0,dev)
            cuda.cuCtxDestroy(ctx)
            # No Context
            self.assertRaises(cuda.error, cuda.cuCtxAttach, 0)
            self.assertRaises(cuda.error ,cuda.cuCtxDetach, ctx)
            # New one
            ctx = cuda.cuCtxCreate(0,dev)
            cuda.cuCtxSynchronize()
            cuda.cuCtxPushCurrent(ctx)
            ctx2 = cuda.cuCtxPopCurrent()
            self.assertEquals(ctx, ctx2)
            # self.assertEquals(cuda.cuCtxGetDevice(), dev)
            # h = cuda.cuCtxAttach(0)
            # cuda.cuCtxDetach(h)
            
            self.assertEquals(ctx2, h)

        
class CudaTestCase(unittest.TestCase):

    def test_cuinit_throws(self):
        self.assertRaises(cuda.error, cuda.cuInit, 1)

if __name__ == '__main__':
    unittest.main()

