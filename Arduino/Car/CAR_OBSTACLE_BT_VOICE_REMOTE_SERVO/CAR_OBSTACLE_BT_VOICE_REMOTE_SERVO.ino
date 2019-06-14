#include <Servo.h>
#include <NewPing.h>

#define trigPin  A0
#define echoPin  A1

int motorIn1 = 9;
int motorIn2 = 10;
int motorIn3 = 11;
int motorIn4 = 12;

#define maxDist 200
boolean goeesForward = false;
int distance = 100;

//long duration, distance;
String voice;
char c;
char stopping;

NewPing sonar(trigPin, echoPin, maxDist);
Servo servoMotor;

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

  servoMotor.attach(3);

  servoMotor.write(115);
  delay(2000);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
}

void loop()
{
  int distRight = 0;
  int distLeft = 0;
  delay(50);
  
  while(Serial.available()>0){
    delay(10);
    c=Serial.read();
    voice+=c;
  }

  if(distance<30 && stopping == '0'){
      moveStop();
      delay(300);
      moveBackward();
      delay(400);
      moveStop();
      delay(300);
      distRight = lookRight();
      delay(300);
      distLeft = lookLeft();
      delay(300);

      if (distRight >= distLeft){
        turnRight();
      }
      else{
        turnLeft();
      }
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
  }  
       
  if(voice.length()>0){
    Serial.println(voice);
    voice="";
  } 

  distance = readPing();
  
  delay(0);
}

int lookRight(){  
  servoMotor.write(50);
  delay(500);
  int distance = readPing();
  delay(100);
  servoMotor.write(115);
  return distance;
}

int lookLeft(){
  servoMotor.write(170);
  delay(500);
  int distance = readPing();
  delay(100);
  servoMotor.write(115);
  return distance;
  delay(100);
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
  digitalWrite(motorIn1, LOW);
  digitalWrite(motorIn2, LOW);
  digitalWrite(motorIn3, LOW);
  digitalWrite(motorIn4, LOW);
  stopping='1';
}

void moveForward(){
  digitalWrite(motorIn1, HIGH);
  digitalWrite(motorIn2, LOW);
  digitalWrite(motorIn3, LOW);
  digitalWrite(motorIn4, HIGH);
  stopping='0';
}

void moveBackward(){
  digitalWrite(motorIn1, LOW);
  digitalWrite(motorIn2, HIGH);
  digitalWrite(motorIn3, HIGH);
  digitalWrite(motorIn4, LOW);
  stopping='0';
}

void turnRight(){
  digitalWrite(motorIn1, LOW);
  digitalWrite(motorIn2, LOW);
  digitalWrite(motorIn3, LOW);
  digitalWrite(motorIn4, HIGH);
  delay(800);
  digitalWrite(motorIn1, HIGH);
  digitalWrite(motorIn2, LOW);
  digitalWrite(motorIn3, LOW);
  digitalWrite(motorIn4, HIGH);
  stopping='0';
}

void turnLeft(){
  digitalWrite(motorIn1, HIGH);
  digitalWrite(motorIn2, LOW);
  digitalWrite(motorIn3, LOW);
  digitalWrite(motorIn4, LOW);
  delay(800);
  digitalWrite(motorIn1, HIGH);
  digitalWrite(motorIn2, LOW);
  digitalWrite(motorIn3, LOW);
  digitalWrite(motorIn4, HIGH);
  stopping='0';
}
