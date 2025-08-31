#include <Config.h>
#include <Memory/Buffer.h>
#include <DataTypes/MemoryDataTypes.h>

/*
Ring Buffer Functions ---
*/
// NEEDS OPTIMIZATION should be able to be more dynamic, sending specific amount to memory
// Writes to buffer one Byte at a time
bool writeBuffer(Buffer &buff, const byte &data)
{
  byte2 nextHead = (buff.head + 1) % BUFFER_SIZE;
  if (nextHead == buff.tail)
  {
    // Buffer full
    return false;
  }
  buff.buffer[buff.head] = data;
  buff.head = nextHead;
  return true;
}
// Reads data from buffer one byte at a time
bool readBuffer(Buffer &buff, byte &data)
{
  if (buff.head == buff.tail)
  {
    // Buffer empty
    return false;
  }
  data = buff.buffer[buff.tail];
  buff.tail = (buff.tail + 1) % BUFFER_SIZE;

  return true;
}
// Ring buffer functions end -

bool fillPacket(Buffer &buff, DataPacket &dataPacket)
{
  if (buff.head == buff.tail)
  {
    // Buffer empty
    return false;
  }
  dataPacket.dataType = (DataTypes)buff.buffer[buff.tail];
  buff.tail++;

  return true;
}

bool cleanBuffer (Buffer &buff)
{
  memset(buff.buffer, 0, sizeof(buff.buffer));
}