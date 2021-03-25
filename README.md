# Indice
* [Introduzione Rcn600 SUSI](#Rcn600-SUSI)
* [Metodi Disponibili](#Metodi-Obbligatori)
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

# Tipi di Dati
I seguenti tipi di dati vengono utilizzati dai metodi della libreria.

------------

```c
SUSI_DIRECTION
```
Tipo *enum*, identifica *simbolicamente* la direzione trasmessa dal Decoder Master: </br>
- SUSI_DIR_REV : Direzione *reverse*
- SUSI_DIR_FWD : Direzione *forward*

------------

```c
SUSI_FN_GROUP
```
Tipo *enum*, identifica *simbolicamente* il gruppo di Funzioni Digitali trasmesse dal Decoder Master:</br>
- SUSI_FN_0_4 : Funzioni dalla 0 alla 4
- SUSI_FN_5_12 : Funzioni dalla 5 alla 12
- SUSI_FN_13_20 : Funzioni dalla 13 alla 20
- SUSI_FN_21_28 : Funzioni dalla 21 alla 28
- SUSI_FN_29_36 : Funzioni dalla 29 alla 36
- SUSI_FN_37_44 : Funzioni dalla 37 alla 44
- SUSI_FN_45_52 : Funzioni dalla 45 alla 52
- SUSI_FN_53_60 : Funzioni dalla 53 alla 60
- SUSI_FN_61_68 : Funzioni dalla 61 alla 68

------------

```c
SUSI_AUX_GROUP
```
Tipo *enum*, identifica *simbolicamente* il gruppo di AUXs trasmesse dal Decoder Master:</br>
- SUSI_AUX_1_8 : AUX dalla 1 alla 8
- SUSI_AUX_9_16 : AUX dalla 9 alla 16
- SUSI_AUX_17_24 : AUX dalla 17 alla 24
- SUSI_AUX_25_32 : AUX dalla 25 alla 32

------------

```c
SUSI_AN_FN_GROUP
```
Tipo *enum*, identifica *simbolicamente* il gruppo di Funzioni Analogiche trasmesse dal Decoder Master:</br>
- SUSI_AN_FN_0_7 : Funzioni Analogiche dalla 0 alla 7
- SUSI_AN_FN_8_15 : Funzioni Analogiche dalla 8 alla 15
- SUSI_AN_FN_16_23 : Funzioni Analogiche dalla 16 alla 23
- SUSI_AN_FN_24_31 : Funzioni Analogiche dalla 24 alla 31
- SUSI_AN_FN_32_39 : Funzioni Analogiche dalla 32 alla 39
- SUSI_AN_FN_40_47 : Funzioni Analogiche dalla 40 alla 47
- SUSI_AN_FN_48_55 : Funzioni Analogiche dalla 48 alla 55
- SUSI_AN_FN_56_63 : Funzioni Analogiche dalla 56 alla 63

------------

# Funzionalita' Extra
Le seguenti funzionalita' vengono comandate *manualmente* agendo su delle #define nel file **Rcn600.h**

------------

```c
#define	NOTIFY_RAW_MESSAGE
```
Questa define rende disponibile un metodo che permette di *esportare* il messaggio *grezzo* per poterlo manipolare in maniera Esterna alla libreria.</br>
Stato di *default*: **Disattivata**</br>
```c
void notifySusiRawMessage(uint8_t *rawMessage, uint8_t messageLength);
```
*notifySusiRawMessage()* viene invocato ogni volta che è presente un messaggio da decodificare
- Input:
  - i byte che compongono il messaggio acquisito dalla libreria
  - la lunghezza del messaggio
- Restituisce:
  - Nulla
