# BMW F20 WT32-SC01 Plus Dashboard - Arduino IDE

Interfaccia grafica completa per visualizzare i dati diagnostici della BMW F20 su display WT32-SC01 Plus con ESP32.

**Versione: Arduino IDE** ✨

## 🚗 Caratteristiche

- **Lettura dati BMW F20** via OBD2 (Bluetooth/Wi-Fi)
- **Interfaccia touch intuitiva** con LVGL
- **Visualizzazione in tempo reale**:
  - RPM e velocità
  - Temperatura motore/olio
  - Consumo carburante
  - Voltaggio batteria
  - Codici diagnostici (DTC)
- **Storage dati** su SD card
- **Menu navigazione** completo
- **Configurazione wireless**

## 📱 Hardware Richiesto

- **WT32-SC01 Plus** (Display 3.5" ESP32)
- **Lettore OBD2 Bluetooth** (es. ELM327/HC-05)
- **Cavo USB** per programmazione
- **Alimentazione 12V** (da accendisigari auto)
- **SD card** (opzionale, per logging)

## 🔧 Installazione Arduino IDE

### 1. Installa Arduino IDE
- Scarica da: https://www.arduino.cc/en/software
- Versione consigliata: 1.8.19 o 2.0+

### 2. Aggiungi Board ESP32
```
File → Preferenze → URL Aggiuntive Gestioni Schede:
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json

Strumenti → Gestione schede → Ricerca "ESP32" → Installa
```

### 3. Seleziona Board
```
Strumenti → Scheda → ESP32 → "ESP32S3 Dev Module"
```

### 4. Installa Librerie Richieste
```
Strumenti → Gestione Librerie → Installa:
- LVGL (lvgl/LVGL) - v8.3.0+
- ArduinoJson - v6.21.3+
- PubSubClient - v2.8.0+
- ELMduino - v3.0.0+
```

## 📁 Struttura Progetto

```
bmw-f20-wt32-dashboard-arduino/
├── BMW_F20_Dashboard.ino      # File principale
├── config.h                    # Configurazioni globali
├── libraries/
│   ├── OBD2Manager/
│   │   ├── OBD2Manager.h
│   │   ├── OBD2Manager.cpp
│   │   ├── ELM327.h
│   │   └── ELM327.cpp
│   ├── BluetoothManager/
│   │   ├── BluetoothManager.h
│   │   └── BluetoothManager.cpp
│   ├── GUIManager/
│   │   ├── GUIManager.h
│   │   └── GUIManager.cpp
│   └── Logger/
│       ├── Logger.h
│       └── Logger.cpp
├── docs/
│   ├── INSTALL.md
│   ├── OBD2_COMMANDS.md
│   └── API.md
└── .gitignore
```

## 🔌 Connessioni Hardware

### WT32-SC01 Plus - OBD2 Bluetooth
```
HC-05 Bluetooth    ←→  WT32-SC01 Plus
VCC (5V)           ←→  5V
GND                ←→  GND
TX                 ←→  GPIO16 (RX)
RX                 ←→  GPIO17 (TX)
```

## 🚀 Come Compilare e Caricare

### 1. Apri il file principale
```
File → Apri → BMW_F20_Dashboard.ino
```

### 2. Configura le impostazioni
- Modifica `config.h` con i tuoi parametri
- Imposta il nome Bluetooth (HC-05)
- Configura debug level

### 3. Seleziona Porta e Board
```
Strumenti → Porta → COM3 (o la tua porta)
Strumenti → Scheda → ESP32 → ESP32S3 Dev Module
```

### 4. Carica il codice
```
Schizzo → Carica (Ctrl+U)
```

### 5. Monitora il debug
```
Strumenti → Monitor Seriale (115200 baud)
```

## ⚙️ Configurazione Iniziale

### config.h
```cpp
// Wi-Fi
#define WIFI_SSID "TuoSSID"
#define WIFI_PASSWORD "TuaPassword"

// Bluetooth
#define BT_DEVICE_NAME "HC-05"
#define UART_RX_PIN 16
#define UART_TX_PIN 17
#define UART_SPEED 38400

// OBD2
#define OBD2_MODE "BLUETOOTH"
#define OBD2_POLL_RATE 500      // ms

// Debug
#define SERIAL_DEBUG 1
#define DEBUG_LEVEL 2  // 0=OFF, 1=ERROR, 2=INFO, 3=DEBUG
```

## 📊 Comandi OBD2 Supportati

| Comando | Descrizione |
|---------|-------------|
| `01 0C` | RPM (giri motore) |
| `01 0D` | Velocità |
| `01 05` | Temperatura liquido |
| `01 46` | Temperatura aria ambiente |
| `01 10` | Portata aria |
| `01 2F` | Livello carburante |
| `01 42` | Voltaggio batteria |
| `19 02` | Codici guasto (DTC) |

## 🐛 Troubleshooting

**Il codice non compila:**
- Verifica che tutte le librerie siano installate
- Controlla la versione di Arduino IDE (min 1.8.19)
- Assicurati di avere ESP32 boards installati

**Il display non si accende:**
- Verifica alimentazione 12V
- Controlla cavo USB
- Premi il bottone RST sul WT32

**Nessuna connessione Bluetooth:**
- Verifica pin GPIO16/GPIO17
- Controlla baudrate (38400)
- Verifica accoppiamento HC-05

## 📚 Documentazione

- [Guida Installazione](docs/INSTALL.md)
- [Documentazione API](docs/API.md)
- [Comandi OBD2](docs/OBD2_COMMANDS.md)

## 🔗 Link Utili

- [Arduino IDE Download](https://www.arduino.cc/en/software)
- [ESP32 Arduino Core](https://github.com/espressif/arduino-esp32)
- [LVGL Documentation](https://docs.lvgl.io/)
- [ELMduino Library](https://github.com/PowerBroker2/ELMduino)

## 📄 Licenza

MIT License

## ⚠️ Disclaimer

Questo software è fornito "così com'è" per scopi educativi. L'uso su strada è a rischio dell'utente.

---

**Creato per**: BMW F20 + WT32-SC01 Plus + Arduino IDE
**Autore**: falcowin
**Ultimo aggiornamento**: 2026-06-04
**Versione**: 1.0.0 - Arduino IDE