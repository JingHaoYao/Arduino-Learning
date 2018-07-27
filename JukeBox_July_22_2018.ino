
#include <pitches.h>
#include <LiquidCrystal.h>

int const buttonA = 5;
int const buttonB = 4;
int buzzer = 2;
LiquidCrystal lcdDisplay(7,8,9,10,11,12);
int songCounter = 0;
String songName[] = {"Mario Theme Song","Mario UnderWorld","Song of Storms","Jeopardy Theme","Jingle Bells","P. Caribbean", "Wind Waker Theme"};
int maxNumberSongs = 8;

void setup() {
pinMode(buttonA,INPUT_PULLUP);
pinMode(buttonB,INPUT_PULLUP);
lcdDisplay.begin(16,2);
lcdDisplay.setCursor(0,0);
lcdDisplay.print("What song do you");
lcdDisplay.setCursor(0,1);
lcdDisplay.print("want to play?");
}

void songNames(int counter){
  lcdDisplay.clear();
  lcdDisplay.setCursor(0,0);
  lcdDisplay.print("Song ");
  lcdDisplay.print(counter);
  lcdDisplay.print(":");
  lcdDisplay.setCursor(0,1);
  lcdDisplay.print(songName[counter-1]);
}

void MarioThemeSong(){
  int melody[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7, 
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0, 

  NOTE_C7, 0, 0, NOTE_G6, 
  0, 0, NOTE_E6, 0, 
  0, NOTE_A6, 0, NOTE_B6, 
  0, NOTE_AS6, NOTE_A6, 0, 

  NOTE_G6, NOTE_E7, NOTE_G7, 
  NOTE_A7, 0, NOTE_F7, NOTE_G7, 
  0, NOTE_E7, 0,NOTE_C7, 
  NOTE_D7, NOTE_B6, 0, 0,

  NOTE_C7, 0, 0, NOTE_G6, 
  0, 0, NOTE_E6, 0, 
  0, NOTE_A6, 0, NOTE_B6, 
  0, NOTE_AS6, NOTE_A6, 0, 

  NOTE_G6, NOTE_E7, NOTE_G7, 
  NOTE_A7, 0, NOTE_F7, NOTE_G7, 
  0, NOTE_E7, 0,NOTE_C7, 
  NOTE_D7, NOTE_B6, 0, 0
  };
  
  int tempo[] = {
  12, 12, 12, 12, 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12, 

  12, 12, 12, 12,
  12, 12, 12, 12, 
  12, 12, 12, 12, 
  12, 12, 12, 12, 

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  };
  
  int songDuration = sizeof(melody);
  for(int thisNote = 0;thisNote < songDuration;thisNote++){
    int noteDuration = 1000/tempo[thisNote];
    tone(buzzer,melody[thisNote],noteDuration);
    int pauseBetweenNotes = noteDuration*1.30;
    delay(pauseBetweenNotes);
    
    if(digitalRead(buttonA) == LOW or thisNote == 76){
      delay(20);
      break;
      }
    }
}

void MarioUnderworldTheme(){
  int melody[] = {
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0, NOTE_DS4, NOTE_CS4, NOTE_D4,
  NOTE_CS4, NOTE_DS4,
  NOTE_DS4, NOTE_GS3,
  NOTE_G3, NOTE_CS4,
  NOTE_C4, NOTE_FS4, NOTE_F4, NOTE_E3, NOTE_AS4, NOTE_A4,
  NOTE_GS4, NOTE_DS4, NOTE_B3,
  NOTE_AS3, NOTE_A3, NOTE_GS3,
  0, 0, 0
  };

  int tempo[] = {
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  6, 18, 18, 18,
  6, 6,
  6, 6,
  6, 6,
  18, 18, 18, 18, 18, 18,
  10, 10, 10,
  10, 10, 10,
  3, 3, 3
  };
  
int songDuration = sizeof(melody);
  for(int thisNote = 0;thisNote < songDuration;thisNote++){
    int noteDuration = 1000/tempo[thisNote];
    tone(buzzer,melody[thisNote],noteDuration);
    int pauseBetweenNotes = noteDuration*1.50;
    delay(pauseBetweenNotes);
    
    if(digitalRead(buttonA) == LOW or thisNote == 54){
      delay(20);
      break;
    }
  }
}

