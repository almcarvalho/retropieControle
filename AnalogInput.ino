/*

*/

// constantes nao sao alteradas:
const int analogInPin = A0;
const int analogInPin1 = A1;
const int analogInPin2 = A2;
const int analogInPin3 = A3;

int sensorVolante = 0;
int sensorAcelerador = 0;
int sensorFreio = 0;
int sensorBorboletaEsquerda = 0;


int rele2 = 2; //esquerda
int rele3 = 3; //direita
int rele4 = 4; //acelerador
int rele5 = 5; //freio
int rele6 = 6; //borboleta esquerda

int rele7 = 7; //esq
int rele8 = 8; //direita



void setup() {
  Serial.begin(9600);
  pinMode(rele2, OUTPUT); //esquerda
  pinMode(rele3, OUTPUT); //direita
  pinMode(rele4, OUTPUT); //acelerador
  pinMode(rele5, OUTPUT); //freio
  pinMode(rele6, OUTPUT); //borboleta esquerda
  pinMode(rele7, OUTPUT);
  pinMode(rele8, OUTPUT);
}

void loop() {
  sensorVolante = analogRead(analogInPin); //volante pino 0
  sensorAcelerador = analogRead(analogInPin1); //acelerador
  sensorFreio = analogRead(analogInPin2); //freio
  sensorBorboletaEsquerda = analogRead(analogInPin3); //borb esqu

  Serial.print("sensor = " );
  Serial.print(sensorAcelerador);

  if (sensorVolante < 300) { //anterior 400
    digitalWrite(rele2, HIGH);
    digitalWrite(rele7, HIGH);
  } else {
    digitalWrite(rele2, LOW);
    digitalWrite(rele7, LOW);
  }


  if (sensorVolante > 700) { //anterior 500
    digitalWrite(rele3, HIGH);
    digitalWrite(rele8, HIGH);
  } else {
    digitalWrite(rele3, LOW);
    digitalWrite(rele8, LOW);
  }

  if (sensorVolante > 400 && sensorVolante < 500) {
    digitalWrite(rele2, LOW);
    digitalWrite(rele3, LOW);
    digitalWrite(rele7, LOW);
    digitalWrite(rele8, LOW);
  }

  if (sensorAcelerador > 120) {
    digitalWrite(rele4, HIGH);
  } else {
    digitalWrite(rele4, LOW);
  }

  if (sensorFreio > 120) {
    digitalWrite(rele5, HIGH);
  } else {
    digitalWrite(rele5, LOW);
  }


  if (sensorBorboletaEsquerda > 200) {
    digitalWrite(rele6, HIGH);
  } else {
    digitalWrite(rele6, LOW);
  }



  // Aguarda 2 milissegundos antes do proximo loop:
  delay(50);
}
