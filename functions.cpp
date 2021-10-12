#include "functions.h"
#include "config.h"
#include <Arduino.h>


//la funzione map() NON è ottimale per i numeri reali (float), quindi è stata creata la seguente:
float map_float(float x, float in_min, float in_max, float out_min, float out_max){
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


void mappaPivot(int lambda, int nu, int *n_MFL_ref, int *n_MFR_ref)
{
    int delta_n;
    if(nu < -DELTA_NU0)      delta_n = nu + DELTA_NU0;
    else if(nu > +DELTA_NU0) delta_n = nu - DELTA_NU0;
    else                         delta_n = 0;

    *n_MFL_ref = delta_n/2;

    *n_MFR_ref = -*n_MFL_ref;		// AG un motore gira al contrario rispetto all'altro

    *n_MFL_ref = map_float(*n_MFL_ref, -FACTOR_MAPPING_PIVOT / 2, FACTOR_MAPPING_PIVOT / 2 , -N_MAX / 2, N_MAX / 2);      // normalizzazione dei dati MAX 50% in pivot
    *n_MFR_ref = map_float(*n_MFR_ref, -FACTOR_MAPPING_PIVOT / 2, FACTOR_MAPPING_PIVOT / 2, -N_MAX / 2, N_MAX / 2);       // normalizzazione dati MAX 50% in pivot
}

void mappaDrive(int lambda, int nu, int *n_MFL_ref, int *n_MFR_ref)
{
    int delta_n,n_i;


    if(nu < -DELTA_NU)      delta_n = nu + DELTA_NU;
    else if(nu > +DELTA_NU) delta_n = nu - DELTA_NU;
    else                        delta_n = 0;


    if(lambda < -DELTA_LAMBDA)      n_i = lambda + DELTA_LAMBDA;
    else if(lambda > +DELTA_LAMBDA) n_i = lambda - DELTA_LAMBDA;
    else                                n_i = 0;

    *n_MFL_ref = n_i + delta_n/2;

    *n_MFL_ref = constrain(*n_MFL_ref, -MAX_ADV_N, MAX_ADV_N);

    *n_MFR_ref = n_i - delta_n/2;

    *n_MFR_ref = constrain(*n_MFR_ref, -MAX_ADV_N, MAX_ADV_N);

    *n_MFL_ref = map_float(*n_MFL_ref, -FACTOR_MAPPING_DRIVE, FACTOR_MAPPING_DRIVE, -N_MAX, N_MAX);               // normalizzazione dei dati
    *n_MFR_ref = map_float(*n_MFR_ref, -FACTOR_MAPPING_DRIVE, FACTOR_MAPPING_DRIVE, -N_MAX, N_MAX);               // normalizzazione dei dati
}


