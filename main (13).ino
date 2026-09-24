// C++ code
//
int bot = 0;
int sensorPin = 9;
int val = 0;
int pirState = LOW;

void setup()
{
  pinMode(9, INPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(sensorPin, INPUT);
}

void loop() {
  val = digitalRead(sensorPin);
  bot = digitalRead(6);
  if (bot == 1){
    if (val == HIGH) {
    if (pirState == LOW) {
      digitalWrite(13, HIGH);
      tone(12, 523, 1000); // play tone 60 (C5 = 523 Hz)
    }
    
  } else {
     digitalWrite(13, LOW);
    if (pirState == HIGH) {
      noTone(12);
    }
  }
  delay(1); // Delay a little bit to improve simulation performance
}
}