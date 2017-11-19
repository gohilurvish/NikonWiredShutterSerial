# Control Wired Shutter of Nikon camera using Arduino
This is a simple arduino program for controlling wired shutter using serial for Nikon cameras (Tested with D5200).

## Cable
A cable similar to this is needed
https://www.amazon.in/Neewer-Photography-Accessories-2-5mm-N3-Control/dp/B00OHDARXG/ref=sr_1_11?ie=UTF8&qid=1511087456&sr=8-11&keywords=nikon+shutter+2.5mm

One end of the cable (the rectangle end) will go in the camera. The otehr end (which can be a 2.5mm/3.5mm jack or may be just open wires) will connect to following circuit.

## Circuit Diagram
![alt text](https://raw.githubusercontent.com/gohilurvish/NikonWiredShutterSerial/master/circuit.png)

From this circuit, 3 wires will go to Arduino (or any other circuit you want to use as trigger)

## Connection to Arduino
Circuit Side      Arduino Side
Ground            Ground
Focus             A1 or any one GPIO (even Analog ping will do)
Shutter           A2 or any one GPIO other then one used for Focus(even Analog ping will do)

## Action
Once the hardware setup is ready...
- open the program Nikon_Shutter_Serial in Arduino IDE
- Change the following pin assignments as per your need.
```
const int focus = A1;
const int shutter = A2;
```
- Upload the program top Arduino
- Open the Serial Monitor
- Wait for the message `...Welcome to Nikon Shutter Serial...`
