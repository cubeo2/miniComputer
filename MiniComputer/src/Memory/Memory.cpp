#include <Config.h>
#include <Memory.h>

#if MEMORY_CONNECT
// Chip select pin for the Adafruit SD Card Shield
const int chipSelect = MEMORY_CS;

// Connect to SD memory
void connectMemory() {
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
    buff.numBytes = numBytes;

    if (dataFile.seek(fileMeta.chunk))
    {
      if (numBytes > 0 && BUFFER_SIZE > numBytes)
      {
        dataFile.read(buff.buffer, numBytes);
      }
      else
      {
        dataFile.read(buff.buffer, BUFFER_SIZE);
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

/*
Ring Buffer Functions ---
*/
// NEEDS OPTIMIZATION should be able to be more dynamic, sending specific amount to memory
// Writes to buffer one Byte at a time
bool writeBuffer(Buffer &buff, const byte &data)
{
  byte2 nextHead = (buff.head + 1) % BUFFER_SIZE;
  if (nextHead == buff.tail)
  {
    // Buffer full
    return false;
  }
  buff.buffer[buff.head] = data;
  buff.head = nextHead;
  return true;
}
// Reads data from buffer one byte at a time
bool readBuffer(Buffer &buff, byte &data)
{
  if (buff.head == buff.tail)
  {
    // Buffer empty
    return false;
  }
  data = buff.buffer[buff.tail];
  buff.tail = (buff.tail + 1) % BUFFER_SIZE;

  return true;
}
// Ring buffer functions end -

bool fillPacket(Buffer &buff, DataPacket &dataPacket)
{
  if (buff.head == buff.tail)
  {
    // Buffer empty
    return false;
  }
  dataPacket.dataType = (DataTypes)buff.buffer[buff.tail];
  buff.tail++;

  return true;
}

// Gets image to print on screen
bool getImage (Buffer &buff) {

}

/*
This
*/
DataTypes interpretMemory(DataPacket &dataPacket)
{
  switch (dataPacket.dataType)
  {
  case image:
    
    break;
  case animation:

    break;
  case audio:

    break;
  case text:

    break;
  case object:

    break;
  case controls:

    break;
  case run:

    break;
  default:

    break;
  }
  return image;
}
DataTypes interpretMemory(Buffer &buff)
{
  switch (buff.buffer[buff.tail])
  {
  case image:

    break;
  case animation:

    break;
  case audio:

    break;
  case text:

    break;
  case object:

    break;
  case controls:

    break;
  case run:

    break;
  default:

    break;
  }
  return image;
}


/*
Functions related to interpreting data from the buffer. This includes
a switching function for determining what type of data is in memory,
and then a function for cleaning the buffer based on what type of 
data is present.
*/

bool cleanBuffer (Buffer &buff)
{

}
#endif