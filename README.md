![GitHub release (latest by date)](https://img.shields.io/github/v/release/TheFidax/digitalPinFast)
![GitHub Release Date](https://img.shields.io/github/release-date/TheFidax/digitalPinFast?color=blue&label=last%20release)
![GitHub commits since latest release (by date)](https://img.shields.io/github/commits-since/TheFidax/digitalPinFast/latest?color=orange)
![Hits](https://hitcounter.pythonanywhere.com/count/tag.svg?url=https%3A%2F%2Fgithub.com%2FTheFidax%2FdigitalPinFast)
[![GitHub issues](https://img.shields.io/github/issues/TheFidax/Rcn600)](https://github.com/TheFidax/digitalPinFast/issues)
[![Fork](https://img.shields.io/github/forks/TheFidax/digitalPinFast)](#)
[![Stars](https://img.shields.io/github/stars/TheFidax/digitalPinFast)](#)
[![License](https://img.shields.io/github/license/TheFidax/digitalPinFast)](#)
[![Total Downloads](https://img.shields.io/github/downloads/TheFidax/digitalPinFast/total)](#)

# Indice
* [Introduzione](#Fast-Digital-Pin)
* [Funzioni Disponibili](#Funzioni-Disponibili)
* [Tipi di Dati](#Tipi-di-Dati)

------------

# Fast Digital Pin
Questa libreria e' pensata per quelle applicazione dove *un numero limitato* di pin vengono usati con *molta frequenza*, pertanto velocizzare il loro utilizzo diventa molto importante.

La libreria permette di velocizzare il comando dei pin digitali (pinMode, digitalWrite, digitalRead) andando a calcolare, **una sola volta** ad inizio esecuzione del codice i parametri richiesti (porta, bit, registri) per i pin su cui si vogliono utilizzare le *funzioni fast*.

**ATTENZIONE: Questa velocizzazione viene ottenuta ospitando in SRAM la struct contenente i dati del pin; *ogni struct pesa 6 Byte!*** 

Le funzioni fornite dalla libreria **non disattivano gli interrupt e non eseguono i controlli sui Timer/PWM**, pertanto il suo utilizzo e' pensato per utenti *piu' esperti*.</br>

**Video Presentazione del Progetto:**</br>

[![Video Presentazione](https://img.youtube.com/vi/xxxxxxx/0.jpg)](http://www.youtube.com/watch?v=xxxxx)

------------

# Funzioni Disponibili
Le seguenti funzioni dalla libreria per sostituire i comandi di *default*.

------------

```c
void determine_pinData(uint8_t pinNumber, pinData* data);
```
Permette di deterimanre, e salvare nella relativa struct, i dati (porta e registri) del pin.<br/>
Va utilizzata nel Setup per salvare, in una variabile di tipo pinData *dichiarata Globalmente*, i dati del pin.  
- Input:
  - il numero del pin di cui ricavare i dati
  - la struct **passata per riferimento** dove salvare i dati
- Restituisce:
  - Nulla

------------

```c
void pinModeFast(pinData pin, uint8_t mode)
```
Analogo a pinMode, evita controlli su pin PWM e NON disabilita gli interrupt.</br>
- Input
  - la struct contente i dati del pin di cui si vuole modificare la configurazuione
  - la nuova configurazione del pin
- Restituisce:
  - nulla

------------

```c
uint8_t digitalReadFast(pinData pin);
```
Analogo a digitalRead, evita controlli su pin PWM e NON disabilita gli interrupt.</br>
- Input:
	- la struct contente i dati del pin di cui si vuole leggere lo stato
- Restituisce:
  - il valore logico letto sul pin

------------

```c
void digitalWriteFast(pinData pin, uint8_t val);
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

Per ogni pin che si vuole utilizzare il *modalita' Fast* e' neccessario dichiarare una variabile globale; nel Setup verranno calcolati i dati del pin e nel Loop sarà possibile utilizzare le funzioni *Fast*.

**Ogni Struct occupa 6 Byte in SRAM.**
