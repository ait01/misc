#include <cstdint>
#include "util.hh"
#include "log.hh"

RC zeroize(void *s, std::size_t n)
{
    LOGD("Zeroizing memory.");
    if (!n) {
        LOGE("Bad parameter: 'n' is 0.");
        return RC::BAD_PARAMS;
    }
    if (s == nullptr) {
        LOGE("Bad parameter: 's' is nullptr.");
        return RC::BAD_PARAMS;
    }
    volatile std::uint8_t *p = (std::uint8_t*)s;
    while (n--) *p++ = 0;
    LOGD("Memory zeroized.");
    return RC::OK;
}
