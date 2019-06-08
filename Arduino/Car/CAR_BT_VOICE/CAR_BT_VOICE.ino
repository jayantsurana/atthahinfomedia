int motorIn1=9;
int motorIn2=10;
int motorIn3=11;
int motorIn4=12;
String voice;
char c;

void setup() 
{
  Serial.begin(9600);
  pinMode(motorIn1, OUTPUT);   //RIGHT MOTOR
  pinMode(motorIn2, OUTPUT);   //RIGHT MOTOR
  pinMode(motorIn3, OUTPUT);   //LEFT MOTOR
  pinMode(motorIn4, OUTPUT);   //LEFT MOTOR
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
  if(voice=="forward"){
    digitalWrite(motorIn1, HIGH);
    digitalWrite(motorIn2, LOW);
    digitalWrite(motorIn3, LOW);
    digitalWrite(motorIn4, HIGH);
    delay(100);
  }else if(voice=="back"){
    digitalWrite(motorIn1, LOW);
    digitalWrite(motorIn2, HIGH);
    digitalWrite(motorIn3, HIGH);
    digitalWrite(motorIn4, LOW);  
    delay(100);
  }else if(voice=="left"){
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
  }else if(voice=="right"){
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
  }else if(voice=="stop"){
    digitalWrite(motorIn1, LOW);
    digitalWrite(motorIn2, LOW);
    digitalWrite(motorIn3, LOW);
    digitalWrite(motorIn4, LOW);
  }
  if(voice.length()>0){
      Serial.println(voice);
       voice="";
  }
}
