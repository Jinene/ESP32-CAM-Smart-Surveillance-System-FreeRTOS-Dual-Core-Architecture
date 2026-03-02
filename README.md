# ESP32-CAM Smart Surveillance System  
### FreeRTOS Dual-Core Architecture with Advanced Memory Management

---

## 📌 Overview

This project demonstrates a professional embedded systems architecture using:

- ESP32-CAM (AI Thinker)
- FreeRTOS
- Dual-core task pinning
- Advanced heap & stack monitoring
- PSRAM optimization
- Modular RTOS design

The goal is to build a **production-style embedded application** rather than a simple Arduino sketch.

---

## 🧠 System Architecture

The ESP32 contains two cores:

- Core 0 (PRO_CPU) → System & WiFi tasks
- Core 1 (APP_CPU) → Application logic

### Task Distribution

| Task         | Core | Priority | Stack |
|-------------|------|----------|--------|
| WiFiTask    | 0    | 1        | 4096   |
| CameraTask  | 1    | 2        | 8192   |
| MonitorTask | 1    | 1        | 4096   |

Tasks are created using:

```cpp
xTaskCreatePinnedToCore()
