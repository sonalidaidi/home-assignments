# Full IoT Home Automation Hub

## Project Description
This project is a complete IoT-based Smart Home Automation System using ESP32. It monitors temperature, humidity, gas leakage, ambient light, and motion. Based on sensor readings, it automatically controls the fan and light, displays information on an OLED, provides gas alerts, hosts a web dashboard, and publishes sensor data using MQTT.

---

## Components Used

- ESP32 DevKit
- DHT22 (DHT11 on hardware)
- MQ-2 Gas Sensor
- PIR Motion Sensor
- LDR
- SSD1306 OLED Display
- 2 Bulbs (Relay Simulation)
- Active Buzzer
- Red LED
- Green LED
- 2 Push Buttons
- Breadboard & Jumper Wires

---

## Connections

| Component | ESP32 Pin |
|-----------|-----------|
| DHT22 DATA | GPIO4 |
| MQ-2 AO | GPIO35 |
| PIR OUT | GPIO13 |
| LDR | GPIO34 |
| OLED SDA | GPIO21 |
| OLED SCL | GPIO22 |
| Fan (Bulb/Relay) | GPIO26 |
| Light (Bulb/Relay) | GPIO27 |
| Buzzer | GPIO14 |
| Red LED | GPIO25 |
| Green LED | GPIO2 |
| Push Button 1 | GPIO0 |
| Push Button 2 | GPIO32 |

---

## System Architecture

Sensors
(DHT22, MQ-2, PIR, LDR)

↓

ESP32 Controller

↓

OLED Display

↓

Fan & Light Control

↓

Web Dashboard

↓

MQTT Broker

---

## Automation Rules

1. Fan turns ON when temperature is greater than 32°C.
2. Fan turns OFF when temperature falls below 28°C.
3. Light turns ON when the room is dark and motion is detected.
4. Gas leakage activates the buzzer and Red LED.
5. Green LED indicates normal operation.
6. Push Button 1 manually controls the fan.
7. Push Button 2 manually controls the light.

---

## Manual Override Logic

Button 1 toggles the fan ON/OFF manually.

Button 2 toggles the light ON/OFF manually.

---

## Web Dashboard

The web dashboard displays:
- Temperature
- Humidity
- Gas Level
- Motion Status
- Light Intensity
- Fan Status
- Light Status

---

## MQTT

Broker:
broker.hivemq.com

Topic:
iitjammu/<yourname>/home

Published Data:
- Temperature
- Humidity
- Gas
- Motion
- Light
- Fan
- Relay
- Alert

---

## Working

The ESP32 continuously reads all sensors. Based on predefined automation rules, it controls the fan and light. The OLED displays real-time values, the buzzer alerts the user in case of gas leakage, the web dashboard allows monitoring through a browser, and MQTT publishes sensor data for remote monitoring.

---

## Conclusion

This project demonstrates a complete IoT Home Automation System by integrating multiple sensors, automatic control, web monitoring, MQTT communication, and manual override features using ESP32.
