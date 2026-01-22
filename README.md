# FNAF Cupcake Animatronic

Arduino and ESP32 powered FNAF Movie inspired animatronic cupcake with servo-controlled movements and glowing NeoPixel eyes.

![Project Status](https://img.shields.io/badge/status-in%20development-yellow)
![License](https://img.shields.io/badge/license-MIT-blue)

> ð¯ **Based on the original design**: This project is inspired by and follows the [FNAF Movie Cupcake V2 by Chaos-Animatronics on Instructables](https://www.instructables.com/FNAF-Movie-Cupcake-V2-Pre-release/). Check out the original guide for additional building tips and reference images!
>
> ## 👥 Project Team
>
> **Builders:**
> - Allan Stampe Kristiansen - [@svinedyret](https://twitter.com/svinedyret)
> - Storm Dirch Bau Holmgaard
> - This FNAF Cupcake Animatronic is being built as a collaborative project combining 3D printing, electronics, and programming skills.
> - 

## ð Overview

This project brings the iconic cupcake from Five Nights at Freddy's to life as a desktop animatronic featuring:

- 7 servo motors for realistic movements
- Glowing RGB NeoPixel eyes (50mm rings)
- Arduino Uno for servo control
- ESP32 for eye animation control
- 3D printed structure and parts
- Inspired by the FNAF Movie design
- Bottango-compatible for advanced animation programming

## ð ï¸ Hardware Requirements

### Electronics

- **1x Arduino Uno** - Main controller for servos
- **1x PCA9685 Servo Shield** - 16-channel PWM servo driver
- **1x ESP32** - Controller for NeoPixel eyes
- **6x MG90S Servos** - Metal gear micro servos for precise movements
- **1x DS3225 Servo** - High-torque servo for jaw movement
- **2x NeoPixel RGB Rings (50mm)** - For glowing eyes
- **1x 5mm LED (Orange)** - Status indicator
- **Power supply** - 5V adequate for all servos
- **USB B cable** - For programming and Bottango connection

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
- **Print Settings**: Supports required
- **Eye pieces**: Print in white PLA with 100% infill for best glow effect

### Painting & Finishing Supplies

- Sandpaper (various grits)
- Putty (for filling gaps between parts)
- Primer spray paint
- Acrylic paints or spray paint (main colors)
- Airbrush (recommended for detailed work)
- Masking tape
- Clear coat (optional, for protection)a

## ð Project Structure

```
fnaf-cupcake-animatronic/
âââ arduino/
â   âââ servo_controller/
â   â   âââ servo_controller.ino
â   â   âââ config.h
â   âââ libraries/
âââ esp32/
â   âââ eye_controller/
â   â   âââ eye_controller.ino
â   â   âââ animations.h
â   âââ libraries/
âââ 3d_models/
â   âââ STL/
â   âââ design_files/
âââ docs/
â   âââ wiring_diagram.png
â   âââ assembly_guide.md
â   âââ calibration.md
â   âââ painting_guide.md
â   âââ bottango_setup.md
âââ tests/
â   âââ servo_test/
â   âââ neopixel_test/
âââ .gitignore
âââ LICENSE
âââ README.md
```

## ð§ Software Setup

### Arduino IDE Setup

1. Install [Arduino IDE](https://www.arduino.cc/en/software) (version 2.0+)
2. Install required libraries:
   - Adafruit PWM Servo Driver Library
   - Wire library (built-in)

### ESP32 Setup

1. Add ESP32 board support to Arduino IDE
   - File â Preferences â Additional Board Manager URLs
   - Add: `https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json`
2. Install ESP32 board package
3. Install required libraries:
   - Adafruit NeoPixel
   - FastLED (optional, for advanced effects)

### Bottango Setup (Optional - Advanced Animation Control)

[Bottango](https://www.bottango.com/) is a powerful animation software that allows you to create complex, synchronized movements for your animatronic.

1. Download and install Bottango software
2. Connect Arduino via USB
3. Import the provided Bottango file from the original Instructables project
4. Follow Bottango tutorials for creating custom animations

**Alternative**: For RC control, you can use a **Frsky FS-i6X** controller with a 10-channel receiver for direct manual control.

### Visual Studio Code (Optional)

If using VS Code with PlatformIO:

```bash
# Install PlatformIO extension
# Open project folder
# PlatformIO will auto-detect configuration
```

## â¡ Quick Start

### 1. Clone Repository

```bash
git clone https://github.com/allan-stampe/fnaf-cupcake-animatronic.git
cd fnaf-cupcake-animatronic
```

### 2. 3D Print All Parts

- Download STL files from `/3d_models/STL/`
- Print with supports enabled
- Print eye pieces in white PLA with 100% infill
- Estimated print time: 30-50 hours total (depending on printer settings)

### 3. Assemble Mechanical Structure

Follow the detailed assembly guide in `/docs/assembly_guide.md` or refer to the [original Instructables assembly video](https://www.instructables.com/FNAF-Movie-Cupcake-V2-Pre-release/).

Key assembly notes:
- Use the "headhold" piece to attach the head to the eyemech
- Glue the headhold to the top of the head piece
- Slide it over the eyemech middle pole

### 4. Paint and Finish

Follow the painting guide in `/docs/painting_guide.md`:

1. **Sand** all printed parts smooth
2. **Fill gaps** with putty between large parts
3. **Prime** (multiple coats: Prime â Sand â Prime)
4. **Paint inside** parts black
5. **Paint outside** parts with main colors
6. **Detail work** with airbrush for small spots
7. **Mask** carefully to keep lines clean

### 5. Wire Electronics

See `/docs/wiring_diagram.png` for complete wiring instructions.

- Servo shield gets power from external 5V supply
- Arduino connects to same power source
- USB B cable needed for programming/Bottango

### 6. Upload Arduino Code

```bash
# Open arduino/servo_controller/servo_controller.ino in Arduino IDE
# Select Board: Arduino Uno
# Select correct COM port
# Click Upload
```

### 7. Upload ESP32 Code

```bash
# Open esp32/eye_controller/eye_controller.ino in Arduino IDE
# Select Board: ESP32 Dev Module
# Select correct COM port
# Click Upload
```

### 8. Test Servos

Run the servo test sketch to verify all connections:

```bash
# Upload tests/servo_test/servo_test.ino
# Open Serial Monitor (115200 baud)
# Follow calibration instructions
```

## ð¨ Features

- **Jaw Movement**: Realistic opening/closing mouth animations
- **Head Tilt**: Pan and tilt movements for lifelike behavior
- **Eye Glow**: RGB NeoPixel rings with multiple animation patterns
- **Modular Design**: Easy to modify and customize
- **Serial Control**: Control via Serial commands for testing
- **Animation Sequences**: Pre-programmed movement patterns
- **Bottango Compatible**: Use professional animation software for complex sequences
- **RC Control Ready**: Can be adapted for remote control operation

## ð Documentation

Detailed guides available in `/docs`:

- [Wiring Diagram](docs/wiring_diagram.png) - Complete electrical connections
- [Assembly Guide](docs/assembly_guide.md) - Step-by-step 3D print assembly
- [Calibration Guide](docs/calibration.md) - Servo calibration procedures
- [Painting Guide](docs/painting_guide.md) - Professional finishing techniques
- [Bottango Setup](docs/bottango_setup.md) - Advanced animation programming
- [Animation Programming](docs/animations.md) - Create custom animations

## ð¥ Build Process

### Phase 1: 3D Printing â
Print all STL files with supports. Eye pieces in white PLA (100% infill).

### Phase 2: Assembly ð
Follow assembly guide. Use putty to fill gaps between major parts.

### Phase 3: Painting ð¨
Sand, prime, paint. Multiple primer coats for smooth finish.

### Phase 4: Electronics â¡
Wire servos, Arduino, ESP32, and NeoPixels according to diagram.

### Phase 5: Programming ð»
Upload Arduino and ESP32 code. Test all servos individually.

### Phase 6: Animation ð­
Program movements using Bottango or create custom sequences.

## ð¤ Contributing

Contributions are welcome! Please feel free to submit pull requests or open issues for:

- Bug fixes
- New animation patterns
- Code improvements
- Documentation updates
- 3D model refinements

## ð License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## ð Acknowledgments

- Original design by **Chaos-Animatronics**: [FNAF Movie Cupcake V2 on Instructables](https://www.instructables.com/FNAF-Movie-Cupcake-V2-Pre-release/)
- **Scott Cawthon** for creating Five Nights at Freddy's
- The **maker community** for 3D printing resources
- **Bottango** team for their amazing animation software

## ð¸ Gallery

_Photos coming soon as project progresses_

### Build Progress

Check back here for updates as the build progresses!

## ð Useful Links

- [Original Instructables Project](https://www.instructables.com/FNAF-Movie-Cupcake-V2-Pre-release/)
- [Thingiverse STL Files](https://www.thingiverse.com/) (link to be added)
- [Bottango Animation Software](https://www.bottango.com/)
- [Arduino Documentation](https://docs.arduino.cc/)
- [ESP32 Documentation](https://docs.espressif.com/projects/arduino-esp32/)
- [Adafruit NeoPixel Guide](https://learn.adafruit.com/adafruit-neopixel-uberguide)

## ð¬ Contact

Allan Stampe Kristiansen - [@svinedyret](https://twitter.com/svinedyret)

Project Link: [https://github.com/allan-stampe/fnaf-cupcake-animatronic](https://github.com/allan-stampe/fnaf-cupcake-animatronic)

---

**Status**: ð§ Work in Progress - Currently in 3D printing phase

**Last updated**: January 2026

---

â­ If you find this project helpful, please consider giving it a star on GitHub!
