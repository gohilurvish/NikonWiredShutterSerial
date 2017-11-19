# Control Wired Shutter of Nikon camera using Arduino
* This is a simple arduino program for controlling wired shutter using serial for Nikon cameras (Tested with D5200).
* The aim of this program is to *try different sequence* with the cable to verify the actual use case

## Cable
A cable similar to this is needed
* https://www.amazon.in/Neewer-Photography-Accessories-2-5mm-N3-Control/dp/B00OHDARXG/ref=sr_1_11?ie=UTF8&qid=1511087456&sr=8-11&keywords=nikon+shutter+2.5mm

One end of the cable (the rectangle end) will go in the camera. The otehr end (which can be a 2.5mm/3.5mm jack or may be just open wires) will connect to following circuit.

## Circuit Diagram
![circut for connection between the cable and arduino](https://raw.githubusercontent.com/gohilurvish/NikonWiredShutterSerial/master/circuit.png)

From this circuit, 3 wires will go to Arduino (or any other circuit you want to use as trigger)

## Connection to Arduino
Circuit Side      Arduino Side
Ground            Ground
Focus             A1 or any one GPIO (even Analog ping will do)
Shutter           A2 or any one GPIO other then one used for Focus(even Analog ping will do)

## Preparation for the Action
Once the hardware setup is ready...
* open the program Nikon_Shutter_Serial in Arduino IDE
* Change the following pin assignments as per your need.
```
const int focus = A1;
const int shutter = A2;
```
* Upload the program top Arduino
* Open the Serial Monitor
* Wait for the message `...Welcome to Nikon Shutter Serial...`
* Send following commands for action (case sensitive)
  * `f` : set focus (press focus button), focusing will not work in manual focus mode
  * `l` : leave focus (release focus button)
  * `s` : press shutter button
  * `r` : release shutter button
  * `1` : delay of 100ms
  * `2` : delay of 200ms
  * .
  * .
  * .
  * `9` : delay of 900ms
  * any other charactor: delay of 10ms

## Action
* Here are some rules for shutter to work
  * In Manual focus mode
    * As soon as both focus and shutter are pressed, shutter will be release (a click will happen)
    * Though a quick release of focus and/or shutter will work (`fslr`), it may fail at times
    * The most safest option is `fs1lr` (faster option is `fs0lr` or `fs00lr`)
    * For sequencial clicks focus can be locked and only shutter can be pressed/released (`fs1r9999s1r9999s1rl`)
    * The delay between one click and other click depends on the shutter speed and the speed of memory card
  * In Auto focus mode
    * If only focus is pressed, the system will *try* to focus. Depends on AF-A/AF-S/AF-C.
    * If *AF-C Priority selection*(mostly in menu a*) is set to shutter
      * With focus pressed, shutter will be release immediately when `f` is hit (even without focus)
      * The option `fslr` may work but safe optio is `fs0lr` or `fs00lr` or `fs1lr`
    * If *AF-C Priority selection*(mostly in menu a*) is set to shutter
      * With focus pressed, shutter will NOT be release until focus is achieved
      * The option `fslr` will not work almost ever. `lr` or `r` should be only sent when click is done

* In sort, focus and release will work just like physical button (and respective physical buttons will not work when pressed via circuit)
