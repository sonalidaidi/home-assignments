# Stepper Motor Position Controller with OLED Display

## Project Overview

This project implements a Stepper Motor Position Controller using an Arduino Uno, 28BYJ-48 Stepper Motor, ULN2003 Driver, SSD1306 OLED Display, Potentiometer, and Push Buttons.

The potentiometer is used to set the desired target angle (0°–360°). The Arduino continuously compares the current motor position with the target position and rotates the motor until they match. Manual clockwise (CW) and counter-clockwise (CCW) movement is also available using push buttons. A Home button resets the motor position to zero. Real-time motor status is displayed on the OLED screen and logged through the Serial Monitor.

---

# Features

- Potentiometer controls target angle (0°–360°)
- Automatic position tracking
- Manual CW and CCW control
- Home position reset
- OLED displays current angle, target angle, steps, and motor direction
- LED indicates motor movement
- Serial Monitor logs motor position continuously
- Deadband filtering to reduce oscillations
- Noise filtering for potentiometer readings

---

# Hardware Required

- Arduino Uno
- 28BYJ-48 Stepper Motor
- ULN2003 Stepper Driver
- SSD1306 OLED Display (128×64 I2C)
- 10kΩ Potentiometer
- 3 Push Buttons
- LED
- 220Ω Resistor
- Breadboard
- Jumper Wires
- USB Cable

---

# Circuit Connections

## Stepper Driver

| ULN2003 | Arduino |
|----------|----------|
| IN1 | D8 |
| IN2 | D9 |
| IN3 | D10 |
| IN4 | D11 |
| VCC | 5V |
| GND | GND |

## OLED Display

| OLED | Arduino |
|------|----------|
| VCC | 5V |
| GND | GND |
| SDA | A4 |
| SCL | A5 |

## Potentiometer

| Pin | Arduino |
|------|----------|
| Left | 5V |
| Middle | A0 |
| Right | GND |

##
