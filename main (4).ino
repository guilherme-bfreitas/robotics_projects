// C++ code
//
int sensor1 = 0;

int sensor2 = 0;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop()
{
  sensor1 = (-40 + 0.488155 * (analogRead(A0) - 20));
  sensor2 = (-40 + 0.488155 * (analogRead(A1) - 20));
  if (sensor1 > 50 || sensor2 > 50) {
    digitalWrite(7, HIGH);
    digitalWrite(6, LOW);
    tone(5, 523, 5000); // play tone 60 (C5 = 523 Hz)
  } else {
    digitalWrite(7, LOW);
    digitalWrite(6, HIGH);
    noTone(5);
  }
  delay(10); // Delay a little bit to improve simulation performance
}