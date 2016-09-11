#include <LCD5110_Graph.h>

#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>


long long int offset=0;
int zero=0;
int ore=0;
int oreStampa=0;
int minuti=0;
long long int secondi=0;

const int analogInPin = A0;
int sensorValue = 0;
int outputValue = 0;
int x=0;

int inizio;
int fine;
int tempo;
int bpm=60;
int led = 13;
int button=11;


LCD5110 myGLCD(3,4,5,6,7);
extern uint8_t SmallFont[];
extern uint8_t MediumNumbers[];
extern uint8_t BigNumbers[];

  int buttonState = 0; 

  
void setup()
{
    Serial.begin(9600);
  myGLCD.InitLCD();
  myGLCD.setContrast(60);
  
  myGLCD.setFont(SmallFont);  
  myGLCD.print("BPM", 66, 15);
  myGLCD.printNumI(bpm, 68, 23);
  myGLCD.update();

  pinMode (led, OUTPUT);
  digitalWrite (led, LOW);
  pinMode (button, INPUT); 
  digitalWrite (button, HIGH);

  mp3_set_serial (Serial);  
  mp3_set_volume (28);
  mp3_stop();
   
}

void loop()
{
  buttonState = digitalRead(button);


if (buttonState == LOW) {

    delay (500);
    
    buttonState = digitalRead(button);

    if (buttonState == HIGH) {      
                              mp3_play (oreStampa+60);
                              delay (1500);
                              mp3_play (minuti);
                              delay (1200);
                              mp3_stop;
                              }

    else {
          while (buttonState == LOW) {
          offset+=20;
          buttonState = digitalRead(button);
          //printHours(); 
          delay(50);}
   
           }
    }
    

  myGLCD.setFont(MediumNumbers);  
  
  secondi=(millis()/1000)+offset;
  
  minuti=secondi/60;
  
  minuti= minuti-(ore *60);

  if (minuti>=60)     { 
                        ore++;
                        oreStampa++;
                       }
                       
  
  if (oreStampa>=24)  { 
                       oreStampa=0;
                       }

  
 // myGLCD.printNumI(secondi, 0, 30);

   if (minuti<10 ){  
                  myGLCD.printNumI(zero, 28, 0);  
                  myGLCD.printNumI(minuti, 40, 0);
                  }

  if (minuti>10 && minuti<60 ){ 
                  myGLCD.printNumI(minuti, 28, 0);
                  }

  if (oreStampa<10){ 
              myGLCD.printNumI(zero, 0, 0); 
              myGLCD.printNumI(oreStampa, 12, 0);
               }

  if (oreStampa>=10 && oreStampa<60){ 
               myGLCD.printNumI(oreStampa, 0, 0);
               }
  
  if (millis()%1000<500){
                         myGLCD.setFont(SmallFont);  
                         myGLCD.print(":", 23, 5);
                        
                         }

  if (millis()%1000>=500){
                          myGLCD.setFont(SmallFont);  
                          myGLCD.print(" ", 23, 5);  
                         
}
  
  
  myGLCD.update();





  sensorValue=analogRead(A0);
  outputValue = map(sensorValue, 0, 1023, 0, 255);


if (outputValue >=170){
                   digitalWrite (13,HIGH); 
                   x++;
                    drawHeart();
                   delay (350 );}

else {digitalWrite (13,LOW); clrHeart();}
                   
                  
if (x==1) {inizio=millis();}
if (x==11) {
            fine=millis(); 
            x=0;
            tempo = fine-inizio;
            bpm = 600000/tempo;
            bpm -=2;
            }

            
            myGLCD.printNumI(bpm, 68, 23);
            
  myGLCD.update();


  
}

