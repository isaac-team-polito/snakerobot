#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>
//	TODO ADD ENCODER AND PID CONTROL
/**
 * @file
 * @version 1.0
 * @author Andrea Grillo
 * 
 * Simple class to control a motor object.
* 
 */
class Motor {
  public:
    Motor(byte pwm, byte in1, byte in2);
    void go(int speed, bool invert);
    void stop();
    void begin();
  private:
    byte pwm, in1, in2;
};

#endif
