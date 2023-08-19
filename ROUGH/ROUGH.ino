#include <EEPROM.h>

void setup()
{
  Serial.begin(9600);
}
int addr;
int data;
void loop(){
  String buffer = "";
  buffer = Serial.readString();
  if(buffer.startsWith("read"))
  {
    addr = buffer.substring(buffer.indexOf(' ')+1).toInt();
    Serial.print("Data from the address ");
    Serial.print(addr);
    Serial.print(" is ");
    Serial.println(EEPROM.read(addr));
    }
    else if (buffer.startsWith("write")){
      addr = buffer.substring(6,7).toInt();
      data = buffer.substring(8).toInt();
      Serial.print("The data to be written on address ");
      Serial.print(addr);
      Serial.print(" is ");
      Serial.println(data);
      EEPROM.write(addr,data);
      }
  }
