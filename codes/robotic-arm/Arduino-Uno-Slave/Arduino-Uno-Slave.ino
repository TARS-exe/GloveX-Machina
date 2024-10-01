#include <Servo.h>

// Servos
Servo servo1;
Servo servo2;
Servo servo3;

Servo myServo1;
Servo myServo2;

void setup() 
{
  Serial.begin(115200); // Start Serial for HC-05 communication
  servo1.attach(3);
  servo2.attach(4);
  servo3.attach(5);
  
  myServo1.attach(2);
  myServo2.attach(7);
}

void loop() 
{
  if (Serial.available() > 0) // Check if data is available
  {
    // Read data from Serial
    String data = Serial.readStringUntil('\n'); // Read a line of data
    int values[4]; // Array to store sensor values
    int index = 0;

    // Parse the received data
    int startIndex = 0;
    int commaIndex = data.indexOf(',');

    while (commaIndex >= 0) {
      values[index++] = data.substring(startIndex, commaIndex).toInt();
      startIndex = commaIndex + 1;
      commaIndex = data.indexOf(',', startIndex);
    }
    values[index] = data.substring(startIndex).toInt(); // Last value

    // Assign received values
    int ax = values[0];
    int ay = values[1];
    int flexValue1 = values[2];
    int flexValue2 = values[3];

    // Map accelerometer data to servo positions
    int servo1Pos = map(ax, -17000, 17000, 0, 179);
    int servo2Pos = map(ay, -17000, 17000, 0, 179);
    int servo3Pos = map(0, -17000 * 1.5, 17000 * 1.5, 0, 179); // Yaw can be adjusted as needed

    // Move the servos
    servo1.write(servo1Pos);
    servo2.write(servo2Pos);
    servo3.write(servo3Pos);
    
    // Map flex sensor values to the servos
    int servoPos1 = map(flexValue1, 800, 900, 0, 180);
    servoPos1 = constrain(servoPos1, 0, 180);
    
    int servoPos2 = map(flexValue2, 800, 900, 0, 180);
    servoPos2 = constrain(servoPos2, 0, 180);
    
    myServo1.write(servoPos1); // Control the first flex servo
    myServo2.write(servoPos2); // Control the second flex servo
  }
}
