#!/bin/bash

# bluetooth connection script
# per velocizzare l'associazione e la connessione al device bt


# inserisci qui il mac address del device Bluetooth
ADDRESS="00:00:00:00:00:00"

# check if enabled
while(systemctl is-enabled bluetooth != 'enabled')
do
sleep 1
done

# wakeup and scan then start
/usr/bin/hciconfig hci0 up
/usr/bin/hciconfig hci0 piscan
systemctl start obex

# connect
while true; do
/usr/sbin/rfkill unblock bluetooth
bluetoothctl << EOF
connect $ADDRESS
EOF
sleep 2
done
