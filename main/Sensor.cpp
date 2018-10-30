#include <NewPing.h>
#include "Arduino.h"
#include "Sensor.h"

namespace {

}

Sensor::Sensor(){

}

float Sensor::forward()
{
  NewPing forward_sensor(forward_trigger, forward_echo, max_distance);
  return forward_sensor.ping() / US_ROUNDTRIP_CM;
}

float Sensor::down()
{
  NewPing down_sensor(down_trigger, down_echo, max_drop);
  return down_sensor.ping() / US_ROUNDTRIP_CM;
}

float Sensor::left_light()
{
  const int left_light_sensor = 7;
  return analogRead(left_light_sensor);
}

float Sensor::center_light()
{
  const int center_light_sensor = 6;
  return analogRead(center_light_sensor);
}

float Sensor::right_light()
{
  const int right_light_sensor = 2;
  return analogRead(right_light_sensor);
}
