#define enablePin 3
#define motor1Pin 4
#define motor2Pin 5
#define switchPin 6

int sensorValue = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(motor1Pin, OUTPUT);
  pinMode(motor2Pin, OUTPUT);
  pinMode(enablePin, OUTPUT);
  pinMode(switchPin, INPUT);


  digitalWrite(enablePin, HIGH);
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(A0);
  sensorValue = sensorValue / 4;
  analogWrite(enablePin, sensorValue);
  Serial.println(digitalRead(switchPin));
  // if the switch is high, motor will turn on one direction:
  if (digitalRead(switchPin) == HIGH) {
    digitalWrite(motor1Pin, LOW);   // set leg 1 of the H-bridge low
    digitalWrite(motor2Pin, HIGH);  // set leg 2 of the H-bridge high
  }
  // if the switch is low, motor will turn in the other direction:
  if (digitalRead(switchPin) == LOW) {
    digitalWrite(motor1Pin, HIGH);  // set leg 1 of the H-bridge high
    digitalWrite(motor2Pin, LOW);   // set leg 2 of the H-bridge low
  }
}

