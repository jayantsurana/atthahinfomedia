int FirstLed=10;
int SecondLed=11;
int ThirdLed=12;

void setup() {
  // put your setup code here, to run once:
   pinMode(FirstLed, OUTPUT);
   pinMode(SecondLed, OUTPUT);
   pinMode(ThirdLed, OUTPUT);

   digitalWrite(FirstLed, LOW);
   digitalWrite(SecondLed, LOW);
   digitalWrite(ThirdLed, LOW);

   Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
   digitalWrite(FirstLed, HIGH);
   digitalWrite(SecondLed, LOW);
   digitalWrite(ThirdLed, LOW);

   Serial.println(" Light Mode : Yield ");
   delay(1000);

   digitalWrite(FirstLed, LOW);
   digitalWrite(SecondLed, HIGH);
   digitalWrite(ThirdLed, LOW);

   Serial.println(" Light Mode : Go ");
   delay(2000);
   digitalWrite(FirstLed, LOW);
   digitalWrite(SecondLed, LOW);
   digitalWrite(ThirdLed, HIGH);

   Serial.println(" Light Mode : Stop ");
   delay(2000);
   
}
