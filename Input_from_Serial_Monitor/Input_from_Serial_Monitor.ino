int ledPin = 13;
String readString;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT); 
}

void loop() {
  while (Serial.available()) {  
    char in = Serial.read();
    readString += in; 
  }

  if (readString.length() >0) {
    Serial.println(readString);

    if (readString == "1")     
    {
      digitalWrite(ledPin, HIGH);
      Serial.println("LED ON");
    }
    else if (readString == "0")
    {
      digitalWrite(ledPin, LOW);
      Serial.println("LED OFF");
    }
    readString="";
  } 
}
