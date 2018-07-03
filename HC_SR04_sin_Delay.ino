
int medida;
int ultra=15;
int eco=14;
int dura;
int distancia;
int dist;
bool distOk= false;
int tomas=0;
int c1=0;
unsigned long time1;
void setup() {
  // put your setup code here, to run once:
 
Serial.begin(9600);
pinMode(ultra,OUTPUT);
pinMode(eco,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  while(true){
  time1=micros();
  if(micros-time1>=10 && c1== 0){
  digitalWrite(ultra,LOW);
  c1++;
  time1=micros();}
  
  if(micros-time1>=10 && c1== 1){
  digitalWrite(ultra,HIGH);
  c1++;
  time1=micros();}
  
    if(micros-time1>=20 && c1== 2){
  digitalWrite(ultra,LOW);
  c1=0;tomas++;
  dura=pulseIn(eco,HIGH);
  distancia=int(dura/58);
  distancia=(0.9775*distancia)-0.2461;
  if(tomas<=10){dist+=distancia;}
  if(tomas==10){dist=dist/10; distOk=true;tomas=0;}
    }
 if(distOk==true){ 
 Serial.print("DIS: ");Serial.println(distancia);
 distOk=false;
  }
  }
 }
