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

/*
Copyright Peter Froud 2022.

This source describes Open Hardware and is licensed under the CERN-OHL-S v2.

You may redistribute and modify this source and make products using it under
the terms of the CERN-OHL-S v2 (https://ohwr.org/cern_ohl_s_v2.txt).

This source is distributed WITHOUT ANY EXPRESS OR IMPLIED WARRANTY,
INCLUDING OF MERCHANTABILITY, SATISFACTORY QUALITY AND FITNESS FOR A
PARTICULAR PURPOSE. Please see the CERN-OHL-S v2 for applicable conditions. 

Source location: https://github.com/pfroud/DMX-controller
*/
