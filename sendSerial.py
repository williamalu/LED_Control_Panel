import serial
import sys
import time

ser = serial.Serial('/dev/ttyACM0', 9600)
time.sleep(.1)

lightState = sys.argv[1]

ser.write(lightState)
