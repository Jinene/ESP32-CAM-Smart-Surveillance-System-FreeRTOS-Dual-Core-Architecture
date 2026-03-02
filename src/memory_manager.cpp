#include "memory_manager.h"
#include "esp_heap_caps.h"

void MemoryManager::printHeapInfo() {

    Serial.println("===== HEAP INFO =====");

    Serial.printf("Free Heap: %d bytes\n", ESP.getFreeHeap());
    Serial.printf("Min Free Heap: %d bytes\n", ESP.getMinFreeHeap());
    Serial.printf("Largest Free Block: %d bytes\n",
        heap_caps_get_largest_free_block(MALLOC_CAP_DEFAULT));

    Serial.printf("Free PSRAM: %d bytes\n",
        heap_caps_get_free_size(MALLOC_CAP_SPIRAM));
}
