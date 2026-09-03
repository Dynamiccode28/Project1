#pragma once
#include <queue>
#include <mutex>
#include <condition_variable>
using namespace std;
template<typename T>
class ThreadSafeQueue {
private:
    queue<T> queue_;
    mutex mutex_;
    condition_variable cv_;

public:
    void push(T value) {
        {
            lock_guard<mutex> lock(mutex_);
            queue_.push(move(value));
        }
        cv_.notify_one();
    }

    T pop() {
        unique_lock<mutex> lock(mutex_);
        cv_.wait(lock, [this]() { return !queue_.empty(); });

        T val = move(queue_.front());
        queue_.pop();
        return val;
    }
};
