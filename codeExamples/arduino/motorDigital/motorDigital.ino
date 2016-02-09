int button = 7;
#define motor1 5
#define motor2 6
#define enablePin 3

void setup() {
  // put your setup code here, to run once:
pinMode(button,INPUT);
pinMode(motor1,OUTPUT);
pinMode(motor2,OUTPUT);
pinMode(enablePin,OUTPUT);

}

void loop() {
  
  int sensorValue = analogRead(A0);
  sensorValue = sensorValue/4;
analogWrite(enablePin, sensorValue);

if(digitalRead(button)==HIGH){
  digitalWrite(motor1,HIGH);
    digitalWrite(motor2,LOW);

}else{
  digitalWrite(motor1,LOW);
    digitalWrite(motor2,LOW);
}

}
