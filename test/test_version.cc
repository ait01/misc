#include <gtest/gtest.h>
#include "version.hh"
#include "log.hh"

TEST(Version, Positive) {
    LOGI("Version %s", VERSION);
    LOGI("Commit %s", COMMIT);
}
