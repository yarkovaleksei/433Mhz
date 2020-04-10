#include <VirtualWire.h>

const int TX_PIN = 12;

void setup() {
  Serial.begin(9600);  // Debugging only
  Serial.println("Setup");

  vw_set_tx_pin(TX_PIN);
  vw_setup(2000);
}

byte count = 1;

char charBuf[3] = {'1','#',' '};

void loop() {
  charBuf[2] = char(count++);
  bool success = true;
 
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("Sending:");
  Serial.print(charBuf[0]);
  Serial.print(charBuf[1]);
  Serial.println(byte(charBuf[2]));
  success = vw_send((uint8_t *)charBuf, 3);

  vw_wait_tx();

  if (success) {
    Serial.println("Finished");
  } else {
    Serial.println("Error while sending message");
  }

  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}
