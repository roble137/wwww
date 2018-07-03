#include <Servo.h>

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>

//matrix
int l;
int Cs = 53; 
int i=0;
int x=7;
bool Mprint=false;
bool ok=false;
unsigned long time3;
Max72xxPanel m1 = Max72xxPanel(Cs, 1, 1);
String msg = "Colombia! RARARA!  Tu Tranquilo!";
int w8 = 70; 

int esp = 1;
int ancpal = 5 + esp;
bool msgact =false; 

// Ultrasonido
int medida;
int ultra=15;
int eco=14;
int dura;
int distancia;
int dist;
bool distOk= false;
int tomas=0;
int c5=0;
unsigned long time4;

// buzzer
int push;
int c1;
int c=0;
bool coff = false;
bool actB = false;
unsigned long time2;

//servos
Servo servoR;
Servo servoL;
unsigned long time1;
int R=90,L=90;
boolean c2=false;
bool cs2=false;
int c22=0;
bool actS = false;

//System

bool systemF= false;

void setup() {
 pinMode(ultra,OUTPUT);
pinMode(eco,INPUT);
  servoR.attach(9);
servoL.attach(10);
  pinMode(30,OUTPUT);
  pinMode(31,OUTPUT);
  pinMode(32,OUTPUT);
  pinMode(33,OUTPUT);
  pinMode(2,INPUT_PULLUP);
  pinMode(7,OUTPUT);
  servoR.write(0);
  servoL.write(180);
   m1.setIntensity(7);
  }
void loop() {
  push=digitalRead(2);
  if(push==0){
    dist=100;
     actS=!actS;
     actB=!actB;
     cs2=!cs2;
     c2=!c2;
     msgact=!msgact;
    systemF=false;
    time1=millis();
    time2=millis();
    time3=millis();
    time4=millis();
    analogWrite(7,0);
    RGBoff();
  }

  if(dist>0 && dist<50 && distOk == true && systemF == false){
    actS=!actS;
     actB=!actB;
     cs2=!cs2;
     c2=!c2;
     msgact=!msgact;
    time1=millis();
    time2=millis();
    time3=millis();
    time4=micros();
    systemF=true;}
          
if(c==0 && coff == false && actB==true){
analogWrite(7,277);
RGBon();}
if((millis() - time1 )>= 100 && c==0 && coff==false && actB==true){
analogWrite(7,0);
coff=!coff;
RGBoff();
time1=millis();}
if((millis() - time1 )>= 350 && c==0 && coff==true&& actB==true){
c++;
coff=!coff;
time1=millis();}

if(c==1 && coff==false&& actB==true){
analogWrite(7,277);
RGBon();}
if((millis() - time1 ) >= 100 && c==1&& coff==false && actB==true){
analogWrite(7,0);
RGBoff();
coff=!coff;
time1=millis();}
if((millis() - time1 )>= 350 && c==1 && coff==true && actB==true){
c++;
coff=!coff;
time1=millis();}

if(c==2 && coff==false && actB==true){
analogWrite(7,277);
RGBon();}
if(millis() - time1 >= 100 && c==2 && coff==false && actB==true){
analogWrite(7,0);
coff=!coff;
time1=millis();}
if((millis() - time1 )>= 150 && c==2 && coff==true && actB==true){
c++;
coff=!coff;
time1=millis();}

if(c==3 && coff==false && actB==true){
analogWrite(7,277);
RGBon();}
if(millis() - time1 >= 100 && c==3 && coff==false && actB==true){
analogWrite(7,0);
RGBoff();
coff=!coff;
time1=millis();}
if((millis() - time1 )>= 150 && c==3 && coff==true && actB==true){
c++;
coff=!coff;
time1=millis();}

if(c==4 && coff==false && actB==true){
analogWrite(7,277);
RGBon();}
if(millis() - time1 >= 100 && c==4 && coff==false && actB==true){
analogWrite(7,0);
RGBoff();
coff=!coff;
time1=millis();}
if((millis() - time1 )>= 350 && c==4 && coff==true && actB==true){
c=0;
coff=!coff;
time1=millis();}


// Servos
if(c2==true && cs2==true && c22==0 && actS==true){
  
  if(R==150 && L==30){time2=millis();c22++;c2=false;}
   servoR.write(R);
   servoL.write(L);
  if(millis()-time2 >=5 && c22==0){
   L--;R++;
  time2=millis();
 }
}   
     
    if((millis()-time2 >=1000) && c2==false && actS==true){
     c2=true;time2=millis();
    }
    
if(c2==true && cs2==true && c22==1 && actS==true){
  
  if(R==30 && L==150){time2=millis();c22=0;}
   servoR.write(R);
  servoL.write(L);
   if(millis()-time2 >=5 && c22==1){
   L++;R--;
   time2=millis();
  }
}

//matrix
 if (i < ancpal * msg.length() + m1.width() - 1 - esp && ok == true  && Mprint == false && msgact==true){
    i++;m1.fillScreen(LOW); ok=false;
    l = i / ancpal;
    x = (m1.width() - 1) - i % ancpal;
    
    if(i >= ancpal * msg.length() + m1.width() - 1 - esp){i=0;}
    }
 
    if ( x + ancpal - esp >= 0 && l >= 0 && ok == false && Mprint == false && msgact==true) {
      if ( l < msg.length() ) {
        m1.drawChar(x, 1, msg[l], HIGH, LOW, 1);
      }

      l--;
      x -= ancpal;
    }
    else if(Mprint == false && msgact==true) {
    ok=true; time3=millis(); Mprint=true;m1.write();}
     
        
        
   if(millis() - time3 >= w8 && ok ==true && Mprint==true && msgact==true){
   Mprint=false;}

   //Ultrasonido
if(systemF == false){
   if(micros()-time4>=10 && c5== 0){
  digitalWrite(ultra,LOW);
  c5++;
  time4=micros();}
  
  if(micros()-time4>=10 && c5== 1){
  digitalWrite(ultra,HIGH);
  c5++;
  time4=micros();}
  
    if(micros()-time4>=20 && c5== 2){
  digitalWrite(ultra,LOW);
  c5=0;tomas++;
  dura=pulseIn(eco,HIGH);
  distancia=int(dura/58);
  distancia=(0.9775*distancia)-0.2461;
  if(tomas<=10){dist+=distancia;distOk=false;}
  if(tomas==10){dist=dist/10; distOk=true;tomas=0;}
    }}
}


void RGBon(){
     analogWrite(30,140);
     analogWrite(31,140);
     analogWrite(32,140);
     analogWrite(33,140);
}
void RGBoff(){
     analogWrite(30,0);
     analogWrite(31,0);
     analogWrite(32,0);
     analogWrite(33,0);
     
}





