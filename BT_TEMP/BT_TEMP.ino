
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX
float temp, tempAvg, tf;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  Serial.println("Goodnight moon!");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  pinMode(A0,INPUT);
}

void loop() { // run over and over

  for (int i=0; i<100; i++)
  {
     temp = analogRead(A0);
     temp = ( temp/1024.0)*5000; 
     temp = temp/10;
     temp = ((9*temp)/5)+32;
     Serial.println(temp);
     tempAvg = tempAvg+temp;
     delay(2);
  }
  tf=tempAvg/100;
  Serial.println("------");
  Serial.println(tf);
  mySerial.println(tf);
  delay(2500);
  tempAvg=0;
}
