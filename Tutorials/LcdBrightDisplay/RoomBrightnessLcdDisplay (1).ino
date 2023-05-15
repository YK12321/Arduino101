/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalHelloWorld

*/
//Modified by YK to read "BRIGHT" in led, when bright detected by photoresistor, and "DARK" in the led when dark detected by photoresistor (in series to a 10k resistor) 
// include the library code:
#include <LiquidCrystal.h>

const int photoPin = A0;      // analog input pin connected to photoresistor
const int threshold = 10000;  // threshold resistance value in ohms
bool roomLit = false;         // variable to keep track of room's previous state
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 4, en = 6, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

void loop() {
  int sensorValue = analogRead(photoPin);                             // read analog value from photoresistor
  float resistance = (1023.0 - sensorValue) * 10000.0 / sensorValue;  // calculate resistance in ohms

  // check if room is illuminated or not
  if (resistance < threshold) {
    if (roomLit) {  // room just became dark
      lcd.clear();
      lcd.print("DARK.");
      roomLit = false;
    }
  } else {
    if (!roomLit) {  // room just became illuminated
      lcd.clear();
      lcd.print("BRIGHT!");
      roomLit = true;
    }
  }

  delay(100);  // wait for 100ms before reading again
}
