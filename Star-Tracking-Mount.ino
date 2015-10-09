#include <SoftwareSerial.h>
#include <Stepper.h>

// Constants and variables
int delayLength = 1353; // In microseconds 450721
int reverseLength = 30; // In seconds
int chA = 12; // setting the Channel A pin
int chB = 13; // setting the Channel B pin
int brakeA = 9; // setting the brake for channel A
int brakeB = 8; // setting the brake for channel B
volatile bool up = false;
volatile bool reverse = false;
volatile bool stopMotor = false;
int buttonForward = 6; // green button | pin 6
int buttonStop = 3; // red button | pin 3
int buttonBackward = 4; // black button | pin 4
volatile int state = LOW; // CHANGE!

void setup() {
  // Outputs for the stepper motor
  pinMode(chA, OUTPUT);
  pinMode(chB, OUTPUT);

  // Output for the stopping of the stepper motor
  pinMode(brakeA, OUTPUT);
  pinMode(brakeB, OUTPUT);

  // Input for the control buttons
  pinMode(buttonForward, INPUT); // Setting the forward button
  pinMode(buttonStop, INPUT); // Setting the stop button
  pinMode(buttonBackward, INPUT); // Setting the backward button
//  attachInterrupt(digitalPinToInterrupt(buttonForward), setDirectionForwards, LOW); // green button
  attachInterrupt(digitalPinToInterrupt(buttonStop), stopFunction, RISING); // red button
  Serial.begin(9600);
}

void loop() {
//  Serial.println(digitalRead(buttonForward));
//  Serial.println(digitalRead(buttonBackward));
//  Serial.println(digitalRead(buttonStop));
  if (digitalRead(buttonBackward) == HIGH){
    up = false;
    stopMotor = false;
    backward();
  }
  
  if(digitalRead(buttonForward) == HIGH || up) {
    stopMotor = false;
    reverse = false;
    up = true;
    forward();
  } 
  
  if(stopMotor) {
//    up = false;
//    reverse = false;
//    stopTurning();
  }
}

void forward() {
  // 1
   digitalWrite(brakeA, LOW);
   digitalWrite(brakeB, HIGH);
   digitalWrite(chB, HIGH);
   analogWrite(5, 255);
   delay(delayLength);
   
 // 2
   digitalWrite(brakeA, LOW);
   digitalWrite(brakeB, HIGH);
   digitalWrite(chB, LOW);
   analogWrite(5, 255);
   delay(delayLength);
   
 // 3
   digitalWrite(brakeA, HIGH);
   digitalWrite(brakeB, LOW);
   digitalWrite(chA, HIGH);
   analogWrite(11, 255);
   delay(delayLength);

 // 4
   digitalWrite(brakeA, HIGH);
   digitalWrite(brakeB, LOW);
   digitalWrite(chA, LOW);
   analogWrite(11, 255);
   delay(delayLength);
}

void backward() {
  // 1
   digitalWrite(brakeA, LOW);
   digitalWrite(brakeB, HIGH);
   digitalWrite(chB, LOW);
   analogWrite(5, 255);
   delay(reverseLength);
   
 // 2
   digitalWrite(brakeA, LOW);
   digitalWrite(brakeB, HIGH);
   digitalWrite(chB, HIGH);
   analogWrite(5, 255);
   delay(reverseLength);
   
 // 3
   digitalWrite(brakeA, HIGH);
   digitalWrite(brakeB, LOW);
   digitalWrite(chA, LOW);
   analogWrite(11, 255);
   delay(reverseLength);

 // 4
   digitalWrite(brakeA, HIGH);
   digitalWrite(brakeB, LOW);
   digitalWrite(chA, HIGH);
   analogWrite(11, 255);
   delay(reverseLength);
}

void stopTurning() {
  // 1
   digitalWrite(brakeA, LOW);
   digitalWrite(brakeB, LOW);
   digitalWrite(chB, LOW);
   analogWrite(5, 0);
   delay(delayLength);
   
 // 2
   digitalWrite(brakeA, LOW);
   digitalWrite(brakeB, LOW);
   digitalWrite(chB, LOW);
   analogWrite(5, 0);
   delay(delayLength);
   
 // 3
   digitalWrite(brakeA, LOW);
   digitalWrite(brakeB, LOW);
   digitalWrite(chA, LOW);
   analogWrite(11, 0);
   delay(delayLength);

 // 4
   digitalWrite(brakeA, LOW);
   digitalWrite(brakeB, LOW);
   digitalWrite(chA, LOW);
   analogWrite(11, 0);
   delay(delayLength);
}

void setDirectionForwards() {
  reverse = false;
  stopMotor = false;
  up = true;
}

void stopFunction() {
  reverse = false;
  stopMotor = true;
  up = false;
}

