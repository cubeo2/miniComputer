#pragma once
#include <Config.h>
#include <Wire.h> 
#include <DataTypes/CommDataTypes.h>

#if COMMUNICATION_PROTO
ISR(SPI_STC_vect);
void startMaster();
void checkSlaveConneciton(DeviceMeta deviceMeta[]);
void ready();
void sendbyte(DeviceMeta device, byte data);

//Transfer functions
// bool transferData(Buffer &data);
// bool receiveData(Buffer &data);
bool memoryType();
#if MEMORY_CONNECT

#else

#endif
#else
inline bool transferData(Buffer &data){}
inline bool receiveData(byte &data){}
inline bool memoryType(){}
#endif