// Traffic Light System using #define
#define RED_PIN 11
#define YELLOW_PIN 12
#define GREEN_PIN 13

// Timing definitions (in milliseconds)
#define RED_TIME 5000       // 5 seconds red
#define YELLOW_TIME 2000    // 2 seconds yellow
#define GREEN_TIME 5000     // 5 seconds green

void setup() {
  // Initialize LED pins as outputs
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  
  // Initialize serial monitor
  Serial.begin(9600);
  Serial.println("Traffic Light System Started");
}

void loop() {
  // Red light phase
  Serial.println("RED LIGHT - STOP");
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  delay(RED_TIME);
  
  // Green light phase
  Serial.println("GREEN LIGHT - GO");
  digitalWrite(RED_PIN, LOW);
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  delay(GREEN_TIME);
  
  // Yellow light phase
  Serial.println("YELLOW LIGHT - READY");
  digitalWrite(RED_PIN, LOW);
  digitalWrite(YELLOW_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
  delay(YELLOW_TIME);
}