#!/bin/bash
DIR="${0%/*}"

echo "Stoppng Bluetooth AutoConnect..."
pkill watch

echo "Stopping Bluetooth Communication Manager..."
pkill btmanager -f

echo "Stopping Button Manager..."
pkill btn-servo -f

echo "Stopping LCD Manager..."
pkill lcd.py -f


