# Guida Installazione Arduino IDE

## 📋 Prerequisiti

### Software
- **Arduino IDE 1.8.19+** o **Arduino IDE 2.0+**
- **Python 3.8+** (per alcune librerie)

### Hardware
- **WT32-SC01 Plus**
- **ELM327 Bluetooth** (HC-05 o simile)
- **Cavo USB Mini**
- **Cavetti Jumper**

## 🔧 Step 1: Installa Arduino IDE

### Windows/Mac/Linux
1. Vai a: https://www.arduino.cc/en/software
2. Scarica e installa Arduino IDE
3. Avvia Arduino IDE

## 📦 Step 2: Aggiungi Board ESP32

### Metodo 1: Gestione Schede (Consigliato)

1. Apri Arduino IDE
2. Vai a: **File** → **Preferenze**
3. In "URL Aggiuntive Gestioni Schede", incolla:
```
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
```
4. Clicca OK
5. Vai a: **Strumenti** → **Scheda** → **Gestione schede**
6. Ricerca: "ESP32"
7. Installa "ESP32 by Espressif Systems"

## 🎯 Step 3: Seleziona Board

1. **Strumenti** → **Scheda** → **ESP32**
2. Seleziona: **ESP32S3 Dev Module** (per WT32-SC01 Plus)
3. **Strumenti** → **Porta** → Seleziona la tua porta COM
4. **Strumenti** → **Velocità di caricamento** → **921600**

## 📚 Step 4: Installa Librerie Richieste

### Via Gestione Librerie

1. **Strumenti** → **Gestione librerie**
2. Ricerca e installa:
   - **LVGL** (lvgl/LVGL) - v8.3.0+
   - **ArduinoJson** - v6.21.3+
   - **PubSubClient** - v2.8.0+
   - **ELMduino** - v3.0.0+ (opzionale, già inclusa)

## 🔌 Step 5: Connessioni Hardware

### HC-05 Bluetooth → WT32-SC01 Plus
```
HC-05           WT32-SC01 Plus
VCC (5V)  ----→  5V
GND       ----→  GND
TX        ----→  GPIO16 (RX)
RX        ----→  GPIO17 (TX)
```

## 📥 Step 6: Carica il Progetto

1. **File** → **Apri** → `BMW_F20_Dashboard.ino`
2. Modifica `config.h` con i tuoi parametri:
   ```cpp
   #define WIFI_SSID "TuoSSID"
   #define BT_DEVICE_NAME "HC-05"
   #define DEBUG_LEVEL 2
   ```
3. **Schizzo** → **Carica** (Ctrl+U)
4. Attendi il completamento

## ✅ Step 7: Verifica

1. Apri: **Strumenti** → **Monitor Seriale**
2. Imposta Baudrate: **115200**
3. Dovresti vedere:
```
========================================
   BMW F20 Dashboard - Arduino IDE
========================================

[INFO] [00:00:01] INFO: Avvio BMW F20 Dashboard - Arduino IDE
[INFO] [00:00:02] INFO: Inizializzazione display...
[INFO] [00:00:03] INFO: Inizializzazione Bluetooth...
[INFO] [00:00:04] INFO: Inizializzazione OBD2...
[INFO] [00:00:05] INFO: Sistema pronto!
```

## 🐛 Troubleshooting

### "Errore: Board 'esp32:esp32:esp32' non trovata"
- Verifica di aver installato il board ESP32
- Riavvia Arduino IDE
- Controlla URL gestione schede

### "Errore di caricamento / Timeout"
- Premi il pulsante **BOOT** del WT32 durante il caricamento
- Prova baudrate 115200 invece di 921600
- Controlla il cavo USB

### "Libreria LVGL non trovata"
- Vai a **Strumenti** → **Gestione librerie**
- Ricerca "LVGL" e installa
- Riavvia Arduino IDE

### "Serial Monitor non mostra output"
- Verifica di aver selezionato la porta corretta
- Imposta Baudrate a **115200**
- Disconnetti e ricollega il cavo USB

## 🔧 Configurazione Avanzata

### Modifica Baudrate
In `config.h`:
```cpp
#define UART_SPEED 38400  // Velocità HC-05
```

### Attiva Debug Completo
```cpp
#define DEBUG_LEVEL 3  // 0=OFF, 1=ERROR, 2=INFO, 3=DEBUG
```

### Disabilita Bluetooth
```cpp
#define BT_ENABLED 0  // Bluetooth disabilitato
```

## 📊 Comandi OBD2 Supportati

| Comando | Descrizione |
|---------|-------------|
| `01 0C` | RPM |
| `01 0D` | Velocità |
| `01 05` | Temperatura liquido |
| `01 2F` | Livello carburante |
| `01 42` | Voltaggio batteria |

## 📚 Riferimenti Utili

- [Arduino IDE Official](https://www.arduino.cc/)
- [ESP32 Arduino Core](https://github.com/espressif/arduino-esp32)
- [LVGL Documentation](https://docs.lvgl.io/)
- [WT32-SC01 Plus Wiki](https://github.com/Makerfabs/WT32-SC01-Plus)

---

**Ultimo aggiornamento**: 2026-06-04