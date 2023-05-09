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

//5 digit binary counter
int ledPins[] = {5, 6, 9, 10, 11}; // Declare an array to store the LED pins
int count = 0; // Initialize the count to 0

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 5; i++) {
    pinMode(ledPins[i], OUTPUT); // Set each LED pin as an output
  }
}

void loop() {
  // Convert the count to binary and display it on the LEDs
  for (int i = 0; i < 5; i++) {
    digitalWrite(ledPins[i], bitRead(count, i));
  }
  Serial.println(count);

  delay(1500); // Wait for 1500ms
  count++; // Increment the count

  // If the count is greater than 31, reset it to 0
  if (count > 31) {
    count = 0;
  }
}
