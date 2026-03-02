#include <Arduino.h>
#include "memory_manager.h"
#include "config.h"

extern TaskHandle_t cameraTaskHandle;
extern TaskHandle_t wifiTaskHandle;
extern TaskHandle_t monitorTaskHandle;

void monitorTask(void *parameter) {

    Serial.println("Monitor Task Started");

    while (true) {

        Serial.println("\n========== SYSTEM MONITOR ==========");

        MemoryManager::printHeapInfo();
        MemoryManager::printPSRAMInfo();

        MemoryManager::printTaskStackUsage(cameraTaskHandle, "CameraTask");
        MemoryManager::printTaskStackUsage(wifiTaskHandle, "WiFiTask");
        MemoryManager::printTaskStackUsage(monitorTaskHandle, "MonitorTask");

        Serial.println("=====================================\n");

        vTaskDelay(MONITOR_DELAY_MS / portTICK_PERIOD_MS);
    }
}
