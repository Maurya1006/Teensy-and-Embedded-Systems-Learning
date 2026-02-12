# Task 01 – Heartbeat and Non-Blocking Timing

## Objective
To understand and implement non-blocking timing in an embedded system
using millis() instead of delay() on the Teensy 4.1 microcontroller.

---

## What I Built
- LED heartbeat blinking every 500 ms using the built-in LED (pin 13)
- Serial uptime logger printing system time every 1000 ms
- Both tasks run simultaneously without blocking the CPU

---

## Key Concepts Learned

### 1. delay()
- Blocks CPU execution
- Prevents other tasks from running
- Unsafe for real-time embedded systems

### 2. millis()
- Returns system uptime in milliseconds
- Runs independently of program execution
- Enables non-blocking scheduling

### 3. Non-Blocking Timing Pattern
```cpp
if (currentTime - lastTime >= interval)
