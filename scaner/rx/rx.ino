#include <RCSwitch.h>

RCSwitch rcSwitch = RCSwitch();

void setup() {
  Serial.begin(9600);
  rcSwitch.enableReceive(0);  // Receiver on interrupt 0 => that is pin #2
  Serial.println("Listening to the broadcast...");
}

void loop() {
  if (rcSwitch.available()) {
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.print("Received: ");
    Serial.print(rcSwitch.getReceivedValue());
    Serial.print(" / Bit length: ");
    Serial.print(rcSwitch.getReceivedBitlength());
    Serial.print(" / Delay: ");
    Serial.print(rcSwitch.getReceivedDelay());
    Serial.print(" / Protocol: ");
    Serial.println(rcSwitch.getReceivedProtocol());
    Serial.println("==============================");

    rcSwitch.resetAvailable();

    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
  }
}
