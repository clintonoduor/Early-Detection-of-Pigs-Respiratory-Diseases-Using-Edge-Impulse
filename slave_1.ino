
#include <Wire.h>
#include <SigFox.h>

void setup() {
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output

  if (!SigFox.begin()) {
    Serial.println("Unable to init the Atmel ATA8520 Sigfox chipset");
    return;
    SigFox.debug();
  }

  void loop() {


    while (Wire.available()) { // slave may send less than requested
      int x = Wire.read(); // receive a byte as character
      if (x == 25)
      {
        SigFox.beginPacket();
        SigFox.write(x);
        SigFox.endPacket();
        Serial.print(x);         // print the integer
      }

    }

    delay(500);
  }

  delay(500);
}
