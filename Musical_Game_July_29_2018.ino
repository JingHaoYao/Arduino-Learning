#include "pitches.h"
#include <LiquidCrystal.h>

int const button1 = 6;
int const button2 = 5;
int const button3 = 4;
int const button4 = 3;
int const button5 = 2;
int const buzzer = 7;
int const notes[] = {NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5};

LiquidCrystal lcd(8,9,10,11,12,13);

int difficulty = 0;
int whatLevel = 0;
bool difficultyConfirm = false;
bool readyToPlay = false;

void difficultySelect(){
  if(digitalRead(button1) == LOW){
    lcd.clear();
    difficulty ++;
    if(difficulty == 5){
      difficulty = 1;
    }
  }
lcd.setCursor(0,0);
lcd.print("Difficulty:");
  switch(difficulty){
    case 1:
    lcd.setCursor(0,1);
    lcd.print("EASY");
    break;
    case 2:
    lcd.setCursor(0,1);
    lcd.print("MEDIUM");
    break;
    case 3:
    lcd.setCursor(0,1);
    lcd.print("HARD");
    break;
    case 4:
    lcd.setCursor(0,1);
    lcd.print("INSANE");
    break;
  }
}

void difficultyConfirmed(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Selected:");
  tone(7,NOTE_C5,500);
   switch(difficulty){
    case 1:
    lcd.setCursor(0,1);
    lcd.print("EASY");
    break;
    case 2:
    lcd.setCursor(0,1);
    lcd.print("MEDIUM");
    break;
    case 3:
    lcd.setCursor(0,1);
    lcd.print("HARD");
    break;
    case 4:
    lcd.setCursor(0,1);
    lcd.print("INSANE");
    break;
  }
}

void easyLevel1(){
  bool level1Input;
  int inputNumber = 0;
  int input[3];
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Level 1:");
  int level1[] = {NOTE_C5,NOTE_D5,NOTE_E5};

while(level1Input == false and whatLevel == 1){
  for(int i=0;i<3;i++){
    tone(7,level1[i],500);
    delay(750);
    }
    level1Input = true;
    break;
}
while(level1Input == true and whatLevel == 1){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Press buttons");
  lcd.setCursor(0,1);
  lcd.print("to select notes.");

  while(inputNumber == 3){
    if(input[0] == level1[0] and input[1] == level1[1] and input[2] == level1[2]){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Congratulations!");
      lcd.setCursor(0,1);
      lcd.print("You beat it!");
      delay(3000);
      whatLevel = 2;
      break;
    }
    else{
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Uh-oh");
      lcd.setCursor(0,1);
      lcd.print("spaghetti-o's!");
      delay(3000);
      level1Input = false;
      break;
    }
  }
  
  if(digitalRead(button1) == LOW){
    tone(7,notes[0],500);
    input[inputNumber] = NOTE_C5;
    inputNumber++;
    delay(200);
  }
  if(digitalRead(button2) == LOW){
    tone(7,notes[1],500);
    input[inputNumber] = NOTE_D5;
    inputNumber++;
    delay(200);
    }
  if(digitalRead(button3) == LOW){
    tone(7,notes[2],500);
    input[inputNumber] = NOTE_E5;
    inputNumber++;
    delay(200);
    }
  if(digitalRead(button4) == LOW){
    tone(7,notes[3],500);
    input[inputNumber] = NOTE_F5;
    inputNumber++;
    delay(200);
  }
  if(digitalRead(button5) == LOW){
    tone(7,notes[4],500);
    input[inputNumber] = NOTE_G5;
    inputNumber++;
    delay(200);
  }
    delay(100);
  }
  delay(100);
}

