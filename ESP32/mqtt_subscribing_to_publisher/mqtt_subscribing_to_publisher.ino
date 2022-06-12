#include <WiFi.h>
#include <ArduinoOTA.h>
#include <PubSubClient.h>

/* Name       Broker Address      TCP    TLS Port    WebSocket   Message    Persistent  Sign Up    Link
 *                                Port   Port        Port        Retention  Session     Required    
 * Eclipse    mqtt.eclipse.org    1883   N/A         80, 443     YES        YES         NO  Link   https://iot.eclipse.org/sandbox.html
 * Mosquitto  test.mosquitto.org  1883   8883, 8884  80          YES        YES         NO  Link   https://test.mosquitto.org
 * HiveMQ     broker.hivemq.com   1883   N/A         8000        YES        YES         NO  Link   https://www.hivemq.com/downloads/
 * Flespi     mqtt.flespi.io      1883   8883        80, 443     YES        YES         YES Link   https://flespi.com/mqtt-broker
 * Dioty      mqtt.dioty.co       1883   8883        8080, 8880  YES        YES         YES Link   http://www.dioty.co
 * Fluux      mqtt.fluux.io       1883   8883        N/A         N/A        N/A         NO  Link   https://fluux.io
 * EMQX       broker.emqx.io      1883   8883        8083        YES        YES         NO  Link   https://www.emqx.io
 */

/*
 * ssid = Coloque o nome da sua rede WiFi
 * password = Coloque a senha da sua rede WiFi
 * mqttServer = Server dos listados acima
 * mqttPort = 1883 Sem criptografia | 8883 com Criptografia (Requer configuracao adicional no Broker)
 * mqttUser = nome do usuário que você definir para envio de dados ao Broker
 * mqttPassword = senha do usuário que você definir para envio de dados ao Broker
 */

const char* ssid = "PUT_YOUR_SSID_HERE";
const char* password =  "PUT_YOUR_SSID_PASSWORD_HERE";

const char *mqttBroker = "broker.emqx.io";
const char *topic = "info";
const char *mqttUsername = "user";
const char *mqttPassword = "123456789";
const int mqttPort = 1883;

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Conectando-se a Rede WiFi...");
  }

  Serial.println("Conectado a Rede WiFi");
  client.setServer(mqttBroker, mqttPort);
  client.setCallback(callback);

  while (!client.connected()) {
    String client_id = "esp32-client-";
    client_id += String(WiFi.macAddress());
    Serial.printf("Client %s ira conectar-se no broker mqtt publico\n", client_id.c_str());
    if (client.connect(client_id.c_str(), mqttUsername, mqttPassword)) {
      Serial.println("Conectado em broker publico EMQX");
    } else {
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
    }
  }

  client.publish(topic, "Publishing in the Topic");
  client.subscribe(topic);

  initOTA();
}

void loop() {
  ArduinoOTA.handle();
  client.loop();
}

void callback(char *topic, byte *payload, unsigned int length) {
  Serial.print("Mensagem recebida do Topico: ");
  Serial.println(topic);
  Serial.print("Mensagem:");
  
  for (int i = 0; i < length; i++) {
    Serial.print((char) payload[i]);
  }
  
  Serial.println();
  Serial.println("-----------------------");
}

void initOTA() {
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
