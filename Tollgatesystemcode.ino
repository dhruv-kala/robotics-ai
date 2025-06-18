#include <Servo.h>

const int trigPin = 7;
const int echoPin = 6;
const int servoPin = 5;

long duration;
int distance;
Servo myServo;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myServo.attach(servoPin);
  myServo.write(0);  // Barrier closed
  Serial.begin(9600);
}

void loop() {
  // Trigger ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  // Toll gate condition
  if (distance < 15) {  // Object detected
    myServo.write(90);  // Open barrier
    delay(5000);        // Wait 5 seconds
    myServo.write(0);   // Close barrier
  }

  delay(100);
}