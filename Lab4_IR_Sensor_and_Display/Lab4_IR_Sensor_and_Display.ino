/*
  Lab4_IR_Sensor_and_Display

  Arduino program to read IR sensor and display

  Name: Kumar Ramesh
  PUID: 0032813975
*/

const int ProxSensor = A2;  //PIN A2 is connected to the output of proximity sensor 
int inputVal = 0; 

void setup() { 
  pinMode(ProxSensor,INPUT);
  Serial.begin(9600);
} 

void loop() { 
  inputVal = analogRead(ProxSensor); 
  Serial.println(inputVal); 
  delay(1000); // Delay for a second
}
