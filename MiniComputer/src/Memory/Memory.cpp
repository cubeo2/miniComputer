#include <Config.h>

#if MEMORY_CONNECT
// Chip select pin for the Adafruit SD Card Shield
const int chipSelect = MEMORY_CS;

void memoryInit()
{
  serialLogLn("Initializing SD card...");

  // Check if SD card is present and can be initialized
  if (!SD.begin(chipSelect))
  {
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

void memoryWrite(const char *filename, const char *data)
{
  File dataFile = SD.open(filename, FILE_WRITE);
  if (dataFile)
  {
    dataFile.println(data);
    dataFile.close(); // Close the file so the data is written
    serialLog("Write successful to ");
    serialLogLn(filename);
  }
  else
  {
    serialLog("Error opening ");
    serialLogLn(filename);
  }
}

// Gets and stores up to 512B in buffer
bool memoryRead(Buffer &buff, FileMeta &file)
{
  const char *filename = file.filename.c_str();
  File dataFile = SD.open(filename);

  if (dataFile)
  {
    serialLog("Reading from ");
    serialLogLn(filename);

    byte2 numBytes = dataFile.size() - file.chunk;
    buff.numBytes = numBytes;

    if (dataFile.seek(file.chunk))
    {
      if (numBytes > 0 && BUFFER_SIZE > numBytes)
      {
        dataFile.read(buff.buffer, numBytes);
      }
      else
      {
        dataFile.read(buff.buffer, BUFFER_SIZE);
      }
      file.nextChunk();
      dataFile.close();
#if SERIAL_LOG
      serialLogLn(buff.toString());
#endif
      return true;
    }
  }
  else
  {
    serialLog("Error opening ");
    serialLogLn(filename);
    return false;
  }
}

//NEEDS OPTOMIZATION
bool writeBuffer(Buffer &buff, const byte &data){
  byte2 nextHead = (buff.head + 1) % BUFFER_SIZE;
  if (nextHead == buff.tail){
    //Buffer full
    return false;
  }
  buff.buffer[buff.head] = data;
  buff.head = nextHead;
  return true;
}

bool readBuffer(Buffer &buff, byte &data){

  if (buff.head == buff.tail) {
    //Buffer empty
    return false;
  }
  data = buff.buffer[buff.tail];
  buff.tail = (buff.tail + 1) % BUFFER_SIZE;

  return true;
}

DataTypes interpretMemory(Buffer &buff) {

  return image;
}
#endif