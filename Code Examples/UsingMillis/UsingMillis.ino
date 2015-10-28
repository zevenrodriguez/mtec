const int ledPin = 13;
int ledState = LOW;

const long interval = 1000;

unsigned long prevMillis = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(1000);
  Serial.println(millis());
  Serial.println(millis());
  Serial.println(millis());
  Serial.println(millis());
  Serial.println(millis());
  Serial.println(millis());
  Serial.println(millis());

  delay(1000);
  Serial.println(millis());
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(millis());

  unsigned  long currentMillis = millis();

  if (currentMillis - prevMillis >= interval) {
    prevMillis = currentMillis;

    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    digitalWrite(ledPin, ledState);

  }

}
