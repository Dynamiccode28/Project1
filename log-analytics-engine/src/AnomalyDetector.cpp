#include "LogEntry.h"
#include <vector>

std::vector<std::string> detectAnomaly(const LogEntry& entry) {
    std::vector<std::string> issues;

    if (entry.level == LogLevel::ERROR)
        issues.push_back("ERROR_EVENT");

    if (entry.response_time > 1500)
        issues.push_back("SLOW_RESPONSE");

    return issues;
}
