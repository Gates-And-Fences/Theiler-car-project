# 🌀 Motor System

## Overview
The motor provides propulsion. The system supports both **brushed (simpler)** and **brushless (ESC-controlled)** motors depending on the setup.

## Current Build
- **Type:** Brushed DC motor (LS-GM002 or 550 size)
- **Voltage Range:** 6–12 V
- **Power:** ~400–500 W burst
- **Speed:** Up to 10 mph (est.)
- **Control Method:** Relay ON/OFF switching

## Connection
- +V line through relay's NO terminal

### ESP32 Motor Control Demo
- **Purpose:** Control motor using ESP32.
- **Connections:**
  - +V line through relay's NO terminal
  - Refer to [ESP32 Motor Control Demo](./ESP32_Motor_Control_Demo.md) for detailed setup.
- –V directly to battery negative
- Relay input controlled by ESP32

## Future Options
- Upgrade to **ESC + PWM** control for speed variation.
- Add encoder for **RPM measurement**.
- Add heat sink or small fan for continuous runs.