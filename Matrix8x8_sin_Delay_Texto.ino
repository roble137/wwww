#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>
int l;
int Cs = 53; 
int i=0;
int x=7;
bool Mprint=false;
bool ok=false;
unsigned long time3;

Max72xxPanel m1 = Max72xxPanel(Cs, 1, 1);

String msg = "Colombia! RARARA!  Tu Tanquilo!";
int w8 = 70; 

int esp = 1;
int ancpal = 5 + esp; 

void setup() {

  m1.setIntensity(7); 

}

void loop() {
    
    
  if (i < ancpal * msg.length() + m1.width() - 1 - esp && ok == true  && Mprint == false){
    i++;m1.fillScreen(LOW); ok=false;
    l = i / ancpal;
    x = (m1.width() - 1) - i % ancpal;
    
    if(i >= ancpal * msg.length() + m1.width() - 1 - esp){i=0;}
    }
 
    if ( x + ancpal - esp >= 0 && l >= 0 && ok == false && Mprint == false) {
      if ( l < msg.length() ) {
        m1.drawChar(x, 1, msg[l], HIGH, LOW, 1);
      }

      l--;
      x -= ancpal;
    }
    else if(Mprint == false) {
    ok=true; time1=millis(); Mprint=true;m1.write();}
     
        
        
   if(millis() - time1 >= w8 && ok ==true && Mprint==true){
   Mprint=false;}
  
}

