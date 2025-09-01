#include <Config.h>
#include <Communication/CommPeripheral.h>
#include <Remote/Remote.h>

/*
THIS TRANSLATION UNIT HAS CODE RELATED TO THE LITERAL HANDHELD CONTROLLER. ITS MAIN PURPOSE IS TO SEND THE APPROPRIATE DATA TO THE MASTER MICROCONTROLLER.

NEEDS OPTIMIZATION - VARIABLE SIZES
*/
#if REMOTE_CONNECT

// LIST OF BUTTONS AND STATES WITH A BUFFER RANGE OF WHAT THE ADC CAN BE
Button buttons[] = {
    {950, 1023, NO_PRESS}, // DIRECTION BUTTONS
    {581, 750, DOWN},
    {401, 580, RIGHT},
    {251, 400, UP},
    {100, 250, LEFT},
    {0, 50, NO_PRESS}, // ACTION BUTTONS
    {801, 1023, START},
    {600, 720, RED},
    {200, 599, BLUE},
    {721, 800, RED_BLUE}};

// DECODES THE GIVEN ADC VALUE IN ORDER TO INTERPRET WHICH BUTTON HAS BEEN PUSHED
ButtonType decodeADC(const int &adc, const Button *buttons, const byte &pin)
{
  // since numActButtons = numDirButtons, I have made simplified variable numButtons to represent both (save a byte)
  byte NUM_BUTTONS = 5;

  byte loopPos;
  switch (pin)
  {
  case DIRECTION_BUTTONS:
    loopPos = 0;
    break;
  case ACTION_BUTTONS:
    loopPos = 5;
    NUM_BUTTONS = 10;
    break;
  default:
    Logln("Invalid input value");
    break;
  }
  for (loopPos; loopPos < NUM_BUTTONS; loopPos++)
  {
    {
      if (adc >= buttons[loopPos].lo && adc <= buttons[loopPos].hi)
      {
        return buttons[loopPos].type;
      }
    }
  }
  return NO_PRESS;
}

// ENSURES A STABLE ADC VALUE IS ESTABLISHED BEFORE CHECKING WHICH BUTTON HAS BEEN PUSHED. Written by Chat GPT 4.1 and modified by Blair C. Tate (aka Cubeo).
int stableRead(int pin)
{
  const byte delayMs = 5;
  int lastADC = analogRead(pin);
  for (byte i = 1; i < delayMs; i++)
  {
    delay(delayMs);
    int currentADC = analogRead(pin);
    // Log(" Current ADC: ");
    // Logln(currentADC);
    if (abs(currentADC - lastADC) > 8)
    {
      Logln("Unstable ADC from Controller");
      Logln(abs(currentADC - lastADC));
      return 2000;
    }
    lastADC = (currentADC + lastADC) / 2;
  }
  return lastADC;
}

#if SERIAL_LOG
// LOGS WHICH BUTTONS HAVE BEEN PRESSED TO SERIAL OUTPUT.
void logButtonsPressed(ButtonType *types)
{
  for (byte i = 1; i <= 2; i++)
  {
    Log("Button ");
    Log((size_t)i);
    Log(": ");
    switch (types[i - 1])
    {
    case NONE:
      Logln("NONE");
      break;
    case UP:
      Logln("UP");
      break;
    case DOWN:
      Logln("DOWN");
      break;
    case LEFT:
      Logln("LEFT");
      break;
    case RIGHT:
      Logln("RIGHT");
      break;
    case START:
      Logln("START");
      break;
    case RED:
      Logln("RED");
      break;
    case BLUE:
      Logln("BLUE");
      break;
    case RED_BLUE:
      Logln("RED_BLUE");
      break;
    case INVALID:
      Logln("INVALID");
      break;
    default:
      Logln("UNKNOWN");
      break;
    };
  }
}
#endif

// CHECKS THE INPUT PINS FOR SIGNALS FROM THE CONTROLLER IN ORDER TO DETERMINE WHICH BUTTONS HAVE BEEN PRESSED.
int checkForCommand()
{
  int pressedButtons = 0;
  int actionButtons = 0;
  int directionButtons = 0;
  int buttonVal = 0;
  const int errorVal = 2000;

  // Checks the value of the action buttons pin
  buttonVal = stableRead(ACTION_BUTTONS);
  if (buttonVal == errorVal)
  {
    pressedButtons = INVALID_BUTTON;
    return pressedButtons;
  }
  actionButtons = decodeADC(buttonVal, buttons, ACTION_BUTTONS);
  pressedButtons = actionButtons;

  if (actionButtons == START)
  {
    Logln("Start button pressed");
    return pressedButtons;
  }
  // Checks the value of the direction buttons pin
  buttonVal = stableRead(DIRECTION_BUTTONS);
  if (buttonVal == errorVal)
  {
    pressedButtons = INVALID_BUTTON;
    return pressedButtons;
  }
  directionButtons = decodeADC(buttonVal, buttons, DIRECTION_BUTTONS);
#if SERIAL_LOG
  logButtonsPressed(pressedButtons);
#endif
  delay(10);

  pressedButtons = ((pressedButtons & 0xF0) | directionButtons << 4) | actionButtons;

  return pressedButtons;
}
#endif