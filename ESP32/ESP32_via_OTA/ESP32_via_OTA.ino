#include <WiFiUdp.h>
#include <ArduinoOTA.h>

#ifndef STASSID
#define STASSID "" // Inserir dentro da aspas dupla o nome da sua rede wi-fi
#define STAPSK  "" // Inserir dentro da aspas dupla a senha da sua rede wi-fi
#endif

//const char* ssid = STASSID;
//const char* password = STAPSK;

// CONFIGURAÇÃO PARA IP FIXO
IPAddress ip(192, 168, 1, 40); // IP do ESP32 // TROCAR O IP PARA O IP DESEJADO
IPAddress gateway(192, 168, 1, 1); // GATEWAY PADRÃO
IPAddress subnet(255, 255, 255, 0); // MASCARA DE REDE

void setup() {

  Serial.begin(115200);
  
  // Set device as a Wi-Fi Station
  WiFi.disconnect(); // CASO ESTEJA CONECTADO EM OUTRA REDE, SE DESCONECTA
  WiFi.mode(WIFI_STA); // DEFINE O DISPOSITIVO EM MODO STATION
  Serial.println();
  Serial.print("Conectando-se a ");
  Serial.println(STASSID);
  WiFi.begin(STASSID, STAPSK); // INICIALIZA O DISPOSITIVO NA REDE WIFI
  WiFi.config(ip, gateway, subnet); // RECEBE AS CONFIGURAÇÕES DO IP FIXO E CONFIGURA O DISPOSITIVO

  // VERIFICA A CONEXÃO, CASO NÃO ESTEJA CONECTADO, REPETE O PROCESSO DE TENTATIVA
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("Falha na conexão! Reiniciando...");
    delay(500);
  }

  Serial.println("");
  Serial.println("WiFi conectada.");
  Serial.println("Endereço de IP: ");
  Serial.println(WiFi.localIP()); // PRINT DO IP NO MONITOR SERIAL

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
  ArduinoOTA.begin();
  Serial.println("Ready");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

}

void loop() {
  // Basta inserir seu código dentro do void loop e MUITO IMPORTANTE: NÃO REMOVER o método "ArduinoOTA.handle()"
  ArduinoOTA.handle();

}
