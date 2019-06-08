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
  if(voice=="forward" || c == '1'){
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
  }
  if(voice.length()>0){
      Serial.println(voice);
       voice="";
  }
}
