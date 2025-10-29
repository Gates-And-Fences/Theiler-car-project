# 🎮 Wireless Controller (Optional)

## Overview
The ESP32 supports Bluetooth, allowing a **Nintendo Switch, PS4, or phone** to control the car wirelessly.

## Options
- **Nintendo Switch Controller:** via ESP32 BLE Gamepad library
- **Smartphone App:** via Bluetooth serial or Wi-Fi web control
- **Wired Switch:** simple button on GPIO pin for manual demo

## Example: BLE Gamepad Library
```cpp
#include <BleGamepad.h>
BleGamepad gamepad;

void setup() {
  gamepad.begin();
}

void loop() {
  if (gamepad.isConnected()) {
    // Map button or joystick to motor control
  }
}
```

## Notes
- Disable power-hungry Wi-Fi features when using BLE.
- Ensure 5 V supply is stable during pairing.