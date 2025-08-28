#pragma once
#include <Config.h>
#include <Wire.h>

#if COMMUNICATION_PROTO && MEMORY_CONNECT
//Transfer functions
bool transferData(Buffer &data);
bool receiveData(Buffer &data);
bool memoryType();
#else
inline bool transferData(Buffer &data){}
inline bool receiveData(byte &data){}
inline bool memoryType(){}
#endif