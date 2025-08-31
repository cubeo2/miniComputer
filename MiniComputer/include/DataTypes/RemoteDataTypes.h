#pragma once 
#include <Config.h>

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