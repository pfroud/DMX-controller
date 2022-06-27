#include <DMXSerial.h>

#define DMX_MAXIMUM 255

// http://www.mathertel.de/Arduino/DMXSerial.aspx

void setup() {
  DMXSerial.init(DMXController);
}

void loop(){
    // https://www.arduino.cc/reference/en/language/functions/random-numbers/random/
   DMXSerial.write(1, random(DMX_MAXIMUM));
   DMXSerial.write(2, random(DMX_MAXIMUM));
   delay(1000);
}
