# Bluetooth Home Light Controller

## Project Description

This project controls two home lights using Bluetooth and an ESP32. The user sends commands from an Android phone through a Bluetooth terminal app. The ESP32 receives the commands and turns the lights ON/OFF while sending back the current status.

---

## Components Used

- ESP32 Dev Board
- 2 LEDs (Light 1 & Light 2)
- 220Ω Resistors
- Push Button
- Active Buzzer
- Breadboard
- Jumper Wires

---

## Connections

| Component | ESP32 Pin |
|-----------|-----------|
| Light 1 LED | GPIO26 |
| Light 2 LED | GPIO27 |
| Push Button | GPIO0 |
| Buzzer | GPIO14 |
| Status LED | GPIO2 |

---

## Pairing Instructions

1. Upload the program to the ESP32.
2. Enable Bluetooth on your Android phone.
3. Open a Bluetooth Terminal app.
4. Pair with the device named **IIT_IoT_HomeCtrl**.
5. Connect to the device.
6. Send the commands listed below to control the lights.

---

## Supported Commands

| Command | Function |
|---------|----------|
| 1 | Light 1 ON |
| 2 | Light 1 OFF |
| 3 | Light 2 ON |
| 4 | Light 2 OFF |
| 5 | ALL ON |
| 6 | ALL OFF |
| ? | Show Current Status |

---

## Working

- ESP32 waits for Bluetooth commands.
- When a valid command is received:
  - The corresponding light turns ON or OFF.
  - The buzzer beeps once.
  - The current light status is sent back to the phone.

---

## Manual Override

The push button allows manual control of the lights even without Bluetooth.

---

## Serial Monitor Output

Displays:
- Bluetooth Connected
- Received Command
- Light Status

Example:

Light1 : ON
Light2 : OFF

---

## Conclusion

This project demonstrates Bluetooth-based wireless home lighting control using an ESP32 with manual override and status feedback.
