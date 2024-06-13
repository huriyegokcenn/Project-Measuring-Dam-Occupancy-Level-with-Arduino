const int analogInPin = A0;
int sensorValue = 0;

void setup() {
  // declare pins to be outputs:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  sensorValue = analogRead(analogInPin);
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\n");
  delay(2);

  // Turn off all LEDs before checking conditions
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);

  if ((sensorValue >= 100) && (sensorValue <= 500)) {
    digitalWrite(2, HIGH);
    delay(100);
  }
  else if ((sensorValue >= 501) && (sensorValue <= 550)) {
    digitalWrite(3, HIGH);
     digitalWrite(2, HIGH);
    delay(100);
  }
  else if ((sensorValue >= 551) && (sensorValue <= 650)) {
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
  } else {
    // All LEDs are already turned off above, no need to turn them off again
    delay(100);
  }
}
