/* Projeto: Display de 7 Segmentos que faz contagem
 * Autor: Danilo Dutra;
 * Itens: Display 7 Segmentos, Protoboard, jumpers e fios, Arduino UNO; // Recomendado o uso de Resistores
 */

#define pinA 12
#define pinB 8
#define pinC 4
#define pinD 6
#define pinE 7
#define pinF 11
#define pinG 3
#define dg1 2
#define dg2 9
#define dg3 10
#define dg4 13
#define dp 5

int velocidade = 1, mil, seg, dec, uni;

byte segmentos[7] = {pinA, pinB, pinC, pinD, pinF, pinG};
byte ordem_digitos[4] = {dg1, dg2, dg3, dg4};
byte digitos[4][4] = { {0,0,0,1}, {0, 0, 1, 0}, {0, 1, 0, 0}, {1, 0, 0, 0}};
byte sete_segmentos_digitos[10][7] = { {0, 0, 0, 0, 0, 0, 0}, // 0
                                       {0, 1, 1, 0, 0, 0, 0}, // 1
                                       {1, 1, 1, 1, 1, 1, 1}, // 2
                                       {1, 1, 1, 1, 0, 1, 1}, // 3
                                       {1, 1, 1, 0, 0, 0, 1}, // 4
                                       {1, 0, 1, 1, 0, 1, 1}, // 5
                                       {1, 0, 1, 1, 1, 1, 1}, // 6
                                       {1, 1, 1, 0, 0, 1, 0}, // 7
                                       {1, 1, 1, 1, 1, 1, 1}, // 8
                                       {1, 1, 1, 1, 0, 1, 1}  // 9
};

void EscreverDigito (byte digito, byte numero) {
  int sequencia = 0;

  AtivarDigito(digito);

  for (byte i = 0; i < 7; i ++) {
    digitalWrite(segmentos[sequencia], sete_segmentos_digitos[numero][i]);
    sequencia ++;
  }  
}

void AtivarDigito(int x) {
  digitalWrite(dg1, 1);
  digitalWrite(dg2, 1);
  digitalWrite(dg3, 1);
  digitalWrite(dg4, 1);

  switch(x) {
    case 1:
    digitalWrite(dg1, 0);
    break;

    case 2:
    digitalWrite(dg2, 0);
    break;

    case 3:
    digitalWrite (dg3, 0);
    break;

    case 4:
    digitalWrite(dg4, 0);
    break;    
  }
}

void setup() {
  int i;

  for (i = 2; i <= 13; i ++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  start();

}

void start() {
  for (mil = 0; mil <= 9; mil ++) {
    for (seg = 0; seg <= 9; seg ++) {
      for (dec = 0; dec <= 9; dec ++) {
        for (uni = 0; uni <= 9; uni ++) {
          EscreverDigito(1, uni);
          delay(velocidade);
          EscreverDigito(2, dec);
          delay(velocidade);
          EscreverDigito(3, seg);
          delay(velocidade);
          EscreverDigito(4, mil);
          delay(velocidade);
        }
      }
    }
  }
}
