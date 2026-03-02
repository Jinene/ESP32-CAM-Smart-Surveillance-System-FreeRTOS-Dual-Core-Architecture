# FreeRTOS Architecture

We use:

- Preemptive scheduling
- Priority-based tasks
- Core pinning
- Stack monitoring

Task Priorities:

CameraTask: Priority 2
WiFiTask: Priority 1
MonitorTask: Priority 1

Camera has higher priority to avoid frame loss.

Stack usage is monitored with:
uxTaskGetStackHighWaterMark()

Heap monitoring via:
heap_caps_get_free_size()
