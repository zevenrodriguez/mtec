const int ledPin = 13;
const int switchPin = 2;
int switchRead = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(switchPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledPin, HIGH);
  switchRead = digitalRead(switchPin);
  Serial.println(switchRead);
//
//  if (switchRead == 1) {
//    digitalWrite(ledPin, HIGH);
//  }
//  
//  if (switchRead == 0) {
//      digitalWrite(ledPin, LOW);
//    }

  



}
