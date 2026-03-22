#include <Arduino.h>

// Chân Motor (Giữ nguyên của bạn)
#define IN1 12
#define IN2 14
#define ENA 13
#define IN3 27
#define IN4 26
#define ENB 25

// Chân Siêu âm
#define TRIG_PIN 5
#define ECHO_PIN 15

const int freq = 1000; // Tần số thấp cho lực kéo mạnh
const int resolution = 8;

void setMotors(int leftSpeed, int rightSpeed) {
  if (leftSpeed >= 0) { digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW); }
  else { digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH); leftSpeed = -leftSpeed; }
  
  if (rightSpeed >= 0) { digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW); }
  else { digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH); rightSpeed = -rightSpeed; }

  ledcWrite(ENA, constrain(leftSpeed, 0, 255));
  ledcWrite(ENB, constrain(rightSpeed, 0, 255));
}

// Hàm đo khoảng cách (cm)
long getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH);
  return duration * 0.034 / 2;
}

void setup() {
  Serial.begin(115200);
  pinMode(IN1, OUTPUT); pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT); pinMode(IN4, OUTPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  ledcAttach(ENA, freq, resolution);
  ledcAttach(ENB, freq, resolution);
}

void loop() {
  long distance = getDistance();
  Serial.print("Khoang cach: "); Serial.print(distance); Serial.println(" cm");

  if (distance > 0 && distance < 10) { // Nếu thấy vật cản gần hơn 30cm
    Serial.println("!!! VAT CAN - DUNG !!!");
    setMotors(0, 0); 
    delay(500);

    Serial.println("Lui mot chut...");
    setMotors(-180, -180); 
    delay(500);

    Serial.println("Quay Phai tranh vat can...");
    setMotors(220, -220); // Tốc độ vừa phải để quay chuẩn
    delay(500); // Chỉnh thời gian này để quay đủ góc né

    setMotors(0, 0);
    delay(200);
  } 
  else {
    Serial.println("Duong thong - Di tiep");
    setMotors(230, 230); // Chạy thẳng với tốc độ cao
  }
  delay(50); // Đợi một chút trước khi đo lần tiếp theo
}
