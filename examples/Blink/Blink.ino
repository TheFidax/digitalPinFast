#include <FastDigitalPin.h>

pinData pinLed;

void setup() {
    determine_pinData(LED_BUILTIN, &pinLed);

    FastPinMode(pinLed, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
    FastDigitalWrite(pinLed, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);                       // wait for a second
    FastDigitalWrite(pinLed, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);                       // wait for a second
}