#include <Arduino.h>
#include <Servo.h>

Servo base; 
Servo low_arm;
Servo high_arm;
Servo actuator;


#define pin_base 3
#define pin_low_arm 5
#define pin_high_arm 10
#define pin_actuator 9

#define speed_delay 20

#define base_inital_pos 120
#define low_arm_inital_pos 110
#define high_arm_inital_pos 100
#define actuator_inital_pos 0

#define high_arm_max_pos 95
#define high_arm_min_pos 40 

int base_pos, low_arm_pos, high_arm_pos, actuator_pos;

float high_arm_pos_smooth,high_arm_pos_smooth_prev ;

unsigned long currentMillis;
long previousMillis = 0;    // set up timers
unsigned long interval = 5;        // time constant for timer

int stepFlag = 0;
long previousStepMillis = 0;


void setup() {
  //setup pins of servo motors 
  //base.attach(pin_base);
  //low_arm.attach(pin_low_arm);
  high_arm.attach(pin_high_arm);
  //actuator.attach(pin_actuator);

  // setup pos servos 
  //base.write(base_inital_pos);
  //low_arm.write(low_arm_inital_pos);
  //high_arm.write(high_arm_inital_pos);
  //actuator.write(actuator_inital_pos);

  base_pos = base_inital_pos;
  low_arm_pos = low_arm_inital_pos;
  high_arm_pos = high_arm_inital_pos;
  actuator_pos = actuator_inital_pos;
  Serial.begin(9600);
}


void loop() {
  int pos;
  // put your main code here, to run repeatedly:

 /*  currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {  // start 5ms timed loop  
      previousMillis = currentMillis;
      if (stepFlag == 0 && currentMillis - previousStepMillis > 5000) {
        high_arm_pos = high_arm_max_pos;
        stepFlag = 1;           
        previousStepMillis = currentMillis;
      }
      else if (stepFlag == 1 && currentMillis - previousStepMillis > 5000) {
        high_arm_pos = high_arm_min_pos;
        stepFlag = 0;           
        previousStepMillis = currentMillis;
      }
  }


  high_arm_pos_smooth = (high_arm_pos * 0.03) + (high_arm_pos_smooth_prev * 0.97);
  high_arm_pos_smooth_prev = high_arm_pos_smooth;

  Serial.println(high_arm_pos_smooth);
  high_arm.write(high_arm_pos_smooth); */





}
