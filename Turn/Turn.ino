#include <Adafruit_NeoPixel.h> 
#include <avr/power.h> 

#define stripPin 3 
#define stripSize 30 
int del = 10;
int del1 = 1;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(30, stripPin, NEO_GRB + NEO_KHZ800); 
void setup() 
{ 
  strip.begin(); 
  strip.show(); // Initialize all pixels to 'off' 
  //strip.setPixelColor(n, red, green, blue);
  pinMode(A1,INPUT);
  pinMode(7,INPUT_PULLUP);



 

} 


void loop() 
{
  red1();
  
}

void calcDel()
{
del1 = (analogRead(A1)/255)*del;
}


void red1()
{
  for(int i = 0; i < 30; i++)
  {
    strip.setPixelColor(i,218,40,0);
    strip.show();
    delay(del);
  }

  for(int i = 0; i < 30; i++)
  {
    strip.setPixelColor(i,0,0,0);
    strip.show();
    delay(del);
  }

  delay(400);

  
 
   
}






void black()
{
    int i = 0;
    for (i;i < 30; i=i+1)
    {
       strip.setPixelColor(i,0,0,0);
    }
    strip.show();
}




 



 

