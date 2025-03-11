
// ขา SenSor
#define SENSOR1 8
#define SENSOR2 9
#define SENSOR3 10
#define SENSOR4 11
#define SENSOR5 12

// ขา Motor
#define ENA 3
#define IN1 1
#define IN2 2
#define IN3 4
#define IN4 5
#define ENB 6

// ความเร็วของ Motor
int motorSpeed = 150;

void setup() {
    Serial.begin(9600);
    pinMode(SENSOR1, INPUT);
    pinMode(SENSOR2, INPUT);
    pinMode(SENSOR3, INPUT);
    pinMode(SENSOR4, INPUT);
    pinMode(SENSOR5, INPUT);
    
    pinMode(ENA, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    pinMode(ENB, OUTPUT);
}

void loop() {
    int s1 = digitalRead(SENSOR1);
    int s2 = digitalRead(SENSOR2);
    int s3 = digitalRead(SENSOR3);
    int s4 = digitalRead(SENSOR4);
    int s5 = digitalRead(SENSOR5);

    Serial.print(s1); Serial.print(" ");
    Serial.print(s2); Serial.print(" ");
    Serial.print(s3); Serial.print(" ");
    Serial.print(s4); Serial.print(" ");
    Serial.println(s5);

    if (s3 == HIGH && s1 == LOW && s2 == LOW && s4 == LOW && s5 == LOW) {
        // วิ่งตรง
        moveForward(motorSpeed, motorSpeed);
    } else if (s2 == HIGH && s3 == HIGH) {
        // เลี้ยวซ้ายเล็กน้อย
        moveForward(motorSpeed / 2, motorSpeed);
    } else if (s4 == HIGH && s3 == HIGH) {
        // เลี้ยวขวาเล็กน้อย
        moveForward(motorSpeed, motorSpeed / 2);
    } else if (s1 == HIGH) {
        // เลี้ยวซ้าย
        moveForward(0, motorSpeed);
    } else if (s5 == HIGH) {
        // เลี้ยวขวา
        moveForward(motorSpeed, 0);
    } else {
        // หยุดตอนไม่เจอเส้น
        stopMotors();
    }
}

void moveForward(int speedL, int speedR) {
    analogWrite(ENA, speedL);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    
    analogWrite(ENB, speedR);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}

void stopMotors() {
    analogWrite(ENA, 0);
    analogWrite(ENB, 0);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
}
