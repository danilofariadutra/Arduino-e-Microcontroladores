/* Projeto: Potenciometro que controla uma sequência de LEDs de acordo com a Frequência que vai aumentando pelo potenciometro, e utilizando um Buzzer Ativo.
 * Itens: Buzzer Ativo, Potenciometro 5k, 8 LEDs, 74HC595, Protoboard, jumpers e fios, Arduino Uno.
 * Autor: Danilo Dutra;
 */

#define buzzer 10
#define pot A5
#define latch 9
#define clk 8
#define data 7

int potenciometro;

void setup() {
  Serial.begin(9600);
  pinMode(latch, OUTPUT);
  pinMode(clk, OUTPUT);
  pinMode(data, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(pot, INPUT);

}
// Controla os LEDs pelo Potenciometro
void loop() {

  potenciometro = map(analogRead(pot), 0, 1023, 0, 5000);
  Serial.println(potenciometro);

  if (potenciometro < 1) {
    shiftOut(data, clk, LSBFIRST, 0x00);
    digitalWrite(latch, HIGH);
  }

  if (potenciometro < 100) {

    shiftOut(data, clk, LSBFIRST, 0x80);
    digitalWrite(latch, HIGH);
  }

  if (potenciometro > 100 && potenciometro < 200) {
    shiftOut(data, clk, LSBFIRST, 0xC0);
    digitalWrite(latch, HIGH);
  }

  if (potenciometro > 200 && potenciometro < 300) {
    shiftOut(data, clk, LSBFIRST, 0xE0);
    digitalWrite(latch, HIGH);
  }

  if (potenciometro > 300 && potenciometro < 400) {
    shiftOut(data, clk, LSBFIRST, 0xF0);
    digitalWrite(latch, HIGH);
  }

  if (potenciometro <= 400 && potenciometro < 500) {
    shiftOut(data, clk, LSBFIRST, 0xF8);
    digitalWrite(latch, HIGH);
  }
  if (potenciometro > 500 && potenciometro < 600) {
    shiftOut(data, clk, LSBFIRST, 0xFC);
    digitalWrite(latch, HIGH);
  }

  if (potenciometro > 600 && potenciometro < 700) {
    shiftOut(data, clk, LSBFIRST, 0xFE);
    digitalWrite(latch, HIGH);
  }

  if (potenciometro > 700) {
    shiftOut(data, clk, LSBFIRST, 0xFF);
    digitalWrite(latch, HIGH);
  }
  digitalWrite(latch, LOW);
  tone(buzzer, potenciometro, 100);
}

/* CONTROLA O BUZZER PELO POTENCIOMETRO
  void loop() {
  tone(buzzer, map(analogRead(pot), 0, 1023, 0, 5000), 100);
  Serial.println(analogRead(pot));

  }*/
