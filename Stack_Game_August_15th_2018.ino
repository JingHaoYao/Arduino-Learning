#include <LedControl.h>
LedControl matrix = LedControl(12,11,10,1);
int const button = 8;
int const buzzer = 7;
int shape[8][8] = {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0}
};
long lastMove = millis();
long lastMove2 = millis();
long slideDuration;
int stackPosition;
int prevStackPosition;
bool slideRight;
int slideRow;
int numBlockSlide;
bool oldVal = HIGH;
bool playing;
int stack[5][8] = {
  {B00001000,B00010000,B00100000,B00010000,B00001000,B00000100,B00001000,B00010000},
  {B00001000,B00001000,B00001000,B00001000,B00011100,B00001000,B00000000,B00000000},
  {B00100100,B00111100,B00100100,B00011000,B00000000,B00000000,B00000000,B00000000},
  {B00011100,B00000100,B00000100,B00011100,B00000000,B00000000,B00000000,B00000000},
  {B00100100,B00010100,B00001100,B00001100,B00010100,B00100100,B00000000,B00000000}
};
int a = 0;

void threeBlockSlide(){
    if(slideRight == true){
      stackPosition ++;
    }
    else if(slideRight == false){
      stackPosition --;
    }
    if(stackPosition == 6){
      slideRight = false;
    }
    else if(stackPosition == 1){
      slideRight = true;
    }
  shape[slideRow][stackPosition] = 1;
  shape[slideRow][stackPosition - 1] = 1;
  shape[slideRow][stackPosition + 1] = 1;
}

void twoBlockSlide(){
  if(slideRight == true){
    stackPosition++;
  }
  else if(slideRight == false){
    stackPosition--;
  }
  if(stackPosition == 7){
    slideRight = false;
  }
  else if(stackPosition == 1){
    slideRight = true;
  }
  shape[slideRow][stackPosition] = 1;
  shape[slideRow][stackPosition - 1] = 1;
}

void oneBlockSlide(){
  if(slideRight == true){
    stackPosition++;
  }
  else if(slideRight == false){
    stackPosition--;
  }
  if(stackPosition == 7){
    slideRight = false;
  }
  else if(stackPosition == 0){
    slideRight = true; 
  }
  shape[slideRow][stackPosition] = 1;
}

void updateMatrix(){
  for(int k = 0;k<8;k++){
      for(int a = 0;a<8;a++){
        if(shape[k][a] == 1){
          matrix.setLed(0,k,a,true);
        }
        else{
          matrix.setLed(0,k,a,false);
        }
      }
    }
}

void gameOver(){
  playing = false;
  a=0;
  matrix.clearDisplay(0);
  for(int k = 0;k<8;k++){
    for(int a = 0;a<8;a++){
        shape[a][k] = 0;
    }
  }
  updateMatrix();
  int note[] = {700, 600, 500, 400, 300, 200};
    for(int i = 0; i < 6; i++){
      tone(buzzer, note[i], 150);
      delay(200);
    }
  delay(100);
}

void youWin(){
  for(int i = 0;i<8;i++){
    matrix.clearDisplay(0);
    delay(250);
    updateMatrix();
    delay(250);
  }
  a=0;
  for(int k = 0;k<8;k++){
    for(int j = 0; j < 8; j++){
     shape[k][j] = 0;
    }
  }
  updateMatrix();
}

void setup() {
matrix.shutdown(0,false);
matrix.setIntensity(0,3);
matrix.clearDisplay(0);
pinMode(button,INPUT_PULLUP);
slideRight = true;
slideDuration = 750;
stackPosition = 1;
slideRow = 0;
numBlockSlide = 3;
playing = false;
}

