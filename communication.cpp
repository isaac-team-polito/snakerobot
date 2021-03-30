#include "communication.h"
#include <Arduino.h>

/*
 * Funzione di lettura comando dalla seriale bluetooth
 * ritorna 0 se non c'è niente da leggere
 * ritorna 1 se ha letto un comando
 * 
 * @param cmd puntatore a array di byte su cui salvare il messaggio
 */
int get_comando(byte cmd[8]) {
	int z;
	// se c'è un carattere da poter leggere  
	if (Serial3.available() > 0 ) {

		//leggo il primo carattere 
		cmd[0] = Serial3.read();

		if (cmd[0] == STX) {  // se il primo carattere è l'inizio della trasmissione
			for(z = 1; cmd[z]<=127 && z<=7 && Serial3.available() && cmd[z] != ETX; z++) {
				delay(1);
				cmd[z] = Serial3.read();
			}

			if(z==7) return(1); //dati ricevuti bene

		}
	}
	return(0);
}


/*
 * Funzione di parsing del comando ricevuto
 * 
 * @param comando array di byte ricevuti dalla funzione getComando
 * 
 * ritorna 1 se i dati sono stati letti correttamente
 * 
 * TODO gestione errori
 */
int parse_comando(byte *data, int *lambda, int *nu){

	*nu = (data[1]-48)*100 +
	 	(data[2]-48)*10 +
	 	(data[3]-48);

	*nu -= 200;                                     //togliere l'offset

	*lambda = (data[4]-48)*100 +
	 	(data[5]-48)*10 +
	 	(data[6]-48);

	*lambda -= 200;                                 //togliere l'offset

	*lambda = constrain(*lambda, -100, 100);        // garantire che il numero non ecceda i limiti

	*nu = constrain(*nu, -100, 100);                // garantire che il numero non ecceda i limiti


	return(1); //parsing eseguito correttamente
}
