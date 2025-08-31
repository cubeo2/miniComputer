#include <Config.h>
#include <Memory/SDmem.h>

#if MEMORY_CONNECT
// Chip select pin for the Adafruit SD Card Shield
const int chipSelect = MEMORY_CS;

// Connect to SD memory
void connectSD() {
    Logln("Connecting to SD card...");

  // Check if SD card is present and can be initialized
  if (!SD.begin(MEMORY_CS))
  {
    Logln("SD card connection failed!");
    return;
  }
  Logln("SD card connected.");
}

//Creates File with input name
void createFile(const char *filename)
{
  File dataFile = SD.open(filename, FILE_WRITE);
  if (dataFile)
  {
    dataFile.close(); // Close the file so the data is written
    Log("File created: ");
    Logln(filename);
  }
  else
  {
    Log("Error creating file: ");
    Logln(filename);
  }
}

// Creates Folder
bool createFolder(const char *folderName)
{
  String folder = "/";
  folder += folderName;

  if (SD.mkdir((char*)folder.c_str()))
  {
    Log("Created folder ");
    Logln(folder);
    return true;
  }
  return false;
}

// Writes data to the user's filename
void memoryWrite(const char *filename, const char *data)
{
  File dataFile = SD.open(filename, FILE_WRITE);
  if (dataFile)
  {
    dataFile.println(data);
    dataFile.close(); // Close the file so the data is written
    Log("Write successful to ");
    Logln(filename);
  }
  else
  {
    Log("Error opening ");
    Logln(filename);
  }
}

// Gets and stores up to 512B in buffer on Arduino
bool memoryRead(Buffer &buff, FileMeta &fileMeta)
{
  const char *filename = fileMeta.filename.c_str();
  File dataFile = SD.open(filename);

  if (dataFile)
  {
    Log("Reading from ");
    Logln(filename);

    byte2 numBytes = dataFile.size() - fileMeta.chunk;

    if (dataFile.seek(fileMeta.chunk))
    {
      if (numBytes > 0 && (buff.head - buff.tail) > numBytes)
      {
        dataFile.read(buff.buffer, numBytes);
      }
      else
      {
        dataFile.read(buff.buffer, sizeof(buff.buffer));
      }
      fileMeta.nextChunk();
      dataFile.close();
#if SERIAL_LOG
      buff.printString();
#endif
      return true;
    }
  }
  else
  {
    Log("Error opening ");
    Logln(filename);
    return false;
  }
}
#endif