// Caso você não tenha a biblioteca "ESP32Servo.h", basta instala-la através da própria Arduino IDE
#include <ESP32Servo.h>

#define PINO_SERVO 15

Servo servo;

unsigned int posicaoInicial = 0;
unsigned int posicaoFinal = 180;
int delayTime = 10;
// Pinos GPIO com PWM no ESP32: 2,4,12-19,21-23,25-27,32-33

void setup() {
  Serial.begin(115200);
  // Allow allocation of all timers
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);
  servo.setPeriodHertz(50);    // standard 50 hz servo
  servo.attach(PINO_SERVO, 500, 2500); // attaches the servo on pin 18 to the servo object
  // using default min/max of 1000us and 2000us
  // different servos may require different min/max settings
  // for an accurate 0 to 180 sweep
}

void loop() {
  for (int c = 0; c <= 180; c ++) {
    servo.write(c);
    Serial.println(c);
    delay(delayTime);
  }

  for (int c = 180; c >= 0; c --) {
    servo.write(c);
    Serial.println(c);
    delay(delayTime);
  }
}
