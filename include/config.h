#ifndef CONFIG_H
#define CONFIG_H

// ===================== WIFI CONFIG =====================
#define WIFI_SSID       "YOUR_WIFI"
#define WIFI_PASSWORD   "YOUR_PASSWORD"

// ===================== TASK STACK SIZES =====================
#define CAMERA_TASK_STACK    8192
#define WIFI_TASK_STACK      4096
#define MONITOR_TASK_STACK   4096

// ===================== TASK PRIORITIES =====================
#define CAMERA_TASK_PRIORITY    2
#define WIFI_TASK_PRIORITY      1
#define MONITOR_TASK_PRIORITY   1

// ===================== CORE ASSIGNMENT =====================
#define WIFI_CORE      0
#define APP_CORE       1

// ===================== MONITOR INTERVAL =====================
#define MONITOR_DELAY_MS 5000

#endif
