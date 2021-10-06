/* Projeto: Tranca Elétrica com Senha;
 * Itens: LCD 16x2, Rotary Encoder, Arduino UNO, Tranca Eletromagnética, Fonte 12v(Para a tranca), um módulo Relé, alguns fios e jumpers.
 * Autor: Danilo Dutra;
 * Projeto pode ser modificado, para utilizar Bluetooth, RFID, Infra-vermelho ou Frequência Rádio também, vai da sua necessidade e uso.
 */

#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>

LiquidCrystal_PCF8574 lcd(0x27);

#define pinA 2
#define pinB 3
#define pinBotao 1

int numero = 0, atual, antigo, contador;
int contador2 = 0;
byte guardaCodigo[4];
int codigo[4] = {1, 2, 3, 4}; // Defina sua senha aqui (Caso queira mais números, altere a quantidade de variaveis no Vetor "int codigo[X]";
void setup() {
  lcd.begin (16, 2);
  Serial.begin(9600);
  pinMode(pinA, INPUT);
  pinMode(pinB, INPUT);
  pinMode(pinBotao, INPUT_PULLUP);
  antigo = digitalRead(pinA);
}

void loop() {
Codigo:
  while (contador2 != 4) {
    while (contador2 != 4) {

      lcd.setBacklight(HIGH);
      lcd.setCursor(0, 0);
      lcd.print("NUMERO ");
      lcd.print(contador2 + 1);

      atual = digitalRead(pinA);
      if (atual != antigo) {
        if (digitalRead(pinB) != atual) {
          numero --;
        } else {
          numero ++;
        }
      }
      if (digitalRead(pinBotao) != 1) {
        guardaCodigo[contador] = numero;
        contador ++;
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("NUMERO: ");
        lcd.print(contador);
        lcd.setCursor(0, 1);
        lcd.print("ESCOLHIDO: ");
        lcd.print(numero);
        delay(2000);
        lcd.print(guardaCodigo[contador]);
        lcd.clear();
        delay(1000);
        contador2 ++;
      }
      lcd.setCursor(0, 1);
      lcd.print(numero);
      antigo = atual;
    }
    break;
  }

  if (codigo[0] != guardaCodigo[0] && guardaCodigo[1] != codigo[1] && guardaCodigo[2] != codigo[2] && guardaCodigo[3] != codigo[3]) {
    for (contador = 0; contador <= 4; contador ++) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("SENHA INCORRETA");
      delay(1000);
      lcd.setBacklight(LOW);
      delay(1000);
      lcd.setBacklight(HIGH);
    }
  }
  if (codigo[0] == guardaCodigo[0] && guardaCodigo[1] == codigo[1] && guardaCodigo[2] == codigo[2] && guardaCodigo[3] == codigo[3]) {
    for (contador = 0; contador <= 4; contador ++) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("DESTRAVADO");
      delay(1000);
      lcd.setBacklight(LOW);
      delay(1000);
      lcd.setBacklight(HIGH);
      delay(1000);
    }
  }
  delay(1000);
  lcd.clear();
  contador2 = 0;
  goto Codigo;
}
