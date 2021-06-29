// Include the required Wire library for I2C
#include <Wire.h>
#include <SigFox.h>

int x;

void setup() {
  if (!SigFox.begin()) {
    Serial.println("Unable to init the Atmel ATA8520 Sigfox chipset");
    return;
    SigFox.debug();

    Wire.begin(9);
    // Attach a function to trigger when something is received.
      void receiveEvent(int bytes)
  {
    x = Wire.read();    // read one character from the I2C
  }

    Wire.onReceive(receiveEvent);
  }


  void loop() {
    //If value received is 1 send notification via Sigfox
    if (x == 1)
    {
      SigFox.beginPacket();
      SigFox.write(x);
      SigFox.endPacket();
      Serial.println("Coughing Pig detected and notification sent");
    }
  }
