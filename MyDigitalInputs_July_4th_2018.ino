int LED = 5;
int aButton = 9;
int bButton = 8;

void setup(){
  pinMode(LED,OUTPUT);
  pinMode(aButton,INPUT_PULLUP);
  pinMode(bButton,INPUT_PULLUP);
}

void loop(){
  if(digitalRead(aButton == LOW)){
    digitalWrite(LED,HIGH);
  }
  if(digitalRead(bButton == LOW)){
    digitalWrite(LED,LOW);
  }
}

