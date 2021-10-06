/* Projeto: The Cure - A Letter to Elise;
   Autor: Danilo Dutra;
   Itens: Buzzer Ativo, Arduino UNO;
*/

#include <Notas.h>
#define buzzer 10

float bpm = 80;
// Cálculo do tempo de cada nota, baseado no tempo da música;
float seminima = (60 / bpm) * 1000;
float semiBreve = seminima * 4;
float minima = seminima * 2;
float colcheia = seminima / 2;
float semiColcheia = seminima / 4;
float fusa = seminima / 8;
float semiFusa = seminima / 16;

void setup() {
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void baseVerso() {
  // A {
  tone(buzzer, NOTE_A3, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_A3, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_A3, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_A3, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_A3, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_A3, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_A3, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_A3, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_A3, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_A3, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_A3, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_A3, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_FS4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_FS4 , semiColcheia);
  delay(semiColcheia);
  // } A

  // E {
  tone(buzzer, NOTE_E4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_E4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_E4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_A5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_A5, semiColcheia);
  delay(semiColcheia);
  // } E

  // F# {
  tone(buzzer, NOTE_FS4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_FS4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_FS4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_FS4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_FS4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_FS4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_FS4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_FS4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_FS4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_FS4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_FS4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_FS4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_B5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_B5, semiColcheia);
  delay(semiColcheia);
  // } F#

  // D {
  tone(buzzer, NOTE_D4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_D4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_D4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_D4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_D4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_D4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_D4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_D4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_D4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_D4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS4, semiColcheia);
  delay(semiColcheia);
  // } D
}

void soloXilofone() {
  for (int c = 0; c < 3; c ++) {
    tone(buzzer, NOTE_E5, semiColcheia);
    delay(semiColcheia);
    tone(buzzer, NOTE_E5, semiColcheia);
    delay(semiColcheia);
    tone(buzzer, NOTE_E5, semiColcheia);
    delay(semiColcheia);
    tone(buzzer, NOTE_E5, semiColcheia);
    delay(semiColcheia);
    tone(buzzer, NOTE_CS5, colcheia);
    delay(colcheia);
    tone(buzzer, NOTE_CS5, semiColcheia);
    delay(semiColcheia);
    tone(buzzer, NOTE_CS5, semiColcheia);
    delay(semiColcheia);
    tone(buzzer, NOTE_B5, semiColcheia);
    delay(semiColcheia);
    tone(buzzer, NOTE_CS5, colcheia);
    delay(colcheia);
    tone(buzzer, NOTE_CS5, colcheia);
    delay(colcheia);
    noTone(buzzer);
    delay(colcheia + semiColcheia);
  }

  tone(buzzer, NOTE_D5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_D5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_D5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_A4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_A4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_B5, colcheia);
  delay(colcheia);
}

void versoUm() {
  // Oh Elise it doesn't matter what you say
  tone(buzzer, NOTE_FS5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_E5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_E5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS4, colcheia + semiColcheia);
  delay(colcheia + semiColcheia);
  tone(buzzer, NOTE_D4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_E5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_E5, seminima);
  delay(seminima);

  // I just can't stay here every ...
  tone(buzzer, NOTE_E5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_E5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS4, colcheia + semiColcheia);
  delay(colcheia + semiColcheia);

  //... yesterday like keep on acting ...
  tone(buzzer, NOTE_CS4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_B4, colcheia + semiColcheia);
  delay(colcheia + semiColcheia);
  tone(buzzer, NOTE_B4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_B4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS4, semiColcheia);
  delay(semiColcheia);

  //... out the same the way we act out
  tone(buzzer, NOTE_D4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS4, colcheia + semiColcheia);
  delay(colcheia + semiColcheia);
  tone(buzzer, NOTE_B4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_B4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_A4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_A4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_B4, colcheia + semiColcheia);
  delay(colcheia + semiColcheia);

  // Every way to smile, forget
  tone(buzzer, NOTE_E5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_E5, colcheia + semiColcheia);
  delay(colcheia + semiColcheia);
  tone(buzzer, NOTE_D4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_D4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_E5, colcheia + semiColcheia);
  delay(colcheia + semiColcheia);
  tone(buzzer, NOTE_FS5, colcheia);
  delay(colcheia);

  // And make-believe we never needed
  tone(buzzer, NOTE_FS5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_E5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_B4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS4, colcheia);
  delay(colcheia);

  // Any more than this
  tone(buzzer, NOTE_D4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_B4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_A3, seminima + semiColcheia);
  delay(seminima + semiColcheia);
  noTone(buzzer);
  delay(seminima);

  // Any more than this
  tone(buzzer, NOTE_D4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_B4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_A3, seminima + semiColcheia);
  delay(seminima + semiColcheia);
  noTone(buzzer);
  delay(seminima);
}

void versoDois() {
  // Oh Elise it doesn't matter what you do
  tone(buzzer, NOTE_FS5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_E5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_E5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS4, colcheia + semiColcheia);
  delay(colcheia + semiColcheia);
  tone(buzzer, NOTE_D4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_E5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_E5, seminima);
  delay(seminima);

  // I know I'll never really...
  tone(buzzer, NOTE_E5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_E5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS4, colcheia + semiColcheia);
  delay(colcheia + semiColcheia);

  // ...get inside of you, To make your...
  tone(buzzer, NOTE_D4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_B4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_A4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_A4, seminima + semiColcheia);
  delay(seminima + semiColcheia);
  tone(buzzer, NOTE_A4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_B4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS4, colcheia + semiColcheia);
  delay(colcheia + semiColcheia);


  // eyes catch fire The way they should
  tone(buzzer, NOTE_D4, colcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_B4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_B4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_A4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_A4, seminima + semiColcheia);
  delay(seminima + semiColcheia);

  // 5
  tone(buzzer, NOTE_E5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_E5, colcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_E5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_E5, colcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_FS5, colcheia);
  delay(colcheia);

  // 6
  tone(buzzer, NOTE_FS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E5, colcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_D4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, seminima);
  delay(seminima);
  tone(buzzer, NOTE_CS5, semiColcheia);
  delay(semiColcheia);

  // 7
  tone(buzzer, NOTE_D4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_B4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_A4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_B4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_A4, colcheia + semiColcheia);
  delay(colcheia + semiColcheia);

  // 8
  tone(buzzer, NOTE_D4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_D4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D4, colcheia + semiColcheia);
  delay(colcheia + semiColcheia);
  tone(buzzer, NOTE_A4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_B4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_A4, seminima);
  delay(seminima);
  tone(buzzer, NOTE_E5, semiColcheia);
  delay(semiColcheia);

  // 9
  tone(buzzer, NOTE_E5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_E5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_E5, colcheia + semiColcheia);
  delay(colcheia + semiColcheia);
  tone(buzzer, NOTE_FS5, colcheia);
  delay(colcheia);

  // 10
  tone(buzzer, NOTE_FS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_E5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_B4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS4, colcheia + semiColcheia);
  delay(colcheia + semiColcheia);

  // 11
  tone(buzzer, NOTE_D4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_B4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_A4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS4, seminima + semiColcheia);
  delay(seminima + semiColcheia);

  // 12
  tone(buzzer, NOTE_D4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_D4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_A4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_B4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_A4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_B4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_A4, minima);
  delay(minima);

  // 13
  tone(buzzer, NOTE_A4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_B4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_A4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_B4, colcheia + seminima + semiColcheia);
  delay(colcheia + seminima + semiColcheia);

  // 14
  tone(buzzer, NOTE_D4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_D4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_B4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_A4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_A4, minima);
  delay(minima);

  // 15
  tone(buzzer, NOTE_A4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_B4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_A4, colcheia + semiColcheia);
  delay(colcheia + semiColcheia);

  // 16
  tone(buzzer, NOTE_B4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_A4, colcheia + semiColcheia);
  delay(colcheia + semiColcheia);
  tone(buzzer, NOTE_B4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS4, colcheia + semiColcheia);
  delay(colcheia + semiColcheia);
  tone(buzzer, NOTE_D4, colcheia);
  delay(colcheia);
}

void interludio() {
  // 1
  tone(buzzer, NOTE_D4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_E5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_E4, colcheia + semiColcheia);
  delay(colcheia + semiColcheia);
  tone(buzzer, NOTE_E4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_D4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D4, colcheia + semiColcheia);
  delay(colcheia + semiColcheia);
  tone(buzzer, NOTE_CS4, colcheia);
  delay(colcheia);

  // 2
  tone(buzzer, NOTE_D4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_B4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_A4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_A4, seminima + colcheia);
  delay(seminima + colcheia);
  tone(buzzer, NOTE_E5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E5, colcheia);
  delay(colcheia);

  //3
  tone(buzzer, NOTE_E5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D4, colcheia + semiColcheia);
  delay(colcheia + semiColcheia);
  tone(buzzer, NOTE_CS4, colcheia);
  delay(colcheia);

  // 4
  tone(buzzer, NOTE_B4, colcheia + semiColcheia);
  delay(colcheia + semiColcheia);
  tone(buzzer, NOTE_CS4, colcheia + semiColcheia);
  delay(colcheia + semiColcheia);
  tone(buzzer, NOTE_A4, seminima + colcheia + semiColcheia);
  delay(seminima + colcheia + semiColcheia);
  tone(buzzer, NOTE_E5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E5, colcheia);
  delay(colcheia);

  // 5
  tone(buzzer, NOTE_E5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS4, colcheia);
  delay(colcheia);

  // 6
  tone(buzzer, NOTE_B4, colcheia + semiColcheia);
  delay(colcheia + semiColcheia);
  tone(buzzer, NOTE_CS4, colcheia + semiColcheia);
  delay(colcheia + semiColcheia);
  tone(buzzer, NOTE_A4, minima);
  delay(minima);
  tone(buzzer, NOTE_E5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E5, seminima + colcheia + semiColcheia);
  delay(seminima + colcheia + semiColcheia);

  // 7
  tone(buzzer, NOTE_D4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_D4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS4, colcheia + semiColcheia);
  delay(colcheia + semiColcheia);
  tone(buzzer, NOTE_D4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS4, colcheia + semiColcheia);
  delay(colcheia + semiColcheia);

  // 8
  tone(buzzer, NOTE_B4, colcheia + semiColcheia);
  delay(colcheia + semiColcheia);
  tone(buzzer, NOTE_CS4, colcheia + semiColcheia);
  delay(colcheia + semiColcheia);
  tone(buzzer, NOTE_A4, minima + semiColcheia);
  delay(minima + semiColcheia);
  tone(buzzer, NOTE_E5, semiColcheia);
  delay(semiColcheia);

  // 9
  tone(buzzer, NOTE_E5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS4, colcheia);
  delay(colcheia);

  // 10
  tone(buzzer, NOTE_B4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_A4, minima + seminima);
  delay(minima + seminima);
  tone(buzzer, NOTE_E5, semiColcheia);
  delay(semiColcheia);

  // 11
  tone(buzzer, NOTE_E5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS4, colcheia);
  delay(colcheia);

  // 12
  tone(buzzer, NOTE_B4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_A4, minima + colcheia + semiColcheia);
  delay(minima + colcheia + semiColcheia);
  tone(buzzer, NOTE_A4, semiColcheia);
  delay(semiColcheia);

  // 13
  tone(buzzer, NOTE_CS4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_B4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_A4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_A4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_B4, minima);
  delay(minima);
  tone(buzzer, NOTE_A4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_B4, semiColcheia);
  delay(semiColcheia);

  // 14
  tone(buzzer, NOTE_CS4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_B4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_B4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_B4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_A4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS4, colcheia + semiColcheia);
  delay(colcheia + semiColcheia);
  tone(buzzer, NOTE_B4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_B4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_A4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_GS3, semiColcheia);
  delay(semiColcheia);
}

void solo() {
  // 1
  tone(buzzer, NOTE_CS5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_D5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_E5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_E5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, semiColcheia);
  delay(semiColcheia);

  // 2
  tone(buzzer, NOTE_CS5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_D5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_E5, colcheia);
  delay(colcheia);

  // 3

  tone(buzzer, NOTE_CS4, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_FS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_FS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_FS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_FS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_GS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_GS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_GS5, semiColcheia);
  delay(semiColcheia);

  // 4
  tone(buzzer, NOTE_GS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_A5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_A5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_A5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_A5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_A5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_FS5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_FS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_FS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, semiColcheia);
  delay(semiColcheia);

  // 5
  tone(buzzer, NOTE_CS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_D5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_D5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_E5, colcheia + semiColcheia);
  delay(colcheia + semiColcheia);
  tone(buzzer, NOTE_E5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_FS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_FS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_FS5, semiColcheia);
  delay(semiColcheia);

  // 6
  tone(buzzer, NOTE_GS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_A5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_A5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_A5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_A5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_A5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_FS5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_FS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_FS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_FS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_FS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_FS5, semiColcheia);
  delay(semiColcheia);

  // 7
  tone(buzzer, NOTE_FS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_GS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_GS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_GS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_GS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_A5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_A5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_A5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_A5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_B5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_B5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_B5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_B5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_A5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_A5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_A5, semiColcheia);
  delay(semiColcheia);

  // 8
  tone(buzzer, NOTE_A5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_B5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_B5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_B5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_B5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_D5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_D5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_D5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_D5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, colcheia);
  delay(colcheia);

  // 9
  tone(buzzer, NOTE_B5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_B5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, seminima + colcheia);
  delay(seminima + colcheia);
  tone(buzzer, NOTE_B5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_B5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_B5, semiColcheia);
  delay(semiColcheia);

  // 10
  tone(buzzer, NOTE_B5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, seminima + colcheia);
  delay(seminima + colcheia);
  tone(buzzer, NOTE_B5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_B5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_B5, semiColcheia);
  delay(semiColcheia);

  // 11
  tone(buzzer, NOTE_B5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_B5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_B5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, colcheia + semiColcheia);
  delay(colcheia + semiColcheia);
  tone(buzzer, NOTE_CS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, semiColcheia);
  delay(semiColcheia);

  // 12
  tone(buzzer, NOTE_CS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_D5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_D5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_D5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_D5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_D5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_D5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_B5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_B5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_B5, semiColcheia);
  delay(semiColcheia);

  // 13
  tone(buzzer, NOTE_B5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_B5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_A5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_A5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_A5, semiColcheia);
  delay(semiColcheia);

  // 14
  tone(buzzer, NOTE_A5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_GS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_GS5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_GS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_FS5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_FS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_FS5, colcheia + semiColcheia);
  delay(colcheia + semiColcheia);
  tone(buzzer, NOTE_FS5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_FS5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_E5, colcheia);
  delay(colcheia);

  // 15
  tone(buzzer, NOTE_E5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_FS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_FS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_FS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_FS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, semiColcheia);
  delay(semiColcheia);

  // 16
  tone(buzzer, NOTE_B5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_D5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_D5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_B5, colcheia + semiColcheia);
  delay(colcheia + semiColcheia);
  tone(buzzer, NOTE_A5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_B5, semiColcheia);
  delay(semiColcheia);

  // 17
  tone(buzzer, NOTE_B5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_B5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_B5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, seminima + colcheia + semiColcheia);
  delay(seminima + colcheia + semiColcheia);
  tone(buzzer, NOTE_B5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_B5, semiColcheia);
  delay(semiColcheia);

  // 18
  tone(buzzer, NOTE_B5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_B5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_B5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, seminima + colcheia + semiColcheia);
  delay(seminima + colcheia + semiColcheia);
  tone(buzzer, NOTE_CS5, colcheia);
  delay(colcheia);

  // 19
  tone(buzzer, NOTE_B5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS5, colcheia + semiColcheia);
  delay(colcheia + semiColcheia);
  tone(buzzer, NOTE_CS5, colcheia + semiColcheia);
  delay(colcheia + semiColcheia);

  // 20
  tone(buzzer, NOTE_CS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_D5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_D5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_D5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_D5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_FS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_FS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_FS5, colcheia + semiColcheia);
  delay(colcheia + semiColcheia);
  tone(buzzer, NOTE_FS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_FS5, semiColcheia);
  delay(semiColcheia);
}

void outro() {

  tone(buzzer, NOTE_E5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_B5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS5, colcheia);
  delay(colcheia);
  noTone(buzzer);
  delay(colcheia + semiColcheia);

  tone(buzzer, NOTE_E5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_B5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, colcheia);
  delay(colcheia);
  noTone(buzzer);
  delay(seminima + semiColcheia);

  tone(buzzer, NOTE_E5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_B5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_B5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, semiColcheia);
  delay(semiColcheia);

  tone(buzzer, NOTE_D5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_D5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_D5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_D5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_A5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_A5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_B5, colcheia);
  delay(colcheia);

  tone(buzzer, NOTE_E5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_B5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS5, colcheia);
  delay(colcheia);
  noTone(buzzer);
  delay(colcheia + semiColcheia);

  tone(buzzer, NOTE_E5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_B5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, colcheia);
  delay(colcheia);
  noTone(buzzer);
  delay(seminima + semiColcheia);

  tone(buzzer, NOTE_E5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_E5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_B5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_CS5, colcheia);
  delay(colcheia);
  tone(buzzer, NOTE_B5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_CS5, semiColcheia);
  delay(semiColcheia);
}
void loop() {
  
    baseVerso();

    for (int c = 0; c < 2; c ++) {
    soloXilofone();
    }

    versoUm();

    for (int c = 0; c < 2; c ++) {
    soloXilofone();
    }

    versoDois();
    interludio();
    solo();
    versoUm();
    outro();
}
