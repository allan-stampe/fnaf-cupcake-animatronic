/*
 * FNAF Cupcake Animatronic - Eye Controller (ESP32)
 * 
 * Controls 2x NeoPixel rings (50mm) for animated glowing eyes
 * 
 * Hardware:
 * - ESP32 Dev Module
 * - 2x NeoPixel RGB Rings (50mm, typically 16 LEDs each)
 * - 5V power supply
 * 
 * Author: Allan Stampe Kristiansen
 * Date: January 2026
 */

#include <Adafruit_NeoPixel.h>

// Pin definitions
#define LEFT_EYE_PIN  25    // GPIO pin for left eye
#define RIGHT_EYE_PIN 26    // GPIO pin for right eye
#define STATUS_LED_PIN 2    // Built-in LED

// NeoPixel configuration
#define NUM_LEDS_PER_EYE 16  // Number of LEDs per ring
#define BRIGHTNESS 100       // 0-255, adjust for desired brightness

// Create NeoPixel objects
Adafruit_NeoPixel leftEye = Adafruit_NeoPixel(
  NUM_LEDS_PER_EYE, 
  LEFT_EYE_PIN, 
  NEO_GRB + NEO_KHZ800
);

Adafruit_NeoPixel rightEye = Adafruit_NeoPixel(
  NUM_LEDS_PER_EYE, 
  RIGHT_EYE_PIN, 
  NEO_GRB + NEO_KHZ800
);

// Color definitions (R, G, B)
struct Color {
  uint8_t r;
  uint8_t g;
  uint8_t b;
};

// Predefined colors
Color COLOR_RED = {255, 0, 0};
Color COLOR_ORANGE = {255, 100, 0};
Color COLOR_YELLOW = {255, 255, 0};
Color COLOR_GREEN = {0, 255, 0};
Color COLOR_BLUE = {0, 0, 255};
Color COLOR_PURPLE = {128, 0, 255};
Color COLOR_WHITE = {255, 255, 255};
Color COLOR_OFF = {0, 0, 0};

// Current animation state
enum AnimationMode {
  IDLE,
  GLOW,
  PULSE,
  RAINBOW,
  ANGRY,
  SCANNING,
  CUSTOM
};

AnimationMode currentMode = GLOW;
Color currentColor = COLOR_ORANGE;  // Default FNAF cupcake orange glow
unsigned long lastUpdate = 0;
int animationStep = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("FNAF Cupcake Animatronic - Eye Controller");
  Serial.println("=========================================");
  
  // Initialize status LED
  pinMode(STATUS_LED_PIN, OUTPUT);
  digitalWrite(STATUS_LED_PIN, HIGH);
  
  // Initialize NeoPixel rings
  leftEye.begin();
  rightEye.begin();
  leftEye.setBrightness(BRIGHTNESS);
  rightEye.setBrightness(BRIGHTNESS);
  leftEye.show(); // Initialize all pixels to 'off'
  rightEye.show();
  
  // Startup animation
  startupAnimation();
  
  Serial.println("Ready! Send commands:");
  Serial.println("- 'idle' - Idle mode");
  Serial.println("- 'glow' - Steady glow");
  Serial.println("- 'pulse' - Pulsing effect");
  Serial.println("- 'rainbow' - Rainbow cycle");
  Serial.println("- 'angry' - Angry red pulse");
  Serial.println("- 'off' - Turn off");
  Serial.println("- 'color <r> <g> <b>' - Set custom color");
}

void loop() {
  // Check for serial commands
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim();
    handleCommand(command);
  }
  
  // Run current animation
  unsigned long currentMillis = millis();
  
  switch (currentMode) {
    case IDLE:
      // Gentle random flickers
      if (currentMillis - lastUpdate > 50) {
        idleAnimation();
        lastUpdate = currentMillis;
      }
      break;
      
    case GLOW:
      // Steady glow
      setSolidColor(currentColor);
      break;
      
    case PULSE:
      // Pulsing effect
      if (currentMillis - lastUpdate > 30) {
        pulseAnimation();
        lastUpdate = currentMillis;
      }
      break;
      
    case RAINBOW:
      // Rainbow cycle
      if (currentMillis - lastUpdate > 50) {
        rainbowAnimation();
        lastUpdate = currentMillis;
      }
      break;
      
    case ANGRY:
      // Angry red pulse
      if (currentMillis - lastUpdate > 20) {
        angryAnimation();
        lastUpdate = currentMillis;
      }
      break;
      
    case SCANNING:
      // Scanning effect
      if (currentMillis - lastUpdate > 50) {
        scanAnimation();
        lastUpdate = currentMillis;
      }
      break;
  }
}

