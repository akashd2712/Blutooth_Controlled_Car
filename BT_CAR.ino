// Ultrasonic Sensor
#define trigPin 4
#define echoPin 5

// Vibration Motors
#define vibLeft 27    // Vibrates when turning RIGHT
#define vibRight 14   // Vibrates when turning LEFT
#define vibCenter 26  // Vibrates when stopping

// Motor Driver Pins (L298N for 4 motors)
#define in1 18 // Motor A
#define in2 19
#define in3 21 // Motor B
#define in4 22

long duration;
int distance;

void setup() {
  Serial.begin(115200);

  // Ultrasonic sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Vibration motors
  pinMode(vibLeft, OUTPUT);
  pinMode(vibRight, OUTPUT);
  pinMode(vibCenter, OUTPUT);

  // Motor driver
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Stop all at start
  stopAllMotors();
  stopAllVibrations();
}

void loop() {
  distance = getDistance();

  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance > 30) {
    moveForward();
    stopAllVibrations();
  }
  else if (distance > 15 && distance <= 30) {
    turnRight();
    vibrateOnce(vibLeft);  // Turning right → Vibrate LEFT motor
  }
  else if (distance <= 15 && distance > 10) {
    turnLeft();
    vibrateOnce(vibRight); // Turning left → Vibrate RIGHT motor
  }
  else {
    stopAllMotors();
    vibrateOnce(vibCenter); // Too close → STOP + Vibrate CENTER motor
  }

  delay(300);
}

int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2; // Distance in cm
}

// Movement Functions
void moveForward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void turnRight() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void turnLeft() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void stopAllMotors() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

// Vibration Functions
void vibrateOnce(int pin) {
  stopAllVibrations();
  digitalWrite(pin, HIGH);
  delay(200);
  digitalWrite(pin, LOW);
}

void stopAllVibrations() {
  digitalWrite(vibLeft, LOW);
  digitalWrite(vibRight, LOW);
  digitalWrite(vibCenter, LOW);
}