void easyLevel2(){
  bool level2Input;
  int inputNumber = 0;
  int input[4];
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Level 2:");
  int level2[] = {NOTE_C5,NOTE_D5,NOTE_F5,NOTE_E5};
  delay(100);

while(level2Input == false and whatLevel == 2){
  for(int i=0;i<4;i++){
    tone(7,level2[i],500);
    delay(750);
    }
    level2Input = true;
    break;
}
while(level2Input == true and whatLevel == 2){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Press buttons");
  lcd.setCursor(0,1);
  lcd.print("to select notes.");

  while(inputNumber == 4){
    if(input[0] == level2[0] and input[1] == level2[1] and input[2] == level2[2] and input[3] == level2[3]){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Congratulations!");
      lcd.setCursor(0,1);
      lcd.print("You beat it!");
      delay(3000);
      whatLevel = 3;
      break;
    }
    else{
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Uh-oh");
      lcd.setCursor(0,1);
      lcd.print("spaghetti-o's!");
      delay(3000);
      level2Input = false;
      break;
    }
  }
  if(digitalRead(button1) == LOW){
    tone(7,notes[0],500);
    input[inputNumber] = NOTE_C5;
    inputNumber++;
    delay(200);
  }
  if(digitalRead(button2) == LOW){
    tone(7,notes[1],500);
    input[inputNumber] = NOTE_D5;
    inputNumber++;
    delay(200);
    }
  if(digitalRead(button3) == LOW){
    tone(7,notes[2],500);
    input[inputNumber] = NOTE_E5;
    inputNumber++;
    delay(200);
    }
  if(digitalRead(button4) == LOW){
    tone(7,notes[3],500);
    input[inputNumber] = NOTE_F5;
    inputNumber++;
    delay(200);
  }
  if(digitalRead(button5) == LOW){
    tone(7,notes[4],500);
    input[inputNumber] = NOTE_G5;
    inputNumber++;
    delay(200);
  }
    delay(100);
  }
  delay(100);
}

void easyLevel3(){
bool level3Input;
int inputNumber = 0;
int input[5];
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Level 3:");
int level3[] = {NOTE_C5,NOTE_D5,NOTE_E5,NOTE_G5,NOTE_C5};

while(level3Input == false and whatLevel == 3){
  for(int i=0;i<5;i++){
    tone(7,level3[i],500);
    delay(750);
    }
    level3Input = true;
    break;
}
while(level3Input == true and whatLevel == 3){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Press buttons");
  lcd.setCursor(0,1);
  lcd.print("to select notes.");

  while(inputNumber == 5){
    if(input[0] == level3[0] and input[1] == level3[1] and input[2] == level3[2] and input[3] == level3[3] and input[4] == level3[4]){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Congratulations!");
      lcd.setCursor(0,1);
      lcd.print("You beat it!");
      delay(3000);
      difficulty = 0;
      whatLevel = 0;
      difficultyConfirm = false;
      readyToPlay = false;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Select a");
      lcd.setCursor(0,1);
      lcd.print("Difficulty!");
      break;
    }
    else{
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Uh-oh");
      lcd.setCursor(0,1);
      lcd.print("spaghetti-o's!");
      delay(3000);
      level3Input = false;
      break;
    }
  }
  if(digitalRead(button1) == LOW){
    tone(7,notes[0],500);
    input[inputNumber] = NOTE_C5;
    inputNumber++;
    delay(200);
  }
  if(digitalRead(button2) == LOW){
    tone(7,notes[1],500);
    input[inputNumber] = NOTE_D5;
    inputNumber++;
    delay(200);
    }
  if(digitalRead(button3) == LOW){
    tone(7,notes[2],500);
    input[inputNumber] = NOTE_E5;
    inputNumber++;
    delay(200);
    }
  if(digitalRead(button4) == LOW){
    tone(7,notes[3],500);
    input[inputNumber] = NOTE_F5;
    inputNumber++;
    delay(200);
  }
  if(digitalRead(button5) == LOW){
    tone(7,notes[4],500);
    input[inputNumber] = NOTE_G5;
    inputNumber++;
    delay(200);
  }
    delay(100);
  }
  delay(100);  
}


