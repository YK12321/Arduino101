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

 
//3 led Blink program with delays
//Blink red x5 slow
//Blink green x10 fast
//Blink blue x15 really slow
#define REDLEDPIN 9
#define GREENLEDPIN 10
#define BLUELEDPIN 11
int slowDelay = 500; //in ms
int fastDelay = 100; //in ms
int reallySlowDelay = 1000; //in ms
bool programComplete = false; //Prevents wasting electricity on lights, by preventing them from turning on again after program execution
int redFlashes = 5;
int greenFlashes = 10;
int blueFlashes = 15;

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
    while(i<redFlashes){
      blinkRed(slowDelay);
      i++;
    }
    while(i<redFlashes+greenFlashes&&i>=redFlashes){
      blinkGreen(fastDelay);
      i++;
    }
    while(i<redFlashes+greenFlashes+blueFlashes&&i>=redFlashes+greenFlashes){
      blinkBlue(reallySlowDelay);
      i++;
    }
  }
}

void blink(int pin, int delayMs){
  digitalWrite(pin, HIGH);
  delay(delayMs);
  digitalWrite(pin, LOW);
  delay(delayMs);
}

void blink(int pin, int intensity, int delayMs){
  analogWrite(pin, intensity);
  delay(delayMs);
  analogWrite(pin, 0);
  delay(delayMs);
}

void blink(String color, int delayMs){
  if(color == "red"){
    blinkRed(delayMs);
  }
  else if(color == "green"){
    blinkGreen(delayMs);
  }
  else if(color == "blue"){
    blinkBlue(delayMs);
  }
}

void blink(String color, int intensity, int delayMs){
  if(color == "red"){
    analogWrite(REDLEDPIN, intensity);
    delay(delayMs);
    analogWrite(REDLEDPIN, 0);
    delay(delayMs);
  }
  else if(color == "green"){
    analogWrite(GREENLEDPIN, intensity);
    delay(delayMs);
    analogWrite(GREENLEDPIN, 0);
    delay(delayMs);
  }
  else if(color == "blue"){
    analogWrite(BLUELEDPIN, intensity);
    delay(delayMs);
    analogWrite(BLUELEDPIN, 0);
    delay(delayMs);
  }
}

void blinkRed(int delayMs){
  blink(REDLEDPIN, delayMs);
}

void blinkGreen(int delayMs){
  blink(GREENLEDPIN, delayMs);
}

void blinkBlue(int delayMs){
  blink(BLUELEDPIN, delayMs);
}
