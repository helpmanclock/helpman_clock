// DFplayer MiniMP3 firmware

// Libraries Needed
#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>

// define RX and TX PIN from Arduino to MP3 Module
#define MP3_TX_PIN A5
#define MP3_RX_PIN A4
  
SoftwareSerial mp3 (MP3_RX_PIN, MP3_TX_PIN);

void setupMp3(void);

void setupMp3(){     

    pinMode(MP3_RX_PIN, INPUT);
    pinMode(MP3_TX_PIN, OUTPUT);
    
}


void playMp3(void);

void playMp3(int a, int b) {
  
  bt.end();
  
  mp3_set_serial (mp3); 
  
  // Initialize MP3 communication
  mp3.begin(9600);
  mp3_set_volume(29);
  
  mp3_play(a+60);
  delay(2000);
  mp3_play(b);
  delay(2000);
  mp3_play(100);
  
  mp3.end();
  // turn back on Bluetooth
  SoftwareSerial bt (BT_RX_PIN, BT_TX_PIN); 
  setupBluetooth();
  
}
