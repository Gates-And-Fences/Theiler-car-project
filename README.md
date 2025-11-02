# 🚗 Science RC Car Project

A lightweight, high-performance **ESP32-powered RC car** built for science, speed, and creativity.  
This project demonstrates how to design and control a small electric car using a **custom Li-ion battery**, **brushless or brushed motor**, **relay control**, and **ESP32 microcontroller**, all within a compact 3D-printed or handmade chassis.

---

## 📘 Overview

The goal of this project is to create an **RC-style science car** capable of running for 60–120 seconds at ~10 mph using an **ESP32 Dev Board** and **Li-ion (2S/7.4 V)** power system.  
The project combines elements of **electronics**, **programming**, **mechanical design**, and **battery engineering**, making it ideal for classroom demonstrations or hobby builds.

## 📚 Documentation

For detailed information about each component, see the comprehensive documentation in the `/docs` folder:

- **[🧠 ESP32 Controller](docs/ESP32.md)** - Microcontroller setup and programming
- **[🌀 Motor System](docs/Motor.md)** - Motor specifications and control
- **[🔋 Battery Pack](docs/Battery.md)** - Li-ion battery design and safety
- **[⚡ Relay Module](docs/Relay.md)** - Motor switching and isolation
- **[🔧 Buck Converter](docs/BuckConverter.md)** - Power regulation
- **[🧱 Chassis Design](docs/Chassis.md)** - Mechanical structure
- **[🔌 Wiring Guide](docs/Wiring.md)** - Complete electrical connections
- **[🎮 Controller Options](docs/Controller.md)** - Wireless control setup

---

## 🧠 Features

- ⚡ **ESP32 Control** – Dual-core microcontroller with Wi-Fi and Bluetooth for wireless input (e.g., Nintendo controller)
- 🔋 **Custom Li-ion Battery** – 2S pack (2×18650 cells, ~7.4 V, 5–6 Ah) with safe BMS
- 🌀 **Motor Drive** – Configurable for brushed or brushless motors (~550-size or LS-GM002)
- 🔌 **Relay Module Switching** – Motor power controlled by a relay to isolate logic and load circuits
- 🪫 **Buck Converter** – Steps battery voltage to safe 5 V for ESP32
- 🧱 **3D-Printed Chassis** – Custom lightweight body with room for battery, motor, and wiring
- 🧩 **Breadboard Prototyping** – Easy wiring, testing, and debugging

---

## 🧰 Parts List

| Category | Component | Example/Specs | Notes |
|-----------|------------|---------------|-------|
| **Microcontroller** | ESP32 Dev Board (CP2102, 30-pin) | Type-C USB | Handles control logic |
| **Power Supply** | 2× 18650 Li-ion cells + BMS | 7.4 V total | Rechargeable |
| **Voltage Regulation** | Buck Converter | Input 7.4–11.1 V → Output 5 V | Powers ESP32 safely |
| **Motor** | LS-GM002 / 550 brushed motor | ~6–12 V | High torque, easy control |
| **Motor Switch** | 5 V relay module | Opto-isolated | Controlled by ESP32 GPIO |
| **Wiring** | Male/Female jumper wires | 22-24 AWG | Connect components |
| **Breadboard** | Standard half-size | — | Prototyping platform |
| **Battery Holder** | 2-cell 18650 holder | w/ balance leads | Connects to BMS |
| **Misc** | Resistors, connectors, gears, 3D-printed parts | — | For chassis and power circuit |

---

## ⚙️ Electrical Overview
```
[Battery 7.4V]
|
+-----> [Buck Converter] ---> 5V ---> [ESP32 5V Pin]
|
+-----> [Relay Module] ---> [Motor + / –]
|
+--> [ESP32 GPIO Control]
```

- **Relay isolates** the high-current motor from the ESP32.
- **Buck converter** ensures stable 5 V logic power.
- **Grounds (GND)** from all modules must be shared.

---

## 🧾 Quick Start Wiring

| ESP32 Pin | Connection | Description |
|------------|-------------|--------------|
| VIN / 5V | From Buck Converter | Power input |
| GND | Common ground | Shared ground |
| GPIO 23 (example) | Relay IN pin | Turns motor on/off |
| 3V3 | Optional sensor supply | 3.3 V peripherals |

> 💡 **Tip:** For complete wiring details, see **[🔌 Wiring Guide](docs/Wiring.md)**

---

## 🔋 Battery Design (2S Li-ion)

- **Configuration:** 2× 18650 cells in series → 7.4 V nominal, ~8.4 V fully charged  
- **Capacity:** 5–6 Ah  
- **BMS:** 2S protection board for balancing and safety  
- **Performance:** ~60–120 s runtime at ~10 mph (depending on load)  
- **Charging:** Standard Li-ion 2S charger or USB balance charger  

**⚠️ Safety Notes:**
- Never short or puncture Li-ion cells.  
- Use heat-resistant wiring and proper insulation.  
- Do not charge unattended.

---

## 🚀 Getting Started

### Option 1: Try the Simulations First
Before building the physical car, you can explore the project through simulations:

