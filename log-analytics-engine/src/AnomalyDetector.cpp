#include "LogEntry.h"
#include <vector>
#include <string>
using namespace std;
vector<string> detectAnomaly(const LogEntry& entry) {
    vector<string> issues;

    if (entry.level == LogLevel::ERROR)
        issues.push_back("ERROR_EVENT");

    if (entry.response_time > 1500)
        issues.push_back("SLOW_RESPONSE");

    return issues;
}
