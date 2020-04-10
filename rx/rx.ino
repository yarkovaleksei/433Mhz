#include <VirtualWire.h>

const int RX_PIN = 12;

void setup()
{
  Serial.begin(9600);  // Debugging only
  Serial.println("Setup...");
 
  vw_set_rx_pin(RX_PIN);
  vw_setup(2000);      // Bits per sec
  vw_rx_start();       // Start the receiver PLL running

  Serial.println("Done!");
}

void loop()
{

  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  vw_wait_rx_max(2000);
 
  if (vw_get_message(buf, &buflen)) // Non-blocking
  {
    int i;

    digitalWrite(LED_BUILTIN, HIGH); // Flash a light to show received good message
    // Message with a good checksum received, dump it.
    Serial.print("Got: ");

    for (i = 0; i < buflen; i++)
    {
      Serial.print(buf[i]);
      Serial.print(" ");
    }
    Serial.println("");
    digitalWrite(LED_BUILTIN, LOW);
  }

  Serial.print("Bad received:"); Serial.println(vw_get_rx_bad());
  Serial.print("Good received:"); Serial.println(vw_get_rx_good());

  delay(1000);
}
