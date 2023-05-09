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

//Program to that change the brightness of an LED in three different levels of intensity
int led = 9;         // the PWM pin the LED is attached to
int brightness = 0;  // how bright the LED is
int dimLevel = 255/9;  // how many points to fade the LED by
int intermediateLevel = 255/2;
int brightLevel = 255;
int superFastDelay = 10;
int superLongDelay = 5000;
int counter = 0;

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // set the brightness of pin 9:
if(counter%3==0){
  brightness=dimLevel;
} else if(counter%3==1){
  brightness=intermediateLevel;
} else if(counter%3==2){
  brightness=brightLevel;
} 
  analogWrite(led, brightness);


  // wait for 5 seconds to change brightness
  delay(superLongDelay);
  counter++;
}
