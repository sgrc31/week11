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

void setup() {
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(data_from_master);
  Wire.onRequest(data_to_master);
}

void loop() {
  delay(100);
}

void data_from_master(int num_bytes) {
  pump.flow(200);
  Serial.println("bella");
}

void data_to_master () {
  Wire.write(1);
}

