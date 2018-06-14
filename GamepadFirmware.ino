#include "joystick.h"
#include "communicator.h"
#include "initializators.h"

//left joystick
const int JOYSTICK1_X = 0;
const int JOYSTICK1_Y = 1;
//right joystick
const int JOYSTICK2_X = 2;
const int JOYSTICK2_Y = 3;
                                                             
Joystick leftJoy(JOYSTICK1_X, JOYSTICK1_Y);
Joystick rightJoy(JOYSTICK2_X, JOYSTICK2_Y);
Communicator comm;

void setup()
{
  Serial.begin(9600);
  initPins();
}

void loop()
{
  if (Serial.available() > 0)
  {
    makeHandshake();
  }
  else
  {
    comm.readState(&leftJoy, &rightJoy);
    comm.sendState();
  }
}
