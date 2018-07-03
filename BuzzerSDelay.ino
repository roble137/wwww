int beep(unsigned char pausa){
  analogWrite(7,277);
  delay(pausa);
  analogWrite(7,0);
  delay(pausa);
}

int timmer(int pausa){
 unsigned long Millis=millis();
 
  
}
int push;
int c1;
int c=0;
bool coff =false;
unsigned long time1=millis;

void setup() {
  // put your setup code here, to run once:
  pinMode(30,OUTPUT);
  pinMode(31,OUTPUT);
  pinMode(32,OUTPUT);
  pinMode(33,OUTPUT);
  pinMode(2,INPUT_PULLUP);
  pinMode(7,OUTPUT);
  beep(50);
  beep(50);
  beep(50);
  beep(50);
  }

void loop() {
  // put your main code here, to run repeatedly:
  push=digitalRead(2);
  if(push==0){
    time1=millis();
    while(true){
      
if(c==0 && coff == false){
analogWrite(7,277);
RGBon();}
if((millis() - time1 )>= 100 && c==0 && coff==false){
analogWrite(7,0);
coff=!coff;
RGBoff();
time1=millis();}
if((millis() - time1 )>= 350 && c==0 && coff==true){
c++;
coff=!coff;
time1=millis();}

if(c==1 && coff==false){
analogWrite(7,277);
RGBon();}
if((millis() - time1 ) >= 100 && c==1&& coff==false){
analogWrite(7,0);
RGBoff();
coff=!coff;
time1=millis();}
if((millis() - time1 )>= 350 && c==1 && coff==true){
c++;
coff=!coff;
time1=millis();}

if(c==2 && coff==false){
analogWrite(7,277);
RGBon();}
if(millis() - time1 >= 100 && c==2 && coff==false){
analogWrite(7,0);
coff=!coff;
time1=millis();}
if((millis() - time1 )>= 150 && c==2 && coff==true){
c++;
coff=!coff;
time1=millis();}

if(c==3 && coff==false ){
analogWrite(7,277);
RGBon();}
if(millis() - time1 >= 100 && c==3 && coff==false){
analogWrite(7,0);
RGBoff();
coff=!coff;
time1=millis();}
if((millis() - time1 )>= 150 && c==3 && coff==true){
c++;
coff=!coff;
time1=millis();}

if(c==4 && coff==false){
analogWrite(7,277);
RGBon();}
if(millis() - time1 >= 100 && c==4 && coff==false){
analogWrite(7,0);
RGBoff();
coff=!coff;
time1=millis();}
if((millis() - time1 )>= 350 && c==4 && coff==true){
c=0;
coff=!coff;
time1=millis();}

}}
}

void RGBon(){
     analogWrite(30,255);
     analogWrite(31,255);
     analogWrite(32,255);
     analogWrite(33,255);
}
void RGBoff(){
     analogWrite(30,0);
     analogWrite(31,0);
     analogWrite(32,0);
     analogWrite(33,0);
     
}


