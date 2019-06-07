const int RED = 9;
const int GREEN = 10;
const int BLUE = 11;

int color[] = {255,0,0};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // red
  for (int downer = 0; downer < 3; downer++){

    int upper = 0;

    if (downer < 2)
      upper = downer + 1;
    else
      upper = 0;
    
    for(int i = 0; i < 255; i++) {
      color[downer]--;
      color[upper]++;
      
      rgbColor(color[0], color[1], color[2]);
      delay(5);
    }
  }
}

void rgbColor(int red, int green, int blue) {
  analogWrite(RED, red);
  analogWrite(GREEN, green);
  analogWrite(BLUE, blue);
  Serial.print("Red: ");
  Serial.print(red);
  Serial.print(" | Green: ");
  Serial.print(green);
  Serial.print(" | Blue: ");
  Serial.println(blue);
 }
