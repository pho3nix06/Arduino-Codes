// C++ code
//
/*
  Gas sensor using buzzer
*/

int gas_sensor = 0;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(6, OUTPUT);
}

void loop()
{
  gas_sensor = analogRead(A0);
  if (gas_sensor >= 250) {
    tone(6, 29, 2000); // play tone 10 (A#0 = 29 Hz)
  }
  delay(10); // Delay a little bit to improve simulation performance
}
