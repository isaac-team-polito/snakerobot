#include "Modulo.h"

/**
 * Initializes the Modulo class.
 * 
 * Method that initializes the 2 traction motors used by the module.
 * 
 * It's necessary for this to be separated from the constructor 
 * because the constructor could be potentially executed before
 * everything necessary to interact with the hardware is ready. 
 * Instead a separated function can only be called when the user 
 * is allowed to call a function, like inside the setup in Arduino.
 */
void Modulo::begin() {
	left->begin();
	right->begin();	
}


void Modulo::write(int motorLeft, int motorRight) {
  left->go(abs(motorLeft),motorLeft>0);
  right->go(abs(motorRight),motorRight>0);

  // TODO pid 
}


