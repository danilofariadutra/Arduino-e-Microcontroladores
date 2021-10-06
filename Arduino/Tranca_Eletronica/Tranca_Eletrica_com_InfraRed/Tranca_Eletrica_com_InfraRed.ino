/* Projeto: Tranca El�trica utilizando Sensor e Controle Infra-vermelho
 * Autor: Danilo Dutra
 * Projeto pode ser modificado, para utilizar Cart�o e Sensor RFID, Bluetooth e Frequ�ncia R�dio, vai da sua necessidade e uso.
 */

#include <IRremote.h>
#define rele 7 // Define o Rel� na porta digital 7

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
    // Serial.println(results.value, HEX); // Caso queira debugar o c�digo e ver o valor no Monitor Serial
    irrecv.resume();
    if (results.value == 0xFF6897) {
      digitalWrite(rele, 0); // Trancado, tranca desligada
    }
    if (results.value == 0xFF30CF) {
      digitalWrite(rele, 1); // Destrancado, tranca ligada
    }
  }
}
