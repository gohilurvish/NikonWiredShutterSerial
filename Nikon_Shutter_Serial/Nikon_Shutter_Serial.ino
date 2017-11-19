/*
 * Nikon Wired Shutter via Serial
 * Written by Urvish Gohil (gohilurvish@gmail.com)
 * Written on 19 Nov 2017
 * For Schematics and other details : https://github.com/gohilurvish/NikonWiredShutterSerial
 */

const int focus = A1;
const int shutter = A2;

void setup() {
  pinMode(focus, OUTPUT);
  pinMode(shutter, OUTPUT);
  
  digitalWrite(focus, LOW);
  digitalWrite(shutter, LOW);
  
  Serial.begin(9600);
  Serial.println("...Welcome to Nikon Shutter Serial...");
}

void loop() {
  char what = 0;
  int del = 0;
  
  while (!Serial.available());
  what = Serial.read();
  
  switch(what)
  {
    case 'f':   //focus
      digitalWrite(focus, HIGH);
      Serial.println("Set F");
      break;
      
    case 'l':   //leave focus
      digitalWrite(focus, LOW);
      Serial.println("Rel F");
      break;
      
    case 's':   //shutter press
      digitalWrite(shutter, HIGH);
      Serial.println("S down");
      break;
      
    case 'r':   //release shutter
      digitalWrite(shutter, LOW);
      Serial.println("S up");
      break;
      
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
      del = (what - '0')*100;
      Serial.print("Del");
      Serial.println(del);
      delay(del);
      break;
      
    default:
      delay(10);
  }
}
