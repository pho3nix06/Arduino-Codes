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
}
void loop() {
  int original = pow(2, 0) * digitalRead(3) + pow(2, 1) * digitalRead(4) + pow(2, 2) * digitalRead(5);
  int read = 7 - original;

  if (read == 0) {
    stop();
  } else if (read == 1) {
    right();
  } else if (read == 2) {
    forward();
  } else if (read == 3) {
    right();
  } else if (read == 4) {
    left();
  } else if (read == 5) {
    stop();
  } else if (read == 6) {
    left();
  } else if (read == 7) {
    stop();
  }
}