/*
  Lab2_Analog_Greater

  Arduino program to read in two analog values, then turn ON (or OFF) 
  an I/O pin depending on whether the first analog input is higher 
  (or lower) than the second analog input.

  Name: Kumar Ramesh
  PUID: 0032813975
*/

int analog_pin_in_1;
int analog_pin_in_2;
const int output_pin = 12;

void setup() {
  pinMode(output_pin, OUTPUT);
}

void loop() {
  analog_pin_in_1 = analogRead(A0);
  analog_pin_in_2 = analogRead(A1);
  if(analog_pin_in_1 > analog_pin_in_2) {
    digitalWrite(output_pin, HIGH);
  } else {
    digitalWrite(output_pin, LOW);
  }
}
