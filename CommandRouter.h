#ifndef COMMAND_ROUTER_H
#define COMMAND_ROUTER_H

  #include "IoTController.h"

void commandRouter(char command) {
  int value, soil, gas, steam, light;

  switch(command) {
    case 'a':
      return turnOnLight();
    case 'b':
      return turnOffLight();
    case 'm':
      return doorControl(0);
    case 'l':
      return doorControl(180);
    case 'o':
      return windowControl(0);
    case 'n':
      return windowControl(180);
    case 's':
      return stopFan();
    case 'r':
      return fanBackward();
    case 'p':
      return turnOnBreathing();
    case 'q':
      return turnOffBreathing();
    case 't':
      value = String(Serial.readStringUntil('#')).toInt();
      doorControl(value);
      return delay(300);
    case 'u':
      value = String(Serial.readStringUntil('#')).toInt();
      windowControl(value);
      return delay(300);
    case 'w':
      value = String(Serial.readStringUntil('#')).toInt();
      return setFanSpeed(value);
    case 'v':
      value = String(Serial.readStringUntil('#')).toInt();
      return setBreathing(value);
    case 'h':
      light = getLight();
      Serial.println(light);
      return delay(100);
    case 'j':
      soil = getSoil();
      Serial.println(soil);
      return delay(100);
    case 'i':
      gas = getGas();
      Serial.println(gas);
      return delay(100);
    case 'k':
      steam = getSteam();
      Serial.println(steam);
      return delay(100);

  }


  Serial.println(command);
}


#endif