#include <Arduino.h>
#include "ServoEasing.hpp"

ServoEasing base; 
ServoEasing low_arm;
ServoEasing high_arm;
ServoEasing actuator;


#define pin_base 5
#define pin_low_arm 3
#define pin_high_arm 10
#define pin_actuator 9

#define speed_delay 20

#define base_inital_pos 120
#define low_arm_inital_pos 110
#define high_arm_inital_pos 100
#define actuator_inital_pos 0

#define high_arm_max_pos 170
#define high_arm_min_pos 120
#define low_arm_max_pos 110
#define low_arm_min_pos 40 


int base_pos, low_arm_pos, high_arm_pos, actuator_pos;

float high_arm_pos_smooth,high_arm_pos_smooth_prev ;

unsigned long currentMillis;
long previousMillis = 0;    // set up timers
unsigned long interval = 5;        // time constant for timer

int stepFlag = 0;
long previousStepMillis = 0;


void setup() {

  Serial.begin(9600);


  Serial.println(F("Attach servo at pin " STR(pin_high_arm)));
  high_arm.attach(pin_high_arm,170);
  low_arm.attach(pin_low_arm, 40);
  actuator.attach(pin_actuator, 180);
  base.attach(pin_base, 180);
  

  delay(500); // Wait for servo to reach start position.
}


void loop() {
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

  Serial.println(F("Move to 135 degree with 40 degree per second blocking"));
  high_arm.startEaseTo(high_arm_max_pos, 30, START_UPDATE_BY_INTERRUPT); 
  actuator.startEaseTo(180, 20, START_UPDATE_BY_INTERRUPT); 
  delay(5000);
  Serial.println(F("Move to 45 degree  with 40 degree per second blocking"));
  high_arm.startEaseTo(high_arm_min_pos, 30, START_UPDATE_BY_INTERRUPT); 
  actuator.startEaseTo(0, 60, START_UPDATE_BY_INTERRUPT); 
  delay(5000);


}
