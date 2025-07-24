#include <Arduino.h>

// put function declarations here:
int myFunction(int, int);

void setup() {
  Serial.begin(9600); // initialize serial communication at 9600 baud rate
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
}

void loop() {
  Serial.println(myFunction(5, 7));
  delay(1000); // wait for a second before repeating
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}