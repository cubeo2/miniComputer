#include <SPI.h>
#include <SD.h>

// Chip select pin for the Adafruit SD Card Shield
const int chipSelect = 10;  

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect (needed for Leonardo/Micro)
  }

  Serial.println("Initializing SD card...");

  // Check if SD card is present and can be initialized
  if (!SD.begin(chipSelect)) {
    Serial.println("SD card initialization failed!");
    return;
  }
  Serial.println("SD card initialized.");

  // Open (or create) a file named "test.txt"
  File dataFile = SD.open("test.txt", FILE_WRITE);

  if (dataFile) {
    dataFile.println("Hello, world! This is a test.");
    dataFile.close();  // Close the file so the data is written
    Serial.println("Write successful!");
  } else {
    Serial.println("Error opening test.txt");
  }
}

void loop() {
  // Nothing happens here
}
