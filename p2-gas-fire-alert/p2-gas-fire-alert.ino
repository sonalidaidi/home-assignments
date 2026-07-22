// Pin Definitions
const int MQ2_PIN = A0;      
const int FLAME_SIM_PIN = 2; // Simulated flame sensor pin
const int BUZZER_PIN = 8;    
#define RL_VALUE 5.0      // Load resistance in Kilo-Ohms (usually 5.0 or 1.0 on modules)
#define R0 10.0           // Replace with your calibrated clean air R0 value
const int GAS_THRESHOLD = 50;

// Math constants for LPG gas curve fitting
const float GAS_A = 574.25;
const float GAS_B = -2.22; 

void setup() {
 // Uses built-in pullup: HIGH by default, LOW when switch is closed
  pinMode(FLAME_SIM_PIN, INPUT_PULLUP); 
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  float analogValue = analogRead(MQ2_PIN);
  
   // LOW means switch is flipped to GND (Simulating Flame Detected)
  int flameDetected = digitalRead(FLAME_SIM_PIN); 
  
   // Convert raw reading to voltage (0V - 5V)
  float v_out = analogValue * (5.0 / 1023.0);
  Serial.print("v_out: ");
  Serial.println(v_out);
  
   // Calculate current sensor resistance (Rs)
  float r_s = RL_VALUE * ((5.0 - v_out) / v_out);
  
   // Calculate the ratio (Rs/R0)
  float ratio = r_s / R0;
  
   // Apply power-law formula to get exact PPM
  float ppm = pow((ratio / GAS_A), (1.0 / GAS_B));

   // Print results to Serial Monitor
  Serial.print("Raw: ");
  Serial.print(analogValue);
  Serial.print(" | Ratio: ");
  Serial.print(ratio);
  Serial.print(" | LPG Concentration: ");
  Serial.print(ppm);
  Serial.println(" ppm");
  Serial.print(" | Flame Status: ");
  Serial.println(flameDetected == LOW ? "FLAME DETECTED!" : "Safe");

  if (ppm > GAS_THRESHOLD || flameDetected == LOW) {
    tone(BUZZER_PIN, 1000); 
  } else {
    noTone(BUZZER_PIN);  
  }

  delay(500); 
}

