#include "ELM327.h"
#include "../Logger/Logger.h"

extern Logger logger;

ELM327::ELM327() : responseTime(0)
{
    memset(response, 0, sizeof(response));
    memset(cmdBuffer, 0, sizeof(cmdBuffer));
}

void ELM327::init()
{
    logger.info("Inizializzazione ELM327");
}

void ELM327::end()
{
    Serial2.end();
    logger.info("ELM327 chiuso");
}

bool ELM327::begin()
{
    logger.info("Avvio comunicazione ELM327");
    
    sendATCommand("AT Z", "OK");
    delay(500);
    
    sendATCommand("AT E0", "OK");
    sendATCommand("AT L0", "OK");
    sendATCommand("AT S0", "OK");
    sendATCommand("AT SP 6", "OK");
    
    return true;
}

bool ELM327::queryPID(uint8_t pid)
{
    char cmd[32];
    snprintf(cmd, sizeof(cmd), "01 %02X", pid);
    
    sendCommand(cmd);
    delay(100);
    
    return readResponse();
}

uint16_t ELM327::getRPM()
{
    if (queryPID(0x0C))
    {
        uint8_t a = strtol(response + 6, NULL, 16);
        uint8_t b = strtol(response + 9, NULL, 16);
        return ((a * 256) + b) / 4;
    }
    return 0;
}

uint8_t ELM327::getSpeed()
{
    if (queryPID(0x0D))
    {
        return strtol(response + 6, NULL, 16);
    }
    return 0;
}

uint8_t ELM327::getCoolantTemperature()
{
    if (queryPID(0x05))
    {
        uint8_t raw = strtol(response + 6, NULL, 16);
        return raw - 40;
    }
    return 0;
}

uint8_t ELM327::getFuelLevel()
{
    if (queryPID(0x2F))
    {
        uint8_t raw = strtol(response + 6, NULL, 16);
        return (raw * 100) / 255;
    }
    return 0;
}

uint16_t ELM327::getFuelPressure()
{
    if (queryPID(0x0A))
    {
        uint8_t raw = strtol(response + 6, NULL, 16);
        return raw * 3;
    }
    return 0;
}

uint8_t ELM327::getEngineLoad()
{
    if (queryPID(0x04))
    {
        uint8_t raw = strtol(response + 6, NULL, 16);
        return (raw * 100) / 255;
    }
    return 0;
}

void ELM327::sendCommand(const char* cmd)
{
    flushSerial();
    
    logger.debug("ELM CMD: %s", cmd);
    Serial2.println(cmd);
    
    responseTime = millis();
}

bool ELM327::readResponse()
{
    unsigned long timeout = millis() + 1000;
    memset(response, 0, sizeof(response));
    uint16_t index = 0;
    
    while (millis() < timeout)
    {
        if (Serial2.available())
        {
            char c = Serial2.read();
            
            if (c == '\r' || c == '\n')
            {
                if (index > 0)
                {
                    response[index] = '\0';
                    logger.debug("ELM RX: %s", response);
                    
                    if (strstr(response, "41") != NULL)
                    {
                        return true;
                    }
                    else if (strstr(response, "NO DATA") != NULL)
                    {
                        logger.warn("ELM: NO DATA");
                        return false;
                    }
                    
                    index = 0;
                }
            }
            else if (c != ' ')
            {
                response[index++] = c;
            }
            
            timeout = millis() + 200;
        }
    }
    
    logger.warn("ELM: Timeout risposta");
    return false;
}

void ELM327::flushSerial()
{
    while (Serial2.available())
    {
        Serial2.read();
    }
    delay(10);
}

bool ELM327::sendATCommand(const char* cmd, const char* expectedResponse)
{
    sendCommand(cmd);
    delay(100);
    
    if (readResponse())
    {
        if (strstr(response, expectedResponse) != NULL)
        {
            logger.debug("ELM AT OK: %s", cmd);
            return true;
        }
    }
    
    logger.warn("ELM AT FAIL: %s", cmd);
    return false;
}