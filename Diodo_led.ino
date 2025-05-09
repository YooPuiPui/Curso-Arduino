int pinled = 12;
int pinled = 13;

#include <Wire.h>


void setup() {
  // put your setup code here, to run once
  pinMode(pinled1, OUTPUT);
  pinMode(pinled2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  digitalWrite(pinled1, LOW);
  digitalWrite(pinled2, LOW);

  delay(2000);
  digitalWrite(pinled1, HIGH);

  delay(1000);
  digitalWrite(pinled2, HIGH);
}
