# FNAF Cupcake Animatronic

Arduino and ESP32 powered FNAF Movie inspired animatronic cupcake with servo-controlled movements and glowing NeoPixel eyes.

![Project Status](https://img.shields.io/badge/status-in%20development-yellow)
![License](https://img.shields.io/badge/license-MIT-blue)

## 📋 Overview

This project brings the iconic cupcake from Five Nights at Freddy's to life as a desktop animatronic featuring:
- 7 servo motors for realistic movements
- Glowing RGB NeoPixel eyes (50mm rings)
- Arduino Uno for servo control
- ESP32 for eye animation control
- 3D printed structure and parts
- Inspired by the FNAF Movie design

## 🛠️ Hardware Requirements

### Electronics
- **1x Arduino Uno** - Main controller for servos
- **1x PCA9685 Servo Shield** - 16-channel PWM servo driver
- **1x ESP32** - Controller for NeoPixel eyes
- **6x MG90S Servos** - Metal gear micro servos for precise movements
- **1x DS3225 Servo** - High-torque servo for jaw movement
- **2x NeoPixel RGB Rings (50mm)** - For glowing eyes
- **1x 5mm LED (Orange)** - Status indicator
- **Power supply** - 5V adequate for all servos

### Mechanical Parts
- M2 ball joints
- M2 threaded rods
- M2 screws (various lengths)
- M3 screws (various lengths)
- 1x M10 screw
- Ball bearings

### 3D Printing
- PLA filament (main structure)
- TPU filament (flexible parts)
- Access to 3D printer

## 📁 Project Structure

```
fnaf-cupcake-animatronic/
├── arduino/
│   ├── servo_controller/
│   │   ├── servo_controller.ino
│   │   └── config.h
│   └── libraries/
├── esp32/
│   ├── eye_controller/
│   │   ├── eye_controller.ino
│   │   └── animations.h
│   └── libraries/
├── 3d_models/
│   ├── STL/
│   └── design_files/
├── docs/
│   ├── wiring_diagram.png
│   ├── assembly_guide.md
│   └── calibration.md
├── tests/
│   ├── servo_test/
│   └── neopixel_test/
├── .gitignore
├── LICENSE
└── README.md
```

## 🔧 Software Setup

### Arduino IDE Setup
1. Install [Arduino IDE](https://www.arduino.cc/en/software) (version 2.0+)
2. Install required libraries:
   - Adafruit PWM Servo Driver Library
   - Wire library (built-in)

### ESP32 Setup
1. Add ESP32 board support to Arduino IDE
   - File → Preferences → Additional Board Manager URLs
   - Add: `https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json`
2. Install ESP32 board package
3. Install required libraries:
   - Adafruit NeoPixel
   - FastLED (optional, for advanced effects)

### Visual Studio Code (Optional)
If using VS Code with PlatformIO:
```bash
# Install PlatformIO extension
# Open project folder
# PlatformIO will auto-detect configuration
```

## ⚡ Quick Start

### 1. Clone Repository
```bash
git clone https://github.com/allan-stampe/fnaf-cupcake-animatronic.git
cd fnaf-cupcake-animatronic
```

### 2. Upload Arduino Code
```bash
# Open arduino/servo_controller/servo_controller.ino in Arduino IDE
# Select Board: Arduino Uno
# Select correct COM port
# Click Upload
```

### 3. Upload ESP32 Code
```bash
# Open esp32/eye_controller/eye_controller.ino in Arduino IDE
# Select Board: ESP32 Dev Module
# Select correct COM port
# Click Upload
```

### 4. Test Servos
Run the servo test sketch to verify all connections:
```bash
# Upload tests/servo_test/servo_test.ino
# Open Serial Monitor (115200 baud)
# Follow calibration instructions
```

## 🎨 Features

- **Jaw Movement**: Realistic opening/closing mouth animations
- **Head Tilt**: Pan and tilt movements for lifelike behavior
- **Eye Glow**: RGB NeoPixel rings with multiple animation patterns
- **Modular Design**: Easy to modify and customize
- **Serial Control**: Control via Serial commands for testing
- **Animation Sequences**: Pre-programmed movement patterns

## 📖 Documentation

Detailed guides available in `/docs`:
- [Wiring Diagram](docs/wiring_diagram.png) - Complete electrical connections
- [Assembly Guide](docs/assembly_guide.md) - Step-by-step 3D print assembly
- [Calibration Guide](docs/calibration.md) - Servo calibration procedures
- [Animation Programming](docs/animations.md) - Create custom animations

## 🤝 Contributing

Contributions are welcome! Please feel free to submit pull requests or open issues for:
- Bug fixes
- New animation patterns
- Code improvements
- Documentation updates
- 3D model refinements

## 📝 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🙏 Acknowledgments

- Inspired by [FNAF Movie Cupcake V2 by Instructables](https://www.instructables.com/FNAF-Movie-Cupcake-V2-Pre-release/)
- Scott Cawthon for creating Five Nights at Freddy's
- The maker community for 3D printing resources

## 📸 Gallery

_Photos coming soon as project progresses_

## 🔗 Useful Links

- [Original Instructables Project](https://www.instructables.com/FNAF-Movie-Cupcake-V2-Pre-release/)
- [Arduino Documentation](https://docs.arduino.cc/)
- [ESP32 Documentation](https://docs.espressif.com/projects/arduino-esp32/)
- [Adafruit NeoPixel Guide](https://learn.adafruit.com/adafruit-neopixel-uberguide)

## 💬 Contact

Allan Stampe Kristiansen - [@svinedyret](https://twitter.com/svinedyret)

Project Link: [https://github.com/allan-stampe/fnaf-cupcake-animatronic](https://github.com/allan-stampe/fnaf-cupcake-animatronic)

---

**Status**: 🚧 Work in Progress - Last updated: January 2026
