#ifndef BLUETOOTH_MANAGER_H
#define BLUETOOTH_MANAGER_H

#include <Arduino.h>

class BluetoothManager
{
public:
    BluetoothManager();
    ~BluetoothManager();

    void init(uint8_t rxPin, uint8_t txPin, uint32_t baudRate);
    void connect(String deviceName);
    void disconnect();
    bool isConnected();
    void reconnect();

    void sendData(String data);
    void sendCommand(String cmd);
    String readLine();
    bool available();

    void handleCommand(String cmd);

private:
    uint8_t rxPin;
    uint8_t txPin;
    uint32_t baudRate;
    bool connected;
    unsigned long lastConnectionTime;
    String deviceName;
    String rxBuffer;
};

#endif // BLUETOOTH_MANAGER_H