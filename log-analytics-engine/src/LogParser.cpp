#include "LogEntry.h"
#include <sstream>
using namespace std;
LogEntry parseLog(const string& line) {
    stringstream ss(line);
    string token;

    LogEntry entry;

    getline(ss, token, '|');
    entry.timestamp = stol(token);

    getline(ss, token, '|');
    if (token == "ERROR") entry.level = LogLevel::ERROR;
    else if (token == "WARNING") entry.level = LogLevel::WARN;
    else entry.level = LogLevel::INFO;

    getline(ss, token, '=');
    ss >> entry.response_time;

    return entry;
}
