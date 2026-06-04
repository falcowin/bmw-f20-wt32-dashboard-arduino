#ifndef GUI_MANAGER_H
#define GUI_MANAGER_H

#include <Arduino.h>

class GUIManager
{
public:
    GUIManager();
    ~GUIManager();

    void init();
    void update();
    void handleInput();

    void showSplashScreen();
    void showMainScreen();
    void showConnectionError();

    void updateMainScreen(uint16_t rpm, uint8_t speed, uint8_t coolantTemp, 
                         uint8_t fuelLevel, float voltage);
    void updateRPM(uint16_t rpm);
    void updateSpeed(uint8_t speed);
    void updateTemperature(uint8_t temp);
    void updateFuelLevel(uint8_t fuel);
    void updateVoltage(float voltage);

private:
    uint16_t lastRPM;
    uint8_t lastSpeed;
    uint8_t lastTemp;
    uint8_t lastFuel;
    float lastVoltage;
    
    void applyTheme();
};

#endif // GUI_MANAGER_H