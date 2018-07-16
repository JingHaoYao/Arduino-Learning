#include <LedControl.h>

LedControl lc=LedControl(10,12,11,1);
unsigned long delaytime = 500;

void setup() {
lc.shutdown(0,false);
lc.setIntensity(0,8);
lc.clearDisplay(0);
}

void loop() {
int K[]={B11111111,B00011000,B00100100,B01000010,B10000001};
int i[]={B00101111,B00000000,B00000000,B00000000,B00000000};
int n[]={B00001111,B00010000,B00010000,B00001111,B00000000};
int g[]={B00111101,B00100101,B00100101,B00111111,B00000000};
int J[]={B01000000,B01000111,B01000001,B01000001,B01111111};

lc.setColumn(0,0,K[0]);
lc.setColumn(0,1,K[1]);
lc.setColumn(0,2,K[2]);
lc.setColumn(0,3,K[3]);
lc.setColumn(0,4,K[4]);
delay(delaytime);

lc.setColumn(0,0,i[0]);
lc.setColumn(0,1,i[1]);
lc.setColumn(0,2,i[2]);
lc.setColumn(0,3,i[3]);
lc.setColumn(0,4,i[4]);
delay(delaytime);
lc.setColumn(0,0,n[0]);
lc.setColumn(0,1,n[1]);
lc.setColumn(0,2,n[2]);
lc.setColumn(0,3,n[3]);
lc.setColumn(0,4,n[4]);
delay(delaytime);
lc.setColumn(0,0,g[0]);
lc.setColumn(0,1,g[1]);
lc.setColumn(0,2,g[2]);
lc.setColumn(0,3,g[3]);
lc.setColumn(0,4,g[4]);
delay(delaytime);

lc.setColumn(0,0,J[0]);
lc.setColumn(0,1,J[1]);
lc.setColumn(0,2,J[2]);
lc.setColumn(0,3,J[3]);
lc.setColumn(0,4,J[4]);
delay(delaytime);
lc.setColumn(0,0,i[0]);
lc.setColumn(0,1,i[1]);
lc.setColumn(0,2,i[2]);
lc.setColumn(0,3,i[3]);
lc.setColumn(0,4,i[4]);
delay(delaytime);

lc.setColumn(0,0,n[0]);
lc.setColumn(0,1,n[1]);
lc.setColumn(0,2,n[2]);
lc.setColumn(0,3,n[3]);
lc.setColumn(0,4,n[4]);
delay(delaytime);
lc.setColumn(0,0,g[0]);
lc.setColumn(0,1,g[1]);
lc.setColumn(0,2,g[2]);
lc.setColumn(0,3,g[3]);
lc.setColumn(0,4,g[4]);
delay(delaytime);

lc.setColumn(0,0,0);
lc.setColumn(0,1,0);
lc.setColumn(0,2,0);
lc.setColumn(0,3,0);
lc.setColumn(0,4,0);
delay(delaytime);

}

