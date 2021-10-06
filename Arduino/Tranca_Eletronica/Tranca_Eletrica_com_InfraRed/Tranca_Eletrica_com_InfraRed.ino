/* Projeto: Tranca Elétrica utilizando Sensor e Controle Infra-vermelho
 * Autor: Danilo Dutra
 * Projeto pode ser modificado, para utilizar Cartão e Sensor RFID, Bluetooth e Frequência Rádio, vai da sua necessidade e uso.
 */

#include <IRremote.h>
#define rele 7 // Define o Relé na porta digital 7

const int RECV_PIN = 11; // Pino do Receptor InfraRed
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
  pinMode(rele, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    // Serial.println(results.value, HEX); // Caso queira debugar o código e ver o valor no Monitor Serial
    irrecv.resume();
    if (results.value == 0xFF6897) {
      digitalWrite(rele, 0); // Trancado, tranca desligada
    }
    if (results.value == 0xFF30CF) {
      digitalWrite(rele, 1); // Destrancado, tranca ligada
    }
  }
}
