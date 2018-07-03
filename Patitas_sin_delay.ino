#include <Servo.h>

Servo servoR;
Servo servoL;
unsigned long time1;
int R=90,L=90,push;
boolean c2=false;
bool cs2=false;
int c22=0;

void setup() {
  // put your setup code here, to run once:
servoR.attach(9);
servoL.attach(10);
pinMode(2,INPUT_PULLUP);
delay(500);
servoR.write(0);
servoL.write(180);



}

void loop() {
push=digitalRead(2);
if(push == 0){
  cs2=!cs;
  c2=!c1;
  time1=millis();
}

if(c2==true && cs2==true && c22==0){
  
  if(R==150 && L==30){time1=millis();c++;c2=false;}
   servoR.write(R);
   servoL.write(L);
  if(millis()-time1 >=5 && c22==0){
   L--;R++;
  time1=millis();
 }
    }
     
    if((millis()-time1 >=1000) && c2==false){
     c1=true;time1=millis();
    }
    
if(c2==true && cs2==true && c22==1){
  
  if(R==30 && L==150){time1=millis();c22=0;}
   servoR.write(R);
  servoL.write(L);
   if(millis()-time1 >=5 && c22==1){
   L++;R--;
   time1=millis();
  }
}
}


