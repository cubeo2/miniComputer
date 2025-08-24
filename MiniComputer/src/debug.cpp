#include <Config.h>

#if SERIAL_LOG
void serialOn() {
    Serial.begin(9600);
    while (!Serial) {
        ; // wait for serial port to connect (needed for Leonardo/Micro)
    }
    Serial.println("Serial communication started.");
}

void serialLog(const char* message) {
    Serial.print(message);
}

void serialLogLn(const char* message) {
    Serial.println(message);
}
void serialLogLn(size_t value) {
    Serial.println(value);
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