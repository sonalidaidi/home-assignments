# Smart Parking Sensor

## Components
- Arduino Uno
- HC-SR04 Ultrasonic Sensor
- OLED Display
- 3 LEDs
- Buzzer

## Connections
- TRIG -> D9
- ECHO -> D10
- SDA -> A4
- SCL -> A5
- Red LED -> D2
- Yellow LED -> D3
- Green LED -> D4
- Buzzer -> D6

## Formula
Distance = (Time × Speed of Sound) / 2

## Working
The ultrasonic sensor measures the distance to an obstacle. The OLED displays the distance. LEDs and the buzzer indicate how close the obstacle is.
## Physics Behind Distance Calculation

The HC-SR04 ultrasonic sensor measures distance using the Time-of-Flight (ToF) principle.

1. The TRIG pin sends a 10 µs pulse.
2. The sensor emits an ultrasonic wave at 40 kHz.
3. The wave travels to the object and reflects back.
4. The ECHO pin stays HIGH for the total travel time of the sound wave.

The distance is calculated using the speed of sound in air.

Formula:

Distance = (Time × Speed of Sound) / 2

Where:
- Time = Echo pulse duration (seconds)
- Speed of Sound = 343 m/s (0.0343 cm/µs)
- Divide by 2 because the sound travels to the object and back.

In the Arduino code:

```cpp
distance = duration * 0.0343 / 2;
```

Here, `duration` is measured in microseconds and `distance` is calculated in centimeters.
