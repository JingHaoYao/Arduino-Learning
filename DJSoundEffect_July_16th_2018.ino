#include <LedControl.h>

LedControl djBoard = LedControl(10,12,11,1);
long const delayTime1 = 200;
long const delayTime2 = 50;

void setup() {
  
djBoard.shutdown(0,false);
djBoard.setIntensity(0,8);
djBoard.clearDisplay(0);
}

void randomBars() {
djBoard.clearDisplay(0);
byte Column1[] = {B00011111,B00000111,B01111111,B00000001};
byte Column2[] = {B00111111,B01111111,B00001111,B00001111};
byte Column3[] = {B01111111,B00000011,B00000001,B00111111};
byte Column4[] = {B00001111,B00000001,B00011111,B11111111};

 for(int i = 0;i < 3;i++){
 djBoard.setColumn(0,0,Column1[i]);
 djBoard.setColumn(0,1,Column2[i]);
 djBoard.setColumn(0,2,Column3[i]);
 djBoard.setColumn(0,3,Column4[i]);
 djBoard.setColumn(0,4,Column1[i]);
 djBoard.setColumn(0,5,Column2[i]);
 djBoard.setColumn(0,6,Column3[i]);
 djBoard.setColumn(0,7,Column4[i]);
 delay(delayTime1);
 }
}

void fillUp() {
  djBoard.clearDisplay(0);
  int rowLight = 0;
  int columnLight = 0;
  
while(columnLight < 8){
   for (int row = 0;row < 8;row++){
   djBoard.setLed(0,rowLight,columnLight,true);
   rowLight++;
   delay(delayTime2);
   }
   columnLight++;
   rowLight = 0;
   delay(delayTime2);
  }
}

void rowstrobeLight(){
  djBoard.clearDisplay(0);
  byte RowLight[4] = {B00011000,B00100100,B01000010,B10000001};
  
  for (int g = 0; g < 8; g++){
    int h = 0;
    delay(50);
    for(int f = 0;f<4;f++){
    djBoard.setRow(0,g,RowLight[h]);
    delay(50);
    djBoard.clearDisplay(0);
    delay(50);
    h++;
    }
  }
}

void crossstrobeLight(){
  djBoard.clearDisplay(0);
  byte RowLight[4] = {B00011000,B00100100,B01000010,B10000001};
  int j = 0;
  int k = 4;
  int z = 3;
  for (int p = 0;p<4;p++){
    djBoard.clearDisplay(0);
    djBoard.setRow(0,k,RowLight[j]);
    djBoard.setRow(0,z,RowLight[j]);
    k++;
    z--;
    j++;
    delay(50);
    djBoard.clearDisplay(0);
    delay(50);
    
  }
  k = 7;
  z = 0;
  j = 3;
  for(int m = 0;m<4;m++){
    djBoard.clearDisplay(0);
    djBoard.setRow(0,k,RowLight[j]);
    djBoard.setRow(0,z,RowLight[j]);
    k--;
    z++;
    j--;
    delay(50);
    djBoard.clearDisplay(0);
    delay(50);
  }
}


void loop() {
randomBars();
randomBars();
randomBars();
fillUp();
rowstrobeLight();
crossstrobeLight();
crossstrobeLight();
crossstrobeLight();
}
