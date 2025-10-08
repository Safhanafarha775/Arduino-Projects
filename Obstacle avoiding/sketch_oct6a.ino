// Ultrasonic Distance Sensor with Buzzer using #define
// Pin Definitions using #define
#define TRIG_PIN 9
#define ECHO_PIN 10
#define BUZZER_PIN 8

// Distance thresholds (in cm)
#define SAFE_DISTANCE 50      // Safe zone - no sound
#define WARNING_DISTANCE 30   // Warning zone - slow beeps
#define DANGER_DISTANCE 15    // Danger zone - fast beeps
#define CRITICAL_DISTANCE 5   // Critical zone - continuous sound

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Set pin modes
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  
  Serial.println("Ultrasonic Distance Sensor with Buzzer Started");
  Serial.println("=============================================");
}

void loop() {
  // Measure distance
  long distance = measureDistance();
  
  // Print distance to serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Control buzzer based on distance
  controlBuzzer(distance);
  
  // Small delay between measurements
  delay(100);
}

long measureDistance() {
  // Clear the TRIG_PIN
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  
  // Set TRIG_PIN HIGH for 10 microseconds
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  // Read ECHO_PIN, returns sound wave travel time in microseconds
  long duration = pulseIn(ECHO_PIN, HIGH);
  
  // Calculate distance (speed of sound = 343 m/s = 0.0343 cm/μs)
  // Distance = (time × speed) / 2 (round trip)
  long distance = duration * 0.0343 / 2;
  
  return distance;
}

void controlBuzzer(long distance) {
  if (distance > SAFE_DISTANCE) {
    // Safe zone - no sound
    noTone(BUZZER_PIN);
    Serial.println("Status: SAFE");
    
  } else if (distance > WARNING_DISTANCE && distance <= SAFE_DISTANCE) {
    // Warning zone - slow beeps
    tone(BUZZER_PIN, 1000, 200); // 1kHz tone for 200ms
    Serial.println("Status: WARNING - Slow beeps");
    delay(500); // Additional delay for slow beeping
    
  } else if (distance > DANGER_DISTANCE && distance <= WARNING_DISTANCE) {
    // Danger zone - medium beeps
    tone(BUZZER_PIN, 1500, 150); // 1.5kHz tone for 150ms
    Serial.println("Status: DANGER - Medium beeps");
    delay(300); // Additional delay for medium beeping
    
  } else if (distance > CRITICAL_DISTANCE && distance <= DANGER_DISTANCE) {
    // Critical zone - fast beeps
    tone(BUZZER_PIN, 2000, 100); // 2kHz tone for 100ms
    Serial.println("Status: CRITICAL - Fast beeps");
    delay(150); // Additional delay for fast beeping
    
  } else if (distance <= CRITICAL_DISTANCE && distance > 0) {
    // Very critical - continuous sound
    tone(BUZZER_PIN, 2500); // Continuous 2.5kHz tone
    Serial.println("Status: VERY CRITICAL - Continuous sound");
    
  } else {
    // Invalid distance reading
    noTone(BUZZER_PIN);
    Serial.println("Status: INVALID READING");
  }
}