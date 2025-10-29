# 🔧 Buck Converter (Step-Down Regulator)

## Purpose
Converts 7.4–11.1 V from the Li-ion battery to a stable 5 V output for the ESP32.

## Example Specs
- **Input Voltage:** 6–24 V
- **Output:** 5 V @ up to 3 A
- **Efficiency:** >90%
- **Type:** LM2596 or XL4015 module
- **Adjustable:** Yes

## Wiring
- IN+ → Battery positive
- IN– → Battery negative
- OUT+ → ESP32 5V pin
- OUT– → Common ground

## Setup
- Before connecting the ESP32, adjust the output using a **multimeter** to precisely 5.0 V.
- Mount module where airflow is available.

## Notes
- Add a small heatsink if operating near max current.
- Keep wiring short to minimize voltage drop.