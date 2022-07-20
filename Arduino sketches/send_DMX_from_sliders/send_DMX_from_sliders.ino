#include <TimerOne.h>
#include <DMXSerial.h>

// DMX is eight-bit so the maximum value is 2^8 - 1.
#define DMX_MAXIMUM 255
#define DMX_MINIMUM 0

/*
The Arduino has a ten-bit analog-to-digital converter,
so the maximum value is 2^10 - 1.
https://www.arduino.cc/reference/en/language/functions/analog-io/analogread/
*/
#define ARDUINO_ADC_MAXIMUM 1023
#define ARDUINO_ADC_MINIMUM 0



void setup() {
  /*
  The parameter is from the enum DMXMode from DMXSerial.h, but apparently we don't specify the enum name.
  
  Documentation about the DMXSerial.init() function:
  https://www.mathertel.de/Arduino/DMXSerial/api/class_d_m_x_serial_class.htm#adf6e7c30360e49fec3c458dc7e557f90
  
  The declaration of the DMXMode enum:
  https://github.com/mathertel/DMXSerial/blob/59393dfc5629c04447e23748ad6f62887482de87/src/DMXSerial.h#L56
  */
  DMXSerial.init(DMXController);

  /*
  The unit is microseconds. 1 microsecond = 1e-6 sec = 1 /(1,000,000) sec.
  
  1e5 microseconds = 100,000 microseconds = 100 milliseconds = 0.1 seconds -> 10 Hz.
  
  The data rate of DMX is 250 kbit/sec which means 250 kHz.
  
  https://www.pjrc.com/teensy/td_libs_TimerOne.html
  */
  Timer1.initialize(1e5);
  Timer1.attachInterrupt(timerInterruptServiceRoutine);
}

void timerInterruptServiceRoutine() {
  /*
  The first DMX channel is one not zero.
  
  Docs about the DMX library:
  http://www.mathertel.de/Arduino/DMXSerial.aspx
  
  Documentation about the DMXSerial.write() function:
  http://www.mathertel.de/Arduino/DMXSerial/api/class_d_m_x_serial_class.htm#a7bded1ed6237d6a113d1f1cc4a7785a1
  
  Documentation about the Arduino map() function:
  https://www.arduino.cc/reference/en/language/functions/math/map/
  */
  DMXSerial.write(1, map(analogRead(A0), ARDUINO_ADC_MINIMUM, ARDUINO_ADC_MAXIMUM, DMX_MINIMUM, DMX_MAXIMUM));
  DMXSerial.write(2, map(analogRead(A1), ARDUINO_ADC_MINIMUM, ARDUINO_ADC_MAXIMUM, DMX_MINIMUM, DMX_MAXIMUM));
  DMXSerial.write(3, map(analogRead(A2), ARDUINO_ADC_MINIMUM, ARDUINO_ADC_MAXIMUM, DMX_MINIMUM, DMX_MAXIMUM));
  DMXSerial.write(4, map(analogRead(A3), ARDUINO_ADC_MINIMUM, ARDUINO_ADC_MAXIMUM, DMX_MINIMUM, DMX_MAXIMUM));
}

void loop() {
    // nothing
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
