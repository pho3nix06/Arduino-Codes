#define L_MOTOR_FRONT 9
#define L_MOTOR_BACK 11
#define R_MOTOR_FRONT 13
#define R_MOTOR_BACK 8
#define MAX_SPEED 200
#define SET_SPEED 200
#define MIN_SPEED 50
#define STOP_SPEED 0
#define LEFT_IR 3
#define MIDDLE_IR 4
#define RIGHT_IR 5
#define TAPE_THRESHOLD 350

void setup() {
  // Intialize pins
  pinMode(LEFT_IR, INPUT);
  pinMode(MIDDLE_IR, INPUT);
  pinMode(RIGHT_IR, INPUT);
}

void loop() {

  if (analogRead(LEFT_IR) < TAPE_THRESHOLD) {
    // We are seeing the line under the left sensor, turn left
    analogWrite(L_MOTOR_FRONT, MIN_SPEED);
    analogWrite(L_MOTOR_BACK, MIN_SPEED);
    analogWrite(R_MOTOR_FRONT, SET_SPEED);
    analogWrite(R_MOTOR_BACK, SET_SPEED);

  } else if (analogRead(MIDDLE_IR) < TAPE_THRESHOLD) {
    // We are seeing the line under the middle sensor, go straight
    analogWrite(L_MOTOR_FRONT, SET_SPEED);
    analogWrite(L_MOTOR_BACK, SET_SPEED);
    analogWrite(R_MOTOR_FRONT, SET_SPEED);
    analogWrite(R_MOTOR_BACK, SET_SPEED);

  } else if (analogRead(RIGHT_IR) < TAPE_THRESHOLD) {
    // We are seeing the line under the right sensor, turn right
    analogWrite(R_MOTOR_FRONT, MIN_SPEED);
    analogWrite(R_MOTOR_BACK, MIN_SPEED);
    analogWrite(L_MOTOR_FRONT, SET_SPEED);
    analogWrite(L_MOTOR_BACK, SET_SPEED);

  } else {
    // We don't see the line at all, let's stop
    analogWrite(R_MOTOR_FRONT, STOP_SPEED);
    analogWrite(R_MOTOR_BACK, STOP_SPEED);
    analogWrite(L_MOTOR_FRONT, STOP_SPEED);
    analogWrite(L_MOTOR_BACK, STOP_SPEED);
  }
}