#include <random>
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

std::vector<std::uint8_t> random(std::size_t len)
{
    std::vector<std::uint8_t> buff;
    std::random_device r;
    std::default_random_engine e(r());
    std::uniform_int_distribution<std::uint8_t> u(1);
    for (std::size_t i = 0; i < len; ++i) buff.push_back(u(e));
    return buff;
}

RC random(std::vector<std::uint8_t> &buff)
{
    if (buff.empty()) {
        LOGE("Buffer is empty.");
        return RC::BAD_PARAMS;
    }
    buff = random(buff.size());
    return RC::OK;
}

RC random(std::uint8_t *buff, std::size_t buffLen)
{
    if (!buffLen) {
        LOGE("Bad parameter: buffer length is 0.");
        return RC::BAD_PARAMS;
    }
    if (buff == nullptr) {
        LOGE("Bad parameter: buffer is nullptr.");
        return RC::BAD_PARAMS;
    }
    auto buff_ = random(buffLen);
    std::copy(buff_.cbegin(), buff_.cend(), buff);
    return RC::OK;
}
