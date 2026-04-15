# Multi-Threaded Log Analytics Engine (C++)

## 📌 Overview
This project implements a **multi-threaded log analytics system** using modern C++.  
It demonstrates how logs are processed concurrently using a **producer–consumer architecture** with a thread-safe queue.

The application reads log entries from a file, processes them concurrently, and generates an aggregated analytics summary.

---

## 🧩 Key Features
- Producer–Consumer design using threads
- Thread-safe queue implemented with mutex and condition variables
- File-based log parsing and severity classification
- Real-time log analytics with graceful thread termination
- Modular and clean design suitable for interviews and GitHub portfolio

---

## 📂 Project Structure

LogAnalyticsEngine/
├── main.cpp # Main program
├── ThreadSafeQueue.h # Thread-safe queue implementation
├── LogEntry.h # Log data structure and enums
├── input.log # Sample input log file
├── README.md # Project documentation

## 📥 Input Format (`input.log`)
Each log entry should follow 
YYYY-MM-DD HH:MM:SS LEVEL Message

## ⚙️ How It Works
1. **Producer thread** reads log lines from `input.log`.  
2. Each line is parsed to extract the log level (`INFO`, `WARN`, `ERROR`).  
3. Parsed logs are pushed into a **thread-safe queue**.  
4. **Consumer thread** pops logs and aggregates statistics.  
5. A **poison pill** signals the consumer to terminate gracefully.  
6. Final **analytics summary** is printed to console.this format:
YYYY-MM-DD HH:MM:SS LEVEL Message

## ⚙️ How It Works
1. **Producer thread** reads log lines from `input.log`.  
2. Each line is parsed to extract the log level (`INFO`, `WARN`, `ERROR`).  
3. Parsed logs are pushed into a **thread-safe queue**.  
4. **Consumer thread** pops logs and aggregates statistics.  
5. A **poison pill** signals the consumer to terminate gracefully.  
6. Final **analytics summary** is printed to console.
