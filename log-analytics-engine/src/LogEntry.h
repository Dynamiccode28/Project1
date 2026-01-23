#pragma once
#include <ctime>

enum class LogLevel {
    INFO,
    WARN,
    ERROR
};

struct LogEntry {
    std::time_t timestamp;   // ✅ FIXED
    LogLevel level;
    int response_time;
};
