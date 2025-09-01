#include <Config.h>

// All code here is pushed to version 0.2 developement cycle

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

// #if MEMORY_CONNECT
// //
// bool transferData(Buffer &data)
// {
//   if (data.head == data.tail)
//   {
//     // Buffer empty
//     return false;
//   }
//   transferPacket packet;
//   byte numBytes;
//   if (data.head - data.tail > 32)
//   {
//     numBytes = 32;
//   }
//   else
//   {
//     numBytes = data.head - data.tail;
//   }
//   for (byte i = 0; i < numBytes; i++)
//   {
//     packet[i] = data.buffer[data.tail];

//     data.tail = (data.tail + 1) % BUFFER_SIZE;
//   }
//   return true;
// }

// bool receiveData(Buffer &data)
// {
// }

// void checkStatus(){
  
// }
// #endif