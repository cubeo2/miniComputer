#include <Config.h>
#include <Visual/LCD.h>
#include <DataTypes/DataTypes.h>
#include <DataTypes/RemoteDataTypes.h>

/*
This file contains function definitions for controlling a 16x2 LCD display in the Mini Computer project.
*/

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

// Store the last two lines printed on the LCD for lcdPrintln functionality
String lines[2];  // for 16x2

// Cursor position, {col, row}
byte cursorPos[] = {0, 0};

// LCD setup function
void lcdSetup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("test");
}

// Functions to print a message to the LCD, clearing previous content
void lcdPrint(const char* message) {
  lcd.clear();
  lcd.print(message);
}
void lcdPrint(String message) {
  lcd.clear();
  lcd.print(message);
}

// Function to print a new line, shifting the previous line up
void lcdPrintln(String newLine) {
  lines[0] = lines[1];
  lines[1] = newLine;

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(lines[0]);
  lcd.setCursor(0,1);
  lcd.print(lines[1]);
}

// Function to move the cursor based on button input
void moveCursor(ButtonType direction) {
    switch (direction){
        case UP:
            if (cursorPos[1] > 0) cursorPos[1]--;
            break;
        case DOWN:
            if (cursorPos[1] < 1) cursorPos[1]++;
            break;
        case LEFT:
            if (cursorPos[0] > 0) cursorPos[0]--;
            break;
        case RIGHT:
            if (cursorPos[0] < 15) cursorPos[0]++;
            break;
        default:
            break;
    }
}

// Function to show the cursor at its current position
void showCursor() {
    lcd.setCursor(cursorPos[0],cursorPos[1]);
    lcd.blink();
}

// Test code to demonstrate LCD functionality
void setup() {
    lcdSetup();
    lcdPrint("hello, world!");
}

String message[] = {"> Test 1", "Line 2", "Line 3", "Line 4"};

void loop() {

    lcdPrint(message[0]);
    moveCursor(RIGHT);
    showCursor();
    delay(1000);
    lcdPrint(message[0]);
    moveCursor(LEFT);
    showCursor();
    delay(1000);
    // for (int i = 0; i < 4; i++) {
    //     lcdPrintln(message[i]);
    //     delay(1000);
    // }
}