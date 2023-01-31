/*
  Lab3_Median_Average

  Arduino program for median filter of 3 samples.

  Name: Kumar Ramesh
  PUID: 0032813975
*/

const int numSamples = 3;
const int analog_pin_in_1 = A0;

int analogSamples[numSamples];
int index = 0;
int median = 0;

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

  index += 1; // update index

  if(index == 1)
    median = analogSamples[index]; // store median

  if(index >= (numSamples - 1)) // reset index if out of bounds
    index = 0;

  analogWrite(analog_pin_out_1, median);

  Serial.print(median);

  delay(100);
}
