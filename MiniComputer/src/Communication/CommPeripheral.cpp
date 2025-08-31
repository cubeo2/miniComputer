#include <Config.h>
#include <Communication/CommPeripheral.h>

#if COMMUNICATION_PROTO

// test variables
volatile Buffer incomingBuffer(430);
Buffer internalBuffer(430);

Buffer outputBuffer(40);
volatile byte dataOut = 0;

ISR(SPI_STC_vect)
{
  incomingBuffer.buffer[incomingBuffer.head] = SPDR;

  Log("Data received: ");
  Logln(incomingBuffer.buffer[incomingBuffer.head]);

  byte nextHead = (incomingBuffer.head + 1) % sizeof(incomingBuffer.buffer);
  incomingBuffer.head = nextHead;
  if (nextHead == incomingBuffer.tail)
  {
    SPDR = NONE;
    Logln("Buffer Full");
    return;
  }
  else
  {
    SPDR = READY;
  }
}

void startPeripheral()
{
  pinMode(MISO, OUTPUT);
  pinMode(10, OUTPUT);
  digitalWrite(10, LOW);
  digitalWrite(PERIPHERAL_CS, LOW);

  SPCR |= _BV(SPE);
  SPI.attachInterrupt();
  Logln("SPI Peripheral started.");
}

void sendData(Buffer &buff)
{
  if (buff.tail != buff.head) {
    SPDR = buff.buffer[buff.tail];
    buff.tail = (buff.tail + 1) % sizeof(buff.buffer);
  }
}

void moveBufferData(Buffer &commBuffer, Buffer &intBuffer)
{
  while (commBuffer.tail != commBuffer.head)
  {
    intBuffer.buffer[intBuffer.head] = commBuffer.buffer[commBuffer.tail];
    intBuffer.head = (intBuffer.head + 1) % sizeof(intBuffer.buffer);
    commBuffer.tail = (commBuffer.tail + 1) % sizeof(commBuffer.buffer);
    if (intBuffer.head == intBuffer.tail)
    {
      Logln("Internal Buffer Full");
      return;
    }
  }
}

#endif