/* Projeto: Braço Robotico controlado pelo módulo HC-05 (Bluetooth) e Joystick;
 * Autor: Danilo Dutra;
 * Projeto pode ser modificado, para utilizar Frequência Rádio também, vai da sua necessidade e uso.
 */

#include <Servo.h>
#include <SoftwareSerial.h> // Biblioteca do Bluetooth HC-05

SoftwareSerial bluetooth(0, 1); // Seta o TX e RX do HC-05

#define base 8 // Porta Digital 8
#define garra 3 // Porta Digital 3
#define braco1 4 // Porta Digital 4
#define braco2 5 // Porta Digital 5
#define joyLX A0
#define joyLY A1
#define joyRX A4
#define joyRY A5
#define BT 11

Servo Base, Garra, Braco1, Braco2;

const int movimentos_iniciais [4] = {100, 100, 50, 100}; // Set de posições iniciais dos servos na sequência: BASE, GARRA, BRACO1, BRACO2
bool inicio = true; // Booleana usada uma única vez para verificar se o Arduíno recebeu algum comando e para suavizar o primeiro comando do Braço
int mov = 89, mov2 = 65, mov3 = 89, mov4 = 65, c; // Variaveis de cada servo. Sequência: BASE(mov), GARRA(mov1), BRACO1(mov3), BRACO2(mov4)
char comando, modo = 'J'; // Variavel para Identificar qual servo o Bluetooth está enviando como sinal e se é para Direita ou Esquerda

int LX,
    LY,
    RX,
    RY,
    LButton,
    atual1,
    atual2,
    atual3,
    atual4,
    velocidade = 10,
    tempo = 15,
    btAtual,
    btAnterior = 1,
    estado = 0;

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  pinMode(base, OUTPUT);
  pinMode(garra, OUTPUT);
  pinMode(braco1, OUTPUT);
  pinMode(braco2, OUTPUT);
  pinMode(joyLX, INPUT);
  pinMode(joyLY, INPUT);
  pinMode(joyRX, INPUT);
  pinMode(joyRY, INPUT);
  pinMode(BT, INPUT_PULLUP);

  Base.attach(8);
  Garra.attach(3);
  Braco1.attach(4);
  Braco2.attach(5);

  LX = map(analogRead(joyLX), 0, 1023, 0, 180);
  LY = map(analogRead(joyLY), 0, 1023, 0, 132);
  RX = map(analogRead(joyRX), 0, 1023, 0, 180);
  RY = map(analogRead(joyRY), 0, 1023, 0, 180);
  btAtual = digitalRead(BT);

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
  Serial.println(modo);
  Serial.println(estado);
  btAtual = digitalRead(BT);
  delay(100);

  if (btAtual == 0 && btAnterior == 1) {
    btAnterior = 0;
    estado = 1;
    modo = 'J';
  }
  else {
    if (estado == 1 && btAtual == 0) {
      btAnterior = 1;
      estado = 0;
      modo = 'B';
    }
  }

  while (modo == 'B') {
    Serial.println(modo);
    Serial.println(estado);

    if (bluetooth.available()) { // Verifica se há sinal de Bluetooth
      comando = bluetooth.read(); // Lê o sinal enviado via Bluetooth
    }
    btAtual = digitalRead(BT);

    if (btAtual == 0 && btAnterior == 1 || comando == 'J') {
      btAnterior = 0;
      estado = 1;
      modo = 'J';
    }
    else {
      if (estado == 1 && btAtual == 0) {
        btAnterior = 1;
        estado = 0;
        modo = 'B';
      }
    }

    if (inicio != false) { // Booleana para verificar se houve um primeiro movimento
      mov = movimentos_iniciais[0];
      mov2 = movimentos_iniciais[1];
      mov3 = movimentos_iniciais[2];
      mov4 = movimentos_iniciais[3];
    }
    inicio = false; // Seta como False para que a condicional anterior não se repita

    // Comandos para o servo BASE
    if (comando == 'L') {
      mov -= 1;
      Serial.print("Base : ");
      Serial.println(mov);
      if (mov < 0) {
        mov = 0;
      }
      Base.write(mov);
      //delay(15);
    }
    if (comando == 'R') {
      mov += 1;
      Serial.print("Base : ");
      Serial.println(mov);
      if (mov > 180) {
        mov = 180;
      }
      Base.write(mov);
      //delay(15);
    }  // FIM do Comandos para o servo BASE

    // Comandos para o servo GARRA
    if (comando == 'O') {
      mov2 += 1;
      if (mov2 > 132) {
        mov2 = 132;
      }
      Garra.write(mov2);
      //delay(15);
    }

    if (comando == 'C') {
      mov2 -= 1;
      if (mov2 < 0) {
        mov2 = 0;
      }
      Garra.write(mov2);
      //delay(15);
    } // FIM do Comandos para o servo GARRA

    // Comandos para o servo BRACO1
    if (comando == 'D') {
      mov3 += 1;
      if (mov3 > 170) {
        mov3 = 170;
      }
      Braco1.write(mov3);
      //delay(15);
    }
    if (comando == 'E') {
      mov3 -= 1;
      if (mov3 < 10) {
        mov3 = 10;
      }
      Braco1.write(mov3);
      //delay(15);
    } // FIM do Comandos para o servo BRACO1

    // Comandos para o servo BRACO2
    if (comando == 'G') {
      mov4 += 1;
      if (mov4 > 170) {
        mov4 = 170;
      }
      Braco2.write(mov4);
      //delay(15);
    }
    if (comando == 'H') {
      mov4 -= 1;
      if (mov4 < 10) {
        mov4 = 10;
      }
      Braco2.write(mov4);
      //delay(15);
    }// FIM do Comandos para o servo BRACO2
  }

  while (modo == 'J') {
    Serial.println(modo);
    Serial.println(estado);

    btAtual = digitalRead(BT);
    delay(100);

    if (bluetooth.available()) { // Verifica se há sinal de Bluetooth
      comando = bluetooth.read(); // Lê o sinal enviado via Bluetooth
    }

    if (btAtual == 0 && btAnterior == 1) {
      btAnterior = 0;
      estado = 1;
      modo = 'J';
    }
    else {
      if (estado == 1 && btAtual == 0 || comando == 'X') {
        btAnterior = 1;
        estado = 0;
        modo = 'B';
        mov, mov2, mov3, mov4 = movimentos_iniciais[0], movimentos_iniciais[1], movimentos_iniciais[2], movimentos_iniciais[3];
      }
    }

    LX = map(analogRead(joyLX), 0, 1023, 0, 180);
    LY = map(analogRead(joyLY), 0, 1023, 0, 132);
    RX = map(analogRead(joyRX), 0, 1023, 0, 180);
    RY = map(analogRead(joyRY), 0, 1023, 0, 180);
    btAtual = digitalRead(BT);

    if (LX != 89 && LY != 65 && RX != 89 && RY != 65) {
      inicio = false; // Seta como False para que a condicional anterior não se repita
    }

    Serial.print("LX: ");
    Serial.println(LX);
    Serial.print("LY: ");
    Serial.println(LY);
    Serial.print("RX: ");
    Serial.println(RX);
    Serial.print("RY: ");
    Serial.println(LY);

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
}
