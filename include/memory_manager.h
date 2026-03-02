#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#include <Arduino.h>

class MemoryManager {
public:
    static void printHeapInfo();
    static void printPSRAMInfo();
    static void printTaskStackUsage(TaskHandle_t taskHandle, const char* taskName);
};

#endif
