#!/usr/bin/env python

# helpman clock
# lcd

# https://software.intel.com/en-us/iot/hardware/sensors/jhd1313m1-display
# http://iotdk.intel.com/docs/master/upm/classupm_1_1_jhd1313m1.html
# http://www.seeedstudio.com/wiki/Grove_-_LCD_RGB_Backlight
# http://iotdk.intel.com/docs/master/upm/python/modules.html
# http://iotdk.intel.com/docs/master/upm/python/_modules/pyupm_i2clcd.html

import pyupm_i2clcd as lcd
import time
import random

# Initialize Jhd1313m1 at 0x3E (LCD_ADDRESS) and 0x62 (RGB_ADDRESS) 
myLcd = lcd.Jhd1313m1(0, 0x3E, 0x62)

myLcd.setCursor(0,0)

# RGB Blue
#myLcd.setColor(53, 39, 249)

# RGB Red
#myLcd.setColor(255, 0, 0)

# RGB White
#myLcd.setColor(255, 255, 255)


# RGB Random
while True:
    a = random.randint(0, 255)
    b = random.randint(0, 255)
    c = random.randint(0, 255)
    myLcd.setColor(a, b, c)
    myLcd.setCursor(0,0)
    myLcd.write('HELPMAN CLOCK')
    myLcd.setCursor(1,2)
    myLcd.write('FABLAB PALERMO')
    print "LCD"
    time.sleep(5)
