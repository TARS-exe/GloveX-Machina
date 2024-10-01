/*
#include <Servo.h> 

Servo myServo;

const int flexPin = A0; 

void setup() 
{ 
  myServo.attach(2);
} 

void loop() 
{ 
  int flexValue;
  int servoPosition;
  
  flexValue = analogRead(flexPin);
  
  servoPosition = map(flexValue, 800, 900, 0, 180);
  servoPosition = constrain(servoPosition, 0, 180);

  myServo.write(servoPosition);
  
  delay(20);
} 
*/

#include <Servo.h>

Servo myServo1;
Servo myServo2;

const int flexPin1 = A0; // First flex sensor pin
const int flexPin2 = A1; // Second flex sensor pin

void setup() 
{ 
  myServo1.attach(2); // Attach the first servo to pin 2
  myServo2.attach(7); // Attach the second servo to pin 5
} 

void loop() 
{ 
  int flexValue1 = analogRead(flexPin1); // Read the value from the first flex sensor
  int flexValue2 = analogRead(flexPin2); // Read the value from the second flex sensor
  
  // Map the flex sensor values to the servo position range
  int servoPosition1 = map(flexValue1, 800, 900, 0, 180);
  servoPosition1 = constrain(servoPosition1, 0, 180); // Ensure the position is within valid range
  
  int servoPosition2 = map(flexValue2, 800, 900, 0, 180);
  servoPosition2 = constrain(servoPosition2, 0, 180); // Ensure the position is within valid range

  myServo1.write(servoPosition1); // Set the first servo position
  myServo2.write(servoPosition2); // Set the second servo position
  
  delay(20); // Small delay to smooth the motion
}