void mediumLevel1(){
bool levelInput;
int input[5];
int inputNumber = 0;
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Level 1:");
int level[] = {NOTE_G5, NOTE_C5, NOTE_E5, NOTE_F5, NOTE_D5};
while(levelInput == false and whatLevel == 1){
  for(int i=0;i<5;i++){
    tone(7,level[i],500);
    delay(500);
    }
    levelInput = true;
    break;
}
while(levelInput == true and whatLevel == 1){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Press buttons");
  lcd.setCursor(0,1);
  lcd.print("to select notes.");

  while(inputNumber == 5){
    if(input[0] == level[0] and input[1] == level[1] and input[2] == level[2] and input[3] == level[3] and input[4] == level[4]){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Congratulations!");
      lcd.setCursor(0,1);
      lcd.print("You beat it!");
      delay(3000);
      whatLevel = 2;
      break;
    }
    else{
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Uh-oh");
      lcd.setCursor(0,1);
      lcd.print("spaghetti-o's!");
      delay(3000);
      levelInput = false;
      break;
    }
  }
  if(digitalRead(button1) == LOW){
    tone(7,notes[0],500);
    input[inputNumber] = NOTE_C5;
    inputNumber++;
    delay(200);
  }
  if(digitalRead(button2) == LOW){
    tone(7,notes[1],500);
    input[inputNumber] = NOTE_D5;
    inputNumber++;
    delay(200);
    }
  if(digitalRead(button3) == LOW){
    tone(7,notes[2],500);
    input[inputNumber] = NOTE_E5;
    inputNumber++;
    delay(200);
    }
  if(digitalRead(button4) == LOW){
    tone(7,notes[3],500);
    input[inputNumber] = NOTE_F5;
    inputNumber++;
    delay(200);
  }
  if(digitalRead(button5) == LOW){
    tone(7,notes[4],500);
    input[inputNumber] = NOTE_G5;
    inputNumber++;
    delay(200);
  }
    delay(100);
  }
  delay(100);  
}

void mediumLevel2(){
bool levelInput;
int input[6];
int inputNumber = 0;
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Level 2:");
int level[] = {NOTE_F5, NOTE_G5, NOTE_E5, NOTE_F5, NOTE_D5, NOTE_E5};
while(levelInput == false and whatLevel == 2){
  for(int i=0;i<6;i++){
    tone(7,level[i],500);
    delay(500);
    }
    levelInput = true;
    break;
}
while(levelInput == true and whatLevel == 2){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Press buttons");
  lcd.setCursor(0,1);
  lcd.print("to select notes.");

  while(inputNumber == 6){
    if(input[0] == level[0] and input[1] == level[1] and input[2] == level[2] and input[3] == level[3] and input[4] == level[4] and input[5] == level[5]){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Congratulations!");
      lcd.setCursor(0,1);
      lcd.print("You beat it!");
      delay(3000);
      whatLevel = 3;
      break;
    }
    else{
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Uh-oh");
      lcd.setCursor(0,1);
      lcd.print("spaghetti-o's!");
      delay(3000);
      levelInput = false;
      break;
    }
  }
  if(digitalRead(button1) == LOW){
    tone(7,notes[0],500);
    input[inputNumber] = NOTE_C5;
    inputNumber++;
    delay(200);
  }
  if(digitalRead(button2) == LOW){
    tone(7,notes[1],500);
    input[inputNumber] = NOTE_D5;
    inputNumber++;
    delay(200);
    }
  if(digitalRead(button3) == LOW){
    tone(7,notes[2],500);
    input[inputNumber] = NOTE_E5;
    inputNumber++;
    delay(200);
    }
  if(digitalRead(button4) == LOW){
    tone(7,notes[3],500);
    input[inputNumber] = NOTE_F5;
    inputNumber++;
    delay(200);
  }
  if(digitalRead(button5) == LOW){
    tone(7,notes[4],500);
    input[inputNumber] = NOTE_G5;
    inputNumber++;
    delay(200);
  }
    delay(100);
  }
  delay(100);  
}

