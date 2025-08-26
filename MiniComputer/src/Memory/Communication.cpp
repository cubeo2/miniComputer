#include <Config.h>


#if COMMUNICATION_PROTO && MEMORY_CONNECT
bool transferData(Buffer &data) {
    if (data.head == data.tail) {
    // Buffer empty!
      return false;
    }
    transferPacket packet;
    byte numBytes;
    if (data.head - data.tail > 32) {
      numBytes = 32;
    } else {
      numBytes = data.head - data.tail;
    }
    for (byte i = 0; i < numBytes; i++) {
      packet[i] = data.buffer[data.tail];

      data.tail = (data.tail + 1) % BUFFER_SIZE;
    }
    return true;
}

bool receiveData(Buffer &data) {
}
#endif