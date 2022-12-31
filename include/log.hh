#ifndef LOG_H
#define LOG_H

#include <vector>

#define LOG(logLevel, logFunc, funcName, line, ...) do { if (_logLevel_ <= logLevel) (logFunc)(funcName, line, __VA_ARGS__); } while (0)
#define LOGD(...) LOG(LogLevel::DEBUG, logDebug, __func__, __LINE__, __VA_ARGS__);
#define LOGI(...) LOG(LogLevel::INFO, logInfo, __func__, __LINE__, __VA_ARGS__);
#define LOGW(...) LOG(LogLevel::WARNING, logWarning, __func__, __LINE__, __VA_ARGS__);
#define LOGE(...) LOG(LogLevel::ERROR, logError, __func__, __LINE__, __VA_ARGS__);
#define LOGC(...) LOG(LogLevel::CRITICAL, logCritical, __func__, __LINE__, __VA_ARGS__);

#ifndef LOG_LEVEL_DEFAULT
#define LOG_LEVEL_DEFAULT (LogLevel::INFO)
#endif //LOG_LEVEL_DEFAULT

enum class LogLevel
{
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    CRITICAL
};

extern LogLevel _logLevel_;

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
