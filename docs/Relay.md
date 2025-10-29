# ⚡ Relay Module

## Overview
The relay module isolates the high-current motor circuit from the low-current control system (ESP32).

## Specs
- **Type:** 1-channel 5 V relay module
- **Trigger:** Active LOW (usually)
- **Isolation:** Opto-isolated recommended
- **Load Rating:** Up to 10 A @ 30 V DC
- **Input Current:** ~20 mA

## Wiring
| Relay Pin | Connects To | Description |
|------------|--------------|-------------|
| VCC | 5 V (from buck converter) | Relay coil power |
| GND | Common ground | Shared with ESP32 |
| IN | GPIO 23 (example) | Control signal |
| COM | Battery + | Input from power |
| NO | Motor + | Output to motor positive |
| NC | — | Not used |

## Notes
- Use heat-shrink tubing around relay terminals.
- Do **not** switch directly from ESP32 power — use external battery.