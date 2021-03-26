#ifndef Robot_h
#define Robot_h

//TODO#include <Arduino.h>

#include "definitions.h"
#include "motor.h"


class Robot {
  public:
	void setup();
//needed?    bool check();
	Motor trazione_1;
	Motor trazione_2;
	Motor trazione_3;

   //TODO
};

#endif


