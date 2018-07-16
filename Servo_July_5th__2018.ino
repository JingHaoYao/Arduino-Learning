#include <Servo.h>

Servo servoBoy;
int Degree;

void setup(){
  servoBoy.attach(9);
}

void loop(){

  for(Degree = 0; Degree <= 180; Degree ++){
    servoBoy.write(Degree);
    delay(15);
  }
  for(Degree = 180; Degree >= 0; Degree -= 1){
    servoBoy.write(Degree);
    delay(15);
  }
}

