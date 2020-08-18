/* Sebastian Burkhart, 2019 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include "../../data-compressor/DataCompressor/common/inc/io.h"

#define BITS_32 4
#define BITS_64 8

#if defined __GNUC__
        #if defined __i386
                #define TARGET_SIZE BITS_32
                #define PLATFORM "i386 linux"
        #elif defined __x86_64
                #define TARGET_SIZE BITS_64
                #define PLATFORM "x86_64 linux"
        #elif defined __arm__
                #define TARGET_SIZE BITS_32
                #define PLATFORM "arm linux"
        #elif defined __aarch64__
                #define TARGET_SIZE BITS_64
                #define PLATFORM "arm (64 bit) linux"
        #else
                #define PLATFORM "invalid"
                #error "unsupported architecture"
        #endif
#elif  defined _MSC_VER  && _MSC_VER >= 1800
        #if defined _WIN64 && !defined _M_ARM
                #define TARGET_SIZE BITS_64
                #define PLATFORM "win64"
        #elif defined _WIN32 && !defined _M_ARM
                #define TARGET_SIZE BITS_32
                #define PLATFORM "win32"
        #else
                #define PLATFORM "invalid"
                #error "unsupported architecture"
        #endif
#else
        #define PLATFORM "invalid compiler"
        #error "unsupported compiler"
#endif

#define SIZE_T_FORMAT_STRING "%" SIZE_T_FORMAT

#if defined _DEBUG  && defined _MSC_VER
        #define MSVC_DEBUG_PAUSE system("pause")
#else
        #define MSVC_DEBUG_PAUSE
#endif
