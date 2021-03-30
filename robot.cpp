#include "robot.h"

/*
 * lambda e nu compresi tra -100 e +100
 * 
 * ritorna 1 se i dati in input stanno nel range corretto
 * 
 * salva in vel_trazione, verso_trazione e angolo_imbardata i dati da passare al modulo dei motori
 */
int mappa(int lambda,int nu, int *vel_trazione, int *verso_trazione, int *angolo_imbardata) {
  
  // se i valori non stanno nel range corretto ritorno -1
  if(abs(nu) > 100 || abs(lambda) > 100) return(-1);

  // se il valore di velocità sta sotto un limite minimo il robot rimane fermo
  if(abs(lambda) < VELOCITA_MINIMA) {
    *vel_trazione = 0;

    // TODO check - rimango nella curvatura precedente o torno a zero?
    *angolo_imbardata = 0;
    return(1);
  }
  
  *verso_trazione = (lambda > 0) ? 1 : 0;
  *vel_trazione = map(abs(lambda),0,100,0,255);

 // if(abs(nu)) < 
   
}



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

  //SENSORI DI CORRENTE DEI TRE MODULI
  pinMode(CURRENT_SENSOR_1,INPUT);
  pinMode(CURRENT_SENSOR_2,INPUT);
  pinMode(CURRENT_SENSOR_3,INPUT);
}//end robot_setup()
