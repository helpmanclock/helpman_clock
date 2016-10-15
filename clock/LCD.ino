// LCD Nokia 5110 firmware

// Libraries Needed
#include <LCD5110_Graph.h>


LCD5110 myGLCD(7,8,9,10,11);
extern uint8_t SmallFont[];
extern uint8_t MediumNumbers[];
extern uint8_t BigNumbers[];


void setupLcd (void);

void setupLcd () {
  
    myGLCD.InitLCD();
    myGLCD.setContrast(65);  
    myGLCD.setFont(SmallFont);  
    myGLCD.print("BPM", 66, 15);
    myGLCD.printNumI(bpm, 68, 23);
    drawHeart ();
    myGLCD.update();

}


int i=69;
int j=0;
 
void drawHeart (void);
void clrHeart (void);

void drawHeart (){
    myGLCD.drawLine(i+3, j+0, i+6, j+0);
    myGLCD.drawLine(i+9, j+0, i+12, j+0);
    myGLCD.drawLine(i+2, j+1, i+7, j+1);
    myGLCD.drawLine(i+8, j+1, i+13, j+1);
    myGLCD.drawLine(i+1, j+2, i+14, j+2);
    myGLCD.drawLine(i+0, j+3, i+15, j+3);
    myGLCD.drawLine(i+0, j+4, i+15, j+4);
    myGLCD.drawLine(i+0, j+5, i+15, j+5);
    myGLCD.drawLine(i+0, j+6, i+15, j+6);
    myGLCD.drawLine(i+1, j+7, i+14, j+7);
    myGLCD.drawLine(i+2, j+8, i+13, j+8);  
    myGLCD.drawLine(i+3, j+9, i+12, j+9);  
    myGLCD.drawLine(i+4, j+10, i+11, j+10);  
    myGLCD.drawLine(i+5, j+11, i+10, j+11);  
    myGLCD.drawLine(i+6, j+12, i+9, j+12);  
    myGLCD.drawLine(i+7, j+13, i+8, j+13);
    myGLCD.update();}

void clrHeart(){

    myGLCD.clrLine(i+3, j+0, i+6, j+0);
    myGLCD.clrLine(i+9, j+0, i+12, j+0);
    myGLCD.clrLine(i+2, j+1, i+7, j+1);
    myGLCD.clrLine(i+8, j+1, i+13, j+1);
    myGLCD.clrLine(i+1, j+2, i+14, j+2);
    myGLCD.clrLine(i+0, j+3, i+15, j+3);
    myGLCD.clrLine(i+0, j+4, i+15, j+4);
    myGLCD.clrLine(i+0, j+5, i+15, j+5);
    myGLCD.clrLine(i+0, j+6, i+15, j+6);
    myGLCD.clrLine(i+1, j+7, i+14, j+7);
    myGLCD.clrLine(i+2, j+8, i+13, j+8);  
    myGLCD.clrLine(i+3, j+9, i+12, j+9);  
    myGLCD.clrLine(i+4, j+10, i+11, j+10);  
    myGLCD.clrLine(i+5, j+11, i+10, j+11);  
    myGLCD.clrLine(i+6, j+12, i+9, j+12);  
    myGLCD.clrLine(i+7, j+13, i+8, j+13);
    myGLCD.update();
}
  
