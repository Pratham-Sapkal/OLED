#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


const unsigned char epd_bitmap_ram [] PROGMEM = {
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x7f, 0xff, 0xff, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xe7, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xfe, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xfc, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xe1, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xc3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0x83, 0xff, 0xf9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0x82, 0xff, 0xf8, 0xff, 0xdf, 0xff, 0xff, 0xf7, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0x07, 0xff, 0xfc, 0xff, 0x8f, 0xff, 0xff, 0xfb, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0x07, 0xff, 0xfc, 0xff, 0x8f, 0xff, 0xff, 0xfb, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xfe, 0x9f, 0xff, 0xfc, 0x7f, 0x0f, 0xff, 0xff, 0xfd, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xfe, 0x07, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xfd, 0xff, 0xff, 0xf9, 0xfe, 0x03, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xfb, 0xff, 0xff, 0xf1, 0xfc, 0x03, 0xff, 0xff, 0xfe, 0x7f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xfb, 0xff, 0xff, 0xe7, 0xfc, 0x03, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf3, 0xff, 0xff, 0xcf, 0xfc, 0x03, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf7, 0xff, 0xff, 0x9f, 0xfc, 0x03, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xe7, 0xff, 0xff, 0x9f, 0xfc, 0x03, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xe1, 0xff, 0xff, 0x3f, 0xe0, 0x07, 0xff, 0xff, 0xff, 0x1f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xe1, 0xff, 0xff, 0x3f, 0xe0, 0x07, 0xff, 0xff, 0xff, 0x1f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xc0, 0xff, 0xfe, 0x7f, 0x80, 0x01, 0xff, 0xff, 0xff, 0x1f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xc0, 0x7f, 0xfe, 0x7c, 0x00, 0x00, 0x7f, 0xff, 0xfe, 0x0f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xc0, 0x7f, 0xfe, 0x7c, 0x00, 0x00, 0x07, 0xff, 0xfc, 0x0f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0x80, 0x1f, 0xfc, 0x7c, 0x00, 0x00, 0x03, 0xff, 0xfe, 0x0f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0x80, 0x07, 0xfc, 0xf8, 0x00, 0x00, 0x03, 0xff, 0xfc, 0x1f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0x80, 0x07, 0xfc, 0xf0, 0x00, 0x00, 0x01, 0xff, 0xfc, 0x17, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0x80, 0x00, 0xfc, 0xfc, 0x00, 0x00, 0x01, 0xff, 0xfc, 0x17, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0x00, 0x00, 0x7c, 0x7c, 0x00, 0x00, 0x01, 0xff, 0xfc, 0x07, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0x00, 0x00, 0x7c, 0x7c, 0x00, 0x00, 0x01, 0xff, 0xfc, 0x03, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0x00, 0x00, 0x7c, 0x78, 0x00, 0x00, 0x00, 0xff, 0xfc, 0x1b, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0x00, 0x00, 0x1e, 0x78, 0x00, 0x00, 0x00, 0xff, 0xfc, 0xfb, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0x00, 0x00, 0x3e, 0x70, 0x00, 0x00, 0x00, 0xff, 0xfb, 0xfb, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xfe, 0x00, 0x00, 0x0e, 0x70, 0x00, 0x00, 0x20, 0xff, 0xff, 0xfb, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xfe, 0x00, 0x00, 0x16, 0x30, 0x00, 0x00, 0x20, 0x7f, 0xff, 0xe3, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xfe, 0x00, 0x00, 0x02, 0x20, 0x00, 0x00, 0x70, 0x7f, 0xff, 0x81, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xfe, 0x00, 0x00, 0x03, 0x20, 0x00, 0x00, 0x70, 0x7f, 0xfc, 0x01, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xfe, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x70, 0x7f, 0xf0, 0x01, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xfe, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0xf0, 0x7f, 0xe0, 0x01, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xfe, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0xf0, 0x7f, 0xc0, 0xd1, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x64, 0x01, 0x85, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x48, 0x01, 0x01, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x40, 0x00, 0x01, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x60, 0x00, 0x01, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x28, 0x00, 0xc0, 0x01, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x24, 0x4b, 0x80, 0x01, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x24, 0x40, 0x00, 0x01, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x2c, 0x00, 0x00, 0x18, 0x40, 0x00, 0x01, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x18, 0x40, 0x00, 0x01, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x08, 0x20, 0x00, 0x01, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x0a, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x40, 0x40, 0x00, 0x0e, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x0c, 0x40, 0x00, 0x03, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x80, 0x60, 0x03, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x08, 0x07, 0xb0, 0x03, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x08, 0x80, 0x03, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff
};

void setup() {
   display.begin(SSD1306_SWITCHCAPVCC, 0x3C); 
   display.clearDisplay();
   delay(1000); 
}

void loop() {
  //oled display code
  display.clearDisplay();
  
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(40, 20);
  display.print("JAI");
  display.display();
  delay(1000);
  display.clearDisplay();
  
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(20, 20);
  display.print("SHREE");
  display.display();
  delay(1000);
  display.clearDisplay();
  
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(40, 20);
  display.print("RAM");
  display.display();
  delay(1000);
  display.clearDisplay();
  
  // Display bitmap
  display.drawBitmap(0, 0, epd_bitmap_ram , 128,64,1);
  display.display();
  delay(1000);
 
  
}
