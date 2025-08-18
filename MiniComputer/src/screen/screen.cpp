#include <Config.h>
#include <Debug.h>

#if SCREEN_CONNECT
//Remove this later
Shift_Register srOne;

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
      // Serial.println("test");
      // Serial.println(out, BIN);
    }
    row = (row & 0x0F) >> 1;
  }
}

void printImage(byte frame[]) {

    // 
    size_t frameCount = sizeof(frame) / sizeof(frame[0]);

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
      
      // Serial.println("Current Millis: ");
      // Serial.println(currentMillis);

      printImage(frames[i].rows);
    }
    // Serial.print("Completed Frame: ");
    // Serial.println(i);
  }
}

void screenSetup() {
  // Initialize the shift register
  srOne.SER = SCREEN_SER;
  srOne.RCLK = SCREEN_RCLK;
  srOne.SCLK = SCREEN_SCLK;
  srOne.OE = SCREEN_OE;

  digitalWrite(srOne.OE, LOW); // Enable output
  
  shift_register_init(&srOne);
}
#endif