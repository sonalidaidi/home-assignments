#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#define TRIG 9
#define ECHO 10

#define RED_LED 2
#define YELLOW_LED 3
#define GREEN_LED 4

#define BUZZER 6

void setup() {
  Serial.begin(9600);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED Failed");
    while (1);
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(2);
  display.setCursor(10, 20);
  display.println("START");
  display.display();
  delay(1500);
}

void loop() {

  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG, LOW);

  long duration = pulseIn(ECHO, HIGH);
  float distance = duration * 0.0343 / 2.0;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("Distance:");

  display.setTextSize(2);
  display.setCursor(0,18);
  display.print(distance,1);
  display.print(" cm");

  noTone(BUZZER);

  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(GREEN_LED, LOW);

  if(distance < 10){
    digitalWrite(RED_LED,HIGH);
    tone(BUZZER,1000);
  }
  else if(distance < 20){
    digitalWrite(YELLOW_LED,HIGH);
    tone(BUZZER,1000);
    delay(200);
    noTone(BUZZER);
  }
  else{
    digitalWrite(GREEN_LED,HIGH);
  }

  display.display();

  delay(100);
}
