#include <Config.h>
#include <Visual/Visual.h>

/*
This file contains function definitions for controlling an LED screen using shift registers in the Mini Computer project.
*/

#if SCREEN_CONNECT
// Remove this later
Shift_Register srOne;

// Sets up the screen by initializing the shift register and configuring the pins
void screenSetup()
{
  srOne.SER = SCREEN_SER;
  srOne.RCLK = SCREEN_RCLK;
  srOne.SCLK = SCREEN_SCLK;
  srOne.OE = SCREEN_OE;

  digitalWrite(srOne.OE, LOW);

  shift_register_init(&srOne);
}

// Initializes the shift register by setting the pin modes
void shift_register_init(Shift_Register *const sr)
{
  pinMode(sr->SER, OUTPUT);
  pinMode(sr->RCLK, OUTPUT);
  pinMode(sr->SCLK, OUTPUT);
  pinMode(sr->OE, OUTPUT);

  Logln("Shift register initialized.");
}

// Writes data to the shift register and updates the output pins
void shift_register_write(Shift_Register *const sr, uint64_t &data)
{
  uint8_t counter;
  byte shiftVal;
  byte bitsAvailable = 40;

  Log("Shifted data: ");
  Logln(data);

  for (counter = 0; counter < bitsAvailable; counter++)
  {
    shiftVal = (data & 0x01);
    digitalWrite(sr->SER, shiftVal);
    digitalWrite(sr->SCLK, HIGH);
    digitalWrite(sr->SCLK, LOW);
    data = data >> 1;
  }
  digitalWrite(sr->RCLK, HIGH);
  digitalWrite(sr->RCLK, LOW);
}

// Test function to print a specific pattern on the screen -> TEST
void printIage64Test()
{

  uint64_t pixelPos = 0x8000080000;

  uint64_t col = (pixelPos & 0xFFFFE00000);
  uint32_t row = (pixelPos & 0x00000FFFFF);

  for (int i = 0; i < 20; i++)
  {
    for (int j = 0; j < 15; j++)
    {
      uint64_t out = col | row;
      shift_register_write(&srOne, out);

      col >>= 1;
    }
    col = 0x8000000000;
    row >>= 1;
  }
}

// Prints a single frame (4 rows) to the LED screen. Was a test function for a 4x4 LED matrix.
void printImage(byte frame[])
{
  digitalWrite(srOne.OE, LOW);

  int delayTime = 1000; 
  size_t frameCount = sizeof(frame) / sizeof(frame[0]);
  uint64_t pixelPos = 0x8000080000;
  uint64_t col = (pixelPos & 0xFFFFE00000);

  for (int a = 0; a < 4; a++)
  {
    uint32_t row = (frame[a] & 0x0F);
    for (int j = 0; j < 4; ++j)
    {
      pixelPos = row | col;
      uint64_t out = frame[a] & pixelPos;
      shift_register_write(&srOne, out);
      col >>= 1;
    }
    Log("Frame: ");
    Logln(frame[a]);
    col = 0b10000000;
    row >>= 1;
  }
}

// Animates a sequence of frames on the LED screen, each for a specified duration
void animate(Frame frames[], size_t frameCount)
{
  Log("Frame Count: ");
  Logln(frameCount);

  for (int i = 0; i < frameCount; i++)
  {

    const long interval = frames[i].duration;
    long previousMillis = millis();

    long currentMillis = millis();

    while (previousMillis + interval >= currentMillis)
    {
      currentMillis = millis();

      printImage(frames[i].rows);
    }
    // Serial.print("Completed Frame: ");
    // Serial.println(i);
  }
}

#endif