
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

