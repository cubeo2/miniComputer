#pragma once
#include <Config.h>

#if SERIAL_LOG
void startLog();
void Log(const char* message);
void Logln(const char* message);
void Log(const String &message);
void Logln(const String &message);
void Log(size_t message);
void Logln(size_t message);
#else
inline void startLog() {}
inline void Log(const char* message) {}
inline void Logln(const char* message) {}
inline void Log(size_t message){}
inline void Logln(size_t message){}
inline void Log(String message){}
inline void Logln(String message){}
#endif

#if DEBUG_MEMORY
void sdLog(const char* message);
#else
inline void sdLog(const char* message) {}
#endif
