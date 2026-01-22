@echo off
REM Setup script for FNAF Cupcake Animatronic project structure
REM Run this in your project root directory

echo Creating project structure...

REM Create main directories
mkdir arduino 2>nul
mkdir arduino\servo_controller 2>nul
mkdir arduino\libraries 2>nul

mkdir esp32 2>nul
mkdir esp32\eye_controller 2>nul
mkdir esp32\libraries 2>nul

mkdir 3d_models 2>nul
mkdir 3d_models\STL 2>nul
mkdir 3d_models\design_files 2>nul

mkdir docs 2>nul

mkdir tests 2>nul
mkdir tests\servo_test 2>nul
mkdir tests\neopixel_test 2>nul

echo.
echo Project structure created successfully!
echo.
echo Next steps:
echo 1. Copy your Arduino sketches to arduino/servo_controller/
echo 2. Copy your ESP32 sketches to esp32/eye_controller/
echo 3. Add STL files to 3d_models/STL/
echo 4. Run: git add .
echo 5. Run: git commit -m "Initial project structure"
echo 6. Run: git push -u origin main
echo.
pause
