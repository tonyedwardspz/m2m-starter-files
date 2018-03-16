#include "Arduino.h"
#include "Motor.h"
#include "Sensor.h"

namespace 
{
  const byte interrupt_pin_2 = 2;
  const byte interrupt_pin_3 = 3;
  
  const auto left_motor_pin_enable = 9;
  const auto left_motor_pin_forward = 8;
  const auto left_motor_pin_reverse = 7;
  const auto right_motor_pin_enable = 10;
  const auto right_motor_pin_forward = 12;
  const auto right_motor_pin_reverse = 11;

  auto speed = 200;

  Motor left_motor{left_motor_pin_enable, left_motor_pin_forward, left_motor_pin_reverse};
  Motor right_motor{right_motor_pin_enable, right_motor_pin_forward, right_motor_pin_reverse};

  Sensor sensor{};
}

void setup()
{
  pinMode(interrupt_pin_2, INPUT_PULLUP);
  pinMode(interrupt_pin_3, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interrupt_pin_2), left_motor_pulse_interrupt, CHANGE);
  attachInterrupt(digitalPinToInterrupt(interrupt_pin_3), right_motor_pulse_interrupt, CHANGE);
  Serial.begin(115200);
}

void loop(){
//  left_motor.forward(speed);
//  right_motor.forward(speed);
//
//  delay(4000);
//
//  left_motor.reverse(speed);
//  right_motor.reverse(speed);
//
//  delay(4000);
//
//  left_motor.stop();
//  right_motor.stop();
//
  // Distance Sensor Usage
  Serial.print("\n");
  Serial.print("\nDistance Forwards: ");
  int dist_forwards = sensor.distance_forwards();
  Serial.print(dist_forwards);

  Serial.print("\nDistance Down: ");
  int dist_down = sensor.distance_down();
  Serial.print(dist_down);

  // Light Sensor Usage
  int left_light = sensor.left_light_sensor();
  int center_light = sensor.center_light_sensor();
  int right_light = sensor.right_light_sensor();

  Serial.print("\nLeft: ");
  Serial.print(left_light);
  Serial.print("\nCenter: ");
  Serial.print(center_light);
  Serial.print("\nRight: ");
  Serial.print(right_light);
  delay(1000);
 
}






void left_motor_pulse_interrupt()
{
  left_motor.get_pulse_count();
}

void right_motor_pulse_interrupt()
{
  right_motor.get_pulse_count();
}
