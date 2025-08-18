#include <Config.h>
#include <Debug.h>

#if MEMORY_CONNECT
// Chip select pin for the Adafruit SD Card Shield
const int chipSelect = MEMORY_CS;  

void memoryInit() {
  serialLogLn("Initializing SD card...");

  // Check if SD card is present and can be initialized
  if (!SD.begin(chipSelect)) {
    serialLogLn("SD card initialization failed!");
    return;
  }
  serialLogLn("SD card initialized.");
}

void createFile(const char* filename) {
  File dataFile = SD.open(filename, FILE_WRITE);
  if (dataFile) {
    dataFile.close();  // Close the file so the data is written
    serialLog("File created: ");
    serialLogLn(filename);
  } else {
    serialLog("Error creating file: ");
    serialLogLn(filename);
  }
}

void memoryWrite(const char* filename, const char* data) {
  File dataFile = SD.open(filename, FILE_WRITE);
  if (dataFile) {
    dataFile.println(data);
    dataFile.close();  // Close the file so the data is written
    serialLog("Write successful to ");
    serialLogLn(filename);
  } else {
    serialLog("Error opening ");
    serialLogLn(filename);
  }
}

void memoryRead(const char* filename) {
  File dataFile = SD.open(filename);
  if (dataFile) {
    serialLog("Reading from ");
    serialLogLn(filename);
    // Read the file until there's nothing else in it
    while (dataFile.available()) {
      Serial.write(dataFile.read());
    }
    dataFile.close();
  } else {
    serialLog("Error opening ");
    serialLogLn(filename);
  }
}
#endif