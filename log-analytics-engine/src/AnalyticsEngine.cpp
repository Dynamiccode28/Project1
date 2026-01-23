#include "ThreadSafeQueue.h"
#include "LogEntry.h"
#include <atomic>
#include <iostream>

class AnalyticsEngine {
private:
    ThreadSafeQueue<LogEntry>& queue_;
    std::atomic<int> anomalyCount_{0};

public:
    AnalyticsEngine(ThreadSafeQueue<LogEntry>& q) : queue_(q) {}

    void run() {
        while (true) {
            LogEntry entry = queue_.pop();

            if (entry.response_time < 0)
                break; // poison pill

            if (entry.response_time > 1500)
                anomalyCount_++;
        }
        std::cout << "Total anomalies: " << anomalyCount_ << std::endl;
    }
};
