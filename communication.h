#ifndef Communication_h
#define Communication_h

#include <Arduino.h>

#include "definitions.h"

#define STX 0x02                                //STX - Codice ASCII (Dec 2), start transmission
#define ETX 0x03                                //ETX - Codice ASCII (Dec 3), end transmission



int get_comando(byte *);
int parse_comando(byte *, int*, int*);


#endif
