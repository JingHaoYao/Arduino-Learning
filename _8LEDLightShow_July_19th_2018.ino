int latchPin = 11;
int clockPin = 9;
int dataPin = 12;

byte leds = 0;

void setup() {
pinMode(latchPin,OUTPUT);
pinMode(dataPin,OUTPUT);
pinMode(clockPin,OUTPUT);

}

void switchUpdate(){
  digitalWrite(latchPin,LOW);
  shiftOut(dataPin,clockPin,LSBFIRST,leds);
  digitalWrite(latchPin,HIGH);
}

void rowFill1(){
  leds = 0;
  switchUpdate();
  for(int i = 0;i<8;i++){
    bitSet(leds,i);
    switchUpdate();
    delay(100);
  }
}

void rowUnFill1(){
  leds = 255;
  switchUpdate();
  for(int k = 0;k<8;k++){
    bitClear(leds,k);
    switchUpdate();
    delay(100);
  }
}

void rowFill2(){
  leds = 128;
  switchUpdate();
  for(int l = 7;l>=0;l--){
    bitSet(leds,l);
    switchUpdate();
    delay(100);
  }
}

void rowUnFill2() {
  leds = 255;
  switchUpdate();
  for(int n = 7;n>=0;n--){
    bitClear(leds,n);
    switchUpdate();
    delay(100);
  }
}

void loop() {
 rowFill1();
 rowUnFill1();
 rowFill2();
 rowUnFill2();
}
