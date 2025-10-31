// Define pin numbers
const int relayPin = 23;
const int buttonPin = 5;

void setup() {
  // Initialize relay pin as output
  pinMode(relayPin, OUTPUT);
  // Initialize button pin as input with pull-up resistor
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  // Check if the button is pressed
  if (digitalRead(buttonPin) == LOW) {
    digitalWrite(relayPin, HIGH);  // Motor ON
  } else {
    digitalWrite(relayPin, LOW);   // Motor OFF
  }
}