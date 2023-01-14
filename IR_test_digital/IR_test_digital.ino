#define IR1 2
// #define IR2 3
// #define IR3 4
// #define IR4 5
// #define IR5 6
// #define IR6 7
// #define IR7 8
// #define IR8 9

void setup() {
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(IR1, INPUT);
  // pinMode(IR2, INPUT);
  // pinMode(IR3, INPUT);
  // pinMode(IR4, INPUT);
  // pinMode(IR5, INPUT);
  // pinMode(IR6, INPUT);
  // pinMode(IR7, INPUT);
  // pinMode(IR8, INPUT);
  Serial.begin(9600);
}

void loop() {
  bool r1 = digitalRead(2);
  
  if (r1 == '1') {
    digitalWrite(10, HIGH);
    delay(5000);
  } else if (r1 == '0') {
    digitalWrite(11, LOW);
    delay(5000);
  }

  // bool r2 = digitalRead(3);
  // bool r3 = digitalRead(4);
  // bool r4 = digitalRead(5);
  // bool r5 = digitalRead(6);
  // bool r6 = digitalRead(7);
  // bool r7 = digitalRead(8);
  // bool r8 = digitalRead(9);

  Serial.println(r1);
  // Serial.println(r2);
  // Serial.println(r3);
  // Serial.println(r4);
  // Serial.println(r5);
  // Serial.println(r6);
  // Serial.println(r7);
  // Serial.println(r8);
}
