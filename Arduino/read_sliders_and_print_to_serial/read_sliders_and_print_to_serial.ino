/*
You can use this Arduino sketch to test your slide potentiometers.
*/

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print(analogRead(A0));
  Serial.print(", ");
  Serial.print(analogRead(A1));
  Serial.print(", ");
  Serial.print(analogRead(A2));
  Serial.print(", ");
  Serial.println(analogRead(A3));
  delay(100);
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
