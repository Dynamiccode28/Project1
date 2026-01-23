#include "LogEntry.h"
#include <sstream>

LogEntry parseLog(const std::string& line) {
    std::stringstream ss(line);
    std::string token;

    LogEntry entry;

    std::getline(ss, token, '|');
    entry.timestamp = std::stol(token);

    std::getline(ss, token, '|');
    if (token == "ERROR") entry.level = LogLevel::ERROR;
    else if (token == "WARNING") entry.level = LogLevel::WARNING;
    else entry.level = LogLevel::INFO;

    std::getline(ss, token, '=');
    ss >> entry.response_time;

    return entry;
}
