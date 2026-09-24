// C++ code
//
int dist = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop()
{
  dist = 0.01723 * readUltrasonicDistance(7, 6);
  Serial.println(dist);
  if (dist > 252 && dist <= 366) {
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(2, HIGH);
    tone(11, 92, 3000); // play tone 30 (F#2 = 92 Hz)
  }
  if (dist > 168 && dist < 252) {
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(2, LOW);
    tone(11, 523, 3000); // play tone 60 (C5 = 523 Hz)
  }
  if (dist > 84 && dist < 168) {
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
    tone(11, 2960, 3000); // play tone 90 (F#7 = 2960 Hz)
  }
  if (dist < 84) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    tone(11, 16744, 3000); // play tone 120 (C10 = 16744 Hz)
  }
  delay(10); // Delay a little bit to improve simulation performance
}