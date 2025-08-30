#include <Config.h>
#include <CommunicationPeripheral.h>


#if COMMUNICATION_PROTO
volatile byte receivedData = 0;
byte receivedFlag = 0;
volatile bool dataReady = false;   

ISR(SPI_STC_vect) {
  receivedData = SPDR;     // Read byte
  dataReady = true;
  Log("Data received: ");
  Logln(receivedData);
  SPDR = 0x02;             // Send back response
}

// Start communication with master
void startSlave()
{
  SPDR = 0x50; 
  pinMode(MISO, OUTPUT);
  pinMode(10, OUTPUT); digitalWrite(10, LOW);
  digitalWrite(PERIPHERAL_CS, LOW);
  
  SPCR |= _BV(SPE);
  SPI.attachInterrupt();
  Logln("SPI Slave started.");
}
#endif