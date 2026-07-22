# Pressure and Altitude Logger

## Project Description
This project measures atmospheric pressure, altitude, and temperature using a BMP180/BMP280 sensor connected to an ESP32. The measured values are displayed on an OLED display and continuously printed on the Serial Monitor.

---

## Components Used

- ESP32 DevKit
- BMP180/BMP280 Pressure Sensor
- SSD1306 OLED Display
- Breadboard
- Jumper Wires

---

## Connections

| Component | ESP32 Pin |
|-----------|-----------|
| BMP SDA | GPIO21 |
| BMP SCL | GPIO22 |
| BMP VCC | 3.3V |
| BMP GND | GND |
| OLED SDA | GPIO21 |
| OLED SCL | GPIO22 |
| OLED VCC | 3.3V |
| OLED GND | GND |

---

## System Architecture

BMP180/BMP280 Sensor

↓

ESP32

↓

OLED Display

↓

Serial Monitor

---

## Working

1. The ESP32 reads pressure, temperature, and altitude from the BMP180/BMP280 sensor.
2. The values are displayed on the OLED.
3. The same values are continuously printed on the Serial Monitor.

---

## Pressure and Altitude Calculation

Pressure is measured directly by the BMP180/BMP280 sensor.

Altitude is calculated using the barometric formula:

Altitude = 44330 × (1 − (Pressure / Sea Level Pressure)^0.1903)

where Sea Level Pressure = 1013.25 hPa.

---

## Serial Monitor Output

Displays:
- Temperature (°C)
- Pressure (hPa)
- Altitude (m)

---

## Conclusion

This project demonstrates real-time atmospheric pressure and altitude measurement using an ESP32 and BMP180/BMP280 sensor with OLED display and Serial Monitor output.
