#!/usr/bin/env python

# trigger button for helpman dispenser
# [to refill dispenser, for example]

# Libraries required
import time
import sys
import mraa
import os

# servo physical config
b = mraa.Gpio(8)
b.dir(mraa.DIR_IN)

servoOpen=False

# main loop
while True:
	btnStatus=b.read()
	if btnStatus == 1:
		if servoOpen == True:
			os.system(os.getcwd() + "/py-servo/servo.py 5")
			servoOpen=False

		else:
			os.system(os.getcwd() + "/py-servo/servo.py 4")
			servoOpen=True

	time.sleep(0.3)
