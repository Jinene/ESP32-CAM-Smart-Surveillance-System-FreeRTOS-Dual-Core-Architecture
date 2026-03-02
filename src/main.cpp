#include <Arduino.h>
#include "config.h"
#include "memory_manager.h"

TaskHandle_t cameraTaskHandle;
TaskHandle_t wifiTaskHandle;
TaskHandle_t monitorTaskHandle;

void setup() {
    Serial.begin(115200);

    MemoryManager::printHeapInfo();

    xTaskCreatePinnedToCore(
        cameraTask,
        "CameraTask",
        8192,
        NULL,
        2,
        &cameraTaskHandle,
        1   // Core 1
    );

    xTaskCreatePinnedToCore(
        wifiTask,
        "WiFiTask",
        4096,
        NULL,
        1,
        &wifiTaskHandle,
        0   // Core 0
    );

    xTaskCreatePinnedToCore(
        monitorTask,
        "MonitorTask",
        4096,
        NULL,
        1,
        &monitorTaskHandle,
        1
    );
}

void loop() {
    // Empty because FreeRTOS handles everything
}