1. **Web Simulation**: Open `web_simulation/index.html` in your browser for an interactive demo
2. **Wokwi Simulation**: Visit [wokwi.com](https://wokwi.com) and load the project files from `wokwi_simulation/`
3. **Demo Code**: Review the Arduino examples in the `demo/` folder

### Option 2: Build the Physical Car
Follow the assembly steps below to build your own RC car.

## 🧩 Assembly Steps

1. **Prepare power system**
   - Solder or connect 2×18650 cells with BMS and output leads.
   - Test output (~7.4 V nominal).
2. **Connect buck converter**
   - Input from battery → Output 5 V → ESP32 5V pin.
3. **Wire relay and motor**
   - Motor’s positive lead through relay’s Normally Open (NO) terminal.
   - Relay IN pin → ESP32 GPIO.
4. **Upload control code**
   - Use Arduino IDE or PlatformIO.
   - Example: toggle relay with a button press.
5. **Test circuit**
   - Verify 5 V at ESP32 and correct relay switching.
6. **Assemble chassis**
   - Mount battery, ESP32, relay, and motor securely.
7. **Control**
   - Use serial, Bluetooth, or a controller (e.g., Nintendo Switch input library) for throttle or trigger.

---

## 💻 Code Examples

This project includes several code examples and simulations:

### Demo Code
- **[motor_control_demo.ino](demo/motor_control_demo.ino)** - Basic motor control implementation
- **[telemetry_demo.ino](demo/telemetry_demo.ino)** - Telemetry and data logging example

### Wokwi Simulation
The project includes a complete **[Wokwi simulation](wokwi_simulation/)** that allows you to test the circuit virtually:
- Interactive circuit diagram
- ESP32 code simulation
- Virtual hardware testing

### Web Simulation
A **[web-based simulation](web_simulation/)** is also available for browser-based testing and visualization.

### Simple ESP32 Relay Motor Control Example
```cpp
// Simple ESP32 Relay Motor Control
int relayPin = 23;
int buttonPin = 5;

void setup() {
  pinMode(relayPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    digitalWrite(relayPin, HIGH);  // Motor ON
  } else {
    digitalWrite(relayPin, LOW);   // Motor OFF
  }
}
```
## 🧠 Current Features & Future Improvements

### ✅ Implemented
- ✅ **Telemetry system** - See `demo/telemetry_demo.ino` for implementation
- ✅ **Web-based simulation** - Interactive browser demo available
- ✅ **Wokwi virtual testing** - Complete circuit simulation environment
- ✅ **Motor control demo** - Basic on/off control implementation

### 🚧 Future Improvements
- Add ESC + PWM for variable motor speed control
- Integrate Bluetooth controller input (Nintendo Switch / PS4 gamepad)
- Upgrade to brushless motor for higher power density
- Design custom PCB for more compact wiring
- Add real-time data visualization to web interface
- Implement advanced motion control algorithms
- Add obstacle avoidance sensors

## 🧰 Tools & Platforms Used

### Hardware Development
- **Electronics**: Soldering iron, multimeter, breadboard, wire kit
- **3D Design**: FreeCAD or Fusion 360 for chassis design
- **Printing**: Bambu Studio or Cura for 3D printing parts
- **Testing**: Bench power supply or Li-ion charger

### Software Development
- **Programming**: Arduino IDE, PlatformIO for ESP32 development
- **Simulation**: Wokwi for virtual circuit testing
- **Web Development**: HTML5, CSS3, JavaScript for browser simulation
- **Version Control**: Git for project management

### Simulation Platforms
- **[Wokwi](https://wokwi.com)** - Virtual electronics prototyping
- **Web Browser** - For interactive demonstrations and testing

## 📸 Media (optional)
You can add images or diagrams here once ready:

```bash
Copy code
/images/
 ├── wiring_diagram.png
 ├── car_assembled.jpg
 ├── battery_pack.jpg
 └── esp32_relay_setup.png
```

![Car Build](images/car_assembled.jpg)

## 🧾 License
This project is released under the MIT License — you can modify and use it freely, with attribution.

## 👥 Contributors
Gates Jones – Co-Project lead, design, electronics, and testing

CJ Hauser - Co-Project lead, development, presentation

Griffin Lukenbill - Project creative team

Bennet Bedard - Project creative team

ChatGPT (GPT-5) – Documentation and design assistance

Pollinations.ai/PrisimAI - Docs and Code assistance

## ⭐ Acknowledgments
- Espressif for the ESP32 platform

- Open-source electronics and RC community

- Instructors and classmates who inspired this science project

## 📦 Repository Structure

```
Theiler-car-project/
├── docs/                    # 📚 Detailed component documentation
│   ├── ESP32.md            # Microcontroller guide
│   ├── Motor.md            # Motor system details
│   ├── Battery.md          # Li-ion battery design
│   ├── Relay.md            # Relay module setup
│   ├── BuckConverter.md    # Power regulation
│   ├── Chassis.md          # Mechanical design
│   ├── Wiring.md           # Electrical connections
│   └── Controller.md       # Wireless control options
├── demo/                   # 💻 Arduino/ESP32 demo code
│   ├── motor_control_demo.ino    # Basic motor control example
│   └── telemetry_demo.ino       # Telemetry and monitoring example
├── 3d_files/               # 🧱 CAD files and 3D printable models
│   └── [3D design files]   # Chassis and component models
├── web_simulation/         # 🌐 Browser-based simulation
│   ├── index.html          # Main simulation interface
│   ├── script.js           # Simulation logic
│   └── style.css           # Styling for web interface
├── wokwi_simulation/       # 🔧 Wokwi virtual circuit simulation
│   ├── diagram.json        # Circuit diagram configuration
│   ├── sketch.ino          # ESP32 simulation code
│   ├── wokwi-project.txt   # Project metadata
│   └── wokwi.toml          # Wokwi configuration
├── LICENSE                 # 📄 MIT License
└── README.md              # 📖 This file
```
