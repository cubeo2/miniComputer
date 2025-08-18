#pragma once
#include <Config.h>

#if SERIAL_LOG
void serialOn();
void serialLog(const char* msg);
void serialLogLn(const char* msg);
#else
inline void serialOn() {}
inline void serialLog(const char* msg) {}
inline void serialLogLn(const char* msg) {}
#endif

#if DEBUG_MEMORY
void sdLog(const char* message);
#else
inline void sdLog(const char* message) {}
#endif
