#include <NewPing.h>

#define trigPin A0
#define echoPin A1
#define maxDist 200

int motorIn2 = 5;
int motorIn1 = 6;
int motorIn4 = 10;
int motorIn3 = 11;

int distance = 100;
String voice;
char c;
char stopping;

NewPing sonar(trigPin, echoPin, maxDist);

void setup() 
{
  stopping='1';
  Serial.begin(9600);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motorIn1, OUTPUT);
  pinMode(motorIn2, OUTPUT);
  pinMode(motorIn3, OUTPUT);
  pinMode(motorIn4, OUTPUT);

  distance = readPing();
  delay(100);
}

void loop()
{
  while(Serial.available()>0){
    delay(10);
    c=Serial.read();
    voice+=c;
  }

  if(distance<30 && stopping == '0'){
    moveStop();
    delay(300);
    moveBackward();
    delay(600);
    moveStop();
    delay(300);
    obstacle();
    delay(300);
  }else if(voice=="forward" || c == '1'){
    moveForward();
    delay(100);
  }else if(voice=="back" || c == '2'){
    moveBackward();  
    delay(100);
  }else if(voice=="left" || c == '3'){
    turnLeft();
    delay(100); 
  }else if(voice=="right" || c == '4'){
    turnRight();
    delay(100); 
  }else if(voice=="stop" || c == '5'){
    moveStop();
    delay(100);
  }else if(voice=="travel" || c == '6'){
    travel();
    delay(10);
    travel();
    delay(10);
    travel();
    delay(10);
    travel();
    delay(100);
  }
       
  if(voice.length()>0){
    Serial.println(voice);
    voice="";
  } 

  distance = readPing();
  delay(0);
}

int readPing(){
  delay(70);
  int cm = sonar.ping_cm();
  if (cm==0){
    cm=250;
  }
  return cm;
}

void moveStop(){
  analogWrite(motorIn1, 0);
  analogWrite(motorIn2, 0);
  analogWrite(motorIn3, 0);
  analogWrite(motorIn4, 0);
  stopping='1';
}

void moveForward(){
  analogWrite(motorIn1, 164);
  analogWrite(motorIn2, 0);
  analogWrite(motorIn3, 0);
  analogWrite(motorIn4, 164);
  stopping='0';
}

void moveBackward(){
  analogWrite(motorIn1, 0);
  analogWrite(motorIn2, 164);
  analogWrite(motorIn3, 164);
  analogWrite(motorIn4, 0);
  stopping='0';
}

void turnRight(){
  analogWrite(motorIn1, 0);
  analogWrite(motorIn2, 0);
  analogWrite(motorIn3, 0);
  analogWrite(motorIn4, 220);
  delay(1200);
  analogWrite(motorIn1, 164);
  analogWrite(motorIn2, 0);
  analogWrite(motorIn3, 0);
  analogWrite(motorIn4, 164);
  stopping='0';
}

void turnLeft(){
  analogWrite(motorIn1, 220);
  analogWrite(motorIn2, 0);
  analogWrite(motorIn3, 0);
  analogWrite(motorIn4, 0);
  delay(1200);
  analogWrite(motorIn1, 164);
  analogWrite(motorIn2, 0);
  analogWrite(motorIn3, 0);
  analogWrite(motorIn4, 164);
  stopping='0';
}

void obstacle(){
  analogWrite(motorIn1, 232);
  analogWrite(motorIn2, 0);
  analogWrite(motorIn3, 0);
  analogWrite(motorIn4, 0);
  delay(1200);
  analogWrite(motorIn1, 164);
  analogWrite(motorIn2, 0);
  analogWrite(motorIn3, 0);
  analogWrite(motorIn4, 164);
  stopping='0';
}

void travel(){
  moveForward();
  delay(800);
  turnLeft();
  delay(800);
  turnLeft();
  delay(800);
  turnLeft();
  delay(800);
  moveBackward();
  delay(200);
  moveStop();
  delay(100);
}
