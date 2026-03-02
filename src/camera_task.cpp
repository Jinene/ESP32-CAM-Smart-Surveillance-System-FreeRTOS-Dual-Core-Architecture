void cameraTask(void *parameter) {
    while (true) {
        camera_fb_t * fb = esp_camera_fb_get();

        if (!fb) {
            Serial.println("Camera capture failed");
        } else {
            Serial.printf("Image size: %u bytes\n", fb->len);
            esp_camera_fb_return(fb);
        }

        vTaskDelay(2000 / portTICK_PERIOD_MS);
    }
}
