#!/bin/bash

# bash wrapper to start all helpman clock code
# and log on files

DIR="${0%/*}"

# dispenser trigger button
echo "Starting Button Manager..."
nohup python -u $DIR/btn-servo.py > btn-servo.log &
sleep 1

# lcd manager
echo "Starting LCD Manager..."
nohup python -u $DIR/lcd.py > lcd.log &
sleep 1

# bluetooth comunication
echo "Starting Bluetooth Communication Manager..."
nohup python -u $DIR/btmanager.py > btmanager.log &
sleep 1

# bluetooth connection
echo "Starting Bluetooth AutoConnect..."
nohup $DIR/btconnect.sh  > btconnect.log &

