#define triacPulse 5


int x = 8;
void setup() {
  Serial.begin(115200);
  pinMode(15, INPUT_PULLUP);
  pinMode(triacPulse, OUTPUT);
  //attachInterrupt(digitalPinToInterrupt(5),ISR,FALLING); // attach Interrupt at PIN2

}

void loop() {


  Serial.println(digitalRead(15));
  if(digitalRead(15)==0)
{
  digitalWrite(triacPulse, 0);
  delay(4); // read AD0
  digitalWrite(triacPulse, 1);
  delay(5); //delay 50 uSec on output pulse to turn on triac  
}
}

/*//ICACHE_RAM_ATTR void ISR()
{
  Serial.print("x:");
  Serial.print(x);
  Serial.print(" 8-x:");
  Serial.println(8-x);
  digitalWrite(triacPulse, 0);
  delay(x); // read AD0
  digitalWrite(triacPulse, 1);
  delay(8 - x); //delay 50 uSec on output pulse to turn on triac

}*/
