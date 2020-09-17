void setup() {

  pinMode(22, OUTPUT);
  pinMode(21, OUTPUT);
}

void loop() {
  digitalWrite(22, HIGH);
  digitalWrite(21, LOW);
  delay(9);
  digitalWrite(22, LOW);
  digitalWrite(21, HIGH);
  delay(1);
}
