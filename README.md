# FlameGuard – Fire Detection System

## Project
FlameGuard is an Arduino Uno-based fire detection project. A flame sensor detects a possible flame, a 16×2 I2C LCD displays the sensor reading and status, and an HC-05 Bluetooth module sends the status to a paired mobile device.

## Connections

### Flame Sensor → Arduino Uno
| Flame sensor pin | Arduino Uno |
|---|---|
| VCC | 5V |
| GND | GND |
| DO | D5 |

### 16×2 I2C LCD → Arduino Uno
| LCD pin | Arduino Uno |
|---|---|
| VCC | 5V |
| GND | GND |
| SDA | A4 |
| SCL | A5 |

### HC-05 Bluetooth → Arduino Uno
| HC-05 pin | Arduino Uno |
|---|---|
| VCC | 5V, if supported by the breakout board |
| GND | GND |
| TXD | D10 (Arduino software-serial RX) |
| RXD | D11 (through a voltage divider) |

**HC-05 RXD voltage divider:** connect Arduino D11 (5V signal) through a 1 kΩ resistor to the divider midpoint, connect a 2 kΩ resistor from the midpoint to GND, and connect the midpoint to HC-05 RXD. This reduces the signal voltage to approximately 3.3V.

## Circuit Diagram

![FlameGuard circuit diagram](Flame_Detector/Arduino_Fire_Detection_Wiring.png)
