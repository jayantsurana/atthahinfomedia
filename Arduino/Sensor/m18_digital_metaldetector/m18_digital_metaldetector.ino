const int sensor = 8;

void setup() {
  Serial.begin(9600);
  pinMode(sensor, INPUT);
}

void loop() {
  int sensorReading = digitalRead(sensor);
  if(sensorReading == 1)
    Serial.println("Searching matal...");
  else
    Serial.println("Metal detected!!!");
  delay(10);
}
