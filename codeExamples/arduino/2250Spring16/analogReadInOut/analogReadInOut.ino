int sensorValue = 0;

const int ledPin = 3;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  analogWrite(ledPin, sensorValue/4);
  
}
