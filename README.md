# Indice
* [Introduzione Rcn600 SUSI](#Rcn600-SUSI)
* [Funzioni Disponibili](#Funzioni-Disponibili)
* [Tipi di Dati](#Tipi-di-Dati)

------------

# Rcn600 SUSI
Questa libreria permette di utilizzare una scheda Arduino (o un microcontrollore tramite Arduino IDE) come Slave per l'interfaccia SUSI.<br/>
Libreria testata su Arduino UNO.

**ATTENZIONE: Alcune schede Arduino funzionano a 3.3v, le interfacce SUSI, *se non specificato*, SONO A 5 VOLT !** 

Per funzionare sono necessari 2 resistori da **470Ω in serie** sulle linee SUSI (Clock e Dati).<br/>
Data  ---> 470Ω ---> Pin generico (anche di tipo analogico)<br/>
Clock ---> 470Ω ---> Pin Interrupt<br/>

Maggiori informazioni della specifiva nel fle [RCN-600.pdf](https://github.com/TheFidax/Rcn600/blob/master/RCN-600.pdf).


**Video Presentazione del Progetto:**</br>

[![Video Presentazione](https://img.youtube.com/vi/VzgkDouOvCY/0.jpg)](http://www.youtube.com/watch?v=VzgkDouOvCY)

------------

# Funzioni Disponibili
Le seguenti funzioni dalla libreria per sostituire i comandi di *default*.

------------

```c
void determine_pinData(uint8_t pinNumber, pinData* data);
```
Permette di deterimanre, e salvare nella relativa struct, i dati (porta e registri) del pin.<br/>
- Input:
  - il numero del pin di cui ricavare i dati
  - la struct **passata per riferimento** dove salvare i dati
- Restituisce:
  - Nulla

------------

```c
void FastPinMode(pinData pin, uint8_t mode)
```
Analogo a pinMode, evita controlli su pin PWM e NON disabilita gli interrupt.</br>
- Input
  - la struct contente i dati del pin di cui si vuole modificare la configurazuione
  - la nuova configurazione del pin
- Restituisce:
  - nulla

------------

```c
uint8_t FastDigitalRead(pinData pin);
```
Analogo a digitalRead, evita controlli su pin PWM e NON disabilita gli interrupt.</br>
- Input:
	- la struct contente i dati del pin di cui si vuole leggere lo stato
- Restituisce:
  - il valore logico letto sul pin

------------

```c
void FastDigitalWrite(pinData pin, uint8_t val);
```
Analogo a digitalWrite, evita controlli su pin PWM e NON disabilita gli interrupt.</br>
- Input:
  - la struct contente i dati del pin di cui si vuole modificare lo stato 
  - il nuovo stato del pin
- Restituisce:
  - nulla

------------

# Tipi di Dati
I seguenti tipi di dati vengono utilizzati dalle funzioni della libreria.

------------

```c
typedef struct {
    uint8_t pinPort;
    uint8_t pinBitMask;
    volatile uint8_t* pinReg;
    volatile uint8_t* pinOut;
} pinData;
```
Struttura dove vengono salvati i dati dei pin per essere utilizzati dalle funzioni.

**Ogni Struct occupa 6 Byte in SRAM.**
