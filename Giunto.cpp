#include "Giunto.h"

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
void Giunto::begin() {
  motore_giunto->begin();
  // ENCODER ASSOLUTO
	//init AMS_AS5048B object
	abs_encoder.begin();

	//set clock wise counting
	// AG needed? 
	abs_encoder.setClockWise(true); 

	//set the 0 to the sensor
	//mysensor.zeroRegW(0x0);

	//left->begin();
	//right->begin();	
}


void Giunto::write(int angle) {
  reference_value = angle;
}

void Giunto::tick() {
  int vel;
  // - - READ ENCODER ANGLE - - 
  abs_encoder.updateMovingAvgExp();

  encoder_angle = abs_encoder.angleR(U_DEG, false);
  
  // - - PID CONTROL - -
  vel = (reference_value - encoder_angle) * GIUNTO_KP;   // contributo proporzionale
  vel += (sum_error * GIUNTO_KI * DT / 1000);         // contributo integrativo
  vel +=  -(1000 * GIUNTO_KD * (encoder_angle - old_encoder_angle) / DT );   // contributo derivativo
 
  sum_error += reference_value - encoder_angle;      // sommatore errori
  old_encoder_angle = encoder_angle;           // salvo vecchio angolo

  // range pwm: 0-255
  motore_giunto->go(constrain(abs(vel),0,255),vel>0);
}


