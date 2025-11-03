#include <Bluepad32.h>

GamepadPtr controller;          // pointer to the connected gamepad
const int MOTOR_PIN = 23;       // pin that drives your motor relay / transistor

void onConnectedGamepad(GamepadPtr gp) { controller = gp; }
void onDisconnectedGamepad(GamepadPtr gp) { controller = nullptr; }

void setup() {
  pinMode(MOTOR_PIN, OUTPUT);
  digitalWrite(MOTOR_PIN, LOW);   // motor off at start

  Serial.begin(115200);
  BP32.setup(&onConnectedGamepad, &onDisconnectedGamepad);
  BP32.forgetBluetoothKeys();     // only needed the first time you pair
  BP32.enableNewBluetoothConnections(true);
  Serial.println("Press SYNC on your controller to connect...");
}

void loop() {
  BP32.update(); // keep Bluetooth active

  // If controller is connected, read the B button
  if (controller && controller->isConnected()) {
    bool bPressed = controller->b();
    digitalWrite(MOTOR_PIN, bPressed ? HIGH : LOW);
  }
}