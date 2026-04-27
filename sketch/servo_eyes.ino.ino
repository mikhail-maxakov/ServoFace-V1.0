#include <Servo.h>

Servo eyeLeftX;
Servo eyeRightX;
Servo eyeY;
Servo eyelidLeft;
Servo eyelidRight;

const int CENTER = 90;
const int OFFSET = 30;
const int ANGLE_MIN = CENTER - OFFSET;
const int ANGLE_MAX = CENTER + OFFSET;

const int EYE_OPEN = 0;
const int EYE_CLOSED = 90;

const unsigned long BLINK_INTERVAL = 4000;
const int BLINK_DURATION = 120;
const int LOOP_DELAY = 25;

float posLeftX = CENTER;
float posRightX = CENTER;
int dirLeft = 1;
int dirRight = -1;

float posY = CENTER;
int dirY = 1;

unsigned long lastBlink = 0;

void setup() {
  eyeLeftX.attach(3);
  eyeRightX.attach(5);
  eyeY.attach(6);
  eyelidLeft.attach(9);
  eyelidRight.attach(10);
  
  eyeLeftX.write(CENTER);
  eyeRightX.write(CENTER);
  eyeY.write(CENTER);
  eyelidLeft.write(EYE_OPEN);
  eyelidRight.write(EYE_OPEN);
  
  delay(500);
}

void loop() {
  posLeftX += 0.8 * dirLeft;
  if (posLeftX >= ANGLE_MAX) {
    posLeftX = ANGLE_MAX;
    dirLeft = -1;
  }
  if (posLeftX <= ANGLE_MIN) {
    posLeftX = ANGLE_MIN;
    dirLeft = 1;
  }
  eyeLeftX.write((int)posLeftX);
  
  posRightX += 1.0 * dirRight;
  if (posRightX >= ANGLE_MAX) {
    posRightX = ANGLE_MAX;
    dirRight = -1;
  }
  if (posRightX <= ANGLE_MIN) {
    posRightX = ANGLE_MIN;
    dirRight = 1;
  }
  eyeRightX.write((int)posRightX);
  
  posY += 0.6 * dirY;
  if (posY >= ANGLE_MAX) {
    posY = ANGLE_MAX;
    dirY = -1;
  }
  if (posY <= ANGLE_MIN) {
    posY = ANGLE_MIN;
    dirY = 1;
  }
  eyeY.write((int)posY);
  
  if (millis() - lastBlink >= BLINK_INTERVAL) {
    eyelidLeft.write(EYE_CLOSED);
    eyelidRight.write(EYE_CLOSED);
    delay(BLINK_DURATION);
    
    eyelidLeft.write(EYE_OPEN);
    eyelidRight.write(EYE_OPEN);
    
    lastBlink = millis();
  }
  
  delay(LOOP_DELAY);
}