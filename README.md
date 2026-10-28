<div align="center">

<img src="https://capsule-render.vercel.app/api?type=waving&color=0:7F1D1D,55:DC2626,100:F97316&height=180&section=header&text=FlameGuard&fontSize=48&fontColor=FFFFFF&fontAlignY=38&desc=Arduino%20Fire%20Detection%20System&descAlignY=62&descSize=18" width="100%" alt="FlameGuard — Arduino Fire Detection System" />

<p>
  <img src="https://img.shields.io/badge/Platform-Arduino%20Uno-00979D?style=for-the-badge&logo=arduino&logoColor=white" alt="Arduino Uno" />
  <img src="https://img.shields.io/badge/Sensor-Flame%20Sensor-EF4444?style=for-the-badge" alt="Flame sensor" />
  <img src="https://img.shields.io/badge/Display-16×2%20I2C%20LCD-2563EB?style=for-the-badge" alt="16 by 2 I2C LCD" />
  <img src="https://img.shields.io/badge/Wireless-HC--05%20Bluetooth-0F766E?style=for-the-badge" alt="HC-05 Bluetooth" />
</p>

**A simple embedded fire-detection project that displays flame-sensor status on an LCD and sends updates over Bluetooth.**

</div>

---

## 🔥 About the Project

FlameGuard uses an **Arduino Uno** to read the digital output of a flame sensor. The current sensor reading and detection status are shown on a **16×2 I2C LCD**, while an **HC-05 Bluetooth module** sends status messages to a paired mobile device.

### ✨ How it works

1. The flame sensor provides a digital output to the Arduino.
2. The Arduino checks the sensor output to determine the detection status.
3. The LCD displays the digital reading and status.
4. The HC-05 sends a status message over Bluetooth, and the Serial Monitor provides debugging output.

> **Note:** The program assumes the flame sensor output is **LOW when a flame is detected**. Sensor modules can vary, so verify your module's output during testing.

---

## 🔌 Circuit Connections

### 🔴 Flame Sensor → Arduino Uno

| Flame sensor pin | Arduino Uno pin |
|:---|:---|
| VCC | 5V |
| GND | GND |
| DO | D5 |

### 🟢 16×2 I2C LCD → Arduino Uno

| LCD pin | Arduino Uno pin |
|:---|:---|
| VCC | 5V |
| GND | GND |
| SDA | A4 |
| SCL | A5 |

### 🔵 HC-05 Bluetooth → Arduino Uno

| HC-05 pin | Arduino Uno pin |
|:---|:---|
| VCC | 5V, if supported by the breakout board |
| GND | GND |
| TXD | D10 (Arduino software-serial RX) |
| RXD | D11 (through a voltage divider) |

### ⚡ Voltage Divider for HC-05 RXD

The Arduino Uno's D11 TX signal is 5V, while the HC-05 RXD logic input is approximately 3.3V. Use a resistor divider to reduce the voltage:

- Connect **D11 → 1 kΩ resistor → divider midpoint**.
- Connect the **midpoint → HC-05 RXD**.
- Connect the **midpoint → 2 kΩ resistor → GND**.

This gives approximately 3.3V at the midpoint. Confirm the requirements of your specific HC-05 breakout board before wiring its power pin.

---

## 🖼️ Circuit Diagram

<div align="center">

<img src="Flame_Detector/Arduino%20Fire%20Detection%20Wiring%20Diagram.png" alt="FlameGuard wiring diagram showing the flame sensor, Arduino Uno, 16×2 I2C LCD, HC-05 Bluetooth module, and RXD voltage divider" width="100%" />

</div>

---

## 🧰 Components Used

| Component | Purpose |
|:---|:---|
| Arduino Uno | Reads the sensor and coordinates outputs |
| Digital flame sensor | Detects a possible flame |
| 16×2 I2C LCD | Displays sensor reading and status |
| HC-05 Bluetooth module | Sends status messages to a paired device |
| 1 kΩ and 2 kΩ resistors | Form the voltage divider for HC-05 RXD |
| Jumper wires | Make the circuit connections |

---

<div align="center">

**FlameGuard · Embedded Systems Project**

<sub>Built with Arduino and Embedded C/C++</sub>

</div>
