#include "Wire.h"    // imports the wire library for talking over I2C
#include <BMP280.h>
BMP280 bmp280;

void setup() {
  //initialize the serial output
  Serial.begin(9600);
  delay(10);
  Serial.println("BMP280 example");
  Wire.begin(); //Join I2C bus
  bmp280.begin();
  Serial.println("Setup Complete");
  //intizlize the SD card reader
  }


void loop() {
  uint32_t pressure = bmp280.getPressure();
  float temperature = bmp280.getTemperature();

  //Print the results
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print("°C \t");
  Serial.print("Pressure: ");
  Serial.print(pressure);
  Serial.println("Pa");

  delay(2000);

}