// int enA = 10;
int in1 = 11;
int in2 = 12;

// int enB = 9;
int in3 = 13;
int in4 = 8;

int max_speed = 200;
int set_speed = 100;
int min_speed = 50;
int stop_speed = 0;
int left_ir = 3;
int middle_ir = 4;
int right_ir = 5;


void forward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void stop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void right() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void left() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void setup() {

  // Intialize pins
  pinMode(left_ir, INPUT);
  pinMode(middle_ir, INPUT);
  pinMode(right_ir, INPUT);
  // Set all the motor control pins to outputs
  // pinMode(enA, OUTPUT);
  // pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);


  // Turn off motors - Initial state
  stop();
  delay(2000);

  forward();
  delay(2000);

  left();
  delay(2000);

  right();
  delay(2000);

  stop();
  delay(2000);
}
void loop() {
}