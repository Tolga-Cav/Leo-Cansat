#include <SPI.h>
#include <LoRa.h>

// Define the pins used by the HT-RA62
#define NSS 17
#define RESET 9
#define DIO0 2

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  while (!Serial);

  // Initialize the LoRa module
  LoRa.setPins(NSS, RESET, DIO0);
  if (!LoRa.begin(868E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
  Serial.println("LoRa initialized successfully.");
}

void loop() {
  // Send a message every second
  LoRa.beginPacket();
  LoRa.print("Hello, world!");
  LoRa.endPacket();
  delay(1000);
}