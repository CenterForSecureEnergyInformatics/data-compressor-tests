/* Sebastian Burkhart, 2019 */
#include "checkBitSize.h"

int main(void)
{
        const size_t targetSize = TARGET_SIZE;
        const char* const result[] = { "error", "success" };
        const int success = sizeof(size_t) == targetSize && sizeof(void*) == targetSize;
        fprintf( (success == 1) ? stdout : stderr, "%s! compiled for %s. size_t = " SIZE_T_FORMAT_STRING " bits, void* = " SIZE_T_FORMAT_STRING " bits. " SIZE_T_FORMAT_STRING " bits expected.\n", result[success], PLATFORM, SIZE_T_CAST(8*sizeof(size_t)), SIZE_T_CAST(8*sizeof(void*)), SIZE_T_CAST(8*targetSize));
        MSVC_DEBUG_PAUSE;
        return (success == 1) ? EXIT_SUCCESS : EXIT_FAILURE;
}
