#pragma once
#include <Config.h>
#include <Wire.h>
#include <DataTypes/CommDataTypes.h>
#include <DataTypes/MemoryDataTypes.h>

#if COMMUNICATION_PROTO
ISR(SPI_STC_vect);
void startPeripheral();
void sendData(Buffer &buff);
void moveBufferData(Buffer &commBuffer, Buffer &intBuffer);

#else
ISR(SPI_STC_vect){}
inline void startPeripheral(){}
inline void sendData(Buffer &buff){}
inline void moveBufferData(Buffer &commBuffer, Buffer &intBuffer){}
#endif