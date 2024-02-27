/**
 * Arduino built in example. (Examples -> <Board> -> Wire -> WireScan)
 * Use this to scan for I2C devices on the bus. The monitor should be on address 0x37 https://boichat.ch/nicolas/ddcci/specs.html#:~:text=DDC/CI%20packets%20are%20transmitted%20using%20the%20I2C%20address%200x37.
 *
 * Example output:
 * Scanning for I2C devices ...
 * I2C device found at address 0x37
 * I2C device found at address 0x4A
 * I2C device found at address 0x4B
 * I2C device found at address 0x50
 *
 */
#include "Wire.h"

void setup()
{
    Serial.begin(115200);
    Wire.begin();
}

void loop()
{
    byte error, address;
    int nDevices = 0;

    delay(5000);

    Serial.println("Scanning for I2C devices ...");
    for (address = 0x01; address < 0x7f; address++)
    {
        Wire.beginTransmission(address);
        error = Wire.endTransmission();
        if (error == 0)
        {
            Serial.printf("I2C device found at address 0x%02X\n", address);
            nDevices++;
        }
        else if (error != 2)
        {
            Serial.printf("Error %d at address 0x%02X\n", error, address);
        }
    }
    if (nDevices == 0)
    {
        Serial.println("No I2C devices found");
    }
}
