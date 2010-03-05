from distutils.core import setup
from distutils.extension import Extension
import os.path
import sys

conf = {'CXXFLAGS' : [], 'LDFLAGS' : []}

include_dirs = ['/usr/local/cuda/include']
libraries=['cuda']
library_dirs=['/usr/local/cuda/lib']

cuda_files = ['src/cuda.c']

setup(name="cuda", 
      ext_modules=[
                    Extension("cuda", cuda_files,
                              library_dirs=library_dirs,
                              libraries=libraries,
                              include_dirs=include_dirs,
                              extra_compile_args=conf["CXXFLAGS"],
                              extra_link_args=conf["LDFLAGS"],                              
                              depends=[]),      
                    ]
     )
