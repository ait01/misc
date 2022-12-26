#include <iostream>
#include <gtest/gtest.h>
#include "version.hh"

TEST(Version, Positive) {
    std::cout << "Version " << VERSION << std::endl;
    std::cout << "Commit " << COMMIT << std::endl;
}
