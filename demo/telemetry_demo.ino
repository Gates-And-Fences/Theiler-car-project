// ESP32 Telemetry Demo for RC Car
// Measures battery voltage and motor current

#include <Arduino.h>

// Pin definitions
const int voltagePin = 34;  // ADC pin for battery voltage monitoring
const int currentPin = 35;  // ADC pin for current sensing
const int relayPin = 23;    // Controls the relay module
const int statusLED = 2;    // Built-in LED for status indication

// Calibration values (adjust based on your voltage divider and shunt resistor)
const float voltageDividerRatio = 2.0;  // Adjust based on your voltage divider circuit
const float shuntResistorValue = 0.1;   // Ohms - adjust based on your shunt resistor
const float adcReferenceVoltage = 3.3;  // ESP32 ADC reference voltage
const int adcMaxValue = 4095;           // ESP32 12-bit ADC max value

// Variables for measurements
float batteryVoltage = 0.0;
float motorCurrent = 0.0;

void setup() {
  // Initialize serial communication
  Serial.begin(115200);
  
  // Configure pins
  pinMode(relayPin, OUTPUT);
  pinMode(statusLED, OUTPUT);
  pinMode(voltagePin, INPUT);
  pinMode(currentPin, INPUT);
  
  // Initialize outputs
  digitalWrite(relayPin, LOW);
  digitalWrite(statusLED, LOW);
  
  // Print startup message
  Serial.println("ESP32 Telemetry Demo Started");
  Serial.println("Measuring battery voltage and motor current");
  Serial.println("------------------------------------------");
}

void loop() {
  // Read raw ADC values
  int voltageRaw = analogRead(voltagePin);
  int currentRaw = analogRead(currentPin);
  
  // Convert raw ADC values to voltage and current
  // For voltage: Apply voltage divider ratio and convert ADC reading
  batteryVoltage = (voltageRaw * adcReferenceVoltage / adcMaxValue) * voltageDividerRatio;
  
  // For current: Convert ADC reading to voltage across shunt, then apply Ohm's law
  float shuntVoltage = currentRaw * adcReferenceVoltage / adcMaxValue;
  motorCurrent = shuntVoltage / shuntResistorValue;
  
  // Print telemetry data
  Serial.print("Battery Voltage: ");
  Serial.print(batteryVoltage, 2);
  Serial.print(" V\t");
  
  Serial.print("Motor Current: ");
  Serial.print(motorCurrent, 3);
  Serial.println(" A");
  
  // Toggle motor/LED every 2 seconds for demonstration
  digitalWrite(relayPin, HIGH);
  digitalWrite(statusLED, HIGH);
  delay(1000);
  
  digitalWrite(relayPin, LOW);
  digitalWrite(statusLED, LOW);
  delay(1000);
}