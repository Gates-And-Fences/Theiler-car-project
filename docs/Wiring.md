# 🔌 Wiring and Connections

## Overview
This file describes all major electrical connections between the components.

## Power Path

```
[Battery 7.4V]
├──> [Buck Converter] → 5V → [ESP32 5V Pin]
└──> [Relay Module] → [Motor]
```

## Ground Path
All grounds **must** connect:

```
Battery GND = Buck Converter GND = ESP32 GND = Relay GND
```

## Signal Path

```
ESP32 GPIO 23 → Relay IN → Motor ON/OFF

### ESP32 Motor Control Demo
- **Purpose:** Control motor using ESP32.
- **Connections:**
  - ESP32 GPIO 23 → Relay IN → Motor ON/OFF
  - Refer to [ESP32 Motor Control Demo](./ESP32_Motor_Control_Demo.md) for detailed wiring.
```

## Tips
- Use **22 AWG silicone wire** for low-current circuits.
- Use **16–18 AWG wire** for motor and battery leads.
- Label wires with tape or heat-shrink for clarity.