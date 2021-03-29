
#include "robot.h"

/**
 * setup pins
 */
void robot_setup() {
	pinMode(DRIVER_1_ATTIVAZIONE,OUTPUT);

	pinMode(TRAZIONE_1_DIREZIONE_1,OUTPUT);
	pinMode(TRAZIONE_1_DIREZIONE_2,OUTPUT);

	pinMode(TRAZIONE_1_PWM,OUTPUT);
	pinMode(TRAZIONE_1_STATUS,INPUT);

	//encoder trazione modulo 1
	pinMode(ENCODER_1_B,INPUT);
	pinMode(ENCODER_1_A,INPUT);


	// - - - MODULO 2 - - - 

	//driver modulo 2
	pinMode(DRIVER_2_ATTIVAZIONE,OUTPUT);

	//motore trazione 2
	pinMode(TRAZIONE_2_DIREZIONE_1,OUTPUT);
	pinMode(TRAZIONE_2_DIREZIONE_2,OUTPUT);

	pinMode(TRAZIONE_2_PWM,OUTPUT);
	pinMode(TRAZIONE_2_STATUS,INPUT);

	//motore imbardata
	pinMode(IMBARDATA_2_DIREZIONE_1,OUTPUT);
	pinMode(IMBARDATA_2_DIREZIONE_2,OUTPUT);

	pinMode(IMBARDATA_2_PWM,OUTPUT);
	pinMode(IMBARDATA_2_STATUS,INPUT);

	//encoder trazione modulo 2
	pinMode(ENCODER_2_B,INPUT);
	pinMode(ENCODER_2_A,INPUT);


	// - - - MODULO 3 - - - 

	//driver modulo 3
	pinMode(DRIVER_3_ATTIVAZIONE,OUTPUT);

	//motore trazione 2
	pinMode(TRAZIONE_3_DIREZIONE_1,OUTPUT);
	pinMode(TRAZIONE_3_DIREZIONE_2,OUTPUT);

	pinMode(TRAZIONE_3_PWM,OUTPUT);
	pinMode(TRAZIONE_3_STATUS,INPUT);

	//motore imbardata
	pinMode(IMBARDATA_3_DIREZIONE_1,OUTPUT);
	pinMode(IMBARDATA_3_DIREZIONE_2,OUTPUT);

	pinMode(IMBARDATA_3_PWM,OUTPUT);
	pinMode(IMBARDATA_3_STATUS,INPUT);

	//encoder trazione modulo 2
	pinMode(ENCODER_3_B,INPUT);
	pinMode(ENCODER_3_A,INPUT);

}//end robot_setup()

