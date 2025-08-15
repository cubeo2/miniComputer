#include <Arduino.h>
#include "screen.h"
#include "debugScreen.h"

typedef unsigned char byte;

typedef struct Shift_Register {
    byte SER;
    byte RCLK;
    byte SCLK;
    byte OE;
} Shift_Register;

// 4x4 matrix
typedef struct Frame {
  byte rows[4];
  int duration;
} Frame;

//done by rows
byte frames[] = {
    0b11001000,
    0b10010100,
    0b00010010,
    0b11110001
};

// 0b00001000, 0b00000100, 0b00000010, 0b00000001
int frameTime = 500;
Frame animation[] = {
    {{0b11111000, 0b10010100, 0b10010010, 0b11110001}, frameTime},
    {{0b11111000, 0b11110100, 0b11110010, 0b11110001}, frameTime},
    {{0b00001000, 0b01100100, 0b01100010, 0b00000001}, frameTime},
    {{0b00001000, 0b00000100, 0b00000010, 0b00000001}, frameTime}
};

void shift_register_init(Shift_Register *sr) {
    pinMode(sr->SER, OUTPUT);
    pinMode(sr->RCLK, OUTPUT);
    pinMode(sr->SCLK, OUTPUT);
    pinMode(sr->OE, OUTPUT);
}

void shift_register_write(Shift_Register * const sr, byte data) {
	uint8_t counter;
	byte shiftVal;
  byte bitsAvailable = 8; 
	
	for (counter = 0; counter < bitsAvailable; counter++){
		shiftVal = (data & 0x01); 
		digitalWrite(sr->SER, shiftVal);
		digitalWrite(sr->SCLK, HIGH);
		digitalWrite(sr->SCLK, LOW);
		data = data >> 1;
	}
	digitalWrite(sr->RCLK, HIGH);
	digitalWrite(sr->RCLK, LOW);
	
}

Shift_Register srOne;

// based on a frame being one byte (for a 4x4 matrix)
// Not very efficient, eventaully I should bit pack depending on the dimensions
// of the matrix
void frameDisplay(byte frame[]) {

  const byte NUM_SHIFTS = 3;

  const int delayTime = 1000;

  for (int i = 0; i < NUM_SHIFTS; i++) {
    byte row = 0b00001000;

    for (int j = 0; j < NUM_SHIFTS; j++) {
      byte col = 0b10000000;

      byte out = (frame[i] & 0xF0) & col;

      if (out) {
        out |= row;
        shift_register_write(&srOne, out);
      }

      digitalWrite(srOne.OE, LOW); // Enable output 
      delay(delayTime);
      digitalWrite(srOne.OE, HIGH); // Disable output
      delay(delayTime);
      
      col = (col & 0xF0) >> 1;
      Serial.println("test");
      Serial.println(out, BIN);
    }
    row = (row & 0x0F) >> 1;
  }
}

void printImage(byte frame[]) {

    int shiftMax = 4;
    size_t frameCount = sizeof(frames) / sizeof(frames[0]);

    byte pixelPos = 0b10001000;

    byte col = (pixelPos & 0xF0);

    for (int a = 0; a < frameCount; a++) {
        byte row = (frame[a] & 0x0F);
        for (int j = 0; j < 4; ++j) {

            pixelPos = row | col;

            byte out =  frame[a] & pixelPos;

            shift_register_write(&srOne, out);

            digitalWrite(srOne.OE, LOW); // Enable output 
            // delay(delayTime);
            digitalWrite(srOne.OE, HIGH); // Disable output
            // delay(delayTime);

            //std::cout << "Pixel Position: ";
            //printByteBinary(out); // this will be the output to the matrix
            col >>= 1;
        }
        col = 0b10000000;
        row >>= 1;
    }
}

void animate(Frame frames[], size_t frameCount) {
  Serial.print("Frame Count: ");
  Serial.println(frameCount);

  for (int i = 0; i < frameCount; i++) {

    const long interval = frames[i].duration;
    long previousMillis = millis();

    long currentMillis = millis();

    while (previousMillis + interval >= currentMillis) {
      currentMillis = millis();
      
      Serial.println("Current Millis: ");
      Serial.println(currentMillis);

      printImage(frames[i].rows);
    }
    Serial.print("Completed Frame: ");
    Serial.println(i);
  }
}


void setup() {
	srOne.SER = 3;
	srOne.RCLK = 10;
	srOne.SCLK = 11;
  srOne.OE = 9;
  digitalWrite(srOne.OE, LOW); // Enable output

  Serial.begin(9600);

  shift_register_init(&srOne);
}

void loop() {

  digitalWrite(srOne.OE, LOW); // Disable output

  size_t animationCount = sizeof(animation) / sizeof(animation[0]);
  animate(animation, animationCount);

  // printImageRow(frames);
}

