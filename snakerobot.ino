#include <Arduino.h>

#include "robot.h"

int lambda,nu,vel_trazione,verso_trazione,angolo_imbardata;
  
byte comando[8];


int main() {
  robot_setup();
  while(true) {
    if(get_comando(comando) &&                                              // se ci sono dati ricevuti
      parse_comando(comando,&lambda,&nu) &&                                 // se il comando è stato letto correttamente - - - TODO gestione errori di parsing
      mappa(lambda,nu,&vel_trazione,&verso_trazione,&angolo_imbardata)) {   // se la mappatura è stata eseguita correttamente
      
      attua(vel_trazione,verso_trazione,angolo_imbardata
    }
  }
   
  
}
