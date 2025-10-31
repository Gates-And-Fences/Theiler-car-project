// Define pin numbers
const int relayPin = 23;
const int motor1Pin = 9;
const int motor2Pin = 10;

#include <BleGamepad.h>
BleGamepad bleGamepad;

void setup() {
  Serial.begin(115200);
  bleGamepad.begin();

  // Initialize relay pin as output
  pinMode(relayPin, OUTPUT);

  // Set motor pins as outputs
  pinMode(motor1Pin, OUTPUT);
  pinMode(motor2Pin, OUTPUT);
}

void loop() {
  if (bleGamepad.isConnected()) {
    int leftStickY = bleGamepad.getLeftYAxis();  // Corrected method call
    int rightStickY = bleGamepad.getRightYAxis(); // Corrected method call

    // Map joystick values to motor speeds (0-255)
    int motor1Speed = map(leftStickY, -127, 127, 0, 255);
    int motor2Speed = map(rightStickY, -127, 127, 0, 255);

    // Write motor speeds
    analogWrite(motor1Pin, motor1Speed);
    analogWrite(motor2Pin, motor2Speed);

    // Print motor speeds for debugging
    Serial.print("Motor 1 Speed: ");
    Serial.println(motor1Speed);
    Serial.print("Motor 2 Speed: ");
    Serial.println(motor2Speed);

    // Delay to prevent flooding serial output
    delay(100);
  }
}