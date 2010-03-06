/************************************
 **
 **    Enums
 **
 ***********************************/

/**
 * Context creation flags
 */
typedef enum CUctx_flags_enum {
    CU_CTX_SCHED_AUTO  = 0,     ///< Automatic scheduling
    CU_CTX_SCHED_SPIN  = 1,     ///< Set spin as default scheduling
    CU_CTX_SCHED_YIELD = 2,     ///< Set yield as default scheduling
    CU_CTX_SCHED_MASK  = 0x3,
    CU_CTX_BLOCKING_SYNC = 4,   ///< Use blocking synchronization
    CU_CTX_MAP_HOST = 8,        ///< Support mapped pinned allocations
    CU_CTX_LMEM_RESIZE_TO_MAX = 16, ///< Keep local memory allocation after launch
    CU_CTX_FLAGS_MASK  = 0x1f,
} CUctx_flags;

/**
 * Event creation flags
 */
typedef enum CUevent_flags_enum {
    CU_EVENT_DEFAULT       = 0, ///< Default event flag
    CU_EVENT_BLOCKING_SYNC = 1, ///< Event uses blocking synchronization
} CUevent_flags;

/**
 * Array formats
 */
typedef enum CUarray_format_enum {
    CU_AD_FORMAT_UNSIGNED_INT8  = 0x01, ///< Unsigned 8-bit integers
    CU_AD_FORMAT_UNSIGNED_INT16 = 0x02, ///< Unsigned 16-bit integers
    CU_AD_FORMAT_UNSIGNED_INT32 = 0x03, ///< Unsigned 32-bit integers
    CU_AD_FORMAT_SIGNED_INT8    = 0x08, ///< Signed 8-bit integers
    CU_AD_FORMAT_SIGNED_INT16   = 0x09, ///< Signed 16-bit integers
    CU_AD_FORMAT_SIGNED_INT32   = 0x0a, ///< Signed 32-bit integers
    CU_AD_FORMAT_HALF           = 0x10, ///< 16-bit floating point
    CU_AD_FORMAT_FLOAT          = 0x20  ///< 32-bit floating point
} CUarray_format;

/**
 * Texture reference addressing modes
 */
typedef enum CUaddress_mode_enum {
    CU_TR_ADDRESS_MODE_WRAP = 0,    ///< Wrapping address mode
    CU_TR_ADDRESS_MODE_CLAMP = 1,   ///< Clamp to edge address mode
    CU_TR_ADDRESS_MODE_MIRROR = 2,  ///< Mirror address mode
} CUaddress_mode;

/**
 * Texture reference filtering modes
 */
typedef enum CUfilter_mode_enum {
    CU_TR_FILTER_MODE_POINT = 0,    ///< Point filter mode
    CU_TR_FILTER_MODE_LINEAR = 1    ///< Linear filter mode
} CUfilter_mode;

/**
 * Device properties
 */
typedef enum CUdevice_attribute_enum {
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
} CUdevice_attribute;


/**
 * Function properties
 */
typedef enum CUfunction_attribute_enum {
    /**
     * The number of threads beyond which a launch of the function would fail.
     * This number depends on both the function and the device on which the
     * function is currently loaded.
     */
    CU_FUNC_ATTRIBUTE_MAX_THREADS_PER_BLOCK = 0,

    /**
     * The size in bytes of statically-allocated shared memory required by
     * this function. This does not include dynamically-allocated shared
     * memory requested by the user at runtime.
     */
    CU_FUNC_ATTRIBUTE_SHARED_SIZE_BYTES = 1,

    /**
     * The size in bytes of user-allocated constant memory required by this
     * function.
     */
    CU_FUNC_ATTRIBUTE_CONST_SIZE_BYTES = 2,

    /**
     * The size in bytes of thread local memory used by this function.
     */
    CU_FUNC_ATTRIBUTE_LOCAL_SIZE_BYTES = 3,

    /**
     * The number of registers used by each thread of this function.
     */
    CU_FUNC_ATTRIBUTE_NUM_REGS = 4,

    CU_FUNC_ATTRIBUTE_MAX
} CUfunction_attribute;

/**
 * Memory types
 */
typedef enum CUmemorytype_enum {
    CU_MEMORYTYPE_HOST = 0x01,      ///< Host memory
    CU_MEMORYTYPE_DEVICE = 0x02,    ///< Device memory
    CU_MEMORYTYPE_ARRAY = 0x03      ///< Array memory
} CUmemorytype;

/**
 * Compute Modes
 */
typedef enum CUcomputemode_enum {
    CU_COMPUTEMODE_DEFAULT    = 0,     ///< Default compute mode (Multiple contexts allowed per device)
    CU_COMPUTEMODE_EXCLUSIVE  = 1,     ///< Compute-exclusive mode (Only one context can be present on this device at a time)
    CU_COMPUTEMODE_PROHIBITED = 2      ///< Compute-prohibited mode (No contexts can be created on this device at this time)
} CUcomputemode;

