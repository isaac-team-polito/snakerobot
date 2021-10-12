#ifndef CONFIG_H
#define CONFIG_H
// tempo di campionamento 
#define DT            150 

// costanti controllo PID GIUNTO
#define GIUNTO_KP      4
#define GIUNTO_KI     .7
#define GIUNTO_KD     .1

// costanti controllo PID trazione
#define TRAZIONE_KP    10
#define TRAZIONE_KI   .7
#define TRAZIONE_KD   .1

// pid encoder
#define PIN_ENC_L_A     11
#define PIN_ENC_L_B     10

// todo pid with 2 encoderd
#define PIN_ENC_A PIN_ENC_L_A
#define PIN_ENC_B PIN_ENC_L_B

#define PIN_ENC_R_A     12
#define PIN_ENC_R_B     13

// FILTRO EMA encoder
#define ALPHA         0.6

//// pin driver motore giunto
#define PIN_GIUNTO_EN 7	// PIN ENABLE

#define PIN_GIUNTO_IN1 4	// PIN DIREZIONE 1
#define PIN_GIUNTO_IN2 3	// PIN DIREZIONE 2
#define PIN_GIUNTO_PWM 2

// pin driver motori trazione
#define PIN_TRAZIONE_EN 3	// PIN ENABLE

#define PIN_TRAZIONE_L_IN1 8	// PIN DIREZIONE 1
#define PIN_TRAZIONE_L_IN2 9	// PIN DIREZIONE 2
#define PIN_TRAZIONE_L_PWM 7

#define PIN_TRAZIONE_R_IN1 5	// PIN DIREZIONE 1
#define PIN_TRAZIONE_R_IN2 4	// PIN DIREZIONE 2
#define PIN_TRAZIONE_R_PWM 6




// TODO 

// COSTANTI DI CONFIGURAZIONE
const int DELTA_LAMBDA = 20;      // semi-ampiezza banda modalità pivot DA OTTIMIZZARE
const int DELTA_NU = 16;          // semi-ampiezza banda avanzamento rettilineo DA OTTIMIZZARE
const int DELTA_NU0 = 4;          // semi-ampiezza banda morta modalità pivot DA OTTIMIZZARE

//// Fattori di scala per il mapping ////
const int FACTOR_MAPPING_PIVOT = (100 - DELTA_NU0);     /// TODO aggiungere descrizioni
const int MAX_ADV_N = (100 - DELTA_LAMBDA);             /// TODO aggiungere descrizioni
const int FACTOR_MAPPING_DRIVE = MAX_ADV_N;             /// TODO aggiungere descrizioni

#define GIUNTO_FACTOR 1

const float N_MAX = 255;          // RPM massima velocità a vuoto del motore

#endif