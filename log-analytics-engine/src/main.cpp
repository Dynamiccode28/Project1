#include "ThreadSafeQueue.h"
#include "LogEntry.h"
#include <thread>
#include<ctime>
#include <iostream>

LogEntry parseLogLine(const std::string& line) {
    if (line.find("ERROR") != std::string::npos)
        return {std::time(nullptr), LogLevel::ERROR, 0};
    else if (line.find("WARN") != std::string::npos)
        return {std::time(nullptr), LogLevel::WARN, 0};
    else
        return {std::time(nullptr), LogLevel::INFO, 0};
}


int main() {
    ThreadSafeQueue<LogEntry> queue;

std::thread producer([&queue]() {
    std::ifstream file("input.log");
    std::string line;

    while (std::getline(file, line)) {
        queue.push(parseLogLine(line));
    }
});

    std::thread consumer([&queue]() {
    int infoCount = 0;
    int warnCount = 0;
    int errorCount = 0;

    int processed = 0;
    const int MAX_LOGS = 5;   // change to 1000 later

    while (processed < MAX_LOGS) {
        LogEntry entry = queue.pop();

        if (entry.level == LogLevel::INFO) infoCount++;
        else if (entry.level == LogLevel::WARN) warnCount++;
        else if (entry.level == LogLevel::ERROR) errorCount++;

        processed++;
    }

    // ✅ SUMMARY PRINT (THIS WAS MISSING)
    std::cout << "\nLog Analytics Summary\n";
    std::cout << "---------------------\n";
    std::cout << "INFO  : " << infoCount << "\n";
    std::cout << "WARN  : " << warnCount << "\n";
    std::cout << "ERROR : " << errorCount << "\n";
    std::cout << "Total Logs Processed: " << processed << std::endl;
});


    producer.join();
    consumer.join();

    return 0;
}
