#include <SD.h> //Load SD card library
#include "Wire.h"    // imports the wire library for talking over I2C

int loop_count = 0; //Initialize the loop counter
int time_to_sense = 30; //Amount of time between flush
File mySensorData; //Data object you will write your sesnor data to
const int chipSelect = 6; //Choose the digital pin which CS of the SD card reader is connected to 

void setup() {
  //initialize the serial output
  Serial.begin(9600);
  Serial.println("Setup Complete");
  //intizlize the SD card reader
  SD.begin(chipSelect); //Initialize the SD card reader
  mySensorData = SD.open("Testfile.txt", FILE_WRITE);
  //Read the sea level pressure in order to zero? the altitude.
  mySensorData.println("This is a test file header");
  }


void loop() {
  mySensorData.println("This is a pretend reading from a sensor");  
  Serial.println("Loop iteration");
  delay(250); //Pause between readings.

    if (loop_count == time_to_sense*4){
    mySensorData.flush();
    mySensorData.close();
    mySensorData = SD.open("PTData.txt", FILE_WRITE);
    loop_count = 0;
  }
  loop_count++;

}