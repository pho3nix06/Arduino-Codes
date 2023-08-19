const int trig = 4;
const int echo = 5;
long duration;
int disCM /*, disINCH*/;

void setup() {
  Serial.begin(250000);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(12);
  digitalWrite(trig,LOW);
  duration = pulseIn (echo,HIGH);
  disCM = (duration*0.035)/2;  //note
  //disINCH = (duration*0.0133)/2; //note
  Serial.println(disCM);
  delay(100);
  /*Serial.println(disINCH);
  delay(100);*/
  
}
