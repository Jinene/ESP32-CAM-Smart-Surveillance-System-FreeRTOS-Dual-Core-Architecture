#include <Arduino.h>
#include <WiFi.h>
#include "config.h"

extern TaskHandle_t wifiTaskHandle;

void wifiTask(void *parameter) {

    Serial.println("WiFi Task Started");

    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    while (WiFi.status() != WL_CONNECTED) {
        Serial.println("Connecting to WiFi...");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }

    Serial.println("WiFi Connected");
    Serial.println(WiFi.localIP());

    while (true) {
        // Keep connection alive
        vTaskDelay(10000 / portTICK_PERIOD_MS);
    }
}
