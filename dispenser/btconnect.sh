#!/bin/bash

# inserisci qui il mac address del device Bluetooth
ADDRESS="00:00:00:00:00:00"

while(systemctl is-enabled bluetooth != 'enabled')
do
sleep 1
done

/usr/bin/hciconfig hci0 up
/usr/bin/hciconfig hci0 piscan
systemctl start obex

while true; do
/usr/sbin/rfkill unblock bluetooth
bluetoothctl << EOF
connect $ADDRESS
EOF
sleep 2
done
