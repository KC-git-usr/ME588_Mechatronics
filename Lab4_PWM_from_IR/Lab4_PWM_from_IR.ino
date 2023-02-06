/*
  Lab4_PWM_from_IR

  Arduino program to write PWM signal from
  an IR sensor

  Name: Kumar Ramesh
  PUID: 0032813975
*/

static const int inputpin_IR = A2; //input from the analog IR sensor 
static const int inputpin_Stop = 2; //input from the digital E Stop button 
static const int outpin_Motor_Dir_fwd = 7; //output to the control motor direction forward
static const int outpin_Motor_Dir_bwd = 8; //output to the control motor direction backward
static const int outpin_Motor_Speed = 3; //output to the control motor speed (PWM)
static int IR_val = 0; //initialize the IR sensor input
static bool Stop_status = false; //initialize the stop status to false
static const int Kd_fast = 1; // speed multiplier to move fast
static const float Kd_slow = 0.5f; // speed multiplier to move slow

void setup() { 
  pinMode(inputpin_IR, INPUT); 
  pinMode(inputpin_Stop, INPUT); 
  pinMode(outpin_Motor_Dir_fwd, OUTPUT);
  pinMode(outpin_Motor_Dir_bwd, OUTPUT); 
  pinMode(outpin_Motor_Speed, OUTPUT); 
} 

void loop() { 

  IR_val = analogRead(inputpin_IR); 
  Stop_status = digitalRead(inputpin_Stop);

  if(Stop_status) {
    digitalWrite(outpin_Motor_Dir_fwd, 0); // stop motor from spinning either dir
    digitalWrite(outpin_Motor_Dir_fwd, 0);
    analogWrite(outpin_Motor_Speed, 0); // set speed to 0
  } else {
      if(IR_val < 100) { // No object
        digitalWrite(outpin_Motor_Dir_fwd, 1);
        digitalWrite(outpin_Motor_Dir_bwd, 0);
        analogWrite(outpin_Motor_Speed, Kd_fast*IR_val);
      } else if((IR_val >= 100) && (IR_val < 1000)) { // object visible
        digitalWrite(outpin_Motor_Dir_fwd, 1);
        digitalWrite(outpin_Motor_Dir_bwd, 0);
        analogWrite(outpin_Motor_Speed, Kd_slow*IR_val);
      } else if(IR_val >= 1000) { // object near
        digitalWrite(outpin_Motor_Dir_fwd, 0);
        digitalWrite(outpin_Motor_Dir_bwd, 1);
        analogWrite(outpin_Motor_Speed, Kd_slow*IR_val);
      }
  }
}