void mediumLevel3(){
bool levelInput;
int input[7];
int inputNumber = 0;
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Level 3:");
int level[] = {NOTE_C5, NOTE_D5, NOTE_E5, NOTE_G5, NOTE_F5, NOTE_E5, NOTE_E5};
while(levelInput == false and whatLevel == 3){
  for(int i=0;i<7;i++){
    tone(7,level[i],500);
    delay(500);
    }
    levelInput = true;
    break;
}
while(levelInput == true and whatLevel == 3){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Press buttons");
  lcd.setCursor(0,1);
  lcd.print("to select notes.");

  while(inputNumber == 7){
    if(input[0] == level[0] and input[1] == level[1] and input[2] == level[2] and input[3] == level[3] and input[4] == level[4] and input[5] == level[5] and input[6] == level[6]){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Congratulations!");
      lcd.setCursor(0,1);
      lcd.print("You beat it!");
      delay(3000);
      difficulty = 0;
      whatLevel = 0;
      difficultyConfirm = false;
      readyToPlay = false;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Select a");
      lcd.setCursor(0,1);
      lcd.print("Difficulty!");
      break;
    }
    else{
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Uh-oh");
      lcd.setCursor(0,1);
      lcd.print("spaghetti-o's!");
      delay(3000);
      levelInput = false;
      break;
    }
  }
  if(digitalRead(button1) == LOW){
    tone(7,notes[0],500);
    input[inputNumber] = NOTE_C5;
    inputNumber++;
    delay(200);
  }
  if(digitalRead(button2) == LOW){
    tone(7,notes[1],500);
    input[inputNumber] = NOTE_D5;
    inputNumber++;
    delay(200);
    }
  if(digitalRead(button3) == LOW){
    tone(7,notes[2],500);
    input[inputNumber] = NOTE_E5;
    inputNumber++;
    delay(200);
    }
  if(digitalRead(button4) == LOW){
    tone(7,notes[3],500);
    input[inputNumber] = NOTE_F5;
    inputNumber++;
    delay(200);
  }
  if(digitalRead(button5) == LOW){
    tone(7,notes[4],500);
    input[inputNumber] = NOTE_G5;
    inputNumber++;
    delay(200);
  }
    delay(100);
  }
  delay(100);  
}

void hardLevel1(){
bool levelInput;
int input[7];
int inputNumber = 0;
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Level 1:");
int level[] = {NOTE_D5,NOTE_F5,NOTE_D5,NOTE_F5, NOTE_G5, NOTE_E5, NOTE_C5};
while(levelInput == false and whatLevel == 1){
  for(int i=0;i<7;i++){
    tone(7,level[i],500);
    delay(300);
    }
    levelInput = true;
    break;
}
while(levelInput == true and whatLevel == 1){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Press buttons");
  lcd.setCursor(0,1);
  lcd.print("to select notes.");

  while(inputNumber == 7){
    if(input[0] == level[0] and input[1] == level[1] and input[2] == level[2] and input[3] == level[3] and input[4] == level[4] and input[5] == level[5] and input[6] == level[6]){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Congratulations!");
      lcd.setCursor(0,1);
      lcd.print("You beat it!");
      delay(3000);
      whatLevel = 2;
      break;
    }
    else{
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Uh-oh");
      lcd.setCursor(0,1);
      lcd.print("spaghetti-o's!");
      delay(3000);
      levelInput = false;
      break;
    }
  }
  if(digitalRead(button1) == LOW){
    tone(7,notes[0],500);
    input[inputNumber] = NOTE_C5;
    inputNumber++;
    delay(200);
  }
  if(digitalRead(button2) == LOW){
    tone(7,notes[1],500);
    input[inputNumber] = NOTE_D5;
    inputNumber++;
    delay(200);
    }
  if(digitalRead(button3) == LOW){
    tone(7,notes[2],500);
    input[inputNumber] = NOTE_E5;
    inputNumber++;
    delay(200);
    }
  if(digitalRead(button4) == LOW){
    tone(7,notes[3],500);
    input[inputNumber] = NOTE_F5;
    inputNumber++;
    delay(200);
  }
  if(digitalRead(button5) == LOW){
    tone(7,notes[4],500);
    input[inputNumber] = NOTE_G5;
    inputNumber++;
    delay(200);
  }
    delay(100);
  }
  delay(100);  
}

