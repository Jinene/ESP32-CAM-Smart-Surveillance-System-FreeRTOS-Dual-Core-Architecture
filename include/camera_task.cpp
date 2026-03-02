#include <Arduino.h>
#include "esp_camera.h"
#include "memory_manager.h"

extern TaskHandle_t cameraTaskHandle;

void cameraTask(void *parameter) {

    Serial.println("Camera Task Started");

    while (true) {

        camera_fb_t * fb = esp_camera_fb_get();

        if (!fb) {
            Serial.println("Camera capture failed");
        } else {
            Serial.printf("Captured image size: %u bytes\n", fb->len);

            // Simulate processing
            vTaskDelay(100 / portTICK_PERIOD_MS);

            esp_camera_fb_return(fb);
        }

        vTaskDelay(2000 / portTICK_PERIOD_MS);
    }
}
