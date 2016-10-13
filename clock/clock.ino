int ore1=-1;
int ore2=-1;
int ore3=-1;

int minuti1=-1;
int minuti2=-1;
int minuti3=-1;


int oreStampa=0;
int minuti=0;

int bpm=65;

int x=0;



void setup () {
  
  Serial.begin (9600);
  setupBluetooth();
  
  pinMode(13, OUTPUT);
  setupMp3();
  setupLcd();

}





void loop () {

orario();

bluetooth();  
   }
   

