#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>
LiquidCrystal_PCF8574 lcd(0x27);

#define btSim 6
#define btNao 7

float num, inicial = -1, ultimo = 1000; // inicial = número inicial, ultimo = o número máximo
bool btS = false, btN = false; // Da um valor inicial para que o while possa inicializar;

void setup() {
  Serial.begin(9600);
  lcd.begin (16, 2);
  pinMode(btSim, INPUT);
  pinMode(btNao, INPUT);
}

void calculaMedia() {
  num = floor(inicial + ultimo) / 2;
}

void loop() {
  for (int c = 0; c < 10; c ++) {
    calculaMedia();
    Serial.println(num);
    lcd.setBacklight(HIGH); // Liga o Backlight
    lcd.setCursor(0, 0);
    lcd.print("O numero e maior");
    lcd.setCursor(0, 1);
    lcd.print("que ");
    lcd.print(num, 0);
    lcd.print("?");

    while (!btN && !btS) {
      // Faz a leitura digital dos Pushbuttons
      btS = digitalRead(btSim);
      btN = digitalRead(btNao);

      if (digitalRead(btSim) == 1) {
        inicial = num;
      }
      else if (digitalRead(btNao) == 1) {
        ultimo = num;
      }
    }
    delay(200);
    
    // Reseta manualmente os valores da variavel bool
    btS = false;
    btN = false;
    delay(200);
    lcd.setBacklight(LOW);
    lcd.clear();
  }
  
  // Caso o ultimo número seja igual ao inicial, a instrução era para não arredondar, então, soma-se + 1 para chegar a resposta;
  if (inicial == ultimo || inicial + 1 == ultimo) {
    num = inicial + 1;
  }

  // Imprime no LCD display
  lcd.setCursor(0, 0);
  lcd.print("O numero e ");
  lcd.println(num, 0);

  for (int c = 0; c < 3; c ++) {
    lcd.setBacklight(HIGH);
    delay(1000);
    lcd.setBacklight(LOW);
    delay(1000);
  }
  delay(2000);
  lcd.clear();

  // Reseta os valores para os iniciais;
  num = 0;
  inicial = -1;
  ultimo = 1000;
}
