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

//Program to use voltage to do something when change in voltage is detected
const int POTENTIOMETER_PIN = A0; // the analog pin the potentiometer is connected to
float prevVoltage = 0; // previous voltage value
const float VOLTAGE_THRESHOLD = 0.01; // minimum voltage change to trigger Serial output

void setup() {
  Serial.begin(9600); // initialize serial communication at 9600 baud
  pinMode(9, OUTPUT);
}

void loop() {
  // read the voltage from the potentiometer
  float voltage = (analogRead(POTENTIOMETER_PIN) / 1023.0) * 5.0; // assuming a 5V system


analogWrite(9, (int)(voltage*255.0/5.0));
if (abs(voltage - prevVoltage) > VOLTAGE_THRESHOLD) {
//code to do anything using voltage when a change in voltage is detected
Serial.prinln("Hello world, the voltage is ");
Serial.print(voltage)
Serial.print("V");
}
prevVoltage = voltage;
delay(10);
}
