void setLED(int pixel, uint32_t color){
  pixels.setPixelColor(pixel, color); 
}

void setPIXELS(uint32_t color0, uint32_t color1, uint32_t color2, uint32_t color3){
  setLED(0,color0);
  setLED(1,color1);                
  setLED(2,color2);
  setLED(3,color3);  
}
