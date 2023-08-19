#include <SPI.h>
#include <LoRa.h>

const int csPin = 15;
const int resetPin = 0;
const int irqPin = 4;
int state=0;
int counter = 0;
int SyncWord = 0x22;

void setup() {
  pinMode(2,OUTPUT);
  Serial.begin(9600);
  while (!Serial);

  Serial.println("LoRa Sender");
  LoRa.setPins(csPin, resetPin, irqPin);
  if (!LoRa.begin(866E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }

  LoRa.setTxPower(20);
  LoRa.setSpreadingFactor(12);
  LoRa.setSignalBandwidth(62.5E3);
  LoRa.setCodingRate4(8);
  LoRa.setSyncWord(SyncWord);
  
}

void loop() {
  Serial.print("Sending packet: ");
  Serial.println(counter);

  // send packet
  LoRa.beginPacket();
  //LoRa.print("hello ");
  LoRa.print(counter);
  state=!state;
  digitalWrite(2,state);
  LoRa.endPacket();

  counter++;

  delay(250);
}
