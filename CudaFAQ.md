# Introduction #

Add your content here.

How to express INFINITY in cuda:

```
#define CUDA_INFINITY __int_as_float(0x7f800000)
```

# Keep in mind that .. #

  * CudaMalloc Aligns memory @ 256 **Bytes**
  * Vector elements can be extracted from the vector with the suffixes .x, .y, .z and .w, as well as the typical color fields .r, .g, .b and .a.
  * Vector loads and stores can be used to implement wide loads and stores, which may improve memory performance.

  * Segments are 128 Bytes
  * Registers are 32 bit
  * A kernel can fetch 128 bits at once mov.b128 and put them in the register file, ie in 4 consecutive registers

  * the counter of the profilers are inside a specific multiprocessor. Allocate a # of blocks >= # multiprocessors

  * don't use buff[i](i.md) != 0x0 use, !!buf[i](i.md)

# Details #

Add your content here.  Format your content with:
  * Text in **bold** or _italic_
  * Headings, paragraphs, and lists
  * Automatic links to other wiki pages