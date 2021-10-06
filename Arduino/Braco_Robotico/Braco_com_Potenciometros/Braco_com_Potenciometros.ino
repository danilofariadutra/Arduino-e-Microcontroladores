/* Projeto: Braço Robotico controlado por 4 Potenciometros;
 * Autor: Danilo Dutra;
 * Projeto pode ser modificado, para utilizar Bluetooth ou Frequência Rádio também, vai da sua necessidade e uso.
 */

#include <Servo.h>

#define p1 A0
#define p2 A1
#define p3 A2
#define p4 A3
#define Base 4
#define Garra 5
#define Braco1 6
#define Braco2 7

Servo base, garra, braco1, braco2;

int v1, v2, v3, v4;

void setup() {
  pinMode(p1, INPUT);
  pinMode(p2, INPUT);
  pinMode(p3, INPUT);
  pinMode(p4, INPUT);
  pinMode(Base, OUTPUT);
  pinMode(Garra, OUTPUT);
  pinMode(Braco1, OUTPUT);
  pinMode(Braco2, OUTPUT);
  base.attach(4);
  garra.attach(5);
  braco1.attach(6);
  braco2.attach(7);
  Serial.begin(9600);
}

void loop() {
  v1 = map(analogRead(p1), 0, 1023, 0, 180);
  v2 = map(analogRead(p2), 0, 1023, 0, 125);
  v3 = map(analogRead(p3), 0, 1023, 80, 180);
  v4 = map(analogRead(p4), 0, 1023, 0, 180);

  if (v1) {
    base.write(v1);
    Serial.print("Base: ");
    Serial.println(v1);
  }
  if (v2) {
    garra.write(v2);
    Serial.print("Garra: ");
    Serial.println(v2);
  }
  if (v3) {
    braco1.write(v3);
    Serial.print("Braco 1: ");
    Serial.println(v3);
  }
  if (v4) {
    braco2.write(v4);
    Serial.print("Braco 2: ");
    Serial.println(v4);
  }
  delay(30);
}
