const int LED7 = 7;
const int LED9 = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED7, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(LED9, 197);
  digitalWrite(LED7, HIGH);
  delay(3);
  digitalWrite(LED7, LOW);
  delay(1);
}
