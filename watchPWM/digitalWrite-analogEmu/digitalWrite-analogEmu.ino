void setup() {
  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);
}

void loop() {
  digitalWrite(25, HIGH);
  digitalWrite(26, LOW);
  delay(9);
  digitalWrite(25, LOW);
  digitalWrite(26, HIGH);
  delay(1);
}