void hardLevel2(){
bool levelInput;
int input[8];
int inputNumber = 0;
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Level 2:");
int level[] = {NOTE_G5, NOTE_F5, NOTE_E5, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_E5};
while(levelInput == false and whatLevel == 2){
  for(int i = 0;i<8;i++){
    tone(7,level[i],500);
    delay(300);
    }
    levelInput = true;
    break;
}
while(levelInput == true and whatLevel == 2){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Press buttons");
  lcd.setCursor(0,1);
  lcd.print("to select notes.");

  while(inputNumber == 8){
    if(input[0] == level[0] and input[1] == level[1] and input[2] == level[2] and input[3] == level[3] and input[4] == level[4] and input[5] == level[5] and input[6] == level[6] and input[7] == level[7]){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Congratulations!");
      lcd.setCursor(0,1);
      lcd.print("You beat it!");
      delay(3000);
      whatLevel = 3;
      break;
    }
    else{
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Uh-oh");
      lcd.setCursor(0,1);
      lcd.print("spaghetti-o's!");
      delay(3000);
      levelInput = false;
      break;
    }
  }
  if(digitalRead(button1) == LOW){
    tone(7,notes[0],500);
    input[inputNumber] = NOTE_C5;
    inputNumber++;
    delay(200);
  }
  if(digitalRead(button2) == LOW){
    tone(7,notes[1],500);
    input[inputNumber] = NOTE_D5;
    inputNumber++;
    delay(200);
    }
  if(digitalRead(button3) == LOW){
    tone(7,notes[2],500);
    input[inputNumber] = NOTE_E5;
    inputNumber++;
    delay(200);
    }
  if(digitalRead(button4) == LOW){
    tone(7,notes[3],500);
    input[inputNumber] = NOTE_F5;
    inputNumber++;
    delay(200);
  }
  if(digitalRead(button5) == LOW){
    tone(7,notes[4],500);
    input[inputNumber] = NOTE_G5;
    inputNumber++;
    delay(200);
  }
    delay(100);
  }
  delay(100);  
}

void hardLevel3(){
bool levelInput;
int input[9];
int inputNumber = 0;
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Level 3:");
int level[] = {NOTE_C5,NOTE_G5,NOTE_C5,NOTE_G5,NOTE_F5,NOTE_D5,NOTE_G5,NOTE_D5,NOTE_E5};
while(levelInput == false and whatLevel == 3){
  for(int i=0;i<9;i++){
    tone(7,level[i],500);
    delay(300);
    }
    levelInput = true;
    break;
 }
while(levelInput == true and whatLevel == 3){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Press buttons");
  lcd.setCursor(0,1);
  lcd.print("to select notes.");

  while(inputNumber == 9){
    if(input[0] == level[0] and input[1] == level[1] and input[2] == level[2] and input[3] == level[3] and input[4] == level[4] and input[5] == level[5] and input[6] == level[6] and input[7] == level[7] and input[8] == level[8]){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Congratulations!");
      lcd.setCursor(0,1);
      lcd.print("You beat it!");
      delay(3000);
      difficulty = 0;
      whatLevel = 0;
      difficultyConfirm = false;
      readyToPlay = false;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Select a");
      lcd.setCursor(0,1);
      lcd.print("Difficulty!");
      break;
    }
    else{
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Uh-oh");
      lcd.setCursor(0,1);
      lcd.print("spaghetti-o's!");
      delay(3000);
      levelInput = false;
      break;
    }
  }
  if(digitalRead(button1) == LOW){
    tone(7,notes[0],500);
    input[inputNumber] = NOTE_C5;
    inputNumber++;
    delay(200);
  }
  if(digitalRead(button2) == LOW){
    tone(7,notes[1],500);
    input[inputNumber] = NOTE_D5;
    inputNumber++;
    delay(200);
    }
  if(digitalRead(button3) == LOW){
    tone(7,notes[2],500);
    input[inputNumber] = NOTE_E5;
    inputNumber++;
    delay(200);
    }
  if(digitalRead(button4) == LOW){
    tone(7,notes[3],500);
    input[inputNumber] = NOTE_F5;
    inputNumber++;
    delay(200);
  }
  if(digitalRead(button5) == LOW){
    tone(7,notes[4],500);
    input[inputNumber] = NOTE_G5;
    inputNumber++;
    delay(200);
  }
    delay(100);
  }
  delay(100);  
}

