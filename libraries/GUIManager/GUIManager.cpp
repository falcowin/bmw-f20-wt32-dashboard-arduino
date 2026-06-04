#include "GUIManager.h"
#include "../Logger/Logger.h"

extern Logger logger;

GUIManager::GUIManager() 
    : lastRPM(0), lastSpeed(0), lastTemp(0), lastFuel(0), lastVoltage(0)
{
}

GUIManager::~GUIManager()
{
}

void GUIManager::init()
{
    logger.info("Inizializzazione GUI Manager");
    
    // TODO: Inizializzare display LVGL per WT32-SC01
    // Questo richiede driver display specifico
    
    applyTheme();
    logger.info("GUI Manager inizializzato");
}

void GUIManager::update()
{
    // TODO: Aggiornare display LVGL
    // lv_task_handler();
}

void GUIManager::handleInput()
{
    // TODO: Gestire input touch
}

void GUIManager::showSplashScreen()
{
    logger.info("Visualizzazione splash screen");
    
    // TODO: Mostrare splash screen con LVGL
    Serial.println("╔════════════════════════════════════════╗");
    Serial.println("║    BMW F20 DASHBOARD - Arduino IDE    ║");
    Serial.println("║      WT32-SC01 Plus Display            ║");
    Serial.println("╚════════════════════════════════════════╝");
}

void GUIManager::showMainScreen()
{
    logger.info("Visualizzazione schermata principale");
    
    // TODO: Mostrare schermata principale con 4 widget
    // RPM, Velocità, Temperatura, Carburante
}

void GUIManager::showConnectionError()
{
    logger.warn("Visualizzazione errore connessione");
    
    // TODO: Mostrare popup errore OBD2
}

void GUIManager::updateMainScreen(uint16_t rpm, uint8_t speed, uint8_t coolantTemp, 
                                  uint8_t fuelLevel, float voltage)
{
    updateRPM(rpm);
    updateSpeed(speed);
    updateTemperature(coolantTemp);
    updateFuelLevel(fuelLevel);
    updateVoltage(voltage);
}

void GUIManager::updateRPM(uint16_t rpm)
{
    if (rpm != lastRPM)
    {
        lastRPM = rpm;
        // TODO: Aggiornare widget RPM su display
    }
}

void GUIManager::updateSpeed(uint8_t speed)
{
    if (speed != lastSpeed)
    {
        lastSpeed = speed;
        // TODO: Aggiornare widget Velocità su display
    }
}

void GUIManager::updateTemperature(uint8_t temp)
{
    if (temp != lastTemp)
    {
        lastTemp = temp;
        // TODO: Aggiornare widget Temperatura su display
    }
}

void GUIManager::updateFuelLevel(uint8_t fuel)
{
    if (fuel != lastFuel)
    {
        lastFuel = fuel;
        // TODO: Aggiornare widget Carburante su display
    }
}

void GUIManager::updateVoltage(float voltage)
{
    if (voltage != lastVoltage)
    {
        lastVoltage = voltage;
        // TODO: Aggiornare widget Voltaggio su display
    }
}

void GUIManager::applyTheme()
{
    logger.info("Applicazione tema");
    
    // TODO: Configurare tema LVGL personalizzato
    // Colori: Blu primario (0x1E90FF), Nero sfondo (0x1A1A1A), Bianco testo (0xFFFFFF)
}