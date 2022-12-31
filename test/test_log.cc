#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "log.hh"

namespace {

constexpr const char* FORMAT = "Test Log #%d";
constexpr int NUMBER = 1;
constexpr const char* EXPECTED_STRING = "Test Log #1\n";
constexpr const char* EXPECTED_STRING_NO_VA = "Test Log";

} //namespace

TEST(Log, Level) {
    ASSERT_EQ(getLogLevel(), LOG_LEVEL_DEFAULT);
    LOGD("Log level DEBUG.");
    LOGI("Log level INFO.");
    LOGW("Log level WARNING.");
    LOGE("Log level ERROR.");
    LOGC("Log level CRITICAL.");
    std::cout << std::endl;
    setLogLevel(LogLevel::DEBUG);
    ASSERT_EQ(getLogLevel(), LogLevel::DEBUG);
    LOGD("Log level DEBUG.");
    LOGI("Log level INFO.");
    LOGW("Log level WARNING.");
    LOGE("Log level ERROR.");
    LOGC("Log level CRITICAL.");
    std::cout << std::endl;
    setLogLevel(LogLevel::INFO);
    ASSERT_EQ(getLogLevel(), LogLevel::INFO);
    LOGD("Log level DEBUG.");
    LOGI("Log level INFO.");
    LOGW("Log level WARNING.");
    LOGE("Log level ERROR.");
    LOGC("Log level CRITICAL.");
    std::cout << std::endl;
    setLogLevel(LogLevel::WARNING);
    ASSERT_EQ(getLogLevel(), LogLevel::WARNING);
    LOGD("Log level DEBUG.");
    LOGI("Log level INFO.");
    LOGW("Log level WARNING.");
    LOGE("Log level ERROR.");
    LOGC("Log level CRITICAL.");
    std::cout << std::endl;
    setLogLevel(LogLevel::ERROR);
    ASSERT_EQ(getLogLevel(), LogLevel::ERROR);
    LOGD("Log level DEBUG.");
    LOGI("Log level INFO.");
    LOGW("Log level WARNING.");
    LOGE("Log level ERROR.");
    LOGC("Log level CRITICAL.");
    std::cout << std::endl;
    setLogLevel(LogLevel::CRITICAL);
    ASSERT_EQ(getLogLevel(), LogLevel::CRITICAL);
    LOGD("Log level DEBUG.");
    LOGI("Log level INFO.");
    LOGW("Log level WARNING.");
    LOGE("Log level ERROR.");
    LOGC("Log level CRITICAL.");
}

TEST(Log, Debug) {
    setLogLevel(LogLevel::DEBUG);
    ::testing::internal::CaptureStderr();
    LOGD(FORMAT, NUMBER);
    std::string output = ::testing::internal::GetCapturedStderr();
    ASSERT_THAT(output, ::testing::StartsWith("[DEBUG]"));
    ASSERT_THAT(output, ::testing::EndsWith(EXPECTED_STRING));

    setLogLevel(LogLevel::INFO);
    ::testing::internal::CaptureStderr();
    LOGD(FORMAT, NUMBER);
    output = ::testing::internal::GetCapturedStderr();
    ASSERT_THAT(output, ::testing::IsEmpty());
}

TEST(Log, Info) {
    setLogLevel(LogLevel::INFO);
    ::testing::internal::CaptureStderr();
    LOGI(FORMAT, NUMBER);
    std::string output = ::testing::internal::GetCapturedStderr();
    ASSERT_THAT(output, ::testing::StartsWith("[INFO]"));
    ASSERT_THAT(output, ::testing::EndsWith(EXPECTED_STRING));

    setLogLevel(LogLevel::WARNING);
    ::testing::internal::CaptureStderr();
    LOGI(FORMAT, NUMBER);
    output = ::testing::internal::GetCapturedStderr();
    ASSERT_THAT(output, ::testing::IsEmpty());
}

TEST(Log, Warning) {
    setLogLevel(LogLevel::WARNING);
    ::testing::internal::CaptureStderr();
    LOGW(FORMAT, NUMBER);
    std::string output = ::testing::internal::GetCapturedStderr();
    ASSERT_THAT(output, ::testing::StartsWith("[WARNING]"));
    ASSERT_THAT(output, ::testing::EndsWith(EXPECTED_STRING));

    setLogLevel(LogLevel::ERROR);
    ::testing::internal::CaptureStderr();
    LOGW(FORMAT, NUMBER);
    output = ::testing::internal::GetCapturedStderr();
    ASSERT_THAT(output, ::testing::IsEmpty());
}

TEST(Log, Error) {
    setLogLevel(LogLevel::ERROR);
    ::testing::internal::CaptureStderr();
    LOGE(FORMAT, NUMBER);
    std::string output = ::testing::internal::GetCapturedStderr();
    ASSERT_THAT(output, ::testing::StartsWith("[ERROR]"));
    ASSERT_THAT(output, ::testing::EndsWith(EXPECTED_STRING));

    setLogLevel(LogLevel::CRITICAL);
    ::testing::internal::CaptureStderr();
    LOGE(FORMAT, NUMBER);
    output = ::testing::internal::GetCapturedStderr();
    ASSERT_THAT(output, ::testing::IsEmpty());
}

TEST(Log, Critical) {
    ::testing::internal::CaptureStderr();
    LOGC(FORMAT, NUMBER);
    std::string output = ::testing::internal::GetCapturedStderr();
    ASSERT_THAT(output, ::testing::StartsWith("[CRITICAL]"));
    ASSERT_THAT(output, ::testing::EndsWith(EXPECTED_STRING));
}

TEST(Log, NoVariadicArgs) {
    setLogLevel(LogLevel::INFO);
    ::testing::internal::CaptureStderr();
    LOGI(EXPECTED_STRING_NO_VA);
    std::string output = ::testing::internal::GetCapturedStderr();
    ASSERT_THAT(output, ::testing::StartsWith("[INFO]"));
    ASSERT_THAT(output, ::testing::EndsWith(std::string(EXPECTED_STRING_NO_VA) + "\n"));
}