void insaneLevel1(){
bool levelInput;
int input[9];
int inputNumber = 0;
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Level 1:");
int level[] = {NOTE_G5,NOTE_F5,NOTE_G5,NOTE_F5,NOTE_C5,NOTE_D5,NOTE_C5,NOTE_D5,NOTE_E5};
while(levelInput == false and whatLevel == 1){
  for(int i = 0;i<9;i++){
    tone(7,level[i],500);
    delay(150);
    }
    levelInput = true;
    break;
}
while(levelInput == true and whatLevel == 1){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Press buttons");
  lcd.setCursor(0,1);
  lcd.print("to select notes.");

  while(inputNumber == 9){
    if(input[0] == level[0] and input[1] == level[1] and input[2] == level[2] and input[3] == level[3] and input[4] == level[4] and input[5] == level[5] and input[6] == level[6] and input[7] == level[7] and input[8] == level[8]){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Congratulations!");
      lcd.setCursor(0,1);
      lcd.print("You beat it!");
      delay(3000);
      whatLevel = 2;
      break;
    }
    else{
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Uh-oh");
      lcd.setCursor(0,1);
      lcd.print("spaghetti-o's!");
      delay(3000);
      levelInput = false;
      break;
    }
  }
  if(digitalRead(button1) == LOW){
    tone(7,notes[0],500);
    input[inputNumber] = NOTE_C5;
    inputNumber++;
    delay(200);
  }
  if(digitalRead(button2) == LOW){
    tone(7,notes[1],500);
    input[inputNumber] = NOTE_D5;
    inputNumber++;
    delay(200);
    }
  if(digitalRead(button3) == LOW){
    tone(7,notes[2],500);
    input[inputNumber] = NOTE_E5;
    inputNumber++;
    delay(200);
    }
  if(digitalRead(button4) == LOW){
    tone(7,notes[3],500);
    input[inputNumber] = NOTE_F5;
    inputNumber++;
    delay(200);
  }
  if(digitalRead(button5) == LOW){
    tone(7,notes[4],500);
    input[inputNumber] = NOTE_G5;
    inputNumber++;
    delay(200);
  }
    delay(100);
  }
  delay(100);  
}

void insaneLevel2(){
bool levelInput;
int input[10];
int inputNumber = 0;
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Level 2:");
int level[] = {NOTE_C5,NOTE_E5,NOTE_G5,NOTE_D5,NOTE_F5,NOTE_G5,NOTE_E5,NOTE_C5,NOTE_F5,NOTE_D5};
while(levelInput == false and whatLevel == 2){
  for(int i = 0;i<10;i++){
    tone(7,level[i],500);
    delay(150);
    }
    levelInput = true;
    break;
}
while(levelInput == true and whatLevel == 2){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Press buttons");
  lcd.setCursor(0,1);
  lcd.print("to select notes.");

  while(inputNumber == 10){
    if(input[0] == level[0] and input[1] == level[1] and input[2] == level[2] and input[3] == level[3] and input[4] == level[4] and input[5] == level[5] and input[6] == level[6] and input[7] == level[7] and input[8] == level[8] and input[9] == level[9]){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Congratulations!");
      lcd.setCursor(0,1);
      lcd.print("You beat it!");
      delay(3000);
      whatLevel = 3;
      break;
    }
    else{
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Uh-oh");
      lcd.setCursor(0,1);
      lcd.print("spaghetti-o's!");
      delay(3000);
      levelInput = false;
      break;
    }
  }
  if(digitalRead(button1) == LOW){
    tone(7,notes[0],500);
    input[inputNumber] = NOTE_C5;
    inputNumber++;
    delay(200);
  }
  if(digitalRead(button2) == LOW){
    tone(7,notes[1],500);
    input[inputNumber] = NOTE_D5;
    inputNumber++;
    delay(200);
    }
  if(digitalRead(button3) == LOW){
    tone(7,notes[2],500);
    input[inputNumber] = NOTE_E5;
    inputNumber++;
    delay(200);
    }
  if(digitalRead(button4) == LOW){
    tone(7,notes[3],500);
    input[inputNumber] = NOTE_F5;
    inputNumber++;
    delay(200);
  }
  if(digitalRead(button5) == LOW){
    tone(7,notes[4],500);
    input[inputNumber] = NOTE_G5;
    inputNumber++;
    delay(200);
  }
    delay(100);
  }
  delay(100);  
}

