#ifndef CONFIG_H
#define CONFIG_H

// ===== CONFIGURAZIONE WIFI =====
#define WIFI_SSID "TuoSSID"
#define WIFI_PASSWORD "TuaPassword"
#define WIFI_TIMEOUT 10000  // ms

// ===== CONFIGURAZIONE BLUETOOTH =====
#define BT_DEVICE_NAME "HC-05"
#define BT_ENABLED 1
#define UART_RX_PIN 16
#define UART_TX_PIN 17
#define UART_SPEED 38400

// ===== CONFIGURAZIONE OBD2 =====
#define OBD2_MODE "BLUETOOTH"  // "BLUETOOTH" o "WIFI"
#define OBD2_POLL_RATE 500     // ms tra le letture
#define OBD2_TIMEOUT 2000      // ms timeout risposta

// ===== CONFIGURAZIONE DISPLAY =====
#define DISPLAY_WIDTH 480
#define DISPLAY_HEIGHT 320
#define DISPLAY_BPP 16
#define TOUCH_CALIBRATION 1

// ===== CONFIGURAZIONE LOGGING =====
#define SERIAL_DEBUG 1
#define DEBUG_LEVEL 2  // 0=OFF, 1=ERROR, 2=INFO, 3=DEBUG

// ===== CONFIGURAZIONE MOTORE =====
#define ENGINE_TYPE "N20"  // BMW F20
#define FUEL_TANK_CAPACITY 50  // litri

// ===== PID OBD2 DA LEGGERE =====
#define PID_RPM 0x0C
#define PID_SPEED 0x0D
#define PID_COOLANT_TEMP 0x05
#define PID_AIR_TEMP 0x46
#define PID_FUEL_LEVEL 0x2F
#define PID_VOLTAGE 0x42

// ===== CONFIGURAZIONE GUI =====
#define GUI_REFRESH_RATE 100  // ms

// ===== CONFIGURAZIONE ALLARMI =====
#define ALARM_COOLANT_TEMP_HIGH 110   // °C
#define ALARM_RPM_HIGH 7000            // RPM
#define ALARM_VOLTAGE_LOW 11.0         // V

// ===== COLORI TEMA =====
#define COLOR_PRIMARY 0x1E90FF      // Blu
#define COLOR_BG 0x1A1A1A           // Nero
#define COLOR_TEXT 0xFFFFFF         // Bianco

#endif // CONFIG_H