int tiempoAc = 0;
int inicioMillis = 0, finMillis = 0;
byte abierto = 0;
int lastR = 1, lastR2 = 1;
int actR = 1, actR2 = 1;
int both = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  actR = digitalRead(2);
  actR2 = digitalRead(3);
  delay(10);

  if((1-actR)*(1-actR2)){
    ambos();
  }else if(1-actR){
    abrir();
  }else if(1-actR2){
    cerrar(0);
  }else if(abs((lastR - actR)*(lastR2 - actR2))){
    checkTime();
  }else{
    tiempoAc = 0;
    inicioMillis = 0;
    finMillis = 0;
  }

  String aux = "";
  switch(abierto){
    case 2:
    aux = "36";
    case 1:
    aux += "0 cerrado";
    break;
    case 0:
    aux = "abierto";
    break;
  }

  Serial.print("Estado de la persiana: "+aux+" Boton 1: ");
  if(1 - actR){
    Serial.print("pulsado");
  }else{
    Serial.print("no pulsado");
  }

  Serial.print(" Boton 2: ");
  if(1 - actR2){
    Serial.print("pulsado");
  }else{
    Serial.print("no pulsado");
  }
  Serial.print(" Tiempo acumulado: ");
  Serial.println(float(tiempoAc)/1000);

  lastR = actR;
  lastR2 = actR2;
}

void ambos(){
  if(inicioMillis == 0){
      inicioMillis = millis();
  }
  finMillis = millis();
  tiempoAc = finMillis - inicioMillis;
}

void abrir(){
  abierto = 0;
}

void cerrar(bool zero){
  if(1 - zero){
    abierto = 1;
    return; 
  }
  abierto = 2;
}

void checkTime(){
  if(tiempoAc<100){
    return;
  }else if(tiempoAc<3000){
    abrir();
  }else if(tiempoAc<6000){
    cerrar(1);
  }
}
