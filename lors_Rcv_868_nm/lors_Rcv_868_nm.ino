#include <SPI.h>
#include <LoRa.h>

const int csPin = 15;
const int resetPin = 0;
const int irqPin = 4;
int state=0;
int SyncWord = 0x22;

void setup() {
  pinMode(2,OUTPUT);
  Serial.begin(9600);
  while (!Serial);

  Serial.println("LoRa Receiver");
  LoRa.setPins(csPin, resetPin, irqPin);

  if (!LoRa.begin(866E6)) {
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
    digitalWrite(2,state);
  }
}
