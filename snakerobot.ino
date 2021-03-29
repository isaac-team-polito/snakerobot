#include <Arduino.h>

#include "robot.h"

int lambda,nu;
  
byte comando[8];

void setup() {
  robot_setup();

  
  
}

void loop() {
  if(get_comando(comando)) { // se ci sono dati ricevuti
    if(parse_comando(comando,&lambda,&nu)) { // se il comando è stato letto correttamente - - - TODO gestione errori di parsing
       
    }
  }
  
}
