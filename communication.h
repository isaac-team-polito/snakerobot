#ifndef Communication_h
#define Communication_h

#include <Arduino.h>

#include "definitions.h"

byte* getComando();
void parse_comando(byte, int, int);


#endif
