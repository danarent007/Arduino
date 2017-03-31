#include <Adafruit_NeoPixel.h> 
#include <avr/power.h> 

#define stripPin 3 
#define stripSize 30 
int fadeSteps = 20;
int fullRed = 255;
int fullGreen = 200;
int fullBlue = 10;
double fadeSeconds = 2.0;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(30, stripPin, NEO_GRB + NEO_KHZ800); 

void setup() 
{
  strip.begin(); 
  strip.show();
  pinMode(8,INPUT_PULLUP);
  

}

void loop() {
  // put your main code here, to run repeatedly:





  

}

int getMaxSteps(int r, int g, int b){
  if(r>g && r>b){
    return r;
  }
  else if(g>b){
    return g;
  }
  else{
    return b;
  }
}

//TODO make fad steps = to max Steps
//Fade in
void fadeIn(){
  //Set values to fraction
  for (int i = 1; i < getMaxSteps(fullRed,fullGreen,fullBlue)+1; i++){
    for (int pixel = 0; pixel < stripSize; pixel++){
      strip.setPixelColor(pixel,fullRed*(i/getMaxSteps(fullRed,fullGreen,fullBlue)),fullGreen*(i/getMaxSteps(fullRed,fullGreen,fullBlue)),fullBlue*(i/getMaxSteps(fullRed,fullGreen,fullBlue))); 
    }
    strip.show();

    //Delay (based on total time)
    delay((fadeSeconds/)*1000);
  }



  
}

