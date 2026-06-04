#ifndef ELM327_H
#define ELM327_H

#include <Arduino.h>

class ELM327
{
public:
    ELM327();
    
    char response[256];
    
    void init();
    void end();
    bool begin();
    bool queryPID(uint8_t pid);
    
    uint16_t getRPM();
    uint8_t getSpeed();
    uint8_t getCoolantTemperature();
    uint8_t getFuelLevel();
    uint16_t getFuelPressure();
    uint8_t getEngineLoad();
    
    void sendCommand(const char* cmd);
    bool readResponse();
    
private:
    char cmdBuffer[64];
    unsigned long responseTime;
    
    void flushSerial();
    bool sendATCommand(const char* cmd, const char* expectedResponse = "OK");
};

#endif // ELM327_H