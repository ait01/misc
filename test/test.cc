#include <iostream>
#include <gtest/gtest.h>
#include "version.hh"
#include "util.hh"
#include "log.hh"

TEST(Version, Positive) {
    std::cout << "Version " << VERSION << std::endl;
    std::cout << "Commit " << COMMIT << std::endl;
}

TEST(Util, Positive) {
    std::uint8_t buffer[1024] { 0 };
    auto rc = zeroize(buffer, sizeof(buffer));
    ASSERT_EQ(rc, RC::OK);
}
