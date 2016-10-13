#!/bin/bash
ADDRESS="00:0:00:00:00:00"


rfkill unblock bluetooth
bluetoothctl << EOF
disconnect $ADDRESS
EOF

