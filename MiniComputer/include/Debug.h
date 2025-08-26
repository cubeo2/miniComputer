#pragma once
#include <Config.h>

#if SERIAL_LOG
void serialOn();
void serialLog(const char* message);
void serialLogLn(const char* message);
void serialLog(const String &message);
void serialLogLn(const String &message);
void serialLog(size_t message);
void serialLogLn(size_t message);
#else
inline void serialOn() {}
inline void serialLog(const char* message) {}
inline void serialLogLn(const char* message) {}
inline void serialLog(size_t message){}
inline void serialLogLn(size_t message){}
#endif

#if DEBUG_MEMORY
void sdLog(const char* message);
#else
inline void sdLog(const char* message) {}
#endif
