#define tranPin 3
int sensorValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(tranPin,OUTPUT);
}

void loop() {
  sensorValue = analogRead(A0);
  sensorValue = sensorValue / 4;
  analogWrite(tranPin,sensorValue);
  
}
