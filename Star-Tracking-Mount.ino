#include <SoftwareSerial.h>
#include <Stepper.h>

int delayLength = 500;// 30

void setup() {
  // put your setup code here, to run once:
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // 1
  digitalWrite(9, LOW);
  digitalWrite(8, HIGH);
  
  digitalWrite(12, HIGH);
  analogWrite(3, 255);
  
  delay(delayLength);
  
  // 3
  digitalWrite(9, LOW);
  digitalWrite(8, HIGH);
  
  digitalWrite(12, LOW);
  analogWrite(3, 255);
  
  delay(delayLength);
  
  // 4
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);
  
  digitalWrite(13, HIGH);
  analogWrite(11, 255);
  
  delay(delayLength);
  
  // 2
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);
  
  digitalWrite(13, LOW);
  analogWrite(11, 255);
  
  delay(delayLength);
}
