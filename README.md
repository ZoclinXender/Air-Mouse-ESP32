# Air-Mouse-ESP32
ESP32 BLE Air Mouse using MPU6050 &amp; HW504

# **ABSTRACT – AIR MOUSE USING ESP32, MPU6050 & HW504 JOYSTICK**

## **1. Introduction**

Human–computer interaction has evolved from traditional wired devices to more intuitive wireless control systems. Conventional mouse devices are limited by surface requirements, mechanical wear, and restricted mobility. This project presents the design and implementation of an **Air Mouse**, a wireless pointing device that interprets hand movement in 3D space to control a computer cursor. By integrating an **ESP32 (Bluetooth HID)** with an **MPU6050 IMU** and **HW504 analog joystick module**, the system achieves seamless wireless cursor control, scrolling, and button clicks without requiring any external dongle.

The proposed system uses **MPU6050 accelerometer and gyroscope data** to compute orientation angles, which are mapped to cursor movement. The **HW504 joystick** enables smooth page navigation (vertical and horizontal scrolling). Separate pushbuttons provide left and right mouse click functionality, while the joystick switch acts as a middle-click input. The ESP32’s built-in Bluetooth Low Energy (BLE) HID feature makes the device highly portable and platform-independent.

This project provides a compact, cost‑effective, and innovative alternative to commercial air‑mouse devices. It demonstrates practical application of embedded systems, sensor fusion, BLE communication, and human–machine interface design.

---

## **2. Objectives**

* To design a wireless air‑mouse using ESP32 without any USB dongle.
* To use MPU6050 sensor data for real‑time cursor movement.
* To implement vertical and horizontal scrolling using the HW504 joystick.
* To implement mouse click functions using pushbuttons.
* To deploy the ESP32 as a BLE HID Mouse compatible with PCs.
* To create a compact, low‑power, user‑friendly pointing device.

---

## **3. Block Diagram**

```
      +----------------------------+
      |          HAND MOTION       |
      +-------------+--------------+
                    |
                    v
            +---------------+
            |   MPU6050     |
            | (Accel+Gyro)  |
            +-------+-------+
                    |
                    v
        +-----------------------+
        |   ESP32 (BLE HID)     |
        |  - Cursor Mapping     |
        |  - BLE Mouse Output   |
        +-----+------+------+---+
              |      |      |
              |      |      |
              v      v      v
    +---------+   +--------+   +-------------+
    | HW504   |   |Buttons |   | Joystick SW |
    |Joystick |   |(L/R click)| |(Middle click)|
    +----+----+   +----+---+   +------+------+
         |             |               |
         v             v               v
   Page Scroll     Mouse Clicks   Middle Click

                    |
                    v
          +-------------------+
          |   Laptop / PC     |
          |   (BLE Receiver)  |
          +-------------------+
```

---

## **4. Hardware Components**

* **ESP32 Development Board** – BLE HID mouse controller
* **MPU6050 (Accelerometer + Gyroscope)** – Cursor orientation sensing
* **HW504 Joystick** – Page/scroll navigation
* **Pushbuttons (GPIO26 & GPIO27)** – Right and left click
* **Joystick SW (GPIO32)** – Middle click
* **Power Supply (USB)**
* Connecting wires, enclosure (optional)

---

## **5. Working Principle**

The ESP32 reads motion data from the MPU6050 through the I2C interface. The gyroscope values correspond to angular rotation, which the ESP32 converts into cursor movement. Small tilts result in fine cursor adjustments, while larger tilts produce faster movement.

The HW504 joystick provides two analog readings (VRx and VRy). These values are mapped to scroll speeds. VRx controls **horizontal scroll**, and VRy controls **vertical scroll**. A dead‑zone prevents unintended drift.

Pushbuttons connected to GPIO pins generate **left** and **right mouse clicks**, while pressing the joystick toggles a **middle click**. The ESP32 broadcasts all actions to a paired computer using the BLE HID Mouse profile, enabling completely wireless operation.

---

## **6. Software Flowchart**

```
            +---------------------+
            |      START          |
            +----------+----------+
                       |
                       v
            +---------------------+
            | Initialize BLE HID  |
            | Initialize MPU6050  |
            | Calibrate Sensors   |
            +----------+----------+
                       |
                       v
            +---------------------+
            | Read MPU Angles     |
            | Map to Cursor Move  |
            +----------+----------+
                       |
                       v
            +---------------------+
            | Read Joystick VRx   |
            | Read Joystick VRy   |
            | Map to Scrolling    |
            +----------+----------+
                       |
                       v
            +---------------------+
            | Read Buttons        |
            | L/R/M Click Output  |
            +----------+----------+
                       |
                       v
            +---------------------+
            | Send HID Commands   |
            |   (Cursor/Scroll)   |
            +----------+----------+
                       |
                       v
            +---------------------+
            |       LOOP          |
            +---------------------+
```

---

## **7. Results**

* Stable cursor movement using hand orientation.
* Smooth vertical and horizontal scrolling with joystick.
* Reliable BLE latency (no dongle required).
* Accurate left, right, and middle click functions.
* Fully wireless system with minimal delay.
* Faculty evaluation: *"Very Good, Nice Innovation"* and awarded **full mark (10/10)**.

---

## **8. Applications**

* Wireless PC control
* Smart TV pointer device
* Presentation remote
* Assistive device for limited‑mobility users
* Gesture‑based control interfaces

---

## **9. Conclusion**

