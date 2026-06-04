#ifndef OBD2_MANAGER_H
#define OBD2_MANAGER_H

#include <Arduino.h>
#include "ELM327.h"

class OBD2Manager
{
public:
    OBD2Manager();
    ~OBD2Manager();

    void init();
    void setMode(String mode);
    void connect();
    void disconnect();
    bool isConnected();

    uint16_t getRPM();
    uint8_t getSpeed();
    uint8_t getCoolantTemp();
    uint8_t getFuelLevel();
    float getBatteryVoltage();

    void readDTC();
    String getDTCCode();
    void clearDTC();
    bool checkEngineLight();

    void sendCommand(String cmd);
    String readResponse();
    void resetConnection();

private:
    ELM327 elm327;
    String mode;
    bool connected;
    unsigned long lastResponseTime;
    
    struct {
        uint16_t rpm;
        uint8_t speed;
        uint8_t coolantTemp;
        uint8_t fuelLevel;
        float voltage;
        String dtcCode;
        bool engineLight;
    } cachedData;

    bool sendAndReceive(String command, String &response);
};

#endif // OBD2_MANAGER_H