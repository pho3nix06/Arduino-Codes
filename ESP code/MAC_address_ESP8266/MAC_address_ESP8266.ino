#include <ESP8266WiFi.h>

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println();

  // Print the MAC address of the ESP32
  Serial.print("MAC Address of the Board : ");
  Serial.println(WiFi.macAddress());
}

void loop() {}
