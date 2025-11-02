#include <Bluepad32.h>

GamepadPtr controller;     // pointer to one controller
const int LED_PIN = 2;     // built-in LED on most ESP32 boards

void onConnectedGamepad(GamepadPtr gp) { controller = gp; }
void onDisconnectedGamepad(GamepadPtr gp) { controller = nullptr; }

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
  BP32.setup(&onConnectedGamepad, &onDisconnectedGamepad);
  BP32.forgetBluetoothKeys();   // only needed the first time you pair
  Serial.println("Press SYNC on your controller to connect.");
}

void loop() {
  BP32.update();                 // keep Bluetooth running
  if (controller && controller->isConnected())
    digitalWrite(LED_PIN, controller->b());   // A button controls LED
}