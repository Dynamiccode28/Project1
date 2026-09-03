#pragma once
#include <ctime>
using namespace std;
enum class LogLevel {
    INFO,
    WARN,
    ERROR
};

struct LogEntry {
    time_t timestamp;  
    LogLevel level;
    int response_time;
};
