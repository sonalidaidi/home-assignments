#include <WiFi.h>
#include <WebServer.h>
#include <Wire.h>
#include <DHT.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#define DHTPIN 4
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

#define GAS_PIN 35
#define PIR_PIN 13
#define LDR_PIN 34

#define FAN_PIN 26
#define LIGHT_PIN 27

#define RED_LED 25
#define GREEN_LED 2
#define BUZZER 14

#define BTN1 0
#define BTN2 32

const char* ssid = "Wokwi-GUEST";
const char* password = "";

WebServer server(80);

float temp, hum;
int gasValue;
int ldrValue;
bool motion;

bool fanState = false;
bool lightState = false;

void setup() {
  Serial.begin(115200);

  pinMode(GAS_PIN, INPUT);
  pinMode(PIR_PIN, INPUT);
  pinMode(LDR_PIN, INPUT);

  pinMode(FAN_PIN, OUTPUT);
  pinMode(LIGHT_PIN, OUTPUT);

  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  pinMode(BUZZER, OUTPUT);

  pinMode(BTN1, INPUT_PULLUP);
  pinMode(BTN2, INPUT_PULLUP);

  dht.begin();

  Wire.begin(21,22);

  display.begin(SSD1306_SWITCHCAPVCC,0x3C);
  display.clearDisplay();
  display.display();

  WiFi.begin(ssid,password);

  while(WiFi.status()!=WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }

  Serial.println("WiFi Connected");
  Serial.println(WiFi.localIP());

  server.on("/",[](){

    String page="<html><body>";
    page+="<h2>Smart Home Dashboard</h2>";
    page+="Temperature: "+String(temp)+" C<br>";
    page+="Humidity: "+String(hum)+" %<br>";
    page+="Gas: "+String(gasValue)+"<br>";
    page+="Light: "+String(ldrValue)+"<br>";
    page+="Motion: "+String(motion)+"<br>";
    page+="</body></html>";

    server.send(200,"text/html",page);

  });

  server.begin();
}void loop() {

  server.handleClient();

  temp = dht.readTemperature();
  hum = dht.readHumidity();

  gasValue = analogRead(GAS_PIN);
  ldrValue = analogRead(LDR_PIN);
  motion = digitalRead(PIR_PIN);

  // Button 1 - Fan
  if (digitalRead(BTN1) == LOW) {
    fanState = !fanState;
    digitalWrite(FAN_PIN, fanState);
    delay(300);
  }

  // Button 2 - Light
  if (digitalRead(BTN2) == LOW) {
    lightState = !lightState;
    digitalWrite(LIGHT_PIN, lightState);
    delay(300);
  }

  // Automatic Fan Control
  if (temp > 30) {
    digitalWrite(FAN_PIN, HIGH);
  }

  // Automatic Light Control
  if (ldrValue < 1500) {
    digitalWrite(LIGHT_PIN, HIGH);
  } else {
    digitalWrite(LIGHT_PIN, LOW);
  }

  // Gas Detection
  if (gasValue > 2000) {
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    tone(BUZZER, 1000);
  } else {
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
    noTone(BUZZER);
  }

  // Motion Detection
  if (motion) {
    Serial.println("Motion Detected!");
  }

  // OLED Display
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(0,0);
  display.print("Temp: ");
  display.print(temp);
  display.println(" C");

  display.print("Hum : ");
  display.print(hum);
  display.println(" %");

  display.print("Gas : ");
  display.println(gasValue);

  display.print("Light: ");
  display.println(ldrValue);

  display.print("Motion: ");
  if (motion)
    display.println("YES");
  else
    display.println("NO");

  display.display();

  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print("  Hum: ");
  Serial.print(hum);
  Serial.print("  Gas: ");
  Serial.print(gasValue);
  Serial.print("  LDR: ");
  Serial.print(ldrValue);
  Serial.print("  Motion: ");
  Serial.println(motion);

  delay(1000);
}
