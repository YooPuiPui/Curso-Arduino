#include "pitches.h";


void setup() {
  // put your setup code here, to run once:
  pinMode(5,OUTPUT);
}

int melody[] = {
  NOTE_FS5, NOTE_FS5, NOTE_D5, NOTE_B4, NOTE_B4, NOTE_E5,
  NOTE_E5, NOTE_E5, NOTE_GS5, NOTE_A5, NOTE_B5,
  NOTE_A5, NOTE_A5, NOTE_A5, NOTE_E5, NOTE_D5, NOTE_FS5,
  NOTE_FS5, NOTE_FS5, NOTE_E5, NOTE_E5, NOTE_FS5, NOTE_E5
};


void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(5,HIGH);
  int pause = 12; 
  delay(pause);
  digitalWrite(4,LOW);
  delay(3000);
}