void SongOfStorms(){
  int melody[]{
  NOTE_D5, NOTE_F5, NOTE_D6,
  NOTE_D5, NOTE_F5, NOTE_D6,
  NOTE_E6, NOTE_F6, NOTE_E6, NOTE_F6, NOTE_E6, NOTE_C6, NOTE_A5,
  NOTE_A5, NOTE_D5, NOTE_F5, NOTE_G5, NOTE_A5,
  NOTE_A5, NOTE_D5, NOTE_F5, NOTE_G5, NOTE_E5,
  NOTE_D5, NOTE_F5, NOTE_D6,
  NOTE_D5, NOTE_F5, NOTE_D6,
  NOTE_E6, NOTE_F6, NOTE_E6, NOTE_F6, NOTE_E6, NOTE_C6, NOTE_A5,
  NOTE_A5, NOTE_D5, NOTE_F5, NOTE_G5, NOTE_A5,
  NOTE_A5, NOTE_D5, NOTE_F5, NOTE_G5, NOTE_E5 
  };

  int tempo[]{
  12, 12, 3,
  12, 12, 3,
  5, 10, 12, 12, 12, 12, 3,
  6, 6, 12, 12, 2,
  6, 6, 12, 12, 2,
  12, 12, 3,
  12, 12, 3,
  5, 10, 12, 12, 12, 12, 3,
  6, 6, 12, 12, 2,
  6, 6, 12, 12, 2
  };

int songDuration = sizeof(melody);
  for(int thisNote = 0;thisNote < songDuration;thisNote++){
    int noteDuration = 1000/tempo[thisNote];
    tone(buzzer,melody[thisNote],noteDuration);
    int pauseBetweenNotes = noteDuration*1.80;
    delay(pauseBetweenNotes);

  if(digitalRead(buttonA) == LOW or thisNote == 45){
      delay(20);
      break;
    }
  }
}

void JeopardyTheme(){
  int melody[] = {
  NOTE_C2, NOTE_F3, NOTE_C3, NOTE_A2, NOTE_A2,
  NOTE_C3, NOTE_F3, NOTE_C3,
  NOTE_C3, NOTE_F3, NOTE_C3, NOTE_F3,
  NOTE_AS3, NOTE_G3, NOTE_F3, NOTE_E3, NOTE_D3, NOTE_CS3,
  NOTE_C2, NOTE_F3, NOTE_C3, NOTE_A2, NOTE_A2, // repeat line 1 and 2
  NOTE_C3, NOTE_F3, NOTE_C3,
  NOTE_AS3, 0, NOTE_G3, NOTE_F3,
  NOTE_E3, NOTE_D3, NOTE_CS3, NOTE_C3};

  int tempo[]{
  4, 4, 4, 8, 8,
  4, 4, 2,
  4, 4, 4, 4,
  3, 8, 8, 8, 8, 8,
  4, 4, 4, 8, 8, 
  4, 4, 2,
  4, 8, 8, 4, 4,
  4, 4, 4, 4,
  0
  };

int songDuration = sizeof(melody);
  for(int thisNote = 0;thisNote < songDuration;thisNote++){
    int noteDuration = 1000/tempo[thisNote];
    tone(buzzer,melody[thisNote],noteDuration);
    int pauseBetweenNotes = noteDuration*1.30;
    delay(pauseBetweenNotes);

  if(digitalRead(buttonA) == LOW or thisNote == 33){
      delay(20);
      break;
    }
  }
}

void JingleBells(){
  int melody[]{
  NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_G5, NOTE_C5, NOTE_D5,
  NOTE_E5,
  NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5,
  NOTE_F5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_D5, NOTE_D5, NOTE_E5,
  NOTE_D5, NOTE_G5
  };

  int tempo[]{
  8, 8, 4,
  8, 8, 4,
  8, 8, 8, 8,
  2,
  8, 8, 8, 8,
  8, 8, 8, 16, 16,
  8, 8, 8, 8,
  4, 4
  };

  int songDuration = sizeof(melody);
  for(int thisNote = 0;thisNote < songDuration;thisNote++){
    int noteDuration = 1000/tempo[thisNote];
    tone(buzzer,melody[thisNote],noteDuration);
    int pauseBetweenNotes = noteDuration*1.30;
    delay(pauseBetweenNotes);

    if(digitalRead(buttonA) == LOW or thisNote == 24){
      delay(20);
      break;
    }
  }
}

