#include <Config.h>
#include <Communication/CommController.h>

#if COMMUNICATION_PROTO

// Start SPI master
void startCommController()
{
  SPDR = READY;

  pinMode(MEMORY_CS, OUTPUT);
  digitalWrite(MEMORY_CS, HIGH);
  pinMode(AUDIO_CS, OUTPUT);
  digitalWrite(AUDIO_CS, HIGH);
  pinMode(SCREEN_CS, OUTPUT);
  digitalWrite(SCREEN_CS, HIGH);
  pinMode(REMOTE_CONT_CS, OUTPUT);
  digitalWrite(REMOTE_CONT_CS, HIGH);

  SPI.begin();
  // SPI.beginTransaction(SPISettings(500000, MSBFIRST, SPI_MODE0));
}
// Check peripheral status, returns peripheral response flag
CommFlag checkPerphStatus(DeviceMeta &device)
{
  digitalWrite(device.csPin, LOW);
  CommFlag response;
  response.commFlag = SPI.transfer(CHECK_STATUS);
  digitalWrite(device.csPin, HIGH);

  delayMicroseconds(100);

  Log("Response received from: ");
  Logln(device.type);
  Log("Response: ");
  Logln(response.commFlag);

  return response;
}

// Checks if peripheral is ready to receive data
bool isPeripheralReady(DeviceMeta &device)
{
  CommFlag response = checkPerphStatus(device);
  if (response.checkFlag() == READY)
  {
    return true;
  }
  return false;
}

// Requests to send data to peripheral device
void requestToSend(DeviceMeta &device)
{
  digitalWrite(device.csPin, LOW);
  SPI.transfer(REQUEST_TO_SEND);
  digitalWrite(device.csPin, HIGH);

  delayMicroseconds(100);

  Log("Request to send sent to: ");
  Logln(device.type);
}

// Sends data packet to peripheral device
bool sendData(DeviceMeta &device, DataPacket &data)
{ 
  if (!isPeripheralReady(device))
  {
    Log("Device not ready: ");
    Logln(device.type);
    return false;
  }
  digitalWrite(device.csPin, LOW);
  SPI.transfer(data.dataType);
  SPI.transfer(data.meta);

  for (byte i = 0; i < sizeof(data.packet); i++)
  {
    SPI.transfer(data.packet[i]);
    delayMicroseconds(100);
  }
  digitalWrite(device.csPin, HIGH);
  return true;
}

#if MEMORY_CONNECT
bool transferData(Buffer &data)
{
  if (data.head == data.tail)
  {
    // Buffer empty!
    return false;
  }
  transferPacket packet;
  byte numBytes;
  if (data.head - data.tail > 32)
  {
    numBytes = 32;
  }
  else
  {
    numBytes = data.head - data.tail;
  }
  for (byte i = 0; i < numBytes; i++)
  {
    packet[i] = data.buffer[data.tail];

    data.tail = (data.tail + 1) % BUFFER_SIZE;
  }
  return true;
}

bool receiveData(Buffer &data)
{
}

void checkStatus(){
  
}
#endif
#endif
