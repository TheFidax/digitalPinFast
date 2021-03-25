#ifndef FAST_DIGITAL_PIN_h
#define FAST_DIGITAL_PIN_h

#include <stdint.h>
#include "arduino.h"

// Struct contenente i dati del singolo pin
typedef struct {
    uint8_t pinPort;
    uint8_t pinBitMask;
    volatile uint8_t* pinReg;
    volatile uint8_t* pinOut;
} pinData;

/*
*	determine_pinData() ricava le informazioni sul pin passato tramite le macro native e ne salva il risultato nella struct
*	Input:
*		- in numero del pin di cui ricavare le informazioni
*       - la struct dove salvare i dati
*	Restituisce:
*		- nulla
*/
void determine_pinData(uint8_t pinNumber, pinData* data);
/*
*	FastPinMode() analogo a pinMode, evita controlli su pin PWM e NON disabilita gli interrupt
*	Input:
*		- la struct contente i dati del pin di cui si vuole modificare la configurazuione
*       - la nuova configurazione del pin
*	Restituisce:
*		- nulla
*/
void FastPinMode(pinData pin, uint8_t mode);
/*
*	FastDigitalRead() analogo a digitalRead, evita controlli su pin PWM e NON disabilita gli interrupt
*	Input:
*		- la struct contente i dati del pin di cui si vuole leggere lo stato
*	Restituisce:
*		- il valore logico letto sul pin
*/
uint8_t FastDigitalRead(pinData pin);
/*
*	FastDigitalWrite() analogo a digitalWrite, evita controlli su pin PWM e NON disabilita gli interrupt
*	Input:
*		- la struct contente i dati del pin di cui si vuole modificare lo stato 
*       - il nuovo stato del pin
*	Restituisce:
*		- nulla
*/
void FastDigitalWrite(pinData pin, uint8_t val);

#endif