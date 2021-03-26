#include <FastDigitalPin.h>

pinData pinLed;

void setup() {
    determine_pinData(LED_BUILTIN, &pinLed);

    pinModeFast(pinLed, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
    digitalWriteFast(pinLed, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);                       // wait for a second
    digitalWriteFast(pinLed, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);                       // wait for a second
}
