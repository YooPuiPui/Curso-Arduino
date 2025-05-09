#include <IRremote.h>

int pin = 6;
IRrecv irrecv(pin);
decode_results results;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(irrecv.decode(&results)){
    Serial.print("El codigo recibido es: ");
    Serial.println(results.value, HEX);
    irrecv.resume();
  }
}
