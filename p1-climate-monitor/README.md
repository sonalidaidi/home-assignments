# 🌡️ Smart Climate Monitor

## 📌 Project Overview
The Smart Climate Monitor measures ambient temperature and humidity using a DHT22 sensor and displays the readings on an OLED display. It also activates a buzzer when a sudden increase in humidity is detected (for example, when breathing on the sensor), providing a simple climate monitoring and alert system.

---

## 🛠 Components Used

- Arduino Uno
- DHT22 Temperature & Humidity Sensor
- 0.96" I2C OLED Display (SSD1306)
- Active Buzzer
- Breadboard
- Jumper Wires

---

## 🔌 Wiring Diagram (Text)

### DHT22
- VCC → 5V
- GND → GND
- DATA → Digital Pin 2

### OLED Display (I2C)
- VCC → 5V
- GND → GND
- SDA → A4
- SCL → A5

### Buzzer
- Positive (+) → Digital Pin 8
- Negative (-) → GND

---

## 📚 Libraries Used

- DHT Sensor Library by Adafruit (v1.4.x)
- Adafruit Unified Sensor (v1.1.x)
- Adafruit GFX Library (v1.11.x)
- Adafruit SSD1306 Library (v2.5.x)

---

## ▶ How It Works

1. Reads temperature and humidity from the DHT22 sensor.
2. Displays the values on the OLED screen.
3. Sends readings to the Serial Monitor in CSV format.
4. If humidity rises rapidly (such as when breathing on the sensor), the buzzer turns ON.
5. When humidity returns to normal, the buzzer turns OFF.

---

## 📊 Serial Monitor Output (CSV)

```
Temperature,Humidity
29.4,46.1
29.5,46.3
29.5,46.5
29.6,61.8
29.7,63.2
```

---

## 📺 Expected OLED Display

```
Smart Climate

Temp: 29.5 C
Hum : 46 %

Status:
NORMAL
```

When humidity increases after breathing on the sensor:

```
Smart Climate

Temp: 29.7 C
Hum : 63 %

Status:
ALERT!
```

The buzzer sounds during the alert condition.

---

## 📂 Repository Contents

```
home-assignments/
└── p1-climate-monitor/
    ├── p1-climate-monitor.ino
    ├── README.md
    ├── serial-monitor.png
    └── demo-video.mp4
```

---

## ✅ Deliverables

- ✔ Arduino `.ino` file
- ✔ README.md
- ✔ Serial Monitor screenshot (minimum 5 CSV rows)
- ✔ Demo video showing:
  - OLED displaying live readings
  - Buzzer activating when breathing on the DHT22 sensor

---

## 📄 License

This project is created for educational and IoT learning purposes.
