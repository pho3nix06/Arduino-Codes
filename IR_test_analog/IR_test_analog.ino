#define IR1 A0
// #define IR2 3
// #define IR3 4
// #define IR4 5
// #define IR5 6
// #define IR6 7
// #define IR7 8
// #define IR8 9

void setup() {
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
  int r1 = analogRead(2);
  // int r2 = analogRead(3);
  // int r3 = analogRead(4);
  // int r4 = analogRead(5);
  // int r5 = analogRead(6);
  // int r6 = analogRead(7);
  // int r7 = analogRead(8);
  // int r8 = analogRead(9);

  Serial.println(r1);
  // Serial.println(r2);
  // Serial.println(r3);
  // Serial.println(r4);
  // Serial.println(r5);
  // Serial.println(r6);
  // Serial.println(r7);
  // Serial.println(r8);
}
