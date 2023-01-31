/*
  Lab3_Read_Analog_and_Display

  Arduino program for averaging filter of 5 samples.

  Name: Kumar Ramesh
  PUID: 0032813975
*/

const int numSamples = 5;
const int analog_pin_in_1 = A0;

int analogSamples[numSamples];
int index = 0;
int sum = 0;
int avg = 0;

// analog output pins
const int analog_pin_out_1 = 3;

void setup() {
  pinMode(analog_pin_in_1, INPUT);
  Serial.begin(9600);

  for(int i = 0; i < numSamples; ++i)
    analogSamples[i] = 0;
}

void loop() {

  analogSamples[index] = analogRead(analog_pin_in_1); // read the analog signal

  sum += analogSamples[index++]; // add to sum and update index

  if(index >= numSamples) // reset index if out of bounds
    index = 0;

  avg = sum / 5; // casted to integer

  analogWrite(analog_pin_out_1, avg);

  Serial.print(avg);

  delay(100);
}
