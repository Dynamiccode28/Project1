#include "ThreadSafeQueue.h"
#include "LogEntry.h"
#include <thread>
#include <fstream>
#include<ctime>
#include <iostream>
using namespace std;
LogEntry parseLogLine(const string& line) {
    if (line.find("ERROR") != string::npos)
        return {time(nullptr), LogLevel::ERROR, 0};
    else if (line.find("WARN") != string::npos)
        return {time(nullptr), LogLevel::WARN, 0};
    else
        return {time(nullptr), LogLevel::INFO, 0};
}


int main() {
    ThreadSafeQueue<LogEntry> queue;

    thread producer([&queue]() {
    ifstream file("input.log");
    string line;

    while (getline(file, line)) {
        queue.push(parseLogLine(line));
    }
});

    thread consumer([&queue]() {
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

    
    cout << "\nLog Analytics Summary\n";
    cout << "---------------------\n";
    cout << "INFO  : " << infoCount << "\n";
    cout << "WARN  : " << warnCount << "\n";
    cout << "ERROR : " << errorCount << "\n";
    cout << "Total Logs Processed: " << processed << std::endl;
});


    producer.join();
    consumer.join();

    return 0;
}
