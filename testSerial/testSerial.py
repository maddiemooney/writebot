from flask import Flask
import serial

letters = input("what to write tm: ")


connected = False

ser = serial.Serial("/dev/cu.usbmodem1421", 9600)

while not connected:
    serin = ser.read()
    connected = True

for char in letters:
    num = ord(char) - 96
    bnum = bytes([num])
    ser.write(bnum)

while ser.read() == '1':
    ser.read()

ser.close()





