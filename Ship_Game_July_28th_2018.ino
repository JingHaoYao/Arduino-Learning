#include <LiquidCrystal.h>

#define CharacterObstacleEmpty ' '
#define CharacterObstacleFull 2
#define CharacterObstacleRight 3
#define CharacterObstacleLeft 4

int const button1 = 2;
int const button2 = 3;
int shipPosition = 0;
int score = 0;
boolean playing;
boolean gameOver;
LiquidCrystal lcd(8,9,10,11,12,13);

char upperObstacle[17];
char lowerObstacle[17];

void initializeGraphics(){
  byte shipGraphics[] = {B00000,B11000,B01100,B11111,B11111,B01100,B11000,B00000};
  byte solidObstacle[] = {B11111,B11111,B11111,B11111,B11111,B11111,B11111,B11111};
  byte rightObstacle[] = {B00011,B00011,B00011,B00011,B00011,B00011,B00011,B00011};
  byte leftObstacle[] = {B11000,B11000,B11000,B11000,B11000,B11000,B11000,B11000};
  lcd.createChar(1,shipGraphics);
  lcd.createChar(2,solidObstacle);
  lcd.createChar(3,rightObstacle);
  lcd.createChar(4,leftObstacle);
  for(int i = 1;i<16;i++){
    upperObstacle[i] = CharacterObstacleEmpty;
    lowerObstacle[i] = CharacterObstacleEmpty;
  }
}

void drawTheScene(){
  upperObstacle[16] = '\0';
  lowerObstacle[16] = '\0';
  lcd.setCursor(0,0);
  lcd.print(upperObstacle);
  lcd.setCursor(0,1);
  lcd.print(lowerObstacle);
}

void advanceObstacle(char obstacle[],byte newObstacle) {
  for(int i = 0;i<16;i++){
  char current = obstacle[i];
  char next = (next == 15) ? newObstacle : obstacle[i+1];
  switch(current){
    case CharacterObstacleEmpty:
    obstacle[i] = (next == CharacterObstacleFull) ? CharacterObstacleRight : CharacterObstacleEmpty;
    break;
    case CharacterObstacleFull:
    obstacle[i] = (next == CharacterObstacleEmpty) ? CharacterObstacleLeft : CharacterObstacleFull;
    break;
    case CharacterObstacleRight:
    obstacle[i] = CharacterObstacleFull;
    break;
    case CharacterObstacleLeft: 
    obstacle[i] = CharacterObstacleEmpty;
    break;
    }
  }
}

void printScore(){
  lcd.setCursor(14,0);
  lcd.print(score);
}

void startingScreen(){
  lcd.clear();
  lcd.begin(16,2);
  lcd.print("Press the button");
  lcd.setCursor(0,1);
  lcd.print("to begin!");
  delay(30);
}

void setup() {
  pinMode(button1,INPUT_PULLUP);
  pinMode(button2,INPUT_PULLUP);
  playing == false;
}

void loop() {
static byte newObstacleType = CharacterObstacleEmpty;
static byte newObstacleDuration = 1;

if(digitalRead(button1) == LOW){
  playing = true;
  delay(100);
  }

if (playing == false){
  startingScreen();
  initializeGraphics();

  }
  
if (playing == true){
  
  if((digitalRead(button1))==LOW){
  shipPosition++;
  if(shipPosition == 2){
    shipPosition = 0;
  }
  lcd.clear();
  lcd.setCursor(0,shipPosition);
  lcd.write(byte(0));
  delay(150);
  }
  
  advanceObstacle(lowerObstacle, newObstacleType == 1 ? CharacterObstacleFull : CharacterObstacleEmpty);
  advanceObstacle(upperObstacle, newObstacleType == 2 ? CharacterObstacleFull : CharacterObstacleEmpty);
  if(newObstacleDuration == 1){
    if(newObstacleType == CharacterObstacleEmpty){
      newObstacleType = (random(3) == 0) ? 1 : 2;
      newObstacleDuration = 2 + random(10);
    }
    else{
      newObstacleType = CharacterObstacleEmpty;
      newObstacleDuration = 10 + random(10);
    }
  }
  drawTheScene();
 }
}
