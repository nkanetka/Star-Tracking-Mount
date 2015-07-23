#include <SoftwareSerial.h>
#include <Stepper.h>

int delayLength = 451; // In microseconds 450721
int reverseLength = 300; // In seconds
int chA = 12; // setting the Channel A pin
int chB = 13; // setting the Channel B pin
int brakeA = 9; // setting the brake for channel A
int brakeB = 8; // setting the brake for channel B
bool reverse = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(chA, OUTPUT);
  pinMode(chB, OUTPUT);
  
  pinMode(brakeA, OUTPUT);
  pinMode(brakeB, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (reverse) {
    backward();
  } else {
    forward();
  }
}

void forward() {
  // 1
   digitalWrite(brakeA, LOW);
   digitalWrite(brakeB, HIGH);
   digitalWrite(chB, HIGH);
   analogWrite(3, 255);
   delay(delayLength);
   
 // 2
   digitalWrite(brakeA, LOW);
   digitalWrite(brakeB, HIGH);
   digitalWrite(chB, LOW);
   analogWrite(3, 255);
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
   analogWrite(3, 255);
   delay(reverseLength);
   
 // 2
   digitalWrite(brakeA, LOW);
   digitalWrite(brakeB, HIGH);
   digitalWrite(chB, HIGH);
   analogWrite(3, 255);
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
