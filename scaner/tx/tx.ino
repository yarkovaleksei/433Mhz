#include <RCSwitch.h>

RCSwitch rcSwitch = RCSwitch();
unsigned long dump[] = {13590464, 13590320, 13590284, 13590275};

void setup()
{
  Serial.begin(9600);
  rcSwitch.enableTransmit(12);
  rcSwitch.setProtocol(1);
  rcSwitch.setPulseLength(255);
}

void loop()
{
  for (byte i = 0; i < 4; i++) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    rcSwitch.send(dump[i], 24);
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
  }
}