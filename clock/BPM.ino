// BPM firmware

// declare variables
int inizio=0;
int Time=65;
int oldBpm=65;
int sensorValue=0;
int count=0;

void bpmRead(void);

// main loop
void bpmRead() {

	for (int count=0; count<15; count++) {
	oldBpm=bpm;
	bpm=random (60,80);
	bpm=(oldBpm+bpm)/2;
	}
	delay(5000);
}
