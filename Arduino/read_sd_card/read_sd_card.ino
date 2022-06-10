#include <SD.h>
#include <SPI.h>
#include <DHT.h>
#include <Adafruit_Sensor.h>

#define DHTTYPE DHT11
#define DHTPIN 4
#define pinoSS 10
#define TIME_TO_SEND 1000

DHT dht(DHTPIN, DHTTYPE);

File fileToWriteSensorValues;

float temperature;
float humidity;
unsigned long int counter = 1;
int option = 999;

void menu() {
  while (true) {
    if ((int) option == 50) {
      Serial.println("Pronto para começar a leitura...");
      break;
    }
    Serial.println("Escolha uma opcao [0 Read File | 1 Remove File | 2 Exit & Begin]");

    while (true) {
      if (Serial.available() > 0) {
        option = Serial.read();

        if ((int) option > 47 && option < 51) {
          Serial.println(option);
          break;
        }
      }
    }

    switch (option) {
      case 48:
        fileToWriteSensorValues = SD.open("SENSOR.txt", FILE_READ);

        if (fileToWriteSensorValues) {
          Serial.println("Conteúdo do Arquivo:");

          while (fileToWriteSensorValues.available()) {
            Serial.write(fileToWriteSensorValues.read());
          }
          fileToWriteSensorValues.close();
        }
        else {
          Serial.println("Erro ao Abrir Arquivo .txt");
        }
        break;

      case 49:
        if (SD.exists("SENSOR.txt")) {
          SD.remove("SENSOR.txt");
          Serial.println("Arquivo removido com sucesso");
        } else {
          fileToWriteSensorValues = SD.open("SENSOR.txt", FILE_WRITE);
          Serial.println("Arquivo não foi encontrado");
        }
        break;
    }
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(pinoSS, OUTPUT);

  dht.begin();
  SD.begin();

  /* Menu inicial ainda no setup():
      Digitando 0 no monitor Serial, o programa lê um arquivo existente com o nome já pré-definido no código (Caso exista algum arquivo já gravado)
      Digitando 1, O arquivo de gravação de leitura do sensor é lido (Caso exista)
      Digitando 2, O programa começa a leitura e gravação no arquivo "SENSOR.txt"
  */
  menu();
}

void loop() {
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();

  if (SD.begin()) {
    fileToWriteSensorValues = SD.open("sensor.txt", FILE_WRITE);
    Serial.println("SD Begin");

    if (fileToWriteSensorValues) {
      Serial.println("Salvando dados...");
      fileToWriteSensorValues.print(counter);
      fileToWriteSensorValues.print(", Temperature: ");
      fileToWriteSensorValues.print(temperature);
      fileToWriteSensorValues.print(" | Humidity: ");
      fileToWriteSensorValues.println(humidity);
      fileToWriteSensorValues.close();
      Serial.println("SD Closed");
    }
  }

  Serial.print(counter);
  Serial.print(" Temperature: ");
  Serial.print(temperature);
  Serial.print(" | Humidity: ");
  Serial.println(humidity);
  
  counter ++;
  delay(TIME_TO_SEND);
}
