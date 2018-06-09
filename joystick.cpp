#include "joystick.h"

Joystick::Joystick(byte v, byte h, byte b):
  _vertical(v),
  _horizontal(h),
  _button(b)
{
  if (b > 0)
  {
    pinMode(b, INPUT_PULLUP);
  }
}

byte Joystick::getDirection()
{
  static const byte dead_zone_size = 70;
  const int x = analogRead(_horizontal);
  const int y = analogRead(_vertical);
  byte direction = 0;
  //horizontal direction
  if (x > 512 + dead_zone_size)
  {
    direction |= LEFT;
  } 
  else if(x < 512 - dead_zone_size)
  {
    direction |= RIGHT;
  }
  //vertical direction
  if (y > 512 + dead_zone_size)
  {
    direction |= DOWN;
  } else if(y < 512 - dead_zone_size)
  {
    direction |= UP;
  }
  return direction;
}

bool Joystick::isButtonPressed()
{
  return _button < 1 || digitalRead(_button) == LOW;
}

