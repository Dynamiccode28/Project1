# Multi-Threaded Log Analytics Engine

## Overview

The **Multi-Threaded Log Analytics Engine** is a concurrent log processing application developed in modern C++. It demonstrates the implementation of the **Producer–Consumer** design pattern using multithreading and synchronization primitives.

The system reads log entries from a file, safely transfers them through a thread-safe queue, processes them concurrently, and generates an aggregated analytics summary. The project emphasizes thread synchronization, clean architecture, and efficient concurrent programming practices.

---

## Features

- Multi-threaded log processing using the Producer–Consumer pattern
- Thread-safe queue implemented with mutexes and condition variables
- Concurrent producer and consumer execution
- Log parsing with severity classification
- Graceful thread shutdown using a poison pill mechanism
- Modular and maintainable C++ design
- Suitable for demonstrating multithreading and concurrency concepts

---

## Project Structure

```text
LogAnalyticsEngine/
│
├── main.cpp                # Application entry point
├── ThreadSafeQueue.h       # Thread-safe queue implementation
├── LogEntry.h              # Log data structure and severity definitions
├── input.log               # Sample log file
└── README.md               # Project documentation
```

---

## Input Format

The application expects each log entry in the following format:

```text
YYYY-MM-DD HH:MM:SS LEVEL Message
```

### Example

```text
2025-06-20 10:15:32 INFO Application started
2025-06-20 10:16:41 WARN Memory usage is high
2025-06-20 10:17:08 ERROR Database connection failed
```

Supported log levels include:

- INFO
- WARN
- ERROR

---

## System Workflow

The application follows a Producer–Consumer architecture.

```text
                input.log
                    │
                    ▼
          Producer Thread
        (Reads & Parses Logs)
                    │
                    ▼
         Thread-Safe Queue
      (Mutex + Condition Variable)
                    │
                    ▼
          Consumer Thread
      (Processes Log Entries)
                    │
                    ▼
         Analytics Summary
```

---

## Processing Pipeline

1. The producer thread reads log entries from `input.log`.
2. Each log line is parsed to extract its timestamp, severity level, and message.
3. Parsed log entries are inserted into a thread-safe queue.
4. The consumer thread retrieves log entries from the queue.
5. Log statistics are aggregated based on severity levels.
6. A poison pill is inserted after all logs are processed to signal graceful termination.
7. The final analytics summary is displayed on the console.

---

## Concurrency Design

The project demonstrates several important concurrency concepts:

- Producer–Consumer architecture
- Thread-safe shared queue
- Mutex-based synchronization
- Condition variables for efficient thread communication
- Atomic and deterministic thread termination
- Separation of producer and consumer responsibilities

---

## Technologies Used

| Category | Technology |
|----------|------------|
| Language | C++ |
| Standard Library | C++ STL |
| Concurrency | std::thread, std::mutex, std::condition_variable |
| Data Structures | Queue |
| File Handling | File Streams (`fstream`) |

---

## Build and Run

### Compile

```bash
g++ -std=c++17 -pthread main.cpp -o LogAnalyticsEngine
```

### Execute

```bash
./LogAnalyticsEngine
```

On Windows (MinGW):

```bash
g++ -std=c++17 -pthread main.cpp -o LogAnalyticsEngine.exe

LogAnalyticsEngine.exe
```

---

## Sample Output

```text
========== Log Analytics Summary ==========

INFO  : 42
WARN  : 8
ERROR : 3

Total Logs Processed : 53
```

---

## Learning Outcomes

This project demonstrates practical understanding of:

- Multithreading in C++
- Producer–Consumer design pattern
- Thread synchronization
- Mutexes and condition variables
- Thread-safe data structures
- Concurrent system design
- File parsing and log processing
- Modern C++ programming practices

---

## Future Improvements

- Multiple producer and consumer threads
- Configurable worker pool
- Log filtering by severity
- Keyword-based log search
- JSON and CSV log support
- Performance benchmarking
- Real-time log monitoring
- Timestamp-based analytics
- Export analytics reports

---

