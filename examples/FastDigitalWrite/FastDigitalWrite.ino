#include <FastDigitalPin.h>

#define PIN_OUTPUT 4

void setup() {
  pinData pinOutput;
  unsigned long initTime, endTime;
  
  Serial.begin(115200);
  while(!Serial) {}

  determine_pinData(PIN_OUTPUT, &pinOutput);
  
  Serial.println("FastDigitalPin test");
  Serial.print("sizeof pinData struct: "); Serial.println(sizeof(pinOutput));
  Serial.println();

  pinMode(PIN_OUTPUT, INPUT);

  Serial.println("Arduino digitalWrite() function:");
  initTime = micros();
  digitalWrite(PIN_OUTPUT, HIGH);
  endTime = micros();

  Serial.print("initTime : "); Serial.println(initTime);
  Serial.print("endTime : "); Serial.println(endTime);
  Serial.print("Time : "); Serial.println(endTime - initTime);
  Serial.println();

  delay(2000);

  Serial.println("FastDigitalWrite() function:");
  initTime = micros();
  FastDigitalWrite(pinOutput, HIGH);
  endTime = micros();

  Serial.print("initTime : "); Serial.println(initTime);
  Serial.print("endTime : "); Serial.println(endTime);
  Serial.print("Time : "); Serial.println(endTime - initTime);
  Serial.println();

  delay(2000);

  Serial.println("register function:"); //D4 = PD4 
  initTime = micros();
  PORTD = B00010000;
  endTime = micros();

  Serial.print("initTime : "); Serial.println(initTime);
  Serial.print("endTime : "); Serial.println(endTime);
  Serial.print("Time : "); Serial.println(endTime - initTime);
  Serial.println();
}

void loop() {
  // put your main code here, to run repeatedly:

}