/*
  Lab1_Blink

  Turns an LED on for 0.5 second, then off for 1.5 second, repeatedly.

  For Arduino UNO, LED_BUILTIN is digital pin 13
  But, we're using digital pin 12 in this demo

  Name: Kumar Ramesh
  PUID: 0032813975
*/

// setting a constant pin number
const int ledPin = 12;  // the number of the LED pin

// when you push the reset or power the board button
// the setup function runs first and only once
void setup() {
  // create an output on our digital pin
  pinMode(ledPin, OUTPUT);
}

// the loop function runs after setup and is looped until power to
// the arduino is shut OFF or the reset button is pressed
void loop() {
  digitalWrite(ledPin, HIGH);  // set digital pin 12 to HIGH
  delay(500);                      // do nothing for 500ms
  digitalWrite(ledPin, LOW);   // set digital pin 12 to LOW
  delay(1500);                      // do nothing for 1500ms
}
