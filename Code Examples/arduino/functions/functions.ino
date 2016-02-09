int pin = 13;
int i = 10;
void setup() {
  // put your setup code here, to run once:
  pinMode(pin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //blinky();

  if (timeDelay() == true) {
    blinkyDelay(100);
    delay(100);
    blinkyDelay(1000);
    delay(100);
  }
}

void blinky() {
  digitalWrite(pin, HIGH);
  delay(500);
  digitalWrite(pin, LOW);
  delay(500);
}

void blinkyDelay(int delayTime) {
  digitalWrite(pin, HIGH);
  delay(delayTime);
  digitalWrite(pin, LOW);
  delay(delayTime);
}

boolean timeDelay() {
  Serial.println("timeDelay");
  delay(1000);
  return true;
}


