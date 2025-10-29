# 🔋 Custom Li-ion Battery (2S Configuration)

## Overview
This battery powers the motor and electronics. It is made from **two 18650 cells** in series for ~7.4 V total.

## Specs
- **Cell Type:** 18650 Li-ion
- **Configuration:** 2S1P (7.4 V nominal, 8.4 V full)
- **Capacity:** 5–6 Ah
- **Discharge:** 50–75C (high current)
- **BMS:** 2S protection + balance board
- **Output:** XT30 or XT60 connector (recommended)

## Safety Notes
- Never short or overcharge cells.
- Use a proper **2S balance charger**.
- Ensure good airflow and insulation around cells.
- Store at 50–60% charge when not in use.

## Wiring Overview

```
[Cell 1 +] → [BMS B1+]
[Cell 1 -] → [BMS B-]
[Cell 2 +] → [BMS B2+]
BMS P+ → Output +
BMS P- → Output -
```