int counter = 0;

long pMillis = 0;

int interval = 100;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  if (millis() - pMillis >= interval) {
    pMillis = millis();
    counter++;
    Serial.println(counter);
  }

}
