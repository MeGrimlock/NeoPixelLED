#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN            6
#define NUMPIXELS      4
#define PIN_ANALOG_IN A0

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

uint32_t red =    pixels.Color(255, 0, 0);
uint32_t orange = pixels.Color(255, 255, 0);
uint32_t green =  pixels.Color(0, 255, 0);
uint32_t blue =   pixels.Color(0, 0, 255);
uint32_t black =  pixels.Color(0, 0, 0);

int delayval = 500; // delay for half a second
int value = 0;

void setup() {  
  pixels.begin(); // This initializes the NeoPixel library.
  Serial.begin(115200);
  delay(3000);
}

void loop() {      
      Serial.print("Valor del sensor = "+String(value)+"dB ");
      Serial.print("Estado: ");
      if(value <= 20) {
        Serial.println("0. Super tranquilo.");
        setPIXELS(blue,black,black,black);
      }else if( (value > 20) && ( value <= 35) ){
        Serial.println("1. Tranquilo.");
        setPIXELS(blue,green,black,black);
      }else if( (value > 35) && ( value <= 70)) {
        Serial.println("2. Conversacion.");
        setPIXELS(blue,green,orange,black);
      }else if(value>70){
        Serial.println("3. Ruidoso.");  
        setPIXELS(blue,green,orange,red);
      }                 
      pixels.show(); // This sends the updated pixel color to the hardware.      
      if (value>80){
        value=10;
      }else{
        value++;    
      }
      delay(100);
}
