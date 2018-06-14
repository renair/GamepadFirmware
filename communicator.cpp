#include "communicator.h"
#include "preferences.h"

Communicator::Communicator(int baud):
	_state(0),
	_previousState(0)
{}

void Communicator::readState(Joystick* joyL, Joystick* joyR)
{
  _state = 0;
  // << N - set N+ 1 bit 
#ifdef SOFTWARE_PULLUP
  _state |= !digitalRead(2);          //LTRIGGER
  _state |= !digitalRead(3) << 1;     //RTRIGGER
  _state |= !digitalRead(4) << 2;     //XBUTTON(LEFT)
  _state |= !digitalRead(5) << 3;     //ABUTTON(DOWN)
  _state |= !digitalRead(6) << 4;     //BBUTTON(RIGTH)
  _state |= !digitalRead(7) << 5;     //YBUTTON(UP)
  _state |= !digitalRead(8) << 6;     //LFUNBUTTON
  _state |= !digitalRead(9) << 7;     //RFUNBUTTON
  _state |= !digitalRead(10) << 8;    //LJOYBUTTON
  _state |= !digitalRead(11) << 9;    //RJOYBUTTON
#else
  _state |= digitalRead(2);          //LTRIGGER
  _state |= digitalRead(3) << 1;     //RTRIGGER
  _state |= digitalRead(4) << 2;     //XBUTTON(LEFT)
  _state |= digitalRead(5) << 3;     //ABUTTON(DOWN)
  _state |= digitalRead(6) << 4;     //BBUTTON(RIGHT)
  _state |= digitalRead(7) << 5;     //YBUTTON(UP)
  _state |= digitalRead(8) << 6;     //LFUNBUTTON
  _state |= digitalRead(9) << 7;     //RFUNBUTTON
  _state |= digitalRead(10) << 8;    //LJOYBUTTON
  _state |= digitalRead(11) << 9;    //RJOYBUTTON
#endif //SOFTWARE_PULLUP
  _state |= joyL->getDirection() << 10;
  _state |= (long int)joyR->getDirection() << 14;
}

void Communicator::sendState()
{
  if (_previousState != _state)
  {
    //Serial.println((int)_state, BIN);
    Serial.write((char*)&_state, sizeof(_state));
    _previousState = _state;
  }
}
