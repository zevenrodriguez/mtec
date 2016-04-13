int ledPin = 13;
int switchPin = 2;
int switchRead = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(switchPin, INPUT);
  Serial.begin(9600);
}

void loop() {
 
  switchRead = digitalRead(switchPin);
  Serial.println(switchRead);

  if (switchRead == 1) {
    tone(13, 440, 10);
  }

}
