
#
#
#
#

import RPi.GPIO as GPIO
import os

# step 1 - Init Broadcom chip and use broadcom numbering
GPIO.setmode(GPIO.BCM)

# step 2 - Make pin input/output
GPIO.setup(21, GPIO.OUT)

# here we make the pin an input and set the internal resitor of the RPi to pull-down i.e. we supply a +voltage 
GPIO.setup(20, GPIO.IN, pull_up_down = GPIO.PUD_DOWN)	

# step 3 - Set pin high or low --> to ATtiny GPIO ports
GPIO.output(21, GPIO.HIGH)


def power_down(channel):

	print("The system is powering down!")
	os.system("sudo shutdown -h now")
	# when the device turns gpio pin 20 goes low and the ATtiny microcontroller turns off the device via it's relay

# add the event to a thread and set the callback function
GPIO.add_event_detect(20, GPIO.RISING, callback = power_down, bouncetime = 300)

# Any old loop
while True:


	a = 23
