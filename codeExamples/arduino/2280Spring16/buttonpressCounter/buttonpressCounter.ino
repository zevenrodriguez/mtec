int ledPin = 13;
int switchPin = 2;
int switchRead = 0;
int counter = 0;

boolean pressing = false;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(switchPin, INPUT);
  Serial.begin(9600);
}

void loop() {

  switchRead = digitalRead(switchPin);
  //Serial.println(switchRead);

  if(switchRead == 1){
    pressing = true;
  }

  if(switchRead == 0 && pressing == true){
    pressing = false;
    //do something
    //counter = counter + 1;
    counter++;
    Serial.println(counter);
  }

  if(counter > 1){
    counter = 0;
  }
  if (counter == 1) {
    digitalWrite(ledPin, HIGH);
  }
  if(counter == 0){
      digitalWrite(ledPin, LOW);
    }

}
