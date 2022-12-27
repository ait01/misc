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
    std::uint8_t buff[128] { 0 };
    auto rc = random(buff, sizeof(buff));
    ASSERT_EQ(rc, RC::OK);
    std::size_t i = 0;
    for (; i < sizeof(buff); ++i) if (buff[i]) break;
    ASSERT_NE(i, sizeof(buff));
    printArray("Buffer", buff, sizeof(buff), true);
    rc = zeroize(buff, sizeof(buff));
    ASSERT_EQ(rc, RC::OK);
    i = 0;
    for (; i < sizeof(buff); ++i) if (buff[i]) break;
    ASSERT_EQ(i, sizeof(buff));
    printArray("Buffer", buff, sizeof(buff), true);
}
