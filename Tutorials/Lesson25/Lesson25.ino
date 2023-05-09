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

 
const int photoPin = A0; // analog input pin connected to photoresistor
const int threshold = 10000; // threshold resistance value in ohms
bool roomLit = false; // variable to keep track of room's previous state

void setup() {
  Serial.begin(9600); // initialize serial communication
  while(!Serial){
    delay(100);
  }
}

void loop() {
  int sensorValue = analogRead(photoPin); // read analog value from photoresistor
  float resistance = (1023.0 - sensorValue) * 10000.0 / sensorValue; // calculate resistance in ohms

  // check if room is illuminated or not
  if (resistance < threshold) {
    if (roomLit) { // room just became dark
      Serial.println("Room is dark");
      roomLit = false;
    }
  } else {
    if (!roomLit) { // room just became illuminated
      Serial.println("Room is illuminated");
      roomLit = true;
    }
  }

  delay(100); // wait for 100ms before reading again
}
