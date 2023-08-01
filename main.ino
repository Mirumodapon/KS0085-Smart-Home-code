#include <Servo.h>
#include "CommandRouter.h"
#include "PinConfig.h"

void setup() {
  Serial.begin(9600);

  pinMode(LED_LIGHT, OUTPUT);
  pinMode(FAN_MOTOR_F, OUTPUT);
  pinMode(FAN_MOTOR_B, OUTPUT);
  pinMode(BREATHING_LED, OUTPUT);
  pinMode(SOIL_SENSOR, INPUT);
  pinMode(STEAM_SENSOR, INPUT);
  pinMode(GAS_SENSOR, INPUT);
  pinMode(LIGHT_SENSOR, INPUT);
  door.attach(DOOR_SERVO);
  window.attach(WINDOW_SERVO);
}

void loop() {
  char command;
  while (Serial.available() > 0) {
    command = Serial.read();
    commandRouter(command);
  }

  delay(100);
}
