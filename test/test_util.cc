#include <gtest/gtest.h>
#include "util.hh"
#include "log.hh"

namespace {

    constexpr std::size_t BUFF_LEN = 128;
    constexpr std::size_t BUFF_NUM = 3;

} //namespace

class Util : public ::testing::Test
{
 protected:
    void SetUp() override
    {
        buffs.resize(BUFF_NUM);
        for (auto &i : buffs) {
            i.resize(BUFF_LEN);
            checkBuffZero(i);
        }
    }

    void TearDown() override {}

    void checkBuffRandom(const std::vector<std::uint8_t> &buff)
    {
        ASSERT_FALSE(buff.empty());
        ASSERT_EQ(buff.size(), BUFF_LEN);
        std::size_t i = 0;
        for (; i < buff.size(); ++i) if (buff[i]) break;
        ASSERT_NE(i, buff.size());
    }

    void checkBuffZero(const std::vector<std::uint8_t> &buff)
    {
        ASSERT_FALSE(buff.empty());
        ASSERT_EQ(buff.size(), BUFF_LEN);
        for (auto i : buff) { ASSERT_FALSE(i); }
    }

 protected:
    std::vector<std::vector<std::uint8_t>> buffs;
};

TEST_F(Util, RandomPositive) {
    auto rc = random(buffs[0].data(), buffs[0].size());
    ASSERT_EQ(rc, RC::OK);
    checkBuffRandom(buffs[0]);

    rc = random(buffs[1]);
    ASSERT_EQ(rc, RC::OK);
    checkBuffRandom(buffs[1]);

    buffs[2] = random(BUFF_LEN);
    checkBuffRandom(buffs[2]);

    ASSERT_NE(buffs[0], buffs[1]);
    ASSERT_NE(buffs[0], buffs[2]);
    ASSERT_NE(buffs[1], buffs[2]);

    printHex("Buffer0", buffs[0], true);
    printHex("Buffer1", buffs[1], true);
    printHex("Buffer2", buffs[2], true);
}

TEST_F(Util, ZeroizePositive) {
    buffs[0] = random(BUFF_LEN);
    checkBuffRandom(buffs[0]);
    printHex("Buffer0", buffs[0], true);

    auto rc = zeroize(buffs[0].data(), buffs[0].size());
    ASSERT_EQ(rc, RC::OK);
    checkBuffZero(buffs[0]);
    printHex("Buffer0", buffs[0], true);
}

TEST_F(Util, ZeroizeBadParams) {
    buffs[0] = random(BUFF_LEN);
    checkBuffRandom(buffs[0]);

    auto rc = zeroize(nullptr, buffs[0].size());
    ASSERT_EQ(rc, RC::BAD_PARAMS);
    rc = zeroize(buffs[0].data(), 0);
    ASSERT_EQ(rc, RC::BAD_PARAMS);
}
