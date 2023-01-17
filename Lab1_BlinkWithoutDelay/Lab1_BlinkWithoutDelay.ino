/*
  Lab1_BlinkWithoutDelay

  Turns on and off a light emitting diode (LED) connected to a digital pin,
  without using the delay() function. This means that other code can run at the
  same time without being interrupted by the LED code.

  Name: Kumar Ramesh
  PUID: 0032813975
*/

// setting a constant pin number
const int ledPin = 12;  // the number of the LED pin

int ledState = LOW;  // ledState used to set the LED

// use "unsigned long" for variables that store time
unsigned long previousMillis = 0;  // will store last time LED was updated

const long on_interval = 500;  // duration to keep ledPin ON
const long off_interval = 1500;  // duration to keep ledPin OFF

void setup() {
  // create an output on our digital pin
  pinMode(ledPin, OUTPUT);
}

// the loop function runs after setup and is looped until power to
// the arduino is shut OFF or the reset button is pressed
void loop() {
  // record the current time since Arduino powered ON
  unsigned long currentMillis = millis();

  // calc diff b/w current time and last time LED state was changed
  if (currentMillis - previousMillis >= on_interval) {
    if (ledState == HIGH) {
      // update last time LED state was changed
      previousMillis = currentMillis;
      ledState = LOW;
      // command to set ledPin HIGH or LOW
      digitalWrite(ledPin, ledState);
    }
  }
  if (currentMillis - previousMillis >= off_interval) {
    if (ledState == LOW) {
      // update last time LED state was changed
      previousMillis = currentMillis;
      ledState = HIGH;
      // command to set ledPin HIGH or LOW
      digitalWrite(ledPin, ledState);
    }
  }
}
