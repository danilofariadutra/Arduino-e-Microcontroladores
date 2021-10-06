#include <WiFi.h>
#include <WiFiUdp.h>
const char ssid[] = ""; // Inserir o nome da Rede dentro da aspas dupla
const char password[] = ""; // Inserir a senha da Rede dentro da aspas dupla
WiFiClient client;

// CONFIGURAÇÃO PARA IP FIXO
IPAddress ip(192, 168, 1, 20); // IP do ESP32
IPAddress gateway(192, 168, 1, 1); // GATEWAY PADRÃO
IPAddress subnet(255, 255, 255, 0); // MASCARA DE REDE

#include <DHT.h>
#define DHTTYPE    DHT11     // DHT 11
#define DHTPIN 27     // Digital pin connected to the DHT sensor
DHT dht(DHTPIN, DHTTYPE);

#include <ArduinoOTA.h> // Biblioteca para atualizar o código via OTA (On the Air), sem a necessidade de conexão USB via Serial
#include <Adafruit_Sensor.h>

#include <ThingSpeak.h>
const long CHANNEL = #NUMERO_DO_CANAL; // Troca o "#NUMERO_DO_CANAL" pelo número channel criado dentro do ThingSpeak
const char *WRITE_API = ""; // Inserir dentro da aspas dupla o número da API

int intervalSensor = 2000; // Intervalo de atualização do sensor
long prevMillisThingSpeak = 0;
int intervalThingSpeak = 15000; // Intervalo minímo para escrever no ThingSpeak write é de 15 segundos

void setup() {
  Serial.begin(115200);
  dht.begin();

  WiFi.disconnect(); // CASO ESTEJA CONECTADO EM OUTRA REDE, SE DESCONECTA
  WiFi.mode(WIFI_STA); // DEFINE O DISPOSITIVO EM MODO STATION
  Serial.println();
  Serial.print("Conectando-se a ");
  Serial.println(ssid);
  WiFi.begin(ssid, password); // INICIALIZA O DISPOSITIVO NA REDE WIFI
  //WiFi.config(ip, gateway, subnet); // RECEBE AS CONFIGURAÇÕES DO IP FIXO E CONFIGURA O DISPOSITIVO
  ThingSpeak.begin(client);  // Inicializa o ThingSpeak
  Serial.println("");  

  // MÉTODO PARA RECEBER A ATUALIZAÇÃO VIA OTA (SEM FIO)
  ArduinoOTA.onStart([]() {
    String type;
    if (ArduinoOTA.getCommand() == U_FLASH) {
      type = "sketch";
    } else { // U_FS
      type = "filesystem";
    }

    // NOTE: if updating FS this would be the place to unmount FS using FS.end()
    Serial.println("Start updating " + type);
  });
  ArduinoOTA.onEnd([]() {
    Serial.println("\nEnd");
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
  });
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) {
      Serial.println("Auth Failed");
    } else if (error == OTA_BEGIN_ERROR) {
      Serial.println("Begin Failed");
    } else if (error == OTA_CONNECT_ERROR) {
      Serial.println("Connect Failed");
    } else if (error == OTA_RECEIVE_ERROR) {
      Serial.println("Receive Failed");
    } else if (error == OTA_END_ERROR) {
      Serial.println("End Failed");
    }
  });

  // INICIALIZA A TRANSMISSÃO OTA
  ArduinoOTA.begin();
  Serial.println("Dispositivo Pronto!");
  Serial.print("Endereço IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {

  // TRANSMISSÃO OTA ATIVA
  ArduinoOTA.handle();

  float temperatura = dht.readTemperature();
  float umidade = dht.readHumidity();

  // Conecta-se ou reconecta o WiFi
  if (WiFi.status() != WL_CONNECTED) {
    Serial.print("Atenção para conectar o SSID: ");
    Serial.println(ssid);
    while (WiFi.status() != WL_CONNECTED) {
      WiFi.begin(ssid, password);
      Serial.print(".");
      delay(5000);
    }
    Serial.println("\nConectado");
  }
  delay(1000);

  if (millis() - prevMillisThingSpeak > intervalThingSpeak) {

    // Configura os campos com os valores
    ThingSpeak.setField(1, temperatura);
    ThingSpeak.setField(2, umidade);

    // Escreve no canal do ThingSpeak
    int x = ThingSpeak.writeFields(CHANNEL, WRITE_API);
    if (x == 200) {
      Serial.println("Update realizado com sucesso");
    }
    else {
      Serial.println("Problema no canal - erro HTTP " + String(x));
    }

    prevMillisThingSpeak = millis();
  }
}
