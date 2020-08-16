#include "U8glib.h"
U8GLIB_SH1106_128X64 u8g(13, 8,9,10,11); 
void drawone();
void drawtwo();
void drawthree();
void drawfour();
void drawfive();

const int pageCount = 5;
int p;
void (*Page[pageCount])() = { drawone, drawtwo,drawthree,drawfour,drawfive};
int transitTime [pageCount] = { 500, 500,500,500,500};


void setup(void) {
  u8g.setFont(u8g_font_unifont);
  u8g.setRot180();
  u8g.setColorIndex(1);
  p = 0;
  Serial.begin(9600);
}

void loop(void) {
  u8g.firstPage();
  do {  
    (*Page[p])();
  } while( u8g.nextPage() );
  delay(transitTime[p]);
  p = p+1;
  if (p == pageCount)
    p = 0;
}
void drawone() {
  u8g.setFont(u8g_font_unifont);
  u8g.setFontPosTop();
  u8g.setPrintPos(0, 1);
  u8g.print("Eysan");
}

void drawtwo() {
  u8g.setPrintPos(88, 1);
  u8g.print("Eysan");
  return 0; 
}

void drawthree() {
  u8g.setPrintPos(0, 44);
  u8g.print("Eysan");
  return 0; 
}
void drawfour() {
  u8g.setPrintPos(88,44);
  u8g.print("Eysan");
  return 0; 
}
void drawfive() {
  u8g.setPrintPos(44, 22);
  u8g.print("Eysan");
  return 0; 
}
