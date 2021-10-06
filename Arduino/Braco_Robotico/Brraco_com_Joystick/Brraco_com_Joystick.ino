#include <Servo.h>

#define base 8 // Porta Digital 8
#define garra 3 // Porta Digital 3
#define braco1 4 // Porta Digital 4
#define braco2 5 // Porta Digital 5
#define joyLX A0
#define joyLY A1
#define joyRX A4
#define joyRY A5

Servo Base, Garra, Braco1, Braco2;

const int movimentos_iniciais [4] = {100, 100, 50, 100}; // Set de posições iniciais dos servos na sequência: BASE, GARRA, BRACO1, BRACO2
bool inicio = true; // Booleana usada uma única vez para verificar se o Arduíno recebeu algum comando e para suavizar o primeiro comando do Braço
int mov = 89, mov2 = 65, mov3 = 89, mov4 = 65, c; // Variaveis de cada servo. Sequência: BASE(mov), GARRA(mov1), BRACO1(mov3), BRACO2(mov4)

int LX,
    LY,
    RX,
    RY,
    LButton,
    velocidade = 2,
    tempo = 15;

void setup() {
  Serial.begin(9600);
  pinMode(base, OUTPUT);
  pinMode(garra, OUTPUT);
  pinMode(braco1, OUTPUT);
  pinMode(braco2, OUTPUT);
  pinMode(joyLX, INPUT);
  pinMode(joyLY, INPUT);
  pinMode(joyRX, INPUT);
  pinMode(joyRY, INPUT);

  Base.attach(8);
  Garra.attach(3);
  Braco1.attach(4);
  Braco2.attach(5);

  LX = map(analogRead(joyLX), 0, 1023, 0, 180);
  LY = map(analogRead(joyLY), 0, 1023, 0, 132);
  RX = map(analogRead(joyRX), 0, 1023, 0, 180);
  RY = map(analogRead(joyRY), 0, 1023, 0, 180);

  // Inicializa as posições primárias com delay
  for (c = 0; c <= movimentos_iniciais[0]; c ++) {
    Base.write(c);
    Garra.write(c);
    Braco2.write(c);
    delay(tempo * 0.75);
  }
  for (c = 0; c <= movimentos_iniciais[3]; c ++) {
    Braco1.write(c);
    delay(tempo * 0.75);
  }
  // FIM

  if (inicio != false) { // Booleana para verificar se houve um primeiro movimento
    mov = movimentos_iniciais[0];
    mov2 = movimentos_iniciais[1];
    mov3 = movimentos_iniciais[2];
    mov4 = movimentos_iniciais[3];
  }
}

void loop() {

  LX = map(analogRead(joyLX), 0, 1023, 0, 180);
  LY = map(analogRead(joyLY), 0, 1023, 0, 132);
  RX = map(analogRead(joyRX), 0, 1023, 0, 180);
  RY = map(analogRead(joyRY), 0, 1023, 0, 180);

  if (LX != 89 && LY != 65 && RX != 89 && RY != 65) {
    inicio = false; // Seta como False para que a condicional anterior não se repita
  }

  Serial.print("LX: ");
  Serial.println(mov);
  Serial.print("LY: ");
  Serial.println(mov2);
  Serial.print("RX: ");
  Serial.println(mov3);
  Serial.print("RY: ");
  Serial.println(mov4);


  if (LX < 89) {
    mov -= velocidade;
    if (mov < 0) {
      mov = 0;
    }
    if (LX < mov) {
      Base.write(mov);
      delay(tempo);
    }
  }

  if (LX > 89) {
    mov += velocidade;
    if (mov > 180) {
      mov = 180;
    }
    if (LX > mov) {
      Base.write(mov);
      delay(tempo);
    }
  }

  // GARRA
  if (LY < 65) {
    mov2 -= velocidade;
    if (mov2 < 0) {
      mov2 = 0;
    }
    if (LY < mov2) {
      Garra.write(mov2);
      delay(tempo);
    }
  }

  if (LY > 65) {
    mov2 += velocidade;
    if (mov2 > 132) {
      mov2 = 132;
    }
    if (LY > mov2) {
      Garra.write(mov2);
      delay(tempo);
    }
  }
  // BRACO 1
  if (RX < 89) {
    mov3 -= velocidade;
    if (mov3 < 0) {
      mov3 = 0;
    }
    if (RX < mov3) {
      Braco1.write(mov3);
      delay(tempo);
    }
  }

  if (RX > 89) {
    mov3 += velocidade;
    if (mov3 > 180) {
      mov3 = 180;
    }
    if (RX > mov3) {
      Braco1.write(mov3);
      delay(tempo);
    }
  }

  //BRACO 2
  if (RY < 65) {
    mov4 -= velocidade;
    if (mov4 < 0) {
      mov4 = 0;
    }
    if (RY < mov4) {
      Braco2.write(mov4);
      delay(tempo);
    }
  }

  if (RY > 65) {
    mov4 += velocidade;
    if (mov4 > 180) {
      mov4 = 180;
    }
    if (RY > mov4) {
      Braco2.write(mov4);
      delay(tempo);
    }
  }
}
