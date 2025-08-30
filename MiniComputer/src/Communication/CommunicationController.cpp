#include <Config.h>
#include <Communication/CommController.h>
#include <DataTypes/CommDataTypes.h>
#include <DataTypes/MemoryDataTypes.h>

#if COMMUNICATION_PROTO

// volatile byte receivedData = 0;
// byte receivedFlag = 0;
// volatile bool dataReady = false;

/*
MASTER FUNCTIONS
*/

// Checks each device for a connection at setup
void checkSlaveConnection(DeviceMeta deviceMeta[])
{
  size_t size = sizeof(deviceMeta) / sizeof(deviceMeta[0]);
  for (byte i = 0; i < size; i++)
  {

    for (int j = 0; j < 2; j++)
    {
      digitalWrite(deviceMeta[i].csPin, LOW);
      SPI.transfer(CHECK_STATUS);
      byte response = SPI.transfer(CHECK_STATUS);
      digitalWrite(deviceMeta[i].csPin, HIGH);

      Log("Response received from: ");
      Log(deviceMeta[i].type);
      if (response == READY)
      {
        Logln(response);
        Logln("= True");
        deviceMeta[i].status = true;
      }
      else
      {
        Logln(response);

        Logln("= False");
        deviceMeta[i].status = false;
      }
      delay(200);
    }
  }
}

void sendData(DeviceMeta device, DataPacket &data)
{
  const byte2 delayMicro = 100;
  const byte packetSize = sizeof(data.packet) / sizeof(data.packet[0]);
  byte response = 0;

  Log("Sending data to device on pin: ");
  Logln(device.csPin);

  for (byte i = 0; i < packetSize; i++)
  {
    digitalWrite(device.csPin, LOW);
    SPI.transfer(data.packet[i]);
    delayMicroseconds(delayMicro);

    response = SPI.transfer(data.packet[i]);
    digitalWrite(device.csPin, HIGH);
  }

  Log("Response received from: ");
  Logln(device.type);
  Log("Response: ");
  Logln(response);

  delay(1000);
}

// Check peripheral status, returns peripheral response flag
CommFlag checkPerphStatus(DeviceMeta &device)
{
  digitalWrite(device.csPin, LOW);
  CommFlag response;
  response.commFlag = SPI.transfer(CHECK_STATUS);
  digitalWrite(device.csPin, HIGH);

  Log("Response received from: ");
  Logln(device.type);
  Log("Response: ");
  Logln(response.commFlag);

  return response;
}

// Start SPI master
void startMaster()
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
#endif
#endif
