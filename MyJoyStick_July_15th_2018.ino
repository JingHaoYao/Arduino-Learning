
//sets pin numbers
int const joystickSwitch = 2;
int const joystickRx = 0;
int const joystickRy = 1;

void setup() {
Serial.begin(9600);
pinMode(joystickSwitch,INPUT_PULLUP);
pinMode(joystickRx,INPUT);
pinMode(joystickRy,INPUT);
}

void loop() {
int onORoff = digitalRead(joystickSwitch);
int xValue = analogRead(joystickRx);
int yValue = analogRead(joystickRy);
int xPosition;
int yPosition;

Serial.println("Switch is ");

if(onORoff == 1){
  Serial.println("OFF. ");
}
if(onORoff == 0){
  Serial.println("ON. ");
}
if(xValue > 520){
  xPosition = 1;
}
if(yValue > 531){
  yPosition = 1; 
}
if(xValue < 494){
  xPosition = 2;
}
if(yValue < 505){
  yPosition = 2;
}
if(yValue >= 505 and yValue <= 531){
  yPosition = 0;
}
if(xValue >= 494 and xValue <= 520){
  xPosition = 0;
}

Serial.println("You are in ");
Serial.print(xPosition);
Serial.print(",");
Serial.print(yPosition);
delay(2000);
}
