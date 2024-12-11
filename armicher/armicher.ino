void setup() {
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  // put your setup code here, to run once:

}

void loop() {
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(10, HIGH);
  delay(1000);
  digitalWrite(9, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(10, HIGH);
  delay(1000);
  for (int i = 0; i < 256; i++)
  {
    digitalWrite(9, HIGH);
    digitalWrite(8, LOW);
    analogWrite(10, i);
    delay(20);


  }
  delay(50);
  for (int i = 0; i < 256; i++)
  {
    digitalWrite(9, LOW);
    digitalWrite(8, HIGH);
    analogWrite(10, i);
    delay(20);

  }
  delay(50);
}
