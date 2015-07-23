#include <Stepper.h>

int firstPin = 12;
int secondPin = 11;
int thirdPin = 9;
int fourthPin = 8;

Stepper motor(200, firstPin, secondPin, thirdPin, fourthPin);

void setup() {
  // put your setup code here, to run once:
  pinMode(firstPin, OUTPUT);
  pinMode(secondPin, OUTPUT);
  pinMode(thirdPin, OUTPUT);
  pinMode(fourthPin, OUTPUT);

  Serial.begin(9600);
  motor.setSpeed(10);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()) {
    int steps = Serial.parseInt();
    motor.step(steps);
  }
}
