#include <Notas.h>
#define buzzer 10

float seminima = 1000;
float semiBreve = seminima * 4;
float minima = seminima * 2;
float colcheia = seminima / 2;
float semiColcheia = seminima / 4;
float fusa = seminima / 8;
float semiFusa = seminima / 16;

int c, contador;

void setup()
{
  pinMode(buzzer, OUTPUT);
  pinMode(potenciometro, INPUT);
  pinMode(ledV, OUTPUT);
  Serial.begin(9600);

  // INTRO
Intro:
  for (c = 0; c <= 1; c++) {
    tone(buzzer, NOTE_AS4, semiColcheia);
    delay(semiColcheia);
    tone(buzzer, 0, semiColcheia);
    delay(semiColcheia);
    tone(buzzer, NOTE_F4, semiColcheia);
    delay(semiColcheia);
    tone(buzzer, 0, semiColcheia);
    delay(semiColcheia);
    tone(buzzer, NOTE_C5, semiColcheia);
    delay(semiColcheia );
    tone(buzzer, 0, semiColcheia);
    delay(semiColcheia);
    tone(buzzer, NOTE_F4, semiColcheia);
    delay(semiColcheia );
    tone(buzzer, 0, semiColcheia);
    delay(semiColcheia);
    tone(buzzer, NOTE_D5, semiColcheia);
    delay(semiColcheia );
    tone(buzzer, 0, semiColcheia);
    delay(semiColcheia);
    tone(buzzer, NOTE_AS4, semiColcheia);
    delay(semiColcheia);
    tone(buzzer, 0, semiColcheia);
    delay(semiColcheia);
    tone(buzzer, NOTE_C5, semiColcheia);
    delay(semiColcheia );
    tone(buzzer, 0, semiColcheia);
    delay(semiColcheia);
    tone(buzzer, NOTE_F4, semiColcheia);
    delay(semiColcheia );
    tone(buzzer, 0, semiColcheia);
    delay(semiColcheia);
  }

  tone(buzzer, NOTE_C5, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, 0, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_G4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, 0, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_AS4, semiColcheia);
  delay(semiColcheia );
  tone(buzzer, 0, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_G4, semiColcheia);
  delay(semiColcheia );
  tone(buzzer, 0, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_F5, semiColcheia);
  delay(semiColcheia );
  tone(buzzer, 0, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_G4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, 0, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_D5, semiColcheia);
  delay(semiColcheia );
  tone(buzzer, 0, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_A4, semiColcheia);
  delay(semiColcheia );
  tone(buzzer, 0, semiColcheia);
  delay(semiColcheia);

  tone(buzzer, NOTE_DS4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, 0, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_A4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, 0, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_D5, semiColcheia);
  delay(semiColcheia );
  tone(buzzer, 0, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_AS4, semiColcheia);
  delay(semiColcheia );
  tone(buzzer, 0, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_F5, semiColcheia);
  delay(semiColcheia );
  tone(buzzer, 0, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_AS4, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, 0, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_D5, semiColcheia);
  delay(semiColcheia );
  tone(buzzer, 0, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_AS4, semiColcheia);
  delay(semiColcheia );
  tone(buzzer, 0, semiColcheia);
  delay(semiColcheia);
  // FIM DA INTRO

  // Solo antes do Pré-Verso
  tone(buzzer, NOTE_F6, minima);
  delay(colcheia);
  tone(buzzer, NOTE_DS6, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_D6, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_DS6, semiColcheia);
  delay(semiColcheia);
  tone(buzzer, NOTE_D6, minima);
  delay(seminima);

  tone(buzzer, NOTE_C6, semiColcheia);
  delay(fusa);
  tone(buzzer, NOTE_D6, semiColcheia);
  delay(fusa);
  tone(buzzer, NOTE_C6, semiColcheia);
  delay(fusa + semiFusa);
  tone(buzzer, NOTE_AS5, minima);
  delay(seminima);

  tone(buzzer, NOTE_C5, minima);
  delay(colcheia + semiColcheia);
  tone(buzzer, NOTE_D5, minima);
  delay(colcheia);
  tone(buzzer, NOTE_G4, minima);
  delay(seminima);

  tone(buzzer, NOTE_DS3, minima);
  delay(fusa + semiFusa);
  tone(buzzer, NOTE_F3, minima);
  delay(fusa + semiFusa);
  tone(buzzer, NOTE_DS3, minima);
  delay(colcheia);

  tone(buzzer, NOTE_F5, minima);
  delay(seminima / 3);
  tone(buzzer, NOTE_DS5, minima);
  delay(seminima / 3);
  tone(buzzer, NOTE_D5, minima);
  delay(seminima / 3);
  tone(buzzer, NOTE_DS5, minima);
  delay(seminima / 3);
  tone(buzzer, NOTE_D5, minima);
  delay(seminima / 3);
  tone(buzzer, NOTE_C5, minima);
  delay(seminima / 3);
  tone(buzzer, NOTE_D5, minima);
  delay(seminima / 3);
  tone(buzzer, NOTE_C5, minima);
  delay(seminima / 3);
  tone(buzzer, NOTE_AS5, minima);
  delay(seminima / 3);
  tone(buzzer, NOTE_C5, minima);
  delay(seminima / 3);
  tone(buzzer, NOTE_D5, minima);
  delay(seminima / 3);
  tone(buzzer, NOTE_DS5, minima);
  delay(seminima / 3);

  tone(buzzer, NOTE_F5, minima);
  delay(minima);
  tone(buzzer, NOTE_G5, minima);
  delay(seminima + colcheia);

  tone(buzzer, NOTE_F5, minima);
  delay(minima + seminima + colcheia);
  tone(buzzer, NOTE_F6, minima);
  delay(minima);

  for (c = 0; c <= 1; c++) {
    tone(buzzer, NOTE_DS3, minima);
    delay(seminima + colcheia);

    tone(buzzer, NOTE_D4, minima);
    delay(fusa + semiFusa);
    tone(buzzer, NOTE_DS4, minima);
    delay(fusa + semiFusa);
    tone(buzzer, NOTE_D4, minima);
    delay(seminima + fusa);
  }
  // PRÉ-VERSO

preVerso:
  for (c = 0; c <= 1; c ++) {
    tone(buzzer, NOTE_AS4, minima);
    delay(colcheia);
    tone(buzzer, 0, minima);
    delay(fusa);
    tone(buzzer, NOTE_AS4, minima);
    delay(colcheia);
    tone(buzzer, 0, minima);
    delay(fusa);
    tone(buzzer, NOTE_AS4, minima);
    delay(fusa);
    tone(buzzer, 0, minima);
    delay(fusa);
    tone(buzzer, NOTE_AS4, minima);
    delay(colcheia);
    tone(buzzer, 0, minima);
    delay(fusa);
    tone(buzzer, NOTE_AS4, minima);
    delay(colcheia);
    tone(buzzer, 0, minima);
    delay(fusa + semiFusa);

    tone(buzzer, NOTE_G4, minima);
    delay(colcheia);
    tone(buzzer, 0, minima);
    delay(fusa);
    tone(buzzer, NOTE_G4, minima);
    delay(colcheia);
    tone(buzzer, 0, minima);
    delay(fusa);
    tone(buzzer, NOTE_G4, minima);
    delay(fusa);
    tone(buzzer, 0, minima);
    delay(fusa);
    tone(buzzer, NOTE_G4, minima);
    delay(colcheia);
    tone(buzzer, 0, minima);
    delay(fusa);
    tone(buzzer, NOTE_G4, minima);
    delay(colcheia);
    tone(buzzer, 0, minima);
    delay(fusa + semiFusa);

    if (contador == 1) {
      tone(buzzer, NOTE_DS3, minima);
      delay(seminima + colcheia);

      tone(buzzer, NOTE_D4, minima);
      delay(fusa + semiFusa);
      tone(buzzer, NOTE_DS4, minima);
      delay(fusa + semiFusa);
      tone(buzzer, NOTE_D4, minima);
      delay(seminima + fusa);

      tone(buzzer, NOTE_DS3, minima);
      delay(seminima + colcheia);

      tone(buzzer, NOTE_G5, minima);
      delay(fusa + semiFusa);
      tone(buzzer, NOTE_GS5, minima);
      delay(fusa + semiFusa);
      tone(buzzer, NOTE_G4, minima);
      delay(seminima + fusa);

      goto preVerso;
    }


    for (c = 0; c <= 1; c++) {
      tone(buzzer, NOTE_DS3, minima);
      delay(seminima + colcheia);

      tone(buzzer, NOTE_D4, minima);
      delay(fusa + semiFusa);
      tone(buzzer, NOTE_DS4, minima);
      delay(fusa + semiFusa);
      tone(buzzer, NOTE_D4, minima);
      delay(seminima + fusa);
    }
    contador ++;
  }

  tone(buzzer, NOTE_AS4, minima);
  delay(colcheia);
  tone(buzzer, 0, minima);
  delay(fusa);
  tone(buzzer, NOTE_AS4, minima);
  delay(colcheia);
  tone(buzzer, 0, minima);
  delay(fusa);
  tone(buzzer, NOTE_AS4, minima);
  delay(fusa);
  tone(buzzer, 0, minima);
  delay(fusa);
  tone(buzzer, NOTE_AS4, minima);
  delay(colcheia);
  tone(buzzer, 0, minima);
  delay(fusa);
  tone(buzzer, NOTE_AS4, minima);
  delay(colcheia);
  tone(buzzer, 0, minima);
  delay(fusa + semiFusa);

  tone(buzzer, NOTE_G4, minima);
  delay(colcheia);
  tone(buzzer, 0, minima);
  delay(fusa);
  tone(buzzer, NOTE_G4, minima);
  delay(colcheia);
  tone(buzzer, 0, minima);
  delay(fusa);
  tone(buzzer, NOTE_G4, minima);
  delay(fusa);
  tone(buzzer, 0, minima);
  delay(fusa);
  tone(buzzer, NOTE_G4, minima);
  delay(colcheia);
  tone(buzzer, 0, minima);
  delay(fusa);
  tone(buzzer, NOTE_G4, minima);
  delay(colcheia);
  tone(buzzer, 0, minima);
  delay(fusa + semiFusa);

  tone(buzzer, NOTE_DS3, minima);
  delay(seminima + colcheia);

  tone(buzzer, NOTE_D4, minima);
  delay(fusa + semiFusa);
  tone(buzzer, NOTE_DS4, minima);
  delay(fusa + semiFusa);
  tone(buzzer, NOTE_D4, minima);
  delay(seminima + fusa);

  tone(buzzer, NOTE_DS3, minima);
  delay(seminima + colcheia);

  tone(buzzer, NOTE_G5, minima);
  delay(fusa + semiFusa);
  tone(buzzer, NOTE_GS5, minima);
  delay(fusa + semiFusa);
  tone(buzzer, NOTE_G4, minima);
  delay(seminima + fusa);

  // FIM PRÉ-VERSO
}
void loop() {
}
