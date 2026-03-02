void monitorTask(void *parameter) {

    while (true) {

        Serial.println("===== TASK MONITOR =====");

        Serial.printf("Camera Stack HighWaterMark: %u\n",
            uxTaskGetStackHighWaterMark(cameraTaskHandle));

        Serial.printf("WiFi Stack HighWaterMark: %u\n",
            uxTaskGetStackHighWaterMark(wifiTaskHandle));

        MemoryManager::printHeapInfo();

        vTaskDelay(5000 / portTICK_PERIOD_MS);
    }
}
