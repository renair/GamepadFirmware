#include "communicator.h"

Communicator::Communicator(int baud)
{
  _state = 0;
  _previousState = 0;
}

void Communicator::readState(Joystick* joyL, Joystick* joyR)
{
  _state = 0;
  // << N - set N+ 1 bit 
//  _state |= digitalRead();
//  _state |= digitalRead() << 1;
//  _state |= digitalRead() << 2;
//  _state |= digitalRead() << 3;
//  _state |= digitalRead() << 4;
//  _state |= digitalRead() << 5;
//  _state |= digitalRead() << 6;
//  _state |= digitalRead() << 7;
//  _state |= digitalRead() << 8;
//  _state |= digitalRead() << 9;
  _state |= joyL->getDirection() << 10;
  _state |= (long int)joyR->getDirection() << 14;
}

void Communicator::sendState()
{
  if (_previousState != _state)
  {
    Serial.write((char*)&_state, sizeof(_state));
    _previousState = _state;
  }
}
