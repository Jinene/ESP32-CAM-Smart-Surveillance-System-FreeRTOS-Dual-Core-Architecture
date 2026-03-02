# ESP32 Dual-Core Architecture

The ESP32 has two Tensilica Xtensa cores:

- Core 0 (PRO_CPU)
- Core 1 (APP_CPU)

In this project:

Core 0:
- WiFi stack
- TCP/IP system tasks
- Network-related operations

Core 1:
- Camera processing
- Monitoring
- Application logic

We use xTaskCreatePinnedToCore() to explicitly assign tasks.

This prevents:
- Core starvation
- WiFi instability
- Random watchdog resets
