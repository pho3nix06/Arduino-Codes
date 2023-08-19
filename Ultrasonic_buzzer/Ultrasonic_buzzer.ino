const int trig_pin = 3;
const int echo_pin = 5;
const int buzzer_pin = 10;
float period,distance;


void setup() {
 pinMode(trig_pin,OUTPUT);
 pinMode(echo_pin,INPUT);
 Serial.begin(9600);
}

void loop() {
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(12);
  digitalWrite(trig_pin, LOW);

  period = pulseIn(echo_pin, HIGH);
  distance = (period*.0343)/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);
}
