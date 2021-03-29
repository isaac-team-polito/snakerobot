#ifndef Robot_h
#define Robot_h


#include "definitions.h"
#include "motor.h"
#include "communication.h" 

void robot_setup();

void go_forward(int speed,int dir);

// velocità di avanzamento, verso di avanzamento, curvatura, verso di curvatura
void go_turning(int speed, int dir, int yaw, int dir_yaw);



#endif
