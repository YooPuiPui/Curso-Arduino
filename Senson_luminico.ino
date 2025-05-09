void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int v = analogRead(A1);

  Serial.print("El nivel de intensidad luminica es: ");
  Serial.println(v);
}
