const int trigPin = 5;
const int echoPin = 6;
int motorIn1 = 9;
int motorIn2 = 10;
int motorIn3 = 11;
int motorIn4 = 12;
long duration, distance;

void setup() 
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motorIn1, OUTPUT);
  pinMode(motorIn2, OUTPUT);
  pinMode(motorIn3, OUTPUT);
  pinMode(motorIn4, OUTPUT);
}

void loop()
{     
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);  
  duration = pulseIn(echoPin, HIGH);
  distance = duration/58.2;
  if(distance<30)
    {
      digitalWrite(motorIn1, HIGH); 
      digitalWrite(motorIn2, LOW); 
      digitalWrite(motorIn3, LOW); 
      digitalWrite(motorIn4, HIGH);
      delay(1200);
    }
    
  else
    {
      digitalWrite(motorIn1, HIGH); 
      digitalWrite(motorIn2, LOW); 
      digitalWrite(motorIn3, HIGH); 
      digitalWrite(motorIn4, LOW);
    }  
  delay(0);
}
