/* Projeto: Adivinha um número entre 0 e 1000;
  Autor: Danilo Dutra
*/

char res = 'V'; // Da um valor diferente de S/N;
float num, inicial = -1, ultimo = 1000; // inicial = número inicial, ultimo = o número máximo (pode altera-lo);
bool estado = false; // Da um valor inicial para que o while possa inicializar;

void setup() {
  Serial.begin(9600);
}

void calculaMedia() {
  num = ceil(inicial + ultimo) / 2; // Arredonda pra cima o número float;
}

void loop() { 
  for (int c = 0; c < 10; c ++) {
    calculaMedia();
    estado = false;
    Serial.print("O número é maior que ");
    Serial.print(num, 0); // Imprime valor sem flutuante;
    Serial.println("?");
    
    while (!estado) {
      res = Serial.read(); // Faz leitura no Monitor Serial (Valor S/N);
      
      if (res == 'S') {
        inicial = num;               
        estado = true;
        res = 'V'; // Zera leitura da variável;
      }
      else if (res == 'N') {
        ultimo = num;
        estado = true;
        res = 'V'; // Zera leitura da variável;
      }
    }
  }

  // Caso o ultimo número seja igual ao inicial, a instrução era para não arredondar, então, soma-se + 1 para chegar a resposta;
  if (inicial == ultimo || inicial + 1 == ultimo) {
    num = inicial + 1;
  }

  // Imprime valor final
  Serial.println("---------------------------");
  Serial.print("O número é ");
  Serial.println(num, 0);
  num = 0; // Zera o valor para reiniciar;

  // Reseta os valores para os iniciais;
  num = 0; 
  inicial = -1;
  ultimo = 1000;
}


