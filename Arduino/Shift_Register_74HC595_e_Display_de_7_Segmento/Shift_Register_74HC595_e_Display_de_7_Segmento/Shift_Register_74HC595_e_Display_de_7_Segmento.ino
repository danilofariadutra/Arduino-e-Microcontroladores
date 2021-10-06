/* Projeto: Display de 7 Segmentos, controlado por sequência de variaveis 8 bit em um Vetor, que através do ShiftRegister 74HC595 fazem uma contagem de 0 até 10, e uma contagem regressiva de 10 até 0;
 * Autor: Danilo Dutra;
 */

#define latch 5
#define clk 6
#define shift 7

int c, tempo = 500;

byte numeros[10] = {
  0b01100000, // 1
  0b11011100, // 2
  0b11110100, // 3
  0b01100110, // 4
  0b10110110, // 5
  0b10111110, // 6
  0b11100000, // 7
  0b11111110, // 8
  0b11110110, // 9
  0b11111010, // 0
};

void setup() {
  Serial.begin(9600);
  pinMode(latch, OUTPUT);
  pinMode(clk, OUTPUT);
  pinMode(shift, OUTPUT);
}

void loop() {

  for (c = 0; c < 10; c ++) {
    digitalWrite(latch, LOW);
    shiftOut(shift, clk, LSBFIRST, numeros[c]);
    digitalWrite(latch, HIGH);
    Serial.println(c);
    delay(tempo);
  }

  for (c = 10; c > 0; c --) {
    digitalWrite(latch, LOW);
    shiftOut(shift, clk, LSBFIRST, numeros[c]);
    digitalWrite(latch, HIGH);
    Serial.println(c);
    delay(tempo);
  }
}
