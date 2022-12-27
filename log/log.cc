#include <cstdarg>
#include <ctime>
#include <iostream>
#include "log.hh"

LogLevel logLevel = LOG_LEVEL_DEFAULT;

void setLogLevel(LogLevel level) { logLevel = level; }
LogLevel getLogLevel(void) { return logLevel; }

#define LOG_TIME_BUFFER_LEN 30 //GMT 2019-01-01 23:59:59

static void log(const char *level, const char *funcName, int line, const char *fmt, std::va_list *args)
{
    std::va_list logArgs;
    va_copy(logArgs, *args);
    auto t = std::time(nullptr);
    std::tm gmtTime;
    gmtime_r(&t, &gmtTime);
    char timeBuf[LOG_TIME_BUFFER_LEN];
    if (std::strftime(timeBuf, sizeof(timeBuf), "%Z %Y-%m-%d %H:%M:%S", &gmtTime)) {
        std::fprintf(stderr, "[%s][%s][%s:%d] ", level, timeBuf, funcName, line);
    } else {
        std::fprintf(stderr, "[%s][%s:%d] ", level, funcName, line);
    }
    std::vfprintf(stderr, fmt, logArgs);
    std::fprintf(stderr, "\n");
    va_end(logArgs);
}

void logDebug(const char *funcName, int line, const char *fmt, ...)
{
    std::va_list args;
    va_start(args, fmt);
    log("DEBUG", funcName, line, fmt, &args);
    va_end(args);
}

void logInfo(const char *funcName, int line, const char *fmt, ...)
{
    std::va_list args;
    va_start(args, fmt);
    log("INFO", funcName, line, fmt, &args);
    va_end(args);
}

void logWarning(const char *funcName, int line, const char *fmt, ...)
{
    std::va_list args;
    va_start(args, fmt);
    log("WARNING", funcName, line, fmt, &args);
    va_end(args);
}

void logError(const char *funcName, int line, const char *fmt, ...)
{
    std::va_list args;
    va_start(args, fmt);
    log("ERROR", funcName, line, fmt, &args);
    va_end(args);
}

void logCritical(const char *funcName, int line, const char *fmt, ...)
{
    std::va_list args;
    va_start(args, fmt);
    log("CRITICAL", funcName, line, fmt, &args);
    va_end(args);
}
