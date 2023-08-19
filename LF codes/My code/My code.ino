int enA = 10;
int in1 = 11;
int in2 = 12;

int enB = 9;
int in3 = 13;
int in4 = 8;

int max_speed = 200;
int set_speed = 100;
int min_speed = 50;
int stop_speed = 0;
int left_ir = 3;
int middle_ir = 4;
int right_ir = 5;





void setup() {
  pinMode(left_ir, INPUT);
  pinMode(middle_ir, INPUT);
  pinMode(right_ir, INPUT);
  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);


  analogWrite(enA, 255);
  analogWrite(enB, 255);
}

void loop() {
  // put your main code here, to run repeatedly:
}
