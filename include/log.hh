#ifndef LOG_H
#define LOG_H

#include <vector>

#define LOG(LOG_LEVEL, logFunc, funcName, line, ...) do { if (logLevel <= LOG_LEVEL) (logFunc)(funcName, line, __VA_ARGS__); } while (0)
#define LOGD(...) LOG(LogLevel::LOG_LEVEL_DEBUG, logDebug, __func__, __LINE__, __VA_ARGS__);
#define LOGI(...) LOG(LogLevel::LOG_LEVEL_INFO, logInfo, __func__, __LINE__, __VA_ARGS__);
#define LOGW(...) LOG(LogLevel::LOG_LEVEL_WARNING, logWarning, __func__, __LINE__, __VA_ARGS__);
#define LOGE(...) LOG(LogLevel::LOG_LEVEL_ERROR, logError, __func__, __LINE__, __VA_ARGS__);
#define LOGC(...) LOG(LogLevel::LOG_LEVEL_CRITICAL, logCritical, __func__, __LINE__, __VA_ARGS__);

#ifndef LOG_LEVEL_DEFAULT
#define LOG_LEVEL_DEFAULT (LogLevel::LOG_LEVEL_INFO)
#endif //LOG_LEVEL_DEFAULT

enum class LogLevel
{
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARNING,
    LOG_LEVEL_ERROR,
    LOG_LEVEL_CRITICAL
};

extern LogLevel logLevel;

void setLogLevel(LogLevel level);
LogLevel getLogLevel(void);
void logDebug(const char *funcName, int line, const char *fmt, ...);
void logInfo(const char *funcName, int line, const char *fmt, ...);
void logWarning(const char *funcName, int line, const char *fmt, ...);
void logError(const char *funcName, int line, const char *fmt, ...);
void logCritical(const char *funcName, int line, const char *fmt, ...);
void printHex(const std::string &name, const std::vector<std::uint8_t> &arr, bool pretty = false);
void printHex(const char *name, const std::uint8_t *arr, std::size_t len, bool pretty = false);

#endif //LOG_H
