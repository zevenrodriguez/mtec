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
  // put your main code here, to run repeatedly:
  //digitalWrite(ledPin, HIGH);
  switchRead = digitalRead(switchPin);
  //Serial.println(switchRead);

  if(switchRead == 1){
    pressing = true;
    //counter++;
    //overloading int
    //counter=counter+100;
    //Serial.println(counter);

  }

  if(switchRead == 0 && pressing == true){
    pressing = false;
    //do something
    //counter = counter + 1;
    counter++;
    Serial.println(counter);
  }
//  if (switchRead == 1) {
//    digitalWrite(ledPin, HIGH);
//  }
//  
//  if (switchRead == 0) {
//      digitalWrite(ledPin, LOW);
//    }
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
