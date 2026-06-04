#include "OBD2Manager.h"
#include "../Logger/Logger.h"

extern Logger logger;

OBD2Manager::OBD2Manager() : connected(false), lastResponseTime(0)
{
    memset(&cachedData, 0, sizeof(cachedData));
}

OBD2Manager::~OBD2Manager()
{
    disconnect();
}

void OBD2Manager::init()
{
    logger.info("Inizializzazione OBD2 Manager");
    elm327.init();
}

void OBD2Manager::setMode(String mode)
{
    this->mode = mode;
    logger.info("OBD2 Mode impostato a: %s", mode.c_str());
}

void OBD2Manager::connect()
{
    if (elm327.begin())
    {
        connected = true;
        logger.info("OBD2 connesso con successo");
    }
    else
    {
        connected = false;
        logger.error("Errore connessione OBD2");
    }
}

void OBD2Manager::disconnect()
{
    elm327.end();
    connected = false;
}

bool OBD2Manager::isConnected()
{
    return connected && (millis() - lastResponseTime < 5000);
}

uint16_t OBD2Manager::getRPM()
{
    if (elm327.queryPID(0x0C))
    {
        cachedData.rpm = elm327.getRPM();
        lastResponseTime = millis();
    }
    return cachedData.rpm;
}

uint8_t OBD2Manager::getSpeed()
{
    if (elm327.queryPID(0x0D))
    {
        cachedData.speed = elm327.getSpeed();
        lastResponseTime = millis();
    }
    return cachedData.speed;
}

uint8_t OBD2Manager::getCoolantTemp()
{
    if (elm327.queryPID(0x05))
    {
        cachedData.coolantTemp = elm327.getCoolantTemperature();
        lastResponseTime = millis();
    }
    return cachedData.coolantTemp;
}

uint8_t OBD2Manager::getFuelLevel()
{
    if (elm327.queryPID(0x2F))
    {
        cachedData.fuelLevel = elm327.getFuelLevel();
        lastResponseTime = millis();
    }
    return cachedData.fuelLevel;
}

float OBD2Manager::getBatteryVoltage()
{
    String response;
    if (sendAndReceive("AT EV", response))
    {
        cachedData.voltage = response.toFloat();
        lastResponseTime = millis();
    }
    return cachedData.voltage;
}

void OBD2Manager::readDTC()
{
    String response;
    if (sendAndReceive("19 02", response))
    {
        cachedData.dtcCode = response;
        cachedData.engineLight = !response.isEmpty();
        lastResponseTime = millis();
        logger.info("DTC: %s", cachedData.dtcCode.c_str());
    }
}

String OBD2Manager::getDTCCode()
{
    return cachedData.dtcCode;
}

void OBD2Manager::clearDTC()
{
    sendCommand("04");
    logger.info("DTC cancellati");
}

bool OBD2Manager::checkEngineLight()
{
    return cachedData.engineLight;
}

void OBD2Manager::sendCommand(String cmd)
{
    elm327.sendCommand(cmd.c_str());
}

String OBD2Manager::readResponse()
{
    return String(elm327.response);
}

void OBD2Manager::resetConnection()
{
    logger.warn("Reset connessione OBD2");
    disconnect();
    delay(1000);
    connect();
}

bool OBD2Manager::sendAndReceive(String command, String &response)
{
    elm327.sendCommand(command.c_str());
    delay(100);
    
    if (elm327.queryPID(command.charAt(0)))
    {
        response = String(elm327.response);
        return true;
    }
    return false;
}