#ifndef UTIL_H
#define UTIL_H

#include <cstdlib>
#include <cstdint>
#include "rc.hh"

RC zeroize(void *s, std::size_t n);
RC random(std::uint8_t *buff, std::size_t buffLen);
RC random(std::vector<std::uint8_t> &buff);
std::vector<std::uint8_t> random(std::size_t len);

#endif //UTIL_H
