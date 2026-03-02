#include "memory_manager.h"
#include "esp_heap_caps.h"

void MemoryManager::printHeapInfo() {
    Serial.println("===== HEAP INFO =====");

    Serial.printf("Free Heap: %u bytes\n", ESP.getFreeHeap());
    Serial.printf("Min Free Heap Ever: %u bytes\n", ESP.getMinFreeHeap());
    Serial.printf("Largest Free Block: %u bytes\n",
        heap_caps_get_largest_free_block(MALLOC_CAP_DEFAULT));
}

void MemoryManager::printPSRAMInfo() {
    Serial.println("===== PSRAM INFO =====");

    Serial.printf("Free PSRAM: %u bytes\n",
        heap_caps_get_free_size(MALLOC_CAP_SPIRAM));

    Serial.printf("Total PSRAM: %u bytes\n",
        heap_caps_get_total_size(MALLOC_CAP_SPIRAM));
}

void MemoryManager::printTaskStackUsage(TaskHandle_t taskHandle, const char* taskName) {

    UBaseType_t highWaterMark = uxTaskGetStackHighWaterMark(taskHandle);

    Serial.printf("%s Stack HighWaterMark: %u words (%u bytes)\n",
                  taskName,
                  highWaterMark,
                  highWaterMark * sizeof(StackType_t));
}
