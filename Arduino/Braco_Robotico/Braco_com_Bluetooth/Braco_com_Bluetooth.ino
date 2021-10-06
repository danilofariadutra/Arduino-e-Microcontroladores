/* Projeto: Braço Robotico controlado pelo módulo HC-05 (Bluetooth);
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

Servo Base, Garra, Braco1, Braco2;

const int movimentos_iniciais [4] = {100, 100, 50, 100}; // Set de posições iniciais dos servos na sequência: BASE, GARRA, BRACO1, BRACO2
bool inicio = true; // Booleana usada uma única vez para verificar se o Arduíno recebeu algum comando e para suavizar o primeiro comando do Braço
int mov, mov2, mov3, mov4, c; // Variaveis de cada servo. Sequência: BASE(mov), GARRA(mov1), BRACO1(mov3), BRACO2(mov4)
char comando; // Variavel para Identificar qual servo o Bluetooth está enviando como sinal e se é para Direita ou Esquerda

void setup() {
  bluetooth.begin(9600);
  Serial.begin(9600);
  pinMode(base, OUTPUT);
  pinMode(garra, OUTPUT);
  pinMode(braco1, OUTPUT);
  pinMode(braco2, OUTPUT);
  Base.attach(8);
  Garra.attach(3);
  Braco1.attach(4);
  Braco2.attach(5);

  // Inicializa as posições primárias com delay
  for (c = 0; c <= movimentos_iniciais[0]; c ++) {
    Base.write(c);
    Garra.write(c);
    Braco2.write(c);
    delay(15);
  }
  for (c = 0; c <= movimentos_iniciais[3]; c ++) {
    Braco1.write(c);
    delay(15);
  }
  // FIM
}

void loop() {

  if (bluetooth.available()) { // Verifica se há sinal de Bluetooth
    comando = bluetooth.read(); // Lê o sinal enviado via Bluetooth
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
    delay(15);
  }
  if (comando == 'R') {
    mov += 1;
    Serial.print("Base : ");
    Serial.println(mov);    
    if (mov > 180) {
      mov = 180;
    }
    Base.write(mov);
    delay(15);
  }  // FIM do Comandos para o servo BASE  

  // Comandos para o servo GARRA  
  if (comando == 'O') {
    mov2 += 1;
    if (mov2 > 132) {
      mov2 = 132;
    }
    Garra.write(mov2);
    delay(15);
  }
   
  if (comando == 'C') {
    mov2 -= 1;
    if (mov2 < 0) {
      mov2 = 0;
    }
    Garra.write(mov2);
    delay(15);
  } // FIM do Comandos para o servo GARRA  

  // Comandos para o servo BRACO1  
  if (comando == 'D') {
    mov3 += 1;
    if (mov3 > 170) {
      mov3 = 170;
    }
    Braco1.write(mov3);
    delay(15);
  }
  if (comando == 'E') {
    mov3 -= 1;
    if (mov3 < 10) {
      mov3 = 10;
    }
    Braco1.write(mov3);
    delay(15);
  } // FIM do Comandos para o servo BRACO1  

  // Comandos para o servo BRACO2 
  if (comando == 'G') {
    mov4 += 1;
    if (mov4 > 170) {
      mov4 = 170;
    }
    Braco2.write(mov4);
    delay(15);
  }
  if (comando == 'H') {
    mov4 -= 1;
    if (mov4 < 10) {
      mov4 = 10;
    }
    Braco2.write(mov4);
    delay(15);
  }// FIM do Comandos para o servo BRACO2
}
