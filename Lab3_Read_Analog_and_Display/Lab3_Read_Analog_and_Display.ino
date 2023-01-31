/*
  Lab3_Read_Analog_and_Display

  Arduino program to read an analog voltage, display the 
  value using the Serial Monitor, and output the same 
  voltage using PWM. 

  Name: Kumar Ramesh
  PUID: 0032813975
*/

const int analog_pin_in_1 = A1;
const int analog_pin_out_1 = 3;

void setup() {
  pinMode(analog_pin_in_1, INPUT);
  pinMode(analog_pin_out_1, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int val;
  val = analogRead(analog_pin_in_1);
  Serial.print(val);
  analogWrite(analog_pin_out_1, val/4);
  delay(100);
}
