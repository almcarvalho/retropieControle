
const int btnSobe = 2;
const int btnDesce = 3;

const int ledPin =  13;

const int analogInPin = A0;

int releSobe = 4; //esquerda
int releDesce = 5; //direita


int buttonState = 0;
int buttonState3 = 0;

int sensorMotor = 0;

void setup() {
  Serial.begin(9600);
  pinMode(releSobe, OUTPUT); //esquerda
  pinMode(releDesce, OUTPUT); //direita
  // inicializa o pino do LED como saida:
  pinMode(ledPin, OUTPUT);

  pinMode(btnSobe, INPUT);
  pinMode(btnDesce, INPUT);
}

void loop() {
  sensorMotor = analogRead(analogInPin); //volante pino 0

  Serial.println("Motor = " );
  Serial.println(sensorMotor);

  // faz a leitura do valor do botao:
  buttonState = digitalRead(btnSobe);

  // verifica se o botao esta pressionado.
  // em caso positivo, buttonState e HIGH:
  if (buttonState == HIGH) {
    // liga o LED:
   // if (sensorMotor > 700) {
      digitalWrite(releSobe, HIGH);
    //}
    //Serial.println("btn Porta 2 Sobe" );
  }
  else {
    // desliga o LED:
    digitalWrite(releSobe, LOW);
    //Serial.println("botao Porta 2 apagado" );
  }


  buttonState3 = digitalRead(btnDesce);
  if (buttonState3 == HIGH) {
    // liga o LED:
    //if (sensorMotor > 20) {
      digitalWrite(releDesce, HIGH);
    //}
    //Serial.println("btn Porta 3 Desce" );
  }
  else {
    // desliga o LED:
    digitalWrite(releDesce, LOW);
    //Serial.println("botao Porta 3 apagado" );
  }

  delay(50);
}
