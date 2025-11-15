/*
   ESP32 AIR MOUSE
   - MPU: cursor movement
   - HW504 joystick: page movement (VRx = horizontal scroll, VRy = vertical scroll)
   - Left click:  GPIO27
   - Right click: GPIO26
   - Joystick SW (press): middle click on GPIO32
*/

#include <BleMouse.h>
#include <Wire.h>
#include "MPU6050_light.h"

// ================= PIN CONFIG =================
#define MPU_SDA   21
#define MPU_SCL   22

#define VRX_PIN   34
#define VRY_PIN   35
#define JOY_SW    32

#define BTN_LEFT  27
#define BTN_RIGHT 26
// ===============================================

BleMouse bleMouse("ESP-AirMouse");
MPU6050 mpu(Wire);

// ----------- Joystick scroll tuning ------------
int ADC_CENTER_X = 2000;   // You can adjust after testing
int ADC_CENTER_Y = 2000;

int DEADZONE = 150;        // Ignore small noise
float SCROLL_MULT = 0.003; // scroll strength
unsigned long SCROLL_INTERVAL = 60; 
unsigned long lastScroll = 0;
// ------------------------------------------------

// Buttons debounce
int readButton(int pin) { return digitalRead(pin) == LOW; }

void setup() {
  Serial.begin(115200);
  delay(500);

  // BLE
  bleMouse.begin();

  // I2C for MPU
  Wire.begin(MPU_SDA, MPU_SCL);

  Serial.println("MPU Starting...");
  byte status = mpu.begin();
  Serial.print("MPU Status = ");
  Serial.println(status);

  Serial.println("Calibrating... keep MPU still");
  delay(20000);
  mpu.calcGyroOffsets();
  Serial.println("Calibration done.");

  // Joystick + buttons
  pinMode(JOY_SW, INPUT_PULLUP);
  pinMode(BTN_LEFT, INPUT_PULLUP);
  pinMode(BTN_RIGHT, INPUT_PULLUP);

  // ADC config
  analogReadResolution(12);
  analogSetAttenuation(ADC_11db);
}

void loop() {

  // Wait for BLE before doing anything
  if (!bleMouse.isConnected()) {
    delay(100);
    return;
  }

  // ---------- MPU CURSOR MOVEMENT ----------
  mpu.update();

  float ax = mpu.getAngleX();
  float ay = mpu.getAngleY();

  // Sensitivity
  float sx = ay * 0.2f;
  float sy = -ax * 0.20f;

  int moveX = constrain((int)sx, -12, 12);
  int moveY = constrain((int)sy, -12, 12);

  if (moveX != 0 || moveY != 0) {
    bleMouse.move(moveX, moveY);
  }

  // ---------- HW504 PAGE MOVEMENT ----------
 // ---------- HW504 PAGE MOVEMENT ----------
int rawX = analogRead(VRX_PIN);
int rawY = analogRead(VRY_PIN);

int diffX = rawX - ADC_CENTER_X;
int diffY = rawY - ADC_CENTER_Y;

if (abs(diffX) < DEADZONE) diffX = 0;
if (abs(diffY) < DEADZONE) diffY = 0;

if (millis() - lastScroll > SCROLL_INTERVAL) {
    lastScroll = millis();

    int scrollY = diffY * SCROLL_MULT;    // Up/down scroll
    int scrollX = diffX * SCROLL_MULT;    // Left/right scroll

    if (scrollY != 0) bleMouse.move(0, 0, -scrollY);        // vertical wheel
    if (scrollX != 0) bleMouse.move(0, 0, 0, scrollX);      // horizontal wheel
}

  

  // ---------- BUTTONS ----------
  if (readButton(BTN_LEFT)) {
    bleMouse.click(MOUSE_LEFT);
    delay(150);
  }

  if (readButton(BTN_RIGHT)) {
    bleMouse.click(MOUSE_RIGHT);
    delay(150);
  }

  if (readButton(JOY_SW)) {
    bleMouse.click(MOUSE_MIDDLE);
    delay(150);
  }
}
