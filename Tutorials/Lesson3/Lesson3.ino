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

//3 led Blink program
//Blink red x5
//Blink green x10
//Blink blue x15
#define REDLEDPIN 8
#define GREENLEDPIN 9
#define BLUELEDPIN 10
bool programComplete = false;
void setup() {
  // put your setup code here, to run once:
  pinMode(REDLEDPIN, OUTPUT);
  pinMode(GREENLEDPIN, OUTPUT);
  pinMode(BLUELEDPIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int i = 0;
  if(!programComplete){
    programComplete=true;
    while(i<5){
      blinkRed();
      i++;
    }
    while(i<15&&i>=5){
      blinkGreen();
      i++;
    }
    while(i<30&&i>=15){
      blinkBlue();
      i++;
    }
  }

}
void blinkRed(){
    digitalWrite(REDLEDPIN,HIGH);
    delay(500);
    digitalWrite(REDLEDPIN,LOW);
    delay(500);
}
void blinkGreen(){
    digitalWrite(GREENLEDPIN,HIGH);
    delay(500);
    digitalWrite(GREENLEDPIN,LOW);
    delay(500);
}
void blinkBlue(){
    digitalWrite(BLUELEDPIN,HIGH);
    delay(500);
    digitalWrite(BLUELEDPIN,LOW);
    delay(500);
}
