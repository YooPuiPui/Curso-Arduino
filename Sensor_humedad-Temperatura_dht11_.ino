#include<DHT.h>
#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  float humedad = dht.readHumidity();
  float temperatura = dht.readTemperature();

  Serial.print("Humedad: ");
  Serial.print(humedad);
  Serial.print("\%t");

  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.print("*C");

  Serial.print("\n");
}