void insaneLevel3(){
bool levelInput;
int input[11];
int inputNumber = 0;
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Level 3:");
int level[] = {NOTE_E5,NOTE_C5,NOTE_G5,NOTE_E5,NOTE_C5,NOTE_G5,NOTE_F5,NOTE_D5,NOTE_G5,NOTE_F5,NOTE_E5};
while(levelInput == false and whatLevel == 3){
  for(int i = 0;i<11;i++){
    tone(7,level[i],500);
    delay(150);
    }
    levelInput = true;
    break;
}
while(levelInput == true and whatLevel == 3){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Press buttons");
  lcd.setCursor(0,1);
  lcd.print("to select notes.");

  while(inputNumber == 11){
    if(input[0] == level[0] and input[1] == level[1] and input[2] == level[2] and input[3] == level[3] and input[4] == level[4] and input[5] == level[5] and input[6] == level[6] and input[7] == level[7] and input[8] == level[8] and input[9] == level[9] and input[10] == level[10]){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Congratulations!");
      lcd.setCursor(0,1);
      lcd.print("You beat it!");
      delay(3000);
      difficulty = 0;
      whatLevel = 0;
      difficultyConfirm = false;
      readyToPlay = false;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Select a");
      lcd.setCursor(0,1);
      lcd.print("Difficulty!");
      break;
    }
    else{
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Uh-oh");
      lcd.setCursor(0,1);
      lcd.print("spaghetti-o's!");
      delay(3000);
      levelInput = false;
      break;
    }
  }
  if(digitalRead(button1) == LOW){
    tone(7,notes[0],500);
    input[inputNumber] = NOTE_C5;
    inputNumber++;
    delay(200);
  }
  if(digitalRead(button2) == LOW){
    tone(7,notes[1],500);
    input[inputNumber] = NOTE_D5;
    inputNumber++;
    delay(200);
    }
  if(digitalRead(button3) == LOW){
    tone(7,notes[2],500);
    input[inputNumber] = NOTE_E5;
    inputNumber++;
    delay(200);
    }
  if(digitalRead(button4) == LOW){
    tone(7,notes[3],500);
    input[inputNumber] = NOTE_F5;
    inputNumber++;
    delay(200);
  }
  if(digitalRead(button5) == LOW){
    tone(7,notes[4],500);
    input[inputNumber] = NOTE_G5;
    inputNumber++;
    delay(200);
  }
    delay(100);
  }
  delay(100);  
}

void setup() {
pinMode(button1,INPUT_PULLUP);
pinMode(button2,INPUT_PULLUP);
pinMode(button3,INPUT_PULLUP);
pinMode(button4,INPUT_PULLUP);
pinMode(button5,INPUT_PULLUP);
lcd.begin(16,2);
lcd.setCursor(0,0);
lcd.print("Select a");
lcd.setCursor(0,1);
lcd.print("Difficulty!");
}

void loop() {

if(difficultyConfirm == false){
  if(digitalRead(button1) == LOW){
    difficultySelect();
    delay(200);
  }
  if(digitalRead(button2) == LOW and difficulty != 0){
    difficultyConfirm = true;
  }
}
if(difficultyConfirm == true){
    if(readyToPlay == false){
       difficultyConfirmed();
        delay(5000);
        readyToPlay = true;
    }
    if(readyToPlay == true){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Level 1:");
      whatLevel = 1;
      while(whatLevel == 1){
      switch(difficulty){
      case 1: easyLevel1(); break;
      case 2: mediumLevel1(); break;
      case 3: hardLevel1(); break;
      case 4: insaneLevel1(); break;
        }
      }
      while(whatLevel == 2){
      switch(difficulty){
      case 1: easyLevel2(); break;
      case 2: mediumLevel2(); break;
      case 3: hardLevel2(); break;
      case 4: insaneLevel2(); break;
      }
      }
      while(whatLevel == 3){
      switch(difficulty){
      case 1: easyLevel3(); break;
      case 2: mediumLevel3(); break;
      case 3: hardLevel3(); break;
      case 4: insaneLevel3(); break;
      }
     }
    }
  }
}



