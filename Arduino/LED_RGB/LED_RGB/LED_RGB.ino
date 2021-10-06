/* Projeto: Sketch para mostrar o uso simples de um LED RGB;
 * Autor: Danilo Dutra;
 * Itens: LED RGB, Protoboard, jumpers e fios, Arduino UNO;
 */

const int redPin = 8; // Define o pino digital 8 para o LED Vermelho
const int greenPin = 10; // Define o pino digital 10 para o LED Verde
const int bluePin = 12; // Define o pino digital 12 para o LED Azul
 
void setup() {}
 
void loop() {
  analogWrite(redPin, random(0,255)); // Sorteia um número randômico entre 0 e 255;
  analogWrite(greenPin, random(0,255)); // Sorteia um número randômico entre 0 e 255;
  analogWrite(bluePin, random(0,255)); // Sorteia um número randômico entre 0 e 255;
  delay(500); // Delay de 500 milisegundos
}
