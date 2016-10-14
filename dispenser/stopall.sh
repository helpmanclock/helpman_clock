#!/bin/bash

# stop all helpman clock processes

DIR="${0%/*}"

# bluetooth connection
echo "Stoppng Bluetooth AutoConnect..."
pkill watch

# bluetooth manager
echo "Stopping Bluetooth Communication Manager..."
pkill btmanager -f

# dispenser button manager
echo "Stopping Button Manager..."
pkill btn-servo -f

# lcd manager
echo "Stopping LCD Manager..."
pkill lcd.py -f


