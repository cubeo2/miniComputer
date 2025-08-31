#pragma once
#include <Config.h>
#include <Wire.h> 
#include <DataTypes/CommDataTypes.h>
#include <DataTypes/MemoryDataTypes.h>

#if COMMUNICATION_PROTO
void startCommController();
CommFlag checkPerphStatus(DeviceMeta &device);
bool isPeripheralReady(DeviceMeta &device);
void requestToSend(DeviceMeta &device);
bool sendData(DeviceMeta &device, DataPacket &data);

#if MEMORY_CONNECT
bool transferData(Buffer &data);
bool receiveData(Buffer &data);
#else
bool transferData(Buffer &data){}
bool receiveData(Buffer &data){}
#endif
#else
inline void startCommController(){}
inline CommFlag checkPerphStatus(DeviceMeta &device){}
inline bool isPeripheralReady(DeviceMeta &device){}
inline void requestToSend(DeviceMeta &device){}
inline bool sendData(DeviceMeta &device, DataPacket &data){}
#endif