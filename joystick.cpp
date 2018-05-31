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
  byte dead_zone_size( 30 );
  const int x = analogRead(_horizontal);
  const int y = analogRead(_vertical);
  byte direction(0);
  //horizontal direction
  if (x > 510 + dead_zone_size){
    direction += 1;
  } else if(x < 510 - dead_zone_size){
    direction += 2;
  }
  //vertical direction
  if (y > 510 + dead_zone_size){
    direction += 3;
  } else if(y < 510 - dead_zone_size){
    direction += 6;
  }
  return direction;
}

bool Joystick::isButtonPressed()
{
  return _button < 1 || digitalRead(_button) == LOW;
}

