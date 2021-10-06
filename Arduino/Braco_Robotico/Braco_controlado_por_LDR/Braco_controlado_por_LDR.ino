/* Projeto: Braço Robotico controlado pelo módulo HC-05 (Bluetooth);
 * Autor: Danilo Dutra;
 * Código teste para movimentar base ou microservo através de luminosidade lida pelo LDR, Esquerdo e Direito.
  * Projeto usado como princípio base para controlar a direção de um carro robotizado.
*/

#include <Servo.h>

#define LDR A5
#define LDR2 A4
#define Base 10

Servo base;

int v1, tempo = 15, readLDR, readLDR2;

void setup() {
  pinMode(Base, OUTPUT);
  base.attach(10);
  Serial.begin(9600);
}

void loop() {
  readLDR = analogRead(LDR);
  readLDR2 = analogRead(LDR2);

  if (readLDR < 900) {
    v1 ++;
    base.write(v1);
    delay(tempo);
    if (v1 >= 180) {
      v1 = 180;
    }
  }
  if (readLDR2 > 150) {
    v1 --;
    base.write(v1);
    delay(tempo);
    if (v1 <= 0) {
      v1 = 0;
    }
  }
}
