#include "communication.h"
#include <Arduino.h>


int getComando(byte *) {
    if (Serial3.available() > 0 ) {
        cmd_BT[0] = Serial3.read();

        if (cmd_BT[0] == STX) {  //Inizio trasmissione
            int z = 1;  //Legge i dati in arrivo

            while (Serial3.available()) {
                delay(1);
                cmd_BT[z] = Serial3.read();
                if (cmd_BT[z] > 127 || z > 7) break;                      //Se > 127 si sfora dal Codice ASCII (0-127) e per z > 7 si sfora la dimensione di cmd[]
        }
    }


	
	
}
int parse_comando(uint8_t *comando, int lambda, int nu){
}
