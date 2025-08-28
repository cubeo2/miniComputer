#pragma once
#include <Config.h>
#include <Wire.h>

#if COMMUNICATION_PROTO
//Transfer functions
bool transferData(Buffer &data);
bool receiveData(Buffer &data);
bool memoryType();
#if MEMORY_CONNECT

#else

#endif
#else
inline bool transferData(Buffer &data){}
inline bool receiveData(byte &data){}
inline bool memoryType(){}
#endif