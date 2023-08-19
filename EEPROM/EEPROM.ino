#include <EEPROM.h>

void readData(int addr) {
  byte content = EEPROM.read(addr);
  Serial.println(content,DEC);
}

void writeData(int addr,byte inputData) {
  if(addr <= EEPROM.length()){
  EEPROM.write(addr,inputData);
     }
}

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  while (Serial.available()) {
  String userCommand = Serial.readString(); 
  int addr = Serial.read(); 
     
  if (userCommand == "read") {
    readData(addr);
  } else if (userCommand == "write") {
    int inputData = Serial.read();
    writeData(addr,inputData);
    }
  }
}
