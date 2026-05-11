// SENSÖR TEST - arduino_sensor_test.ino
const int TRIG = 12;
const int ECHO = 13;
const int SERVO = 3;

#include <Servo.h>
Servo scanServo;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  
  scanServo.attach(SERVO);
  scanServo.write(90); // Ortala
  
  Serial.println("Sensör Test Başladı");
}

void loop() {
  // Mesafe ölç
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  
  long duration = pulseIn(ECHO, HIGH, 30000);
  float distance = duration * 0.034 / 2.0;
  
  Serial.print("Mesafe: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Servo test
  scanServo.write(45);
  delay(1000);
  scanServo.write(90);
  delay(1000);
  scanServo.write(135);
  delay(1000);
  scanServo.write(90);
  delay(1000);
}