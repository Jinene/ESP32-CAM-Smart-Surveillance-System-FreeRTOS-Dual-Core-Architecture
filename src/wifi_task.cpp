void wifiTask(void *parameter) {
    WiFi.begin("SSID", "PASSWORD");

    while (WiFi.status() != WL_CONNECTED) {
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }

    Serial.println("WiFi Connected");

    while (true) {
        vTaskDelay(10000 / portTICK_PERIOD_MS);
    }
}
