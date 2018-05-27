#include "joystick.h"
#include "communicator.h"

const int JOYSTICK_X = 0;
const int JOYSTICK_Y = 1;

Joystick j1(JOYSTICK_X, JOYSTICK_Y);
Communicator comm;

byte direct;

void setup()
{
  Serial.begin(9600);
  direct = j1.getDirection();
}

void loop()
{
  comm.readState(&j1, &j1);
  comm.sendState();


  //  byte newdir = j1.getDirection();
  //  if(newdir != direct)
  //  {
  //    direct = newdir;
  //    switch(direct)
  //    {
  //      case CENTER: Serial.println("CENTER"); break;
  //      case UP: Serial.println("UP"); break;
  //      case UP_RIGHT: Serial.println("UP_RIGHT"); break;
  //      case RIGHT: Serial.println("RIGHT"); break;
  //      case RIGHT_DOWN: Serial.println("RIGHT_DOWN"); break;
  //      case DOWN: Serial.println("DOWN"); break;
  //      case DOWN_LEFT: Serial.println("DOWN_LEFT"); break;
  //      case LEFT: Serial.println("LEFT"); break;
  //      case LEFT_UP: Serial.println("LEFT_UP"); break;
  //    }
  //  }
}
