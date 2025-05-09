#define blinking 100

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

int preguntarTiempo(){
  Serial.print("¿Cunatas decimas de segundos (10 = 1 segundo) desea para el semaforo?\n");
  int aux;
  do{
    while(Serial.available() == 0){
    }
    aux = Serial.parseInt();

    if(aux < 5 || aux > 50){
      Serial.println("CAntidad invalida, debe estar entre 5 y 50 decimas");
    }

  }while (aux < 5 || aux > 50);

  Serial.print(aux);
  Serial.print(" decimas de segundo seleccionadas\n");
  return aux;
}

void Encender(int R, int G, int B){
  digitalWrite(9,R);
  digitalWrite(10,B);
  digitalWrite(11,G);
}

void loop() {
  // put your main code here, to run repeatedly:
  int decimas = 0;
  decimas = preguntarTiempo();
  int inicio = millis();
  int fin = inicio;

  while((fin - inicio)<=15000){
    Encender(0,1,0); // verde
    delay(100*decimas);
    Encender(1,1,0); // amarillo
    delay(100*decimas);
    Encender(1,0,0); // rojo
    delay(100*decimas);
    fin = millis();
  }
  Encender(0,0,0);
  Serial.print("Ciclo terminado. ingrese nuevo valor\n");
}
