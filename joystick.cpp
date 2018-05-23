#include "joystick.h"
//#include <Console.h>

Joystick::Joystick(byte v, byte h, byte b):
  _vertical(v),
  _horizontal(h),
  _button(b)
{
  if(b > 0)
  {
    pinMode(b, INPUT_PULLUP);
  }
}

JoystickDirection Joystick::getDirection()
{
  const int x = analogRead(_horizontal);
  const int y = analogRead(_vertical);
//  Serial.print(x);
//  Serial.print(';');
//  Serial.print(y);
//  Serial.print('\n');
//  return CENTER;
  if(470 < x && x < 550 && y > 550)
  {
    return UP;
  }
  if(x > 550 && 400 < y && y < 650)
  {
    return RIGHT;
  }
  if(x < 470 && 400 < y && y < 650)
  {
    return LEFT;
  }
  if(470 < x && x < 550 && y < 470)
  {
    return DOWN;
  }
  if(x > 550 && y > 550)
  {
    return UP_RIGHT;
  }
  if(y > 550 && y < 470)
  {
    return RIGHT_DOWN;
  }
  if(x < 470 && y > 550)
  {
    return LEFT_UP;
  }
  if(y < 470 && y < 470)
  {
    return DOWN_LEFT;
  }
  return CENTER;
}

bool Joystick::isButtonPressed()
{
  return _button < 1 || digitalRead(_button) == LOW;
}