The Air Mouse using ESP32, MPU6050, and HW504 joystick is a compact, innovative solution offering intuitive, wireless computer control. By leveraging BLE HID capabilities, real‑time sensor data processing, and precise motion mapping, the system demonstrates strong practical value in human–computer interaction. The modular and low‑cost nature of the design makes it suitable for academic projects, prototypes, and commercial product extensions.

---

## **10. Future Enhancements**

* Add gesture‑based commands (flick = click, shake = exit)
* Add battery + charging module
* Improve filtering with Kalman/Mahony filters
* Add vibration haptic feedback
* Create a 3D‑printed ergonomic enclosure

# README.md

## **Air Mouse Using ESP32, MPU6050 & HW504 Joystick**

A fully wireless **Air Mouse** built using **ESP32 (BLE HID)**, **MPU6050** IMU, and **HW504 joystick module**, capable of controlling a computer cursor using hand motion—no USB dongle required.

This project demonstrates practical embedded systems design, sensor fusion, Bluetooth HID communication, and human–computer interaction.

---

## 🚀 **Features**

* **Cursor movement** using **MPU6050 accelerometer + gyroscope**
* **Vertical scroll** using HW504 joystick (VRy)
* **Horizontal scroll** using HW504 joystick (VRx)
* **Left click** using pushbutton (GPIO27)
* **Right click** using pushbutton (GPIO26)
* **Middle click** using HW504 joystick switch (GPIO32)
* **BLE HID Mouse** using ESP32’s built-in Bluetooth (works on Windows/macOS/Linux)
* **Fully wireless operation**
* **Low cost, portable, simple design**

---

## 🧩 **Block Diagram**

```
      +----------------------------+
      |        HAND MOTION         |
      +-------------+--------------+
                    |
                    v
            +---------------+
            |   MPU6050     |
            | (Accel+Gyro)  |
            +-------+-------+
                    |
                    v
        +-----------------------+
        |   ESP32 (BLE HID)     |
        | - Cursor Mapping      |
        | - Scroll Mapping      |
        | - Click Handling      |
        +----+------+-----+-----+
             |      |     |
             |      |     |
             v      v     v
         HW504     Buttons   Joystick SW
      (VRx/VRy)   L/R Click   Middle Click
             |      |     |
             v      v     v
         Scrolling  Clicks  Middle Click
                    |
                    v
         +---------------------+
         |   Laptop / PC       |
         | (Bluetooth Mouse)   |
         +---------------------+
```

---

## 🛠️ **Hardware Requirements**

| Component       | Purpose                  |
| --------------- | ------------------------ |
| ESP32 Dev Board | BLE HID Mouse Controller |
| MPU6050         | Cursor movement (IMU)    |
| HW504 Joystick  | Page navigation (scroll) |
| Pushbutton x2   | Left & Right clicks      |
| Joystick SW     | Middle click             |
| Jumper wires    | Connections              |
| USB Cable       | Power + programming      |

---

## 📌 **Pin Mapping**

### **MPU6050**

| Function | ESP32 Pin |
| -------- | --------- |
| SDA      | 21        |
| SCL      | 22        |

### **HW504 Joystick**

| Function | ESP32 Pin |
| -------- | --------- |
| VRx      | 34        |
| VRy      | 35        |
| SW       | 32        |

### **Buttons**

| Action      | ESP32 Pin |
| ----------- | --------- |
| Left Click  | 27        |
| Right Click | 26        |

---

## 🧪 **How It Works**

* The **MPU6050** measures hand tilt along X/Y axes and maps this to **cursor movement**.
* The **HW504 joystick** gives two analog values:

  * VRx → Horizontal scroll
  * VRy → Vertical scroll
* A **deadzone** removes noise and prevents accidental drift.
* Buttons trigger standard BLE mouse actions:

  * Left Click → BTN27
  * Right Click → BTN26
  * Joystick press → Middle click
* ESP32 sends all outputs over **Bluetooth HID**, so no dongle is needed.

---

## 📂 **Project Structure**

```
Air-Mouse-ESP32/
│
├── Code/
│   └── airmouse.ino
│
├── Docs/
│   └── Abstract.pdf
│
├── Images/
│   └── block_diagram.png
│
└── README.md
```

---

## 💻 **How to Upload the Code**

1. Install **ESP32 board package** in Arduino IDE
2. Install required libraries:

   * **ESP32-BLE-Mouse**
   * **MPU6050_light** (rfetick version)
3. Connect ESP32 via USB
4. Select:

   * Board: **ESP32 Dev Module**
   * Port: COMx
5. Upload the sketch
6. Pair ESP32 from your PC’s Bluetooth menu
7. Move your ESP32 → Cursor moves
8. Use joystick for scroll
9. Use buttons for clicks

---

## 🎯 **Applications**

* Wireless PC control
* Presentation device
* Smart TV mouse
* Assistive tech for users with mobility issues
* Gesture-based interfaces

---

## 🏁 **Results**

* Smooth Air-Mouse movement
* Stable BLE performance
* Accurate scroll and click
* Fully functional wireless system
* Evaluated as *“Very Good, Nice Innovation”* — awarded **10/10 marks**

---

## 🚀 **Future Improvements**

* Gesture recognition (flick = click, shake = exit)
* Auto-calibration on startup
* Sensitivity toggle button
* 3D-printed enclosure
* Adaptive filtering (Kalman/Madgwick)
* Battery-powered portable version

---

## 📜 **License**

MIT License – Free to use, modify, and share.

