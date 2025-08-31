#pragma once 
#include <Config.h>

// Types of possible buttons and button configurations. When used should be bitpacked in order to store the action button and direction button pressed. Direction buttons first 4 bits, and action buttons are the last 4 bits.
enum ButtonType : byte
{
  NO_PRESS,
  INVALID_BUTTON,
  LEFT,
  UP,
  RIGHT,
  DOWN,
  START,
  RED,
  BLUE,
  RED_BLUE
};
struct Button
{
  int lo;
  int hi;
  ButtonType type;
};