#include <Config.h>

byte commFlag[]{
    0x00, // Check for connection
    0x01, // Request to send data
    0x02, // Data received
    0x03, // Data sent
    0xFF  // Reset

};
volatile byte dataReceived = 0;
volatile byte flag = 0;

#if COMMUNICATION_PROTO

/*
RECEIVES DATA AND INTERRUPTS MAIN LOOP TO SHIFT DATA INTO ONBOARD SHIFT REGISTER
*/
ISR(SPI_STC_vect){
  dataReceived = SPDR;
}
// Start SPI master
void startMaster()
{
  SPI.begin();

  pinMode(CONTROLLER_CS, OUTPUT);
  digitalWrite(CONTROLLER_CS, HIGH);
}
// start communication with master
void startSlave()
{
  pinMode(MISO, OUTPUT);
  SPI.attachInterrupt();
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
