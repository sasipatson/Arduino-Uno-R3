//Define Pins

int ENA = 3; // Enable Pin of the Right Motor (must be PWM)
int IN1 = 1; // Control Pin
int IN2 = 2;

int ENB = 6; // Enable Pin of the Left Motor (must be PWM)
int IN3 = 4;
int IN4 = 5;

// Speed of the Motors
#define ENASpeed 100 
#define ENBSpeed 100

// Sensors
int Sensor1 = 0;
int Sensor2 = 0;
int Sensor3 = 0;
int Sensor4 = 0;
int Sensor5 = 0;

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
}

void loop() {
  // Use analogWrite to run motor at adjusted speed
  analogWrite(ENA, ENASpeed);
  analogWrite(ENB, ENBSpeed);

  // Read the Sensors (HIGH = BLACK Line, LOW = WHITE Line)
  Sensor1 = digitalRead(8);
  Sensor2 = digitalRead(9);
  Sensor3 = digitalRead(10);
  Sensor4 = digitalRead(11);
  Sensor5 = digitalRead(12);

  // Movement Logic
  if (Sensor3 == HIGH) { // Move Forward
    forward();
  } else if (Sensor2 == HIGH) { // Slight Left
    slightLeft();
  } else if (Sensor1 == HIGH) { // Hard Left
    hardLeft();
  } else if (Sensor4 == HIGH) { // Slight Right
    slightRight();
  } else if (Sensor5 == HIGH) { // Hard Right
    hardRight();
  } else { // Stop
    stopMotors();
  }
}

void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void slightLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void hardLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void slightRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void hardRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
