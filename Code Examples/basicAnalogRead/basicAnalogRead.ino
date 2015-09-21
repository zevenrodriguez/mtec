//Variables go here
int pot = 0; //The pin we are going to connect to
int analogValue = 0; // This is the variable that holds the value of out potentiometer

void setup() {
// put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogValue = analogRead(pot);
  Serial.println(analogValue);
}
