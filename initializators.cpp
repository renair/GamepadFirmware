#include "initializators.h"
#include "preferences.h"

void initPins()
{
  for(byte pin = 2; pin <= 11; ++pin) // 10 pins in total
  {
    pinMode(pin, INPUT);
#ifdef SOFTWARE_PULLUP
    digitalWrite(pin, HIGH);
#endif //SOFTWARE_PULLUP
  }
}

bool makeHandshake()
{
  const char buff[4] = "joi?";
  while(Serial.available() < 4)
  {
    delay(50);
  }
  for(byte i = 0;i < 4;++i)
  {
    if(buff[i] != Serial.read())
    {
      return false;
    }
  }
  Serial.write("yes)");
  return true;
}
