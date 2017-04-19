#include <Wire.h>
#include "Pump.h"
#include "Platform.h"

#define DRIVER_ENABLE 5
#define DRIVER_STEP 6
#define DRIVER_DIR 7
#define LED 2
#define SERVO_1 9
#define SERVO_2 10
#define THERMISTOR A1

#define MAX_TUBES 18
#define STEPS_PER_TUBE 33

Platform platform(DRIVER_ENABLE, DRIVER_STEP, DRIVER_DIR, MAX_TUBES, STEPS_PER_TUBE);

int tube_number = 0;
int pump_one = 0;
int pump_two;

void setup() {
  Serial.begin(9600);
  Wire.begin();
}

void blink_led(int numb) {
  for (int i=0; i<numb ; i++)
  {
      digitalWrite(LED, HIGH);
      delay(1000);
      digitalWrite(LED, LOW);
      delay(1000);
  }
}

void loop() {
  Serial.println("Master inizializzato");
  delay(200);
  while (Serial.available() > 0) {
    int tube_number = Serial.parseInt();
    int pump_one = Serial.parseInt();
    int pump_two = Serial.parseInt();
    Serial.println("prese variabili");
    if (Serial.read() == '\n') {
      Serial.println("inizio trasmissione");
      platform.goTo(tube_number);
      Wire.beginTransmission(8);
      Wire.write(pump_one);
      Wire.endTransmission();
      blink_led(2);
      delay(100);
      Wire.requestFrom(8, 2);
      if (Wire.available()) {
        int r = Wire.read();
        Serial.println(r);
      }
    }
  }
}
