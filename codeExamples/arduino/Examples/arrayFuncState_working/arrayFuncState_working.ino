#define led0 3
#define led1 4
#define toggleSwitch 2

int toggleState = 0;
int currentState = 0;

boolean pressing = false;

const int led0Size = 8;
int led0Seq[led0Size] = {1, 1, 0, 0, 1, 0, 1, 0};

int delayTime = 500;
int previousMillis = 0;

int counter = 0;

void setup() {
  Serial.begin(9600);
  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(toggleSwitch, INPUT);

}

void loop() {
  toggleState = digitalRead(toggleSwitch);
  //Serial.println(toggleState);

  if (toggleState == HIGH) {
    pressing = true;
  }

  if (toggleState == LOW && pressing == true) {
    pressing = false;
    currentState++; // currentState = currentState + 1;
    Serial.println(currentState);
  }

  if (currentState == 0) {
    seq(led0, 0);
    seq(led1, 0);
  } else if (currentState == 1) {
    seq(led0, 1);
    seq(led1, 1);
  } else if (currentState == 2) {
    seq(led0, 0);
    seq(led1, 1);
  } else if (currentState == 3) {
    seq(led0, 1);
    seq(led1, 0);
  } else if (currentState == 4) {
    //sequence
    if(timeCheck()){
      seq(led0, led0Seq[counter]);
      seq(led1, led0Seq[counter]);
      counter++;
      if(counter >= led0Size){
        counter = 0;
      }
    }

    //
    // seq(led1, led0Seq[i]);


  } else {
    currentState = 0;
    //turn off leds
  }

}

void seq(int pin, int highLow) {
  digitalWrite(pin, highLow);
}


boolean timeCheck() {
  long currentMillis = millis(); // only avaiable inside timecheck function
  if (currentMillis - previousMillis >= delayTime) {
    previousMillis = currentMillis;
    return true;
  } else {
    return false;
  }

}


