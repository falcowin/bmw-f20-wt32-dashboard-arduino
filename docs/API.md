# API Documentation - BMW F20 Dashboard (Arduino IDE)

## 📌 Panoramica

Questo documento descrive tutte le classi e i metodi principali del progetto Arduino IDE.

## 📝 File Principale

### BMW_F20_Dashboard.ino

File principale che contiene:
- Inizializzazione sistemi
- Loop principale
- Gestione OBD2
- Aggiornamento GUI

## 🎮 GUIManager

Gestisce l'interfaccia grafica.

```cpp
void init()                    // Inizializza display
void update()                  // Aggiorna display
void showSplashScreen()       // Mostra schermata iniziale
void showMainScreen()         // Mostra schermata principale
void updateMainScreen(...)    // Aggiorna tutti i widget
```

## 🔌 OBD2Manager

Gestisce la comunicazione OBD2.

```cpp
void init()                   // Inizializza OBD2
bool isConnected()            // Verifica connessione
uint16_t getRPM()            // Legge RPM
uint8_t getSpeed()           // Legge velocità
uint8_t getCoolantTemp()     // Legge temperatura
uint8_t getFuelLevel()       // Legge livello carburante
```

## 📡 BluetoothManager

Gestisce la comunicazione Bluetooth.

```cpp
void init(rx, tx, baud)      // Inizializza UART
void connect(name)           // Connette dispositivo
bool isConnected()           // Verifica stato
String readLine()            // Legge dati
bool available()             // Controlla disponibilità
```

## 📝 Logger

Sistema di logging multi-livello.

```cpp
void init(debug, level)      // Inizializza logger
void error(format, ...)      // Log errore
void warn(format, ...)       // Log avviso
void info(format, ...)       // Log informazione
void debug(format, ...)      // Log debug
```

## 🌐 ELM327

Driver per modulo OBD2 ELM327.

```cpp
bool begin()                 // Inizializza connessione
bool queryPID(pid)          // Legge un PID
uint16_t getRPM()          // Legge RPM
uint8_t getSpeed()         // Legge velocità
```

## 📊 Strutture Dati

### config.h
Contiene tutte le configurazioni globali:
```cpp
#define WIFI_SSID "..."
#define BT_DEVICE_NAME "HC-05"
#define UART_RX_PIN 16
#define UART_TX_PIN 17
#define OBD2_POLL_RATE 500
#define DEBUG_LEVEL 2
```

## 🔄 Flusso Principale

1. **Setup()**
   - Inizializza Serial
   - Inizializza Logger
   - Inizializza Display
   - Inizializza Bluetooth
   - Inizializza OBD2

2. **Loop()**
   - Leggi dati OBD2 (ogni OBD2_POLL_RATE ms)
   - Aggiorna GUI
   - Gestisci Bluetooth
   - Delay 10ms (prevent watchdog)

## 💾 Memoria

- **RAM totale**: ~320KB (WT32-SC01 Plus)
- **PSRAM**: 8MB (disponibile)
- **Heap free**: ~100KB (tipico durante esecuzione)

## 🚨 Codici di Errore

| Codice | Descrizione |
|--------|------------|
| 0x01 | Connessione OBD2 fallita |
| 0x02 | Timeout risposta OBD2 |
| 0x03 | Errore parsing dati |

## 📚 Esempi di Utilizzo

### Lettura RPM
```cpp
uint16_t rpm = obd2Manager.getRPM();
logger.info("RPM: %d", rpm);
```

### Aggiornamento GUI
```cpp
guiManager.updateRPM(rpm);
guiManager.updateSpeed(speed);
guiManager.updateTemperature(temp);
```

### Log personalizzato
```cpp
logger.debug("Valore personalizzato: %d", valore);
```

---

**Ultimo aggiornamento**: 2026-06-04
**Versione**: 1.0.0 - Arduino IDE
**Compatibile con**: Arduino IDE 1.8.19+, Arduino IDE 2.0+