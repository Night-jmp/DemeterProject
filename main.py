import serial
from datetime import datetime
import time

def main():
	ser = serial.Serial('/dev/cu.usbmodem1421', 9600)
	outFile = open("sensordata.csv","a+")
	outFile.write("Temperature,Luminosity,Humidity,Time\n")
	i = 0
	while True:
		message = ser.readline()
		outFile.write(message.strip() + ",")
		message = ser.readline()
		outFile.write(message.strip() + ",")
		message = ser.readline()
		outFile.write(message.strip() + ",")
		outFile.write(str(datetime.now()).split()[1] + "\n")

		print(message)
main()
