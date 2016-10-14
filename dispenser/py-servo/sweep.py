#!/usr/bin/env python

# Libraries required
from Servo import *
import time

# Create a new servo object with a reference name
myServo = Servo("First Servo")

# Attaches the servo to pin 3 in Arduino Expansion board
myServo.attach(3)

# Print servo settings
print ""
print "*** Servo Initial Settings ***"
print myServo
print ""

try:
    # Sweeps the servo motor forever
    while True:
        # From 0 to 90 degrees
        for angle in range(0,90):
            myServo.write(angle)
            time.sleep(0.005)

        # From 90 to 0 degrees
        for angle in range(90,-1,-1):
            myServo.write(angle)
            time.sleep(0.005)
            
except KeyboardInterrupt:
        print "Sweep ended."
