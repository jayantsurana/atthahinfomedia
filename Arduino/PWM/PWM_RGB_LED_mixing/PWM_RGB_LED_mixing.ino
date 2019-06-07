const int RED = 9;
const int GREEN = 10;
const int BLUE = 11;

const int MINRANDOM = 0;
const int MAXRANDOM = 255;

int redB;
int blueB;
int greenB;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  redB = random(MINRANDOM, MAXRANDOM);
  greenB = random(MINRANDOM, MAXRANDOM);
  blueB = random(MINRANDOM, MAXRANDOM);

  analogWrite(RED, redB);
  analogWrite(GREEN, greenB);
  analogWrite(BLUE, blueB);
  delay(1000);
}
