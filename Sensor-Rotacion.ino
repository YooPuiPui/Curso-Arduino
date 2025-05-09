int actVal = 0;
int preVal = actVal;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("valor potenciometro: ");
  int aux = analogRead(A0);
  Serial.print(aux);

  Serial.print(" Angulo: ");
  float escalaAux1 = float(aux)*320/1023;
  Serial.print(escalaAux1);

  Serial.print("Angulo persiana: ");
  float escalaAux2 = escalaAux1*180/320 - 90;
  Serial.println(escalaAux2);

  delay(50);
}
