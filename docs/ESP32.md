# 🧠 ESP32 Controller

## Overview
The **ESP32 Dev Board** serves as the central control unit of the RC car. It manages power signals, relay activation, and optional wireless control via Bluetooth or Wi-Fi.

## Specifications
- **Model:** ESP32-WROOM-32 (CP2102)
- **Input Voltage:** 5 V (via 5V pin or USB)
- **Logic Voltage:** 3.3 V
- **Wi-Fi:** 802.11 b/g/n
- **Bluetooth:** v4.2 BR/EDR and BLE
- **GPIO Pins:** 30 total (usable ~25)
- **Processor:** Dual-core 32-bit @ 240 MHz

## Pin Assignments (example)
| Function | Pin | Notes |
|-----------|-----|-------|
| Motor Relay | GPIO 23 | Controls motor ON/OFF |
| Battery Monitor | GPIO 34 | Analog input (optional) |
| Bluetooth Pairing LED | GPIO 2 | Status indicator |
| GND | — | Common ground |

## Setup
- Program via **Arduino IDE** or **PlatformIO**.
- Board: `ESP32 Dev Module`
- Upload speed: `115200`
- Power via USB or 5 V pin.

## Notes
- Always connect **GND** to all other module grounds.
- Use **Vin/5V** pin from the buck converter, not direct battery voltage.