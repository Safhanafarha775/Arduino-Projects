// C++ code
//
#define TRIG 9
#define ECHO 10
#define BUZZER 11

long duration;
int distance;

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BUZZER, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Send a pulse to trigger the sensor
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // Read the echo pulse
  duration = pulseIn(ECHO, HIGH);

  // Calculate distance in cm
  distance = duration * 0.034 / 2;

  // Print distance
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Control buzzer based on distance
  if (distance < 10) {           // Very close
    digitalWrite(BUZZER, HIGH);  // Buzzer ON
  } else {
    digitalWrite(BUZZER, LOW);   // Buzzer OFF
  }

  delay(200);
}