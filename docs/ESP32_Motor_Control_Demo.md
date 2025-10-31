# ESP32 Motor Control Demo

## Overview
This document provides instructions and examples for setting up and using the ESP32 Motor Control Demo Code.

## Wiring Diagram
![Wiring Diagram](./images/wiring_diagram.png)

## Setup Instructions
1. Connect the ESP32 to your computer via USB.
2. Upload the `code/esp32_motor_control_demo_code.ino` sketch to the ESP32 using the Arduino IDE.
3. Connect the motor driver to the ESP32 according to the wiring diagram.
4. Power the motor driver and ESP32 with a 7.4V battery through the buck converter.

## Usage Examples
### Controlling the Motor
To control the motor, use the following code snippet:
```cpp
void setup() {
  // Initialize motor control pins
  pinMode(MOTOR_PIN, OUTPUT);
}

void loop() {
  // Turn motor on
  digitalWrite(MOTOR_PIN, HIGH);
  delay(2000);

  // Turn motor off
  digitalWrite(MOTOR_PIN, LOW);
  delay(2000);
}