/*
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 *  Author: YK
 *
 *  If you use or modify this program, please give credit to the author
 *  where necessary, and include this copyright notice.
 */

//Program to turn on green led if photoresistor detects room is illuminated, if photoresistor detects room isn't illuminated, turn on red led
const int photoPin = A0; // analog input pin connected to photoresistor
const int greenLedPin = 9; //output pin for green led (turns on if room is illuminated)
const int redLedPin = 10; //output pin for red led (turnd on if room isn't illuminated)
const int threshold = 10000; // threshold resistance value in ohms
bool roomLit = false; // variable to keep track of room's previous state

void setup() {
  Serial.begin(9600); //try to initialize serial communication
  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  delay(1000);
}

void loop() {
  int sensorValue = analogRead(photoPin); // read analog value from photoresistor
  float resistance = (1023.0 - sensorValue) * 10000.0 / sensorValue; // calculate resistance in ohms

  // check if room is illuminated or not
  if (resistance < threshold) {
    if (roomLit) { // room just became dark
      Serial.println("Room is dark");
      digitalWrite(greenLedPin, LOW);
      digitalWrite(redLedPin, HIGH);
      roomLit = false;
    }
  } else {
    if (!roomLit) { // room just became illuminated
      Serial.println("Room is illuminated");
      digitalWrite(redLedPin, LOW);
      digitalWrite(greenLedPin, HIGH);
      roomLit = true;
    }
  }

  delay(100); // wait for 100ms before reading again
}
