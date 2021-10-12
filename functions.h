#ifndef FUNCTIONS_H
#define FUNCTIONS_H


void mappaDrive(int lambda, int nu, int *n_MFL_ref, int *n_MFR_ref);
void mappaPivot(int lambda, int nu, int *n_MFL_ref, int *n_MFR_ref);

float map_float(float x, float in_min, float in_max, float out_min, float out_max);

#endif