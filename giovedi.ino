#include "config.h"
#include "Modulo.h"
#include "Giunto.h"
#include "functions.h"
#include "communication.h"

Modulo modulo1;
Giunto giunto1;

void setup() {
	Serial.begin(9600);
	Serial.println("HOLA!");

  Serial3.begin(9600);                          //comunicazione seriale BT su Rx3

	modulo1.begin();
  giunto1.begin();
}

void loop() {
  int lambda, nu, refMotorL = 0, refMotorR = 0;
  byte comando[8];

  giunto1.tick();

#ifdef SERIAL
  if (Serial.available()) {
    lambda = Serial.parseInt(); 
    nu = Serial.parseInt();
#else
  if(get_comando(comando)) {
    parse_comando(comando,&lambda,&nu);
#endif
    giunto1.write(GIUNTO_FACTOR * nu);
   

    if(lambda == 0 && nu == 0) return;
        //// MAPPATURA
      if (abs(lambda) < DELTA_LAMBDA)     // mappatura pivot, ruoto su me stesso
      {
        Serial.println("pivot");
        mappaPivot(lambda,nu, &refMotorL,&refMotorR);
      }
      else                                        // mappatura drive, cammino ed eventualmente ruoto
        mappaDrive(lambda,nu,&refMotorL,&refMotorR);

    Serial.print("motoresx = ");
    Serial.print(refMotorL);
    Serial.print("    motoredx = ");
    Serial.print(refMotorR);
    Serial.print("    angolo = ");
    Serial.println(GIUNTO_FACTOR * nu);
    // scrivo sui motori
    modulo1.write(refMotorL,refMotorR);
  } 
}