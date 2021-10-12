#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <Arduino.h>
//#include "PID.h"
#include "Motor.h"
#include "config.h"


#define MAX_SPEED 255

/**
 * @file
 * @version 1.0
 * @author Andrea Grillo
 * 
 * Class to control the traction motors of the module.
 */
class Modulo {
  public:   
    void begin();
    void write(int motorLeft, int motorRight);

  private:
    Motor *right = new Motor(PIN_TRAZIONE_R_PWM, PIN_TRAZIONE_R_IN1, PIN_TRAZIONE_R_IN2); 
    Motor *left = new Motor(PIN_TRAZIONE_L_PWM, PIN_TRAZIONE_L_IN1, PIN_TRAZIONE_L_IN2); 
    //PID pid_left = PID(0.1, 100, -100, TRAZIONE_KP, TRAZIONE_KI, TRAZIONE_KD);
    //PID pid_right = PID(0.1, 100, -100, TRAZIONE_KP, TRAZIONE_KI, TRAZIONE_KD);
};

#endif
