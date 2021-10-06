#include <Notas.h>
#define solo 9
#define base 10

float seminima = 1000;
float semiBreve = seminima * 4;
float minima = seminima * 2;
float colcheia = seminima / 2;
float semiColcheia = seminima / 4;
float fusa = seminima / 8;
float semiFusa = seminima / 16;
int c;

void setup() {
  pinMode(base, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  /* Solo 
  tone(base, NOTE_E7, minima + semiMinima);
  delay(colcheia);
  tone(base, 0, semiColcheia);
  delay(colcheia);
  tone(base, NOTE_FS7, minima + semiMinima);
  delay(colcheia);
  tone(base, 0, semiColcheia);
  delay(colcheia);
  tone(base, NOTE_G7, semiMinima + colcheia);
  delay(semiColcheia);
  tone(base, 0, semiColcheia);
  delay(semiColcheia);
  tone(base, NOTE_A7, semiMinima);
  delay(semiColcheia);
  tone(base, 0, semiColcheia);
  delay(semiColcheia);
  tone(base, NOTE_G7, minima + semiMinima);
  delay(semiColcheia);
  tone(base, 0, semiColcheia);
  delay(semiColcheia);
  tone(base, NOTE_E7, minima + semiMinima);
  delay(semiColcheia);
  tone(base, 0, minima);
  delay(minima);
   */

  tone(base, NOTE_E5, semiColcheia);
  delay(fusa);
  tone(base, 0, semiColcheia);
  delay(fusa);
  tone(base, NOTE_B5, semiColcheia);
  delay(fusa);
  tone(base, NOTE_E5, semiColcheia);
  delay(fusa);
  tone(base, 0, semiColcheia);
  delay(fusa);
  tone(base, NOTE_B5, semiColcheia);
  delay(fusa);
  tone(base, NOTE_E5, semiColcheia);
  delay(colcheia);

  tone(base, NOTE_FS5, semiColcheia);
  delay(fusa);
  tone(base, 0, semiColcheia);
  delay(fusa);
  tone(base, NOTE_D6, semiColcheia);
  delay(fusa);
  tone(base, NOTE_FS5, semiColcheia);
  delay(fusa);
  tone(base, 0, semiColcheia);
  delay(semiColcheia);
  tone(base, NOTE_D6, semiColcheia);
  delay(fusa);
  tone(base, NOTE_FS5, semiColcheia);
  delay(colcheia);

  tone(base, NOTE_D5, semiColcheia);
  delay(fusa);
  tone(base, 0, semiColcheia);
  delay(fusa);
  tone(base, NOTE_A5, semiColcheia);
  delay(fusa);
  tone(base, NOTE_D5, semiColcheia);
  delay(fusa);
  tone(base, 0, semiColcheia);
  delay(fusa);
  tone(base, NOTE_A5, semiColcheia);
  delay(fusa);
  tone(base, NOTE_D5, semiColcheia);
  delay(colcheia);

  for (c = 0; c <= 1; c++) {

    tone(base, NOTE_C5, semiColcheia);
    delay(fusa);
    tone(base, 0, semiColcheia);
    delay(fusa);
    tone(base, NOTE_G5, semiColcheia);
    delay(fusa);
    tone(base, NOTE_C5, semiColcheia);
    delay(fusa);
    tone(base, 0, semiColcheia);
    delay(fusa);
    tone(base, NOTE_G5, semiColcheia);
    delay(fusa);
    tone(base, NOTE_C5, semiColcheia);
    delay(colcheia);
  }

  tone(base, NOTE_D5, semiColcheia);
  delay(fusa);
  tone(base, 0, semiColcheia);
  delay(fusa);
  tone(base, NOTE_A5, semiColcheia);
  delay(fusa);
  tone(base, NOTE_D5, semiColcheia);
  delay(fusa);
  tone(base, 0, semiColcheia);
  delay(fusa);
  tone(base, NOTE_A5, semiColcheia);
  delay(fusa);
  tone(base, NOTE_D5, semiColcheia);
  delay(colcheia);

  for (c = 0; c <= 1; c++) {
    tone(base, NOTE_E5, semiColcheia);
    delay(fusa);
    tone(base, 0, semiColcheia);
    delay(fusa);
    tone(base, NOTE_B5, semiColcheia);
    delay(fusa);
    tone(base, NOTE_E5, semiColcheia);
    delay(fusa);
    tone(base, 0, semiColcheia);
    delay(fusa);
    tone(base, NOTE_B5, semiColcheia);
    delay(fusa);
    tone(base, NOTE_E5, semiColcheia);
    delay(colcheia);
  }
}
