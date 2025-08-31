#include <Config.h>
#include <DataTypes/MemoryDataTypes.h>

#if MEMORY_CONNECT
bool writeBuffer(Buffer &buff, const byte &data);
bool readBuffer(Buffer &buff, byte &data);
bool fillPacket(Buffer &buff, DataPacket &dataPacket);
bool cleanBuffer (Buffer &buff);
#else
inline bool writeBuffer(Buffer &buff, const byte &data){}
inline bool readBuffer(Buffer &buff, byte &data){}
inline bool fillPacket(Buffer &buff, DataPacket &dataPacket){}
inline bool cleanBuffer (Buffer &buff){}
#endif