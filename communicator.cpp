#include "communicator.h"

Communicator::Communicator(int baud)
{
  _state._value = 0;
  _previousState = 0;
}

void Communicator::readState(Joystick* joyL, Joystick* joyR)
{
//  _state._bits._button1 = digitalRead();
//  _state._bits._button2 = digitalRead();
//  _state._bits._button3 = digitalRead();
//  _state._bits._button4 = digitalRead();
//  _state._bits._button5 = digitalRead();
//  _state._bits._button6 = digitalRead();
//  _state._bits._button7 = digitalRead();
//  _state._bits._button8 = digitalRead();
//  _state._bits._button9 = digitalRead();
//  _state._bits._button10 = digitalRead();
  _state._bits._directionL = joyL->getDirection();
  _state._bits._directionR = joyR->getDirection();
}

void Communicator::sendState()
{
  if(_previousState != _state._value)
  {
    Serial.println(_state._value);
    _previousState = _state._value;
  }
}
