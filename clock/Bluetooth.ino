// Bluetooth Comunication Firmware

// libraries needed
#include <SoftwareSerial.h>

// servo
int servo1=0;
int servo2=0;
int servo3=0;

int servo1State=0;
int servo2State=0;
int servo3State=0;

// define pin RX and TX from Arduino to BT module
#define BT_TX_PIN A3
#define BT_RX_PIN A2

SoftwareSerial bt (BT_RX_PIN, BT_TX_PIN); 

void setupBluetooth(void);
void bluetooth(void);

void setupBluetooth() {
    pinMode(BT_RX_PIN, INPUT);
    pinMode(BT_TX_PIN, OUTPUT);
    // Initialize Bluetooth communication
    bt.begin (9600);
}


String ReadSerial(int attempts =3) {
  
      String buff = "";
      char c;
      //Serial.println("Read attempt " + String(attempts));
      if(bt.overflow()) {
        Serial.println("BT overflow");
      }
      if(bt.available()) {
        Serial.print("Data available");
      } else {
        Serial.print(".");
      }      
      while (bt.available() > 0) {                  
                  c= bt.read();                                     
                  if(c=='\n'){
                         return buff;
                   }
                   buff+=c;
                   if(buff.length() > 32){
                    Serial.println("BUFFER OVERFLOW");
                    return "";
                  }
       } 
       delay(100);
       
       if(attempts > 1) {       
        return ReadSerial(--attempts);
       } else {
        Serial.println();
        return "";
       }
}


// if we have data in the Serial Buffer send to Bluetooth Module
void bluetooth() {
  while (Serial.available() > 0) {    
    Serial.println("While Serial.available() >>> ");
    char x = Serial.read();
    Serial.println("X is >>>"+String(x));
    bt.print(x);
}

  String receive = ReadSerial();
  
  if (receive != "") {
      
   Serial.print("Received data from BT: ");
   Serial.print(receive.length());
   Serial.println(" bytes");
      
    if (receive == "P") {
      Serial.println("Pills");
      // open or close servo1
      bt.println(servo1);
      // open or close servo2
      bt.println(servo2);
      // open or close servo3
      bt.println(servo3);
      delay(1000);
      
      servo1=0;
      servo2=0;
      servo3=0;
      
    }

    if (receive == "H") {
       Serial.println("HeartBeat");
       bpm=random (60,80);
       bt.println(bpm);
     }

if (receive == "D") {
  
      Serial.println("Received data:");
      String d1=ReadSerial();
      delay(10);
      Serial.println("Received config:");
      Serial.println("D1: '"+d1+"'");
      oreStampa = d1.substring(0,2).toInt();
      minuti = d1.substring(3).toInt();
      bt.println("OK");
      
      }
     
    if(receive == "C") {
      Serial.println("Received config:");
      String c1=ReadSerial();
      delay(10);
      String c2=ReadSerial();
      delay(10);
      String c3=ReadSerial();
      delay(10);
      Serial.println("Received config:");
      Serial.println("C1: '"+c1+"'");
      if(c1 == "-") {
        ore1 = -1;
        minuti1 = -1;
      } else {
        ore1 = c1.substring(0,2).toInt();
        minuti1 = c1.substring(3).toInt();
      }


      if(c2 == "-") {
        ore2 =-1;
        minuti2=-1;
      } else {
        ore2 = c2.substring(0,2).toInt();
        minuti2 = c2.substring(3).toInt();
      }


      if(c3 == "-") {
        ore3 = -1;
        minuti3 = -1;
      } else {
        ore3 = c3.substring(0,2).toInt();
        minuti3 = c3.substring(3).toInt();
      }
      
      
      Serial.println("C2: '"+c2+"'");
      Serial.println("C3: '"+c3+"'");
      bt.println("OK");
    }

    Serial.println(">>>" + receive);  
  }

}
