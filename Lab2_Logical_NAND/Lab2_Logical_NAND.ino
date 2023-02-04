/*
  Lab2_Logical_NAND

  Arduino program to emulate a Logical NAND

  Name: Kumar Ramesh
  PUID: 0032813975
*/

static const int d_pin_in_1 = 2;
static const int d_pin_in_2 = 3; 
static const int d_pin_out_1 = 4;

void setup() { 
  pinMode(d_pin_out_1, OUTPUT); 
} 

void loop() { 
  int A = digitalRead(d_pin_in_1);
  int B = digitalRead(d_pin_in_2);
  int Z = !(A && B);
  digitalWrite(d_pin_out_1, Z); 
  delay(1000);
}

