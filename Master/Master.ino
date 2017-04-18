#include <Wire.h>
#include "Pump.h"

#define DRIVER_ENABLE 5
#define DRIVER_STEP 6
#define DRIVER_DIR 7
#define LED 2
#define SERVO_1 9
#define SERVO_2 10
#define THERMISTOR A1

Pump pump(DRIVER_ENABLE,DRIVER_STEP,DRIVER_DIR);

int tube_number = 0;
int pump_one = 0;
int pump_two;

void setup() {
  Serial.begin(9600);
}

void loop() {
  digitalWrite(LED,HIGH);
  pump.flow(100);
  digitalWrite(LED,LOW);

  while (Serial.available() > 0) {
    int tube_number = Serial.parseInt();
    int pump_one = Serial.parseInt();
    int pump_two = Serial.parseInt();
    if (Serial.read() == '\n') {
        digitalWrite(LED, HIGH);
        Serial.println('OK');
        delay(3000);
        digitalWrite(LED, LOW);
    }
  }
  
}