void loop() {
if(playing == false){
  if((millis() - lastMove2) >= 500){
    lastMove2 = millis();
    matrix.clearDisplay(0);
    for(int i = 0;i<8;i++){
      matrix.setRow(0,i,stack[a][i]);
    }
    a++;
    if(a == 5){
      a = 0;
    }
  }
  if(digitalRead(button) == LOW){
    matrix.clearDisplay(0);
    playing = true;
    slideRight = true;
    slideDuration = 750;
    stackPosition = 1;
    slideRow = 0;
    numBlockSlide = 3;
    delay(1000);
  }
}

if(playing == true){
if(digitalRead(button) == HIGH){
 if((millis() - lastMove) >= slideDuration){
  lastMove = millis();
      for(int j = 0; j < 8; j++){
        shape[slideRow][j] = 0;
      }
      if(numBlockSlide == 3){
        threeBlockSlide();
      }
      if(numBlockSlide == 2){
        twoBlockSlide();
      }
      if(numBlockSlide == 1){
        oneBlockSlide();
      }
 }
 updateMatrix();
}

if(digitalRead(button) == LOW and oldVal == HIGH){
    if(slideRow == 0){
      prevStackPosition = stackPosition;
      tone(buzzer,400,100);
    }
    if(slideRow >= 1){
    if(numBlockSlide == 1){
      if(stackPosition == prevStackPosition){
        prevStackPosition = stackPosition;
        tone(buzzer,400,100);
      }
      else{
        gameOver();
      }
    }
    if(numBlockSlide == 2){
        if(stackPosition == prevStackPosition){
          numBlockSlide == 2;
          prevStackPosition = stackPosition;
          tone(buzzer,400,100);
        }
        else if(stackPosition == prevStackPosition+1){
          for(int j = 0; j < 8; j++){
            shape[slideRow][j] = 0;
          }
          shape[slideRow][prevStackPosition+1] = 0;
          shape[slideRow][prevStackPosition] = 1;
          numBlockSlide = 1;
          prevStackPosition = stackPosition - 1;
          tone(buzzer,400,100);
        }
        else if(stackPosition == prevStackPosition-1){
          for(int j = 0; j < 8; j++){
            shape[slideRow][j] = 0;
          }
          shape[slideRow][prevStackPosition-1] = 1;
          shape[slideRow][prevStackPosition] = 0;
          shape[slideRow][prevStackPosition-2]= 0;
          numBlockSlide = 1;
          prevStackPosition = stackPosition;
          tone(buzzer,400,100);
        }
        else{
          gameOver();
        }
      }
    
      if(numBlockSlide == 3){
        if(stackPosition == prevStackPosition){
          numBlockSlide = 3;
          prevStackPosition = stackPosition;
          tone(buzzer,400,100);
        }
        else if(stackPosition == prevStackPosition-1){
          for(int j = 0; j < 8; j++){
            shape[slideRow][j] = 0;
          }
          shape[slideRow][prevStackPosition] = 1;
          shape[slideRow][prevStackPosition+1] = 0;
          shape[slideRow][prevStackPosition-1] = 1;
          numBlockSlide = 2;
          prevStackPosition = stackPosition+1;
          tone(buzzer,400,100);
        }
        else if(stackPosition == prevStackPosition+1){
          for(int j = 0; j < 8; j++){
            shape[slideRow][j] = 0;
          }
          shape[slideRow][prevStackPosition] = 1;
          shape[slideRow][prevStackPosition+1] = 1;
          shape[slideRow][prevStackPosition-1] = 0;
          numBlockSlide = 2;
          prevStackPosition = stackPosition;
          tone(buzzer,400,100);
        }
        else if(stackPosition == prevStackPosition+2){
          for(int j = 0; j < 8; j++){
            shape[slideRow][j] = 0;
          }
          shape[slideRow][prevStackPosition] = 0;
          shape[slideRow][prevStackPosition+1] = 1;
          shape[slideRow][prevStackPosition-1] = 0;
          numBlockSlide = 1;
          prevStackPosition = stackPosition-1;
          tone(buzzer,400,100);
        }
        else if(stackPosition == prevStackPosition-2){
          for(int j = 0; j < 8; j++){
            shape[slideRow][j] = 0;
          }
          shape[slideRow][prevStackPosition] = 0;
          shape[slideRow][prevStackPosition+1] = 0;
          shape[slideRow][prevStackPosition-1] = 1;
          numBlockSlide = 1;
          prevStackPosition = stackPosition+1;
          tone(buzzer,400,100);
        }
        else{
          gameOver();
        }
     }
  }
 updateMatrix();
 delay(200);
 stackPosition = random(7);
 slideRow++;
 slideDuration = slideDuration - 85;
 if(slideRow == 8){
  youWin();
  playing = false;
 }
 }
}
}

