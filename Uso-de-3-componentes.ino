#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

float texterior; 
int pinlm35 = 2;
int pinled1 = 12;
int pinled2 = 13;
int i = 0;
int tiempo;
int estadopersiana = -1;
int estadocalefaccion = -1;
unsigned long tiempo1 = 0;
unsigned long tiempo2 = 0;

// Declaración de funciones
int abrirpersiana();
int cerrarpersiana();
int activarcalefaccion();
int activaraireacondicionado();
void actualizarmillis();

void setup() {
  pinMode(pinled1, OUTPUT);
  pinMode(pinled2, OUTPUT);
  Serial.begin(9600);
  dht.begin();
  tiempo1 = millis();
  tiempo2 = millis();
}

void loop() {
  tiempo2 = millis();
  actualizarmillis();

  if (i == 0) {
    Serial.println("Bienvenido al controlador de temperatura");
    Serial.println("Para comenzar ingrese cada cuanto quiere realizar el chequeo (En minutos)");

    do {
      tiempo = Serial.parseInt();
    } while (tiempo < 1 || tiempo > 60);
    i = 1;
  }

  float humedad = dht.readHumidity();
  float tinterior = dht.readTemperature();
  texterior = analogRead(pinlm35);
  texterior = (5.0 * texterior * 100.0) / 1024.0;

  // Frío en el interior
  if (texterior > tinterior && texterior > 20.0 && tinterior < 18.0) {
    if (estadopersiana == -1) {
      Serial.print("Le gustaría abrir la persiana?: 1 = sí / 0 = no ");
      delay(5000);
      int seleccion = Serial.parseInt();
      if (seleccion == 1) {
        estadopersiana = abrirpersiana();
      }
      if (seleccion == 0) {
        estadopersiana = cerrarpersiana();
        estadocalefaccion = activarcalefaccion();
      }
    }

    if (tinterior < 18.0) {
      digitalWrite(pinled1, HIGH);
      while (tinterior < 18.0 && tinterior > 20.0) {
        tinterior = dht.readTemperature();
      }
      digitalWrite(pinled1, LOW);
    }
  }

  // Calor en el interior
  if (texterior < tinterior && texterior < 18.0 && tinterior > 20.0) {
    if (estadopersiana == -1) {
      Serial.print("¿Le gustaría cerrar la persiana?: (1 = Sí / 0 = No) ");
      delay(5000);
      int seleccion = Serial.parseInt();
      if (seleccion == 1) {
        estadopersiana = cerrarpersiana();
      }
      if (seleccion == 0) {
        estadopersiana = abrirpersiana();
        estadocalefaccion = activaraireacondicionado();
      }
    }

    if (tinterior > 20.0) {
      digitalWrite(pinled2, HIGH);
      while (tinterior < 18.0 && tinterior > 20.0) {
        tinterior = dht.readTemperature();
        Serial.println(tinterior);
        actualizarmillis();
      }
      digitalWrite(pinled2, LOW);
    }
  }
}

// Definiciones de funciones
int abrirpersiana() {
  return 1;
}

int cerrarpersiana() {
  return 0;
}

int activarcalefaccion() {
  return 1;
}

int activaraireacondicionado() {
  return 0;
}

void actualizarmillis() {
  if (millis() - tiempo1 > (unsigned long)(tiempo * 60000)) {
    tiempo1 = millis();
  }
}
