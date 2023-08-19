#include <SPI.h>
#include <LoRa.h>

const int csPin = 7;
const int resetPin = 6;
const int irqPin = 2;
int state=0;
int SyncWord = 0x22;

void setup() {
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  while (!Serial);

  Serial.println("LoRa Receiver");
  LoRa.setPins(csPin, resetPin, irqPin);

  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
  LoRa.setSpreadingFactor(12);
  LoRa.setSignalBandwidth(62.5E3);
  LoRa.setCodingRate4(8);                   
  LoRa.setSyncWord(SyncWord);
  
}

void loop() {
  // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // received a packet
    Serial.print("Received packet '");

    // read packet
    while (LoRa.available()) {
      Serial.print((char)LoRa.read());
    }

    // print RSSI of packet
    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());
    state=!state;
    digitalWrite(13,state);
  }
}
