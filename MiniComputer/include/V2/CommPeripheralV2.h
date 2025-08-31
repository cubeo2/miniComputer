#include <Config.h>
// V2
// FOR NOW, THIS PROJECT WILL NOT ALLOW FOR PERIPHERALS TO SEND DATA BACK TO THE CONTROLLER. VERSION 2 WILL EXPAND ON THIS IN ORDER TO ALLOW MORE COMPLEX PERIPHERALS TO BE USED. CURRENTLY DO NOT HAVE THE TIME TO IMPLEMENT THIS. CHECK DESIGN NOTES FOR HOW THIS WILL WORK. IT IS ALSO MAYBE A GOOD IDEA TO USE I^2C FOR PERIPHERAL->CONTROLLER COMMUNICATION.

// volatile CommFlag receivedFlag;
// Sets priority to 1 and flag to READY
// CommFlag testDeviceStatus;
// CommFlag testControllerStatus;
// FlagType currentStatus = READY;

// void requestToSend() {
//   SPDR = REQUEST_TO_SEND;
// }

// void checkControllerStatus() {
//   testControllerStatus = SPDR;
// }

// void sendData(Buffer &data) {
//   if (data.head == data.tail) {
//     Logln("No data to send");
//     return;
//   } else if ()
//   SPDR = data.buffer[data.tail];
//   data.tail = (data.tail + 1) % sizeof(data.buffer);
// }
// bool checkFlag(FlagType flag)
// {
// }

// decides how to interpret incoming data based on its current status
// // V2
// // could change the currentStatus to ready if its priority is higher than the current task the peripheral is doing
// void routeData(FlagType incomingFlag)
// {
//   switch (currentStatus)
//   {
//   case READY:
//     currentStatus = RECEIVING;
//     Logln("Status set to RECEIVING");
//     break;
//   case RECEIVING:
//   // V2
//   // The use of a ring buffer here may need to be optimized, or not used at all
//     incomingBuffer.head = (incomingBuffer.head + 1) % sizeof(incomingBuffer.buffer);
//     byte nextHead = (incomingBuffer.head + 1) % sizeof(incomingBuffer.buffer);
//     if (nextHead == incomingBuffer.tail)
//     {
//       SPDR = NOT_READY;
//       Logln("Buffer Full");
//     } else if (incomingBuffer.head == incomingBuffer.tail) {
//       currentStatus = RECEIVED;
//       SPDR = currentStatus;
//       Logln("Data Received");
//     }
//     break;
//   case NOT_READY:

//     break;
//   default:

//     break;
//   }
// }

// set the new status based on the flag received from the controller
// needs to be updated in later versions for more complex functionality
// FlagType checkFlag(FlagType flag)
// {
//   switch (flag)
//   {
//   case CHECK_STATUS:
//     return currentStatus;
//     break;
//   case NOT_READY:

//     break;
//   case REQUEST_TO_SEND:
//     currentStatus = RECEIVING;
//     return currentStatus;
//     Logln("Status set to RECEIVING");
//     break;
//     case SENDING:

//     break;
//     // Possibly add a reset function here to reset the peripheral
//   case RESET:

//     break;
//   default:
//     return currentStatus;
//     break;

//   }
// }

// // Start communication with master
// void startPeripheral()
// {
//   SPDR = testDeviceStatus.commFlag;
//   pinMode(MISO, OUTPUT);
//   pinMode(10, OUTPUT);
//   digitalWrite(10, LOW);
//   digitalWrite(PERIPHERAL_CS, LOW);

//   SPCR |= _BV(SPE);
//   SPI.attachInterrupt();
//   Logln("SPI Peripheral started.");
// }

// void setup()
// {
//   testDeviceStatus.commFlag = (ONE & 0xF0) | (READY & 0x0F);
//   testControllerStatus.commFlag = (ONE & 0xF0) | (NONE & 0x0F);
// }