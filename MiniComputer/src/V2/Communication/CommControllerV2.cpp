#include <Config.h>

// volatile byte receivedData = 0;
// byte receivedFlag = 0;
// volatile bool dataReady = false;


// void sendData(DeviceMeta device, DataPacket &data)
// {
//   const byte2 delayMicro = 100;
//   const byte packetSize = sizeof(data.packet) / sizeof(data.packet[0]);
//   byte response = 0;

//   Log("Sending data to device on pin: ");
//   Logln(device.csPin);

//   for (byte i = 0; i < packetSize; i++)
//   {
//     digitalWrite(device.csPin, LOW);
//     SPI.transfer(data.packet[i]);
//     delayMicroseconds(delayMicro);

//     response = SPI.transfer(data.packet[i]);
//     digitalWrite(device.csPin, HIGH);
//   }

//   Log("Response received from: ");
//   Logln(device.type);
//   Log("Response: ");
//   Logln(response);

//   delay(1000);
// }