// Handle serial commands
void handleCommand(String cmd) {
  if (cmd == "idle") {
    Serial.println("Mode: Idle");
    currentMode = IDLE;
  }
  else if (cmd == "glow") {
    Serial.println("Mode: Glow");
    currentMode = GLOW;
    currentColor = COLOR_ORANGE;
  }
  else if (cmd == "pulse") {
    Serial.println("Mode: Pulse");
    currentMode = PULSE;
  }
  else if (cmd == "rainbow") {
    Serial.println("Mode: Rainbow");
    currentMode = RAINBOW;
  }
  else if (cmd == "angry") {
    Serial.println("Mode: Angry");
    currentMode = ANGRY;
  }
  else if (cmd == "scanning") {
    Serial.println("Mode: Scanning");
    currentMode = SCANNING;
  }
  else if (cmd == "off") {
    Serial.println("Eyes off");
    setOff();
  }
  else if (cmd.startsWith("color")) {
    // Parse color command: color <r> <g> <b>
    int r, g, b;
    if (sscanf(cmd.c_str(), "color %d %d %d", &r, &g, &b) == 3) {
      currentColor = {(uint8_t)r, (uint8_t)g, (uint8_t)b};
      currentMode = GLOW;
      Serial.printf("Color set to R:%d G:%d B:%d\n", r, g, b);
    }
  }
  else {
    Serial.println("Unknown command!");
  }
}

// Set both eyes to solid color
void setSolidColor(Color color) {
  for (int i = 0; i < NUM_LEDS_PER_EYE; i++) {
    leftEye.setPixelColor(i, leftEye.Color(color.r, color.g, color.b));
    rightEye.setPixelColor(i, rightEye.Color(color.r, color.g, color.b));
  }
  leftEye.show();
  rightEye.show();
}

// Turn off all LEDs
void setOff() {
  leftEye.clear();
  rightEye.clear();
  leftEye.show();
  rightEye.show();
}

// Startup animation
void startupAnimation() {
  Serial.println("Running startup animation...");
  
  // Fade in
  for (int brightness = 0; brightness <= BRIGHTNESS; brightness += 5) {
    leftEye.setBrightness(brightness);
    rightEye.setBrightness(brightness);
    setSolidColor(COLOR_ORANGE);
    delay(30);
  }
  
  delay(500);
}

// Idle animation - gentle flicker
void idleAnimation() {
  int flicker = random(-20, 20);
  int brightness = constrain(BRIGHTNESS + flicker, 50, BRIGHTNESS);
  
  leftEye.setBrightness(brightness);
  rightEye.setBrightness(brightness);
  setSolidColor(currentColor);
}

// Pulse animation
void pulseAnimation() {
  float breath = (exp(sin(millis()/2000.0*PI)) - 0.36787944) * 108.0;
  int brightness = map(breath, 0, 108, 30, BRIGHTNESS);
  
  leftEye.setBrightness(brightness);
  rightEye.setBrightness(brightness);
  setSolidColor(currentColor);
}

// Rainbow cycle animation
void rainbowAnimation() {
  for (int i = 0; i < NUM_LEDS_PER_EYE; i++) {
    int pixelHue = (animationStep + (i * 65536L / NUM_LEDS_PER_EYE)) % 65536;
    leftEye.setPixelColor(i, leftEye.gamma32(leftEye.ColorHSV(pixelHue)));
    rightEye.setPixelColor(i, rightEye.gamma32(rightEye.ColorHSV(pixelHue)));
  }
  leftEye.show();
  rightEye.show();
  animationStep += 256;
}

// Angry red pulse animation
void angryAnimation() {
  int brightness = (sin(animationStep * 0.1) + 1) * 64 + 127;
  leftEye.setBrightness(brightness);
  rightEye.setBrightness(brightness);
  setSolidColor(COLOR_RED);
  animationStep++;
}

// Scanning animation
void scanAnimation() {
  leftEye.clear();
  rightEye.clear();
  
  int pos = animationStep % NUM_LEDS_PER_EYE;
  leftEye.setPixelColor(pos, leftEye.Color(currentColor.r, currentColor.g, currentColor.b));
  rightEye.setPixelColor(pos, rightEye.Color(currentColor.r, currentColor.g, currentColor.b));
  
  leftEye.show();
  rightEye.show();
  animationStep++;
}

// Helper: Convert HSV to RGB color
Color hsvToRgb(int h, int s, int v) {
  float hue = h / 360.0;
  float sat = s / 100.0;
  float val = v / 100.0;
  
  float r, g, b;
  
  if (sat == 0) {
    r = g = b = val;
  } else {
    int i = int(hue * 6);
    float f = (hue * 6) - i;
    float p = val * (1 - sat);
    float q = val * (1 - sat * f);
    float t = val * (1 - sat * (1 - f));
    
    switch (i % 6) {
      case 0: r = val; g = t; b = p; break;
      case 1: r = q; g = val; b = p; break;
      case 2: r = p; g = val; b = t; break;
      case 3: r = p; g = q; b = val; break;
      case 4: r = t; g = p; b = val; break;
      case 5: r = val; g = p; b = q; break;
    }
  }
  
  return {(uint8_t)(r * 255), (uint8_t)(g * 255), (uint8_t)(b * 255)};
}
