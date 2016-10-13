#!/usr/bin/env python

# Libraries required
from Servo import *
import time
import sys

# Create a new servo object with a reference name
myServo = Servo("First Servo")

# Attaches the servo to pin 3 in Arduino Expansion board
if len(sys.argv) == 1:
	print("Please specify Servo N")
	sys.exit()

s = sys.argv[1]

if s == "1":	
	print("Activating servo 1")
	myServo.attach(6)
if s == "2":	
	print("Activating servo 2")
	myServo.attach(5)
if s == "3":	
	print("Activating servo 3")
	myServo.attach(3)
if s == "4":	
	print("Activating servo 0-open")
	myServo.attach(9)
if s == "5":	
	print("Activating servo 0-close")
	myServo.attach(9)

# Print servo settings
#print ""
#print "*** Servo Initial Settings ***"
#print myServo
#print ""

try:
    # Sweeps the servo motor forever
   # while True:
        # From 0 to 180 degrees
   if s != "5":
        for angle in range(0,90):
            myServo.write(angle)
            time.sleep(0.005)
   if s != "4":
        # From 180 to 0 degrees
        for angle in range(90,-1,-1):
            myServo.write(angle)
            time.sleep(0.005)
            
except KeyboardInterrupt:
        print "Sweep ended."
