#include <DHT.h>
#include <Servo.h>
#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
float texterior;
int pinlm35=2;
Servo servo;
float deseada;

void setup() {
  Serial.begin(9600);
  servo.attach(7);
  dht.begin();
  pinMode(12, OUTPUT);
  pinMode(13,OUTPUT);

}

void abrir(){
  servo.write(90);
}

void cerrar(){
  cerrar(0);
}

void cerrar(bool grad){
  Serial.print("Cierre: ");
  Serial.println(grad);

  if(grad){
    servo.write(0);
    return;
  }
  servo.write(180);
}

void loop() {
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  deseada = 13;

  while(deseada <=0.0 || deseada >40.0){
    while(Serial.available()==0){}
    deseada = Serial.parseFloat();
    if(deseada==0){
      Serial.print("No se puede ingresar palabras");
    }
    Serial.println(deseada);
  }

  float maximo = deseada +3.0;
  float minimo = deseada - 2.0;

  float tinterior=dht.readTemperature();
  Serial.println(tinterior);

  texterior = analogRead(pinlm35);
  texterior = (5.0*texterior*100.0)/1024.0;

  int intensidad = analogRead(A1);
  Serial.println(intensidad);
  if(intensidad <=300){
    cerrar(1);
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);

  }else{
    if(tinterior > maximo){
      cerrar();
      digitalWrite(13,HIGH);
      digitalWrite(12,LOW);
    }

    if(tinterior < minimo){
      abrir();
      digitalWrite(12,HIGH);
      digitalWrite(13,LOW);

      Serial.println(intensidad);
      tinterior = dht.readTemperature();
      Serial.println(tinterior);
      Serial.println((minimo>tinterior));
      Serial.println((maximo<tinterior));
      delay(3000);
    }
  }
  delay(1000);

}
