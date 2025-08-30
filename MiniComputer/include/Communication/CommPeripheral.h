#pragma once
#include <Config.h>
#include <Wire.h>
#include <DataTypes/CommDataTypes.h>

#if COMMUNICATION_PROTO
ISR(SPI_STC_vect);
void startSlave();
void ready();
#else
inline void startSlave(){}
inline void ready(){}
#endif