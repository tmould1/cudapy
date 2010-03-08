import cuda
from cuda import *

import unittest

cuda.cuInit()
        
class SmokeTest(unittest.TestCase):

    def test_start(self):
        cuda.cuDriverGetVersion()
        if cuda.cuDeviceGetCount() > 0:
            dev = cuda.cuDeviceGet(0)
            cuDeviceGetName(dev)
            cuDeviceComputeCapability(dev)
            cuDeviceTotalMem(dev)
            for name in cuda.CUdevice_attribute:
                value = getattr(cuda,name)
                cuda.cuDeviceGetAttribute(value,dev)

            ctx = cuda.cuCtxCreate(0,dev)
            self.assertEquals(cuCtxGetDevice(), dev)
            cuCtxDestroy(ctx)
            # No Context
            self.assertRaises(cuda.error, cuda.cuCtxAttach, 0)
            self.assertRaises(cuda.error ,cuda.cuCtxDetach, ctx)
            # New one
            ctx = cuCtxCreate(0,dev)
            cuCtxAttach(0)
            cuCtxSynchronize()
            # cuCtxPushCurrent(ctx)
            # ctx2 = cuCtxPopCurrent()
            # self.assertEquals(ctx, ctx2)
            # h = cuda.cuCtxAttach(0)
            # cuda.cuCtxDetach(h)
            # self.assertEquals(ctx2, h)
    
    def test_module(self):
        dev = cuDeviceGet(0)
        ctx = cuCtxCreate(0,dev)
        mod = cuModuleLoad("./sdk/vectorAdd.ptx")
        cuModuleUnload(mod)
        cuCtxDestroy(ctx)
        
class CudaTestCase(unittest.TestCase):

    def test_cuinit_throws(self):
        self.assertRaises(cuda.error, cuda.cuInit,1)

if __name__ == '__main__':
    unittest.main()

