int inizio=0;
int Time=65;
int oldBpm=65;
int sensorValue=0;
int count=0;

void bpmRead(void);

void bpmRead(){
/*
   inizio=millis();
  
  for (count=0; count<5; ){
    
          sensorValue = analogRead(A0);
          if (sensorValue>530 && sensorValue<600){
          sensorValue = analogRead(A0);
                         count++;
                         digitalWrite(13,HIGH);
                         delay(100);}
  else {
                         digitalWrite(13,LOW);}
  delay(100);

  }
  
Time = millis()-inizio;
oldBpm=bpm;
bpm=300000/Time;

if (bpm<90){

if (bpm<55) bpm+=10;
}



else{bpm=random (oldBpm,80);}


bpm=(oldBpm+bpm)/2;



Serial.print("bpm:    ");
Serial.println(bpm);
Serial.println("Reading ...");

count=0;

*/

for (int count=0; count<15; count++){
oldBpm=bpm;
bpm=random (60,80);
bpm=(oldBpm+bpm)/2;
}
delay(5000);
}
