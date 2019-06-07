int In1 = 7;
int In2 = 8;
//int ENA = 5;
//int SPEED = 210;

void setup() {
  // put your setup code here, to run once:
  pinMode(In1, OUTPUT);
  pinMode(In2, INPUT);
  //pinMode(ENA, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(In1, LOW);
  digitalWrite(In2, HIGH);
  delay(1000);
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  delay(1000);
  //analogWrite(ENA, SPEED);
}
