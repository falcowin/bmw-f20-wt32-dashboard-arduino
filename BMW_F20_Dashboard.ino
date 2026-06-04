#include "config.h"
#include "libraries/Logger/Logger.h"
#include "libraries/BluetoothManager/BluetoothManager.h"
#include "libraries/OBD2Manager/OBD2Manager.h"
#include "libraries/GUIManager/GUIManager.h"

// Istanze globali
Logger logger;
BluetoothManager btManager;
OBD2Manager obd2Manager;
GUIManager guiManager;

// Variabili globali
unsigned long lastOBD2Read = 0;
unsigned long lastGUIUpdate = 0;

void setup()
{
    // Inizializza Serial
    Serial.begin(115200);
    delay(1000);

    // Inizializza Logger
    logger.init(SERIAL_DEBUG, DEBUG_LEVEL);
    logger.info("=");
    logger.info("Avvio BMW F20 Dashboard - Arduino IDE");
    logger.info("=");

    // Inizializza Display
    logger.info("Inizializzazione display...");
    guiManager.init();
    guiManager.showSplashScreen();
    delay(2000);

    // Inizializza Bluetooth
    if (BT_ENABLED)
    {
        logger.info("Inizializzazione Bluetooth...");
        btManager.init(UART_RX_PIN, UART_TX_PIN, UART_SPEED);
        btManager.connect(BT_DEVICE_NAME);
    }

    // Inizializza OBD2
    logger.info("Inizializzazione OBD2...");
    obd2Manager.init();
    obd2Manager.setMode(OBD2_MODE);

    logger.info("Sistema pronto!");
    logger.info("=");
    
    guiManager.showMainScreen();
}

void loop()
{
    unsigned long currentTime = millis();

    // ===== LETTURA OBD2 =====
    if (currentTime - lastOBD2Read >= OBD2_POLL_RATE)
    {
        lastOBD2Read = currentTime;

        if (obd2Manager.isConnected())
        {
            // Leggi dati OBD2
            uint16_t rpm = obd2Manager.getRPM();
            uint8_t speed = obd2Manager.getSpeed();
            uint8_t coolantTemp = obd2Manager.getCoolantTemp();
            uint8_t fuelLevel = obd2Manager.getFuelLevel();
            float voltage = obd2Manager.getBatteryVoltage();

            // Aggiorna GUI
            guiManager.updateMainScreen(rpm, speed, coolantTemp, fuelLevel, voltage);

            // Debug output
            if (DEBUG_LEVEL >= 2)
            {
                logger.debug("RPM: %d | Speed: %d km/h | Temp: %d°C | Fuel: %d%% | Voltage: %.1fV",
                           rpm, speed, coolantTemp, fuelLevel, voltage);
            }
        }
        else
        {
            logger.warn("OBD2 non connesso");
            guiManager.showConnectionError();
        }
    }

    // ===== AGGIORNAMENTO GUI =====
    if (currentTime - lastGUIUpdate >= GUI_REFRESH_RATE)
    {
        lastGUIUpdate = currentTime;
        guiManager.update();
        guiManager.handleInput();
    }

    // ===== GESTIONE BLUETOOTH =====
    if (btManager.available())
    {
        String data = btManager.readLine();
        if (data.startsWith("CMD:"))
        {
            btManager.handleCommand(data);
        }
    }

    delay(10);  // Previeni watchdog timeout
}
