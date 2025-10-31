// Simple ESP32 Relay Motor Control Demo
// Based on the Science RC Car Project documentation
//
// This code demonstrates how to control a motor using a relay module
// connected to an ESP32 microcontroller. The relay isolates the high-current
// motor circuit from the low-current control circuit.
//
// Hardware connections:
// - Relay VCC -> 5V from buck converter
// - Relay GND -> Common ground with ESP32
// - Relay IN -> ESP32 GPIO 23 (controls relay activation)
// - Relay COM -> Battery positive terminal
// - Relay NO -> Motor positive terminal
// - Motor negative terminal -> Battery negative terminal
// - Push button -> ESP32 GPIO 5 (with internal pull-up resistor)
// - Status LED -> ESP32 GPIO 2 (built-in LED)

// Pin definitions
const int relayPin = 23;    // Controls the relay module
const int buttonPin = 5;    // Push button for manual control
const int statusLED = 2;    // Built-in LED for status indication

// Motor state
bool motorRunning = false;

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(115200);
  
  // Configure pins
  pinMode(relayPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(statusLED, OUTPUT);
  
  // Initialize outputs
  digitalWrite(relayPin, LOW);  // Motor off by default
  digitalWrite(statusLED, LOW); // LED off by default
  
  // Print startup message
  Serial.println("ESP32 Motor Control Demo Started");
  Serial.println("Press the button to toggle motor on/off");
}

void loop() {
  // Check if button is pressed (with debouncing)
  if (digitalRead(buttonPin) == LOW) {
    delay(50); // Simple debounce
    
    // Verify button is still pressed
    if (digitalRead(buttonPin) == LOW) {
      // Toggle motor state
      motorRunning = !motorRunning;
      
      if (motorRunning) {
        digitalWrite(relayPin, HIGH);  // Activate relay to turn motor ON
        digitalWrite(statusLED, HIGH); // Turn on status LED
        Serial.println("Motor ON");
      } else {
        digitalWrite(relayPin, LOW);   // Deactivate relay to turn motor OFF
        digitalWrite(statusLED, LOW); // Turn off status LED
        Serial.println("Motor OFF");
      }
      
      // Wait for button release
      while (digitalRead(buttonPin) == LOW) {
        delay(10);
      }
    }
  }
  
  // Small delay to prevent excessive CPU usage
  delay(10);
}