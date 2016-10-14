#!/bin/bash

# bluetooth disconnection handling

# inserisci qui il mac address del device Bluetooth
ADDRESS="00:0:00:00:00:00"

# disconnect
rfkill unblock bluetooth
bluetoothctl << EOF
disconnect $ADDRESS
EOF

