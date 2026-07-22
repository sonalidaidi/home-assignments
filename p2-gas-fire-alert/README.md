# Gas & Fire Safety Alert System

## Project Description

This project detects gas leaks and fire using an MQ-2 gas sensor and a flame sensor. It provides three safety levels using LEDs and a buzzer to alert the user.

---

## Components Used

- Arduino Uno
- MQ-2 Gas Sensor
- Flame Sensor
- Active Buzzer
- Red LED
- Yellow LED
- Green LED
- 220Ω Resistors
- Breadboard
- Jumper Wires

---

## Connections

| Component | Arduino Pin |
|-----------|-------------|
| MQ-2 AO | A0 |
| Flame Sensor DO | D7 |
| Green LED | D10 |
| Yellow LED | D11 |
| Red LED | D12 |
| Buzzer | D9 |

---

## Working

The Arduino continuously monitors the MQ-2 gas sensor and flame sensor.

- Safe condition → Green LED ON
- Gas detected → Yellow LED blinks with a slow buzzer
- Flame detected → Red LED ON with continuous buzzer

Both sensors operate independently to improve safety.

---

## Alert Levels

### Safe
- Green LED ON
- Buzzer OFF

### Warning
- Yellow LED ON
- Slow Beep

### Danger
- Red LED ON
- Continuous Buzzer

---

## MQ-2 Warm-up Requirement

The MQ-2 sensor contains a heating element that must warm up before producing stable gas readings.

Allow the sensor to warm up for **1–2 minutes** after power is applied before using its readings.

---

## Why is the Flame Sensor Active-Low?

The flame sensor outputs **LOW (0)** when a flame is detected and **HIGH (1)** when no flame is present.

This is called **active-low** because the output becomes LOW during an active detection event.

---

## Serial Monitor Output

Displays:
- Gas Sensor Value
- Flame Status
- Current Alert Level

Example:

Gas: 145

Flame: NO

Status: SAFE

-----------------------

Gas: 620

Flame: NO

Status: WARNING

-----------------------

Gas: 820

Flame: YES

Status: DANGER

---

## Conclusion

This project demonstrates a simple gas and fire safety alert system using MQ-2 and flame sensors with LED and buzzer indications for different alert levels.
