#ifndef IOT_COMMAND_H
#define IOT_COMMAND_H

  #include "PinConfig.h"

  void turnOnLight() { digitalWrite(LED_LIGHT, HIGH); }
  void turnOffLight() { digitalWrite(LED_LIGHT, LOW); }
  void doorControl(int degree) { door.write(degree); }
  void windowControl(int degree) { window.write(degree); }

  void fanForward() {
    digitalWrite(FAN_MOTOR_F, HIGH);
    digitalWrite(FAN_MOTOR_B, LOW);
  }
  void fanBackward() {
    digitalWrite(FAN_MOTOR_F, LOW);
    digitalWrite(FAN_MOTOR_B, HIGH);
  }
  void setFanSpeed(int speed) {
    digitalWrite(FAN_MOTOR_B, LOW);
    analogWrite(FAN_MOTOR_F, speed);
  }
  void stopFan() {
    digitalWrite(FAN_MOTOR_F, LOW);
    digitalWrite(FAN_MOTOR_B, LOW);
  }

  void turnOnBreathing() { digitalWrite(BREATHING_LED, HIGH); }
  void turnOffBreathing() { digitalWrite(BREATHING_LED, LOW); }
  void setBreathing(int value) { analogWrite(BREATHING_LED, value); }

  int getSoil() { return analogRead(SOIL_SENSOR); }
  int getGas() { return analogRead(GAS_SENSOR); }
  int getSteam() { return analogRead(STEAM_SENSOR); }
  int getLight() { return analogRead(LIGHT_SENSOR); }

#endif