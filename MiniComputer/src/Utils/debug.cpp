#include <Config.h>

/*
This file contains debugging utilities for the Mini Computer project.
It provides functions for serial logging and SD card logging, which can be enabled or disabled via configuration macros.
*/

#if SERIAL_LOG
void startLog() {
    Serial.begin(9600);
    while (!Serial) {
        ; // wait for serial port to connect (needed for Leonardo/Micro)
    }
    Serial.println("Serial communication started.");
}

void Log(const char* message) {
    Serial.print(message);
}
void Logln(const char* message) {
    Serial.println(message);
}
void Log(size_t value) {
    Serial.print(value);
}
void Logln(size_t value) {
    Serial.println(value);
}
void Log(const String &message) {
    Serial.print(message.c_str());
}
void Logln(const String &message){
    Serial.print(message.c_str());
}
void Log(byte val, int format) {
    Serial.print(val, format);
}
void Logln(byte val, int format) {
    Serial.println(val, format);
}
#endif
#if DEBUG_MEMORY
void sdLog(const char* message) {
    serialLog("writing to SD card");
    
    File dataFile = SD.open("log.txt", FILE_WRITE);
    if (dataFile) {
        dataFile.println(message);
        dataFile.close();  // Close the file so the data is written
        serialLog("Write successful to SD card!");
    } else {
        serialLog("Error opening log.txt on SD card");
    }
}
#endif