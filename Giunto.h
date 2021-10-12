#ifndef GIUNTO_H
#define GIUNTO_H

#include "Motor.h"
#include "config.h"
#include "ams_as5048b.h"


#define MAX_SPEED 255
#define MAX_ANGLE 100
#define MIN_ANGLE 0


class Giunto {
  public:   
    void begin();
    void write(int angle);
    void tick();

  private:
    Motor *motore_giunto = new Motor(PIN_GIUNTO_PWM, PIN_GIUNTO_IN1, PIN_GIUNTO_IN2);
    AMS_AS5048B abs_encoder;
    int reference_value = 0,
      sum_error = 0,
      encoder_angle,
      old_encoder_angle;
};

#endif
 