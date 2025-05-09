float valorsensor;
int pinLM35 = 2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  valorsensor=analogRead(pinLM35);
  valorsensor=(5.0*valorsensor*100.0)/1024.0;

  Serial.print("La tempuratura actual es: ");
  Serial.println(valorsensor);
  delay(5000);
} 
