//  firmware

// declare var
long long int offset=39500;
int zero=0;
int ore=0;
long long int secondi=0;


void orario (void);


void orario () {
  
  myGLCD.setFont(MediumNumbers);  
  
  if (minuti<10 ) {
                    myGLCD.printNumI(zero, 28,15);  
                    myGLCD.printNumI(minuti, 40, 15);
                  }

   if (minuti>=10 && minuti<60 ) { 
                    myGLCD.printNumI(minuti, 28, 15);
                    }
                       
  
  if (oreStampa>=24) { 
                     oreStampa=0;
                     }


  if (oreStampa<10) { 
                      myGLCD.printNumI(zero, 0, 15); 
                      myGLCD.printNumI(oreStampa, 12, 15);
                     }


  if (oreStampa>=10 && oreStampa<24) { 
                      myGLCD.printNumI(oreStampa, 0, 15);
                      }

                         myGLCD.setFont(SmallFont);  
                         myGLCD.print(":", 23, 20);
                         myGLCD.printNumI(bpm, 68, 23);
                         drawHeart();
                         myGLCD.update();


  if (ore1==oreStampa && minuti1==minuti &&  servo1State==0) {
                     servo1 = 1;
                     playMp3(ore1, minuti1);
                     servo1State = 1;
                     }
                     
  if (ore2==oreStampa && minuti2==minuti &&  servo2State==0) {
                     servo2 = 1;
                     playMp3(ore2, minuti2);
                     servo2State = 1;
                     }

  if (ore3==oreStampa && minuti3==minuti &&  servo3State==0) {
                     servo3 = 1;
                     playMp3(ore3, minuti3);
                     servo3State = 1;
                     }	

  if (ore1>=oreStampa && minuti1>minuti && servo1State==1) {
                     servo1State=0;
	}
   
  if (ore2>=oreStampa && minuti2>minuti && servo2State==1) {
                     servo2State=0;
	}

  if (ore3>=oreStampa && minuti3>minuti && servo3State==1) {
                     servo3State=0;
	}

}
