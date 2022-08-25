/*
  JSN-SR04T-V3.0 Ultrasonic Sensor - Mode 1 Demo
  Uses JSN-SR04T-V3.0 Ultrasonic Sensor
  Displays on Serial Monitor
 
  Mode 1 is set by bridging "M1" pads on board
*/
 
// Include the Software Serial library
#include <SoftwareSerial.h>
 
// Define connections to sensor
int pinRX = 10;
int pinTX = 11;
 
// Array to store incoming serial data
unsigned char data_buffer[4] = {0};
 
// Integer to store distance
int distance = 0;
 
// Variable to hold checksum
unsigned char CS;
 
// Object to represent software serial port
SoftwareSerial mySerial(pinRX, pinTX);
 
void setup() {
  // Set up serial monitor
  Serial.begin(115200);
  // Set up software serial port
  mySerial.begin(9600);
}
 
void loop() {
 
  // Run if data available
  if (mySerial.available() > 0) {
 
    delay(4);
 
    // Check for packet header character 0xff
    if (mySerial.read() == 0xff) {
      // Insert header into array
      data_buffer[0] = 0xff;
      // Read remaining 3 characters of data and insert into array
      for (int i = 1; i < 4; i++) {
        data_buffer[i] = mySerial.read();
      }
 
      //Compute checksum
      CS = data_buffer[0] + data_buffer[1] + data_buffer[2];
      // If checksum is valid compose distance from data
      if (data_buffer[3] == CS) {
        distance = (data_buffer[1] << 8) + data_buffer[2];
        // Print to serial monitor
        Serial.print("distance: ");
        Serial.print(distance);
        Serial.println(" mm");
      }
    }
  }
}