/**
 * Online compiler options
 */
typedef enum CUjit_option_enum
{
    /**
     * Max number of registers that a thread may use.
     */
    CU_JIT_MAX_REGISTERS            = 0,

    /**
     * IN: Specifies minimum number of threads per block to target compilation
     * for\n
     * OUT: Returns the number of threads the compiler actually targeted.
     * This restricts the resource utilization fo the compiler (e.g. max
     * registers) such that a block with the given number of threads should be
     * able to launch based on register limitations. Note, this option does not
     * currently take into account any other resource limitations, such as
     * shared memory utilization.
     */
    CU_JIT_THREADS_PER_BLOCK,

    /**
     * Returns a float value in the option of the wall clock time, in
     * milliseconds, spent creating the cubin
     */
    CU_JIT_WALL_TIME,

    /**
     * Pointer to a buffer in which to print any log messsages from PTXAS
     * that are informational in nature
     */
    CU_JIT_INFO_LOG_BUFFER,

    /**
     * IN: Log buffer size in bytes.  Log messages will be capped at this size
     * (including null terminator)\n
     * OUT: Amount of log buffer filled with messages
     */
    CU_JIT_INFO_LOG_BUFFER_SIZE_BYTES,

    /**
     * Pointer to a buffer in which to print any log messages from PTXAS that
     * reflect errors
     */
    CU_JIT_ERROR_LOG_BUFFER,

    /**
     * IN: Log buffer size in bytes.  Log messages will be capped at this size
     * (including null terminator)\n
     * OUT: Amount of log buffer filled with messages
     */
    CU_JIT_ERROR_LOG_BUFFER_SIZE_BYTES,

    /**
     * Level of optimizations to apply to generated code (0 - 4), with 4
     * being the default and highest level of optimizations.
     */
    CU_JIT_OPTIMIZATION_LEVEL,

    /**
     * No option value required. Determines the target based on the current
     * attached context (default)
     */
    CU_JIT_TARGET_FROM_CUCONTEXT,

    /**
     * Target is chosen based on supplied CUjit_target_enum.
     */
    CU_JIT_TARGET,

    /**
     * Specifies choice of fallback strategy if matching cubin is not found.
     * Choice is based on supplied CUjit_fallback_enum.
     */
    CU_JIT_FALLBACK_STRATEGY
    
} CUjit_option;

/**
 * Online compilation targets
 */
typedef enum CUjit_target_enum
{
    CU_TARGET_COMPUTE_10            = 0,    ///< Compute device class 1.0
    CU_TARGET_COMPUTE_11,                   ///< Compute device class 1.1
    CU_TARGET_COMPUTE_12,                   ///< Compute device class 1.2
    CU_TARGET_COMPUTE_13,                   ///< Compute device class 1.3
    CU_TARGET_COMPUTE_20                    ///< Compute device class 2.0
} CUjit_target;

/**
 * Cubin matching fallback strategies
 */
typedef enum CUjit_fallback_enum
{
    /** Prefer to compile ptx */
    CU_PREFER_PTX                   = 0,

    /** Prefer to fall back to compatible binary code */
    CU_PREFER_BINARY

} CUjit_fallback;

/**
 * Flags to register a graphics resource
 */
typedef enum CUgraphicsRegisterFlags_enum {
    CU_GRAPHICS_REGISTER_FLAGS_NONE  = 0x00,
} CUgraphicsRegisterFlags;

/**
 * Flags for mapping and unmapping interop resources
 */
typedef enum CUgraphicsMapResourceFlags_enum {
    CU_GRAPHICS_MAP_RESOURCE_FLAGS_NONE          = 0x00,
    CU_GRAPHICS_MAP_RESOURCE_FLAGS_READ_ONLY     = 0x01,
    CU_GRAPHICS_MAP_RESOURCE_FLAGS_WRITE_DISCARD = 0x02,    
} CUgraphicsMapResourceFlags;

/**
 * Array indices for cube faces
 */
typedef enum CUarray_cubemap_face_enum {
    CU_CUBEMAP_FACE_POSITIVE_X  = 0x00, ///< Positive X face of cubemap
    CU_CUBEMAP_FACE_NEGATIVE_X  = 0x01, ///< Negative X face of cubemap
    CU_CUBEMAP_FACE_POSITIVE_Y  = 0x02, ///< Positive Y face of cubemap
    CU_CUBEMAP_FACE_NEGATIVE_Y  = 0x03, ///< Negative Y face of cubemap
    CU_CUBEMAP_FACE_POSITIVE_Z  = 0x04, ///< Positive Z face of cubemap
    CU_CUBEMAP_FACE_NEGATIVE_Z  = 0x05, ///< Negative Z face of cubemap
} CUarray_cubemap_face;
