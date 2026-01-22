/*
 * FNAF Cupcake Animatronic - Configuration
 * 
 * Adjust these values to calibrate your specific servos
 */

#ifndef CONFIG_H
#define CONFIG_H

// PCA9685 I2C Address (default is 0x40)
#define PCA9685_ADDRESS 0x40

// Servo calibration values (adjust these for your servos)
// Format: {min_angle, neutral_angle, max_angle}
struct ServoCalibration {
  uint8_t min;
  uint8_t neutral;
  uint8_t max;
};

// Calibration for each servo
ServoCalibration servoCalibration[7] = {
  {60, 90, 120},   // SERVO_JAW (DS3225)
  {45, 90, 135},   // SERVO_HEAD_PAN
  {45, 90, 135},   // SERVO_HEAD_TILT
  {60, 90, 120},   // SERVO_EAR_LEFT
  {60, 90, 120},   // SERVO_EAR_RIGHT
  {45, 90, 135},   // SERVO_EXTRA_1
  {45, 90, 135}    // SERVO_EXTRA_2
};

// Animation timings (milliseconds)
#define IDLE_ANIMATION_INTERVAL 5000   // Time between idle movements
#define BLINK_INTERVAL 3000            // Time between eye blinks
#define JAW_OPEN_SPEED 15              // Speed of jaw opening
#define JAW_CLOSE_SPEED 10             // Speed of jaw closing

// Movement limits (safety)
#define MAX_SERVO_SPEED 5              // Minimum delay between servo steps (ms)
#define SERVO_TIMEOUT 10000            // Servo movement timeout (ms)

// Debug mode
#define DEBUG_MODE true                // Set to false to disable serial debug

#endif
