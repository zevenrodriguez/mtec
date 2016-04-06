const int ledPin = 13;
const int switchPin = 2;
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
    
  }

//We want to check if the button is currently released and has been pressed before its been released
  if(switchRead == 0 && pressing == true){
    //setting up for the next time we press
    pressing = false;
    //Do something
    counter++;
    Serial.println(counter);
  }
}
