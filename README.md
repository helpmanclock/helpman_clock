#HELPMAN CLOCK

##FABLAB PALERMO - MAKEIT INTEL CONTEST - FABLAB TOUR

###makerfaire roma 2016

####more info @
_http://www.instructables.com/id/HELPMAN-CLOCK/?ALLSTEPS_


Il progetto è composto da due parti

**HELPMAN CLOCK**
Il codice si trova nella directory clock
Firmware per Arduino Nano + LCD Nokia5110 + HC05 + DFplayer MiniMP3


**HELPMAN DISPENSER**
Il codice si trova nella directory dispenser
Python script per Intel Edison
Bash script wrapper da inserire sul crontab @reboot


**HELPMAN ANDROID APP**
Il codice si trova nella directory android_app \n
creata con App Inventor http://appinventor.mit.edu/explore/


**IMPORTANTE!!!**  Customizzare prima dell'uso \n
dispenser/btconnect.sh AND dispenser/btdisconnect.sh \n
Inserisci qui dentro il mac address del device bluetooth \n 
ADDRESS="00:00:00:00:00:00"


dispenser/readconfig.py AND savedata.py
Inserisci qui l'url dello spreadsheet google
url="https://docs.google.com/spreadsheets/blablabla"


Lo stesso URL va configurato all'interno dell'APP helpman clock per ANDROID
tramite le opzioni di configurazione.
