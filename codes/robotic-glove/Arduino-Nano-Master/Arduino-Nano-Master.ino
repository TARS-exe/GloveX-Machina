#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>

// Create MPU6050 instance
MPU6050 mpu;
int16_t ax, ay, az;

// Flex sensor pins
const int flexPin1 = A0; // First flex sensor pin
const int flexPin2 = A1; // Second flex sensor pin

void setup() 
{
  Serial.begin(115200); // Start Serial for HC-05 communication
  Wire.begin(); // Start I2C for MPU6050

  // Initialize MPU6050
  mpu.initialize();
  Serial.println(mpu.testConnection() ? "MPU6050 connected" : "MPU6050 connection failed");
}

void loop() 
{
  // Read MPU6050 data
  mpu.getMotion6(&ax, &ay, &az, NULL, NULL, NULL);
  
  // Read flex sensor values
  int flexValue1 = analogRead(flexPin1);
  int flexValue2 = analogRead(flexPin2);
  
  // Send data over Serial to the Uno via HC-05
  Serial.print(ax); Serial.print(",");
  Serial.print(ay); Serial.print(",");
  Serial.print(flexValue1); Serial.print(",");
  Serial.println(flexValue2);
  
  delay(50); // Small delay between readings
}
