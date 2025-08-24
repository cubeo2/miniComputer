#include <Config.h>

// Screen Testing Code
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

Shift_Register srOne;

// void loop() {

//   digitalWrite(srOne.OE, LOW); // Disable output

//   size_t animationCount = sizeof(animation) / sizeof(animation[0]);
//   animate(animation, animationCount);

//   // printImageRow(frames);
// }