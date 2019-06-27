const int IRsensor = 6;
//E18 , brown is 5v, blue is gnd, black is signal.

void setup() {
  Serial.begin(9600);
  pinMode(IRsensor, INPUT);
}

void loop() {
  int sensorReading = digitalRead(IRsensor);
  if(sensorReading == 1)
    Serial.println("Searching items...");
  else
    Serial.println("Item detected!!!");
  delay(10);
}
