#!/bin/bash
DIR="${0%/*}"


echo "Starting Button Manager..."
nohup python -u $DIR/btn-servo.py > btn-servo.log &
sleep 1

echo "Starting LCD Manager..."
nohup python -u $DIR/lcd.py > lcd.log &
sleep 1

echo "Starting Bluetooth Communication Manager..."
nohup python -u $DIR/btmanager.py > btmanager.log &
sleep 1

echo "Starting Bluetooth AutoConnect..."
nohup $DIR/btconnect.sh  > btconnect.log &

