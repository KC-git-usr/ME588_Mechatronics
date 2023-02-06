/*
  Lab4_IR_Sensor_LED

  Arduino program to read IR sensor and switch LED ON
  if object detected

  Name: Kumar Ramesh
  PUID: 0032813975
*/

int IRSensor=2; // Connect the IR sensor to PIN 2 
int LED=13; // Connect LED to PIN 13 

void setup() { 
  pinMode(IRSensor, INPUT); // Sensor PIN INPUT 
  pinMode(LED, OUTPUT); // Led PIN OUTPUT 
} 

void loop() { 
  int statusSensor = digitalRead(IRSensor); 
  if(statusSensor == 1) {
    digitalWrite(LED, HIGH); // LED High 
  } else { 
    digitalWrite(LED, LOW); // LED LOW 
  }
}
