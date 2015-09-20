

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int potRead = analogRead(A0);
  Serial.print("Current state is: ");
  Serial.println(check(potRead));
}
//Reads a potentiometer and returns one of 3 states
int check(int potValue) {
  if (potValue >= 0 && potValue <= 300) {
    return 0;
  } else if (potValue > 300 && potValue <= 600) {
    return 1;
  } else {
    return 2;
  }


}
