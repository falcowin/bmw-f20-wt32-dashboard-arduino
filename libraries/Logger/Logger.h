#ifndef LOGGER_H
#define LOGGER_H

#include <Arduino.h>

class Logger
{
public:
    Logger();
    
    void init(bool serialDebug, uint8_t debugLevel);
    void error(const char* format, ...);
    void warn(const char* format, ...);
    void info(const char* format, ...);
    void debug(const char* format, ...);
    
    uint8_t getDebugLevel() const { return currentDebugLevel; }
    void setDebugLevel(uint8_t level) { currentDebugLevel = level; }
    
    void logData(uint16_t rpm, uint8_t speed, uint8_t temp, uint8_t fuel);
    void logError(String errorMsg);
    
private:
    bool serialDebugEnabled;
    uint8_t currentDebugLevel;
    
    void logToSerial(const char* level, const char* message);
    const char* getTimestamp();
};

#endif // LOGGER_H