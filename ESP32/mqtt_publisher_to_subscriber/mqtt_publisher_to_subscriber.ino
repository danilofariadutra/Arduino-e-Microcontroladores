#include <WiFi.h>
#include <WiFiUdp.h>
#include <PubSubClient.h>
#include <ArduinoOTA.h>
#include <DHT.h>
#include <Adafruit_Sensor.h>

#define DHTTYPE DHT11
#define DHTPIN 27
#define TIME_TO_SEND 1000
#define TIME_OUT 2000

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

const char* mqttServer = "broker.emqx.io";
const int mqttPort = 1883;
const char* mqttTopic = "info";
const char* mqttUser = "user";
const char* mqttPassword = "123456789";

WiFiClient espClient;
PubSubClient client(espClient);
DHT dht(DHTPIN, DHTTYPE);

int counter = 1;
char message[100];
float temperature;
float humidity;

void setup() {
  Serial.begin(115200);
  dht.begin();
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Iniciando conexao com a rede WiFi..");
  }
  
  Serial.println("WiFi conectada.");
  Serial.println("Endereço de IP: ");
  Serial.println(WiFi.localIP()); // PRINT DO IP NO MONITOR SERIAL
  
  initOTA();
}

void loop() {
  ArduinoOTA.handle();
  // Faz a conexao com o broker MQTT
  reconnectToBroker();
  updateSensorValues();

  sprintf(message, "Sensor Read %d | Temperature: %.1f, Humidity: %.1f", counter, temperature, humidity);
  Serial.print("Mensagem enviada: ");
  Serial.println(message);

  // Envia a mensagem ao broker
  client.publish(mqttTopic, message);
  Serial.println("Mensagem enviada com sucesso...");
  
  //Incrementa o contador
  counter ++;
  
  //Aguarda 1 segundo para enviar uma nova mensagem
  delay(TIME_TO_SEND);
}

void getHumidityValue() {
  humidity = dht.readHumidity();
  if (isnan(humidity)) {
    Serial.println("Falha ao ler o sensor DHT!");
  }
  else {
    Serial.println(humidity);
  }
}

void getTemperatureValue() {
  temperature = dht.readTemperature();
  if (isnan(temperature)) {
    Serial.println("Falha ao ler o sensor DHT!");
  }
  else {
    Serial.println(temperature);
  }
}

void updateSensorValues() {
  getHumidityValue();
  getTemperatureValue();
}

void reconnectToBroker() {
  // Conexao ao broker MQTT
  client.setServer(mqttServer, mqttPort);
  while (!client.connected()) {
    Serial.println("Conectando ao broker MQTT...");
    if (client.connect("ESP32Client", mqttUser, mqttPassword )) {
      Serial.println("Conectado ao broker!");
    }
    else {
      Serial.print("Falha na conexao ao broker - Estado: ");
      Serial.print(client.state());
      delay(TIME_OUT);
    }
  }
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
