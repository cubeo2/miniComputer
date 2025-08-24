#pragma once
#include <Config.h>

#if SERIAL_LOG
void serialOn();
void serialLog(const char* msg);
void serialLogLn(const char* msg);
void serialLog(size_t msg);
void serialLogLn(size_t msg);
#else
inline void serialOn() {}
inline void serialLog(const char* msg) {}
inline void serialLogLn(const char* msg) {}
inline void serialLog(size_t msg){}
inline void serialLogLn(size_t msg){}
#endif

#if DEBUG_MEMORY
void sdLog(const char* message);
#else
inline void sdLog(const char* message) {}
#endif
