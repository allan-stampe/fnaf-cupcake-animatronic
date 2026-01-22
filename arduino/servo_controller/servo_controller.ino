/*
 * FNAF Cupcake Animatronic - Servo Controller
 * 
 * Controls 7 servos via PCA9685 PWM driver:
 * - 6x MG90S servos for body movements
 * - 1x DS3225 servo for jaw
 * 
 * Hardware:
 * - Arduino Uno
 * - PCA9685 Servo Shield
 * - 7 Servos
 * 
 * Author: Allan Stampe Kristiansen
 * Date: January 2026
 */

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include "config.h"

// Create servo driver object
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Servo definitions
#define SERVO_JAW      0  // DS3225 - Main jaw movement
#define SERVO_HEAD_PAN 1  // MG90S - Left/right head turn
#define SERVO_HEAD_TILT 2 // MG90S - Up/down head tilt
#define SERVO_EAR_LEFT 3  // MG90S - Left ear movement
#define SERVO_EAR_RIGHT 4 // MG90S - Right ear movement
#define SERVO_EXTRA_1  5  // MG90S - Extra movement 1
#define SERVO_EXTRA_2  6  // MG90S - Extra movement 2

// Servo pulse length calculations
// PCA9685 uses 12-bit resolution (4096 steps)
#define SERVOMIN  150 // Minimum pulse length (out of 4096)
#define SERVOMAX  600 // Maximum pulse length (out of 4096)

// Current servo positions (0-180 degrees)
int servoPositions[7] = {90, 90, 90, 90, 90, 90, 90};

// Animation speed (milliseconds between updates)
#define ANIMATION_SPEED 15

void setup() {
  Serial.begin(115200);
  Serial.println("FNAF Cupcake Animatronic - Servo Controller");
  Serial.println("==========================================");
  
  // Initialize PCA9685
  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz
  
  delay(10);
  
  // Move all servos to neutral position
  Serial.println("Moving to neutral position...");
  for (int i = 0; i < 7; i++) {
    setServoAngle(i, 90);
  }
  
  delay(1000);
  
  Serial.println("Ready! Send commands:");
  Serial.println("- 'test' - Run test sequence");
  Serial.println("- 'neutral' - Move to neutral position");
  Serial.println("- 'jaw open' - Open jaw");
  Serial.println("- 'jaw close' - Close jaw");
  Serial.println("- 's<num> <angle>' - Set servo <num> to <angle> (e.g., 's0 45')");
}

void loop() {
  // Check for serial commands
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim();
    handleCommand(command);
  }
  
  // Add your animation loop here
  // Example: call different animation functions based on state
}

// Handle serial commands
void handleCommand(String cmd) {
  if (cmd == "test") {
    Serial.println("Running test sequence...");
    testSequence();
  } 
  else if (cmd == "neutral") {
    Serial.println("Moving to neutral position...");
    moveToNeutral();
  }
  else if (cmd == "jaw open") {
    Serial.println("Opening jaw...");
    setServoAngle(SERVO_JAW, 120);
  }
  else if (cmd == "jaw close") {
    Serial.println("Closing jaw...");
    setServoAngle(SERVO_JAW, 60);
  }
  else if (cmd.startsWith("s")) {
    // Parse servo control command: s<num> <angle>
    int spacePos = cmd.indexOf(' ');
    if (spacePos > 0) {
      int servoNum = cmd.substring(1, spacePos).toInt();
      int angle = cmd.substring(spacePos + 1).toInt();
      
      if (servoNum >= 0 && servoNum < 7 && angle >= 0 && angle <= 180) {
        Serial.print("Setting servo ");
        Serial.print(servoNum);
        Serial.print(" to ");
        Serial.print(angle);
        Serial.println(" degrees");
        setServoAngle(servoNum, angle);
      } else {
        Serial.println("Invalid servo number or angle!");
      }
    }
  }
  else {
    Serial.println("Unknown command!");
  }
}

// Set servo angle (0-180 degrees)
void setServoAngle(uint8_t servoNum, uint8_t angle) {
  // Constrain angle to valid range
  angle = constrain(angle, 0, 180);
  
  // Convert angle to pulse length
  uint16_t pulse = map(angle, 0, 180, SERVOMIN, SERVOMAX);
  
  // Set PWM
  pwm.setPWM(servoNum, 0, pulse);
  
  // Update position tracking
  servoPositions[servoNum] = angle;
}

// Smooth servo movement
void moveServoSmooth(uint8_t servoNum, uint8_t targetAngle, uint8_t speed) {
  int currentAngle = servoPositions[servoNum];
  
  if (currentAngle < targetAngle) {
    for (int angle = currentAngle; angle <= targetAngle; angle++) {
      setServoAngle(servoNum, angle);
      delay(speed);
    }
  } else {
    for (int angle = currentAngle; angle >= targetAngle; angle--) {
      setServoAngle(servoNum, angle);
      delay(speed);
    }
  }
}

// Move all servos to neutral position
void moveToNeutral() {
  for (int i = 0; i < 7; i++) {
    moveServoSmooth(i, 90, 10);
  }
}

// Test sequence - move each servo
void testSequence() {
  Serial.println("Testing each servo...");
  
  for (int i = 0; i < 7; i++) {
    Serial.print("Testing servo ");
    Serial.println(i);
    
    // Move to min
    moveServoSmooth(i, 45, 5);
    delay(500);
    
    // Move to max
    moveServoSmooth(i, 135, 5);
    delay(500);
    
    // Return to neutral
    moveServoSmooth(i, 90, 5);
    delay(500);
  }
  
  Serial.println("Test complete!");
}

// Example animation: Jaw open/close
void animateJaw() {
  moveServoSmooth(SERVO_JAW, 120, 10);  // Open
  delay(500);
  moveServoSmooth(SERVO_JAW, 60, 10);   // Close
  delay(500);
}

// Example animation: Head turn
void animateHeadTurn() {
  moveServoSmooth(SERVO_HEAD_PAN, 45, 10);   // Turn left
  delay(1000);
  moveServoSmooth(SERVO_HEAD_PAN, 135, 10);  // Turn right
  delay(1000);
  moveServoSmooth(SERVO_HEAD_PAN, 90, 10);   // Center
}