void PiratesOfTheCarribean(){
  int melody[] = {
   NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0, 
   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, 
   NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
   NOTE_A4, NOTE_G4, NOTE_A4, 0,
   
   NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0, 
   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, 
   NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
   NOTE_A4, NOTE_G4, NOTE_A4, 0,
   
   NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0, 
   NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, 0, 
   NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, 0,
   NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, 0,
   
   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, 
   NOTE_D5, NOTE_E5, NOTE_A4, 0, 
   NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, 0,
   NOTE_C5, NOTE_A4, NOTE_B4, 0,

   NOTE_A4, NOTE_A4, 
   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, 
   NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
   NOTE_A4, NOTE_G4, NOTE_A4, 0,

   NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0, 
   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, 
   NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
   NOTE_A4, NOTE_G4, NOTE_A4, 0,
   
   NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0, 
   NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, 0, 
   NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, 0,
   NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, 0,
   
   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, 
   NOTE_D5, NOTE_E5, NOTE_A4, 0, 
   NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, 0,
   NOTE_C5, NOTE_A4, NOTE_B4, 0,

   NOTE_E5, 0, 0, NOTE_F5, 0, 0,
   NOTE_E5, NOTE_E5, 0, NOTE_G5, 0, NOTE_E5, NOTE_D5, 0, 0,
   NOTE_D5, 0, 0, NOTE_C5, 0, 0,
   NOTE_B4, NOTE_C5, 0, NOTE_B4, 0, NOTE_A4,

   NOTE_E5, 0, 0, NOTE_F5, 0, 0,
   NOTE_E5, NOTE_E5, 0, NOTE_G5, 0, NOTE_E5, NOTE_D5, 0, 0,
   NOTE_D5, 0, 0, NOTE_C5, 0, 0,
   NOTE_B4, NOTE_C5, 0, NOTE_B4, 0, NOTE_A4  
  };

  int tempo[]{
  125, 125, 250, 125, 125, 
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 375, 125, 
  
  125, 125, 250, 125, 125, 
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 375, 125, 
  
  125, 125, 250, 125, 125, 
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 125, 250, 125,

  125, 125, 250, 125, 125, 
  250, 125, 250, 125, 
  125, 125, 250, 125, 125,
  125, 125, 375, 375,

  250, 125,
  
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 375, 125, 
  
  125, 125, 250, 125, 125, 
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 375, 125, 
  
  125, 125, 250, 125, 125, 
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 125, 250, 125,

  125, 125, 250, 125, 125, 
  250, 125, 250, 125, 
  125, 125, 250, 125, 125,
  125, 125, 375, 375,
 
  250, 125, 375, 250, 125, 375,
  125, 125, 125, 125, 125, 125, 125, 125, 375,
  250, 125, 375, 250, 125, 375,
  125, 125, 125, 125, 125, 500,

  250, 125, 375, 250, 125, 375,
  125, 125, 125, 125, 125, 125, 125, 125, 375,
  250, 125, 375, 250, 125, 375,
  125, 125, 125, 125, 125, 500
  };

    int songDuration = sizeof(melody);
  for(int thisNote = 0;thisNote < songDuration;thisNote++){
    int noteDuration = tempo[thisNote];
    tone(buzzer,melody[thisNote],noteDuration);
    int pauseBetweenNotes = noteDuration*1.10;
    delay(pauseBetweenNotes);

    if(digitalRead(buttonA) == LOW or thisNote == 202){
      delay(20);
      break;
    }
  }
}

void WindWakerTheme(){
  int melody[] = {
    NOTE_A5, NOTE_A5,
    NOTE_A5, NOTE_D6, NOTE_F6, NOTE_E6, NOTE_D6, NOTE_C6,
    NOTE_D6, NOTE_B5, NOTE_G5, NOTE_C6, NOTE_A5, NOTE_D6, NOTE_B5,
    NOTE_C6, NOTE_A5, NOTE_G5, NOTE_D6, NOTE_B5, NOTE_C6,
    NOTE_D6, NOTE_E6, NOTE_F6, NOTE_D6, NOTE_E6, NOTE_A5, NOTE_A5,
    NOTE_A5, NOTE_D6, NOTE_F6, NOTE_E6, NOTE_D6, NOTE_C6,
    NOTE_D6, NOTE_B5, NOTE_G5, NOTE_C6, NOTE_A5, NOTE_D6, NOTE_B5,
    NOTE_C6, NOTE_D6, NOTE_F6, NOTE_A6, NOTE_B6, NOTE_F6, NOTE_C6,
    NOTE_D6
  };

  int tempo[] = {
    4, 8,
    4, 8, 4, 8, 4, 8,
    4, 8, 4, 8, 8, 8, 8,
    4, 8, 4, 8, 4, 8,
    4, 8, 8, 8, 8, 4, 8,
    4, 8, 4, 8, 4, 8,
    4, 8, 4, 8, 8, 8, 8,
    4, 8, 4, 8, 8, 8, 8,
    2
  };
  
  int songDuration = sizeof(melody);
  for(int thisNote = 0;thisNote < songDuration;thisNote++){
    int noteDuration = 1000/tempo[thisNote];
    tone(buzzer,melody[thisNote],noteDuration);
    int pauseBetweenNotes = noteDuration*1.30;
    delay(pauseBetweenNotes);

    if(digitalRead(buttonA) == LOW or thisNote == 48){
      delay(20);
      break;
    }
  }
}

void songConfirm(int counter){
    lcdDisplay.clear();
    lcdDisplay.setCursor(0,0);
    lcdDisplay.print("Now playing:");
    lcdDisplay.setCursor(0,1);
    lcdDisplay.print(songName[counter-1]);
    switch(songCounter){
      case 1: MarioThemeSong(); break;
      case 2: MarioUnderworldTheme(); break;
      case 3: SongOfStorms(); break;
      case 4: JeopardyTheme(); break;
      case 5: JingleBells(); break;
      case 6: PiratesOfTheCarribean(); break;
      case 7: WindWakerTheme(); break;
    }
  }
  
void loop() {
  if(digitalRead(buttonA) == LOW){
    songCounter++;
    if(songCounter == maxNumberSongs){
      songCounter = 1;
    }
    songNames(songCounter);
    delay(200);
  }
  if(digitalRead(buttonB) == LOW){
      songConfirm(songCounter);
  }
}
