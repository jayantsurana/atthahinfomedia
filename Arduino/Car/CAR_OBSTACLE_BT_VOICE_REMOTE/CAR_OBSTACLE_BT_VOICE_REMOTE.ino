const int trigPin = 5;
const int echoPin = 6;
int motorIn1 = 9;
int motorIn2 = 10;
int motorIn3 = 11;
int motorIn4 = 12;
long duration, distance;
String voice;
char c;

void setup() 
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motorIn1, OUTPUT);
  pinMode(motorIn2, OUTPUT);
  pinMode(motorIn3, OUTPUT);
  pinMode(motorIn4, OUTPUT);
}

void loop()
{
  while(Serial.available()>0){
    delay(10);
    c=Serial.read();
    if(c=='#'){
      break;
    }
    voice+=c;
  }
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);  
  duration = pulseIn(echoPin, HIGH);
  distance = duration/58.2;

  if(distance<30){
    digitalWrite(motorIn1, HIGH); 
    digitalWrite(motorIn2, LOW); 
    digitalWrite(motorIn3, HIGH); 
    digitalWrite(motorIn4, LOW);
    delay(1200);
    digitalWrite(motorIn1, HIGH); 
    digitalWrite(motorIn2, LOW); 
    digitalWrite(motorIn3, LOW); 
    digitalWrite(motorIn4, HIGH);
    delay(100);
  }else if(voice=="forward" || c == '1'){
    digitalWrite(motorIn1, HIGH);
    digitalWrite(motorIn2, LOW);
    digitalWrite(motorIn3, LOW);
    digitalWrite(motorIn4, HIGH);
    delay(100);
  }else if(voice=="back" || c == '2'){
    digitalWrite(motorIn1, LOW);
    digitalWrite(motorIn2, HIGH);
    digitalWrite(motorIn3, HIGH);
    digitalWrite(motorIn4, LOW);  
    delay(100);
  }else if(voice=="left" || c == '3'){
    digitalWrite(motorIn1, HIGH);
    digitalWrite(motorIn2, LOW);
    digitalWrite(motorIn3, LOW);
    digitalWrite(motorIn4, LOW);
    delay(800);
    digitalWrite(motorIn1, HIGH);
    digitalWrite(motorIn2, LOW);
    digitalWrite(motorIn3, LOW);
    digitalWrite(motorIn4, HIGH);
    delay(100); 
  }else if(voice=="right" || c == '4'){
    digitalWrite(motorIn1, LOW);
    digitalWrite(motorIn2, LOW);
    digitalWrite(motorIn3, LOW);
    digitalWrite(motorIn4, HIGH);
    delay(800);
    digitalWrite(motorIn1, HIGH);
    digitalWrite(motorIn2, LOW);
    digitalWrite(motorIn3, LOW);
    digitalWrite(motorIn4, HIGH);
    delay(100);   
  }else if(voice=="stop" || c == '5'){
    digitalWrite(motorIn1, LOW);
    digitalWrite(motorIn2, LOW);
    digitalWrite(motorIn3, LOW);
    digitalWrite(motorIn4, LOW);
    delay(100);
  }       
  if(voice.length()>0){
    Serial.println(voice);
    voice="";
  } 
  
  delay(0);
}
