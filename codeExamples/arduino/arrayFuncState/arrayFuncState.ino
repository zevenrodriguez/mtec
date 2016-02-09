 #define led0 3
#define led1 4
#define toggleSwitch 2

int toggleState = 0;

const int led0Size = 8;

int led0Seq[led0Size] = {1, 0, 1, 0, 1, 1, 0, 0} ;


const int led1Size = 8;

int led1Seq[led1Size] = {0, 0, 1, 1, 0, 1, 0, 1} ;

int delayTime = 500;

boolean pressing = false;
volatile boolean donePress = false;

boolean timer = false;
unsigned long previousMillis = 0;        // will store last time LED was updated

int counter = 0;

int currentState = 0;

void setup() {
  Serial.begin(9600);
  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(toggleSwitch, INPUT);

  /*
   for (int i = 0; i < led0Size; i++){
     Serial.println(led0Seq[i]);
   }
   */

}

void loop() {

  toggleState = digitalRead(toggleSwitch);

  if (toggleState == HIGH) {
    pressing = true;
  }

  if (toggleState == LOW && pressing == true) {
    pressing = false;
    currentState++;
    
    if(currentState >= 5){
     currentState = 0; 
    }
  }
  


  if (currentState == 4) {
    //Serial.println(timeCheck());

    if (timeCheck()) {
      seq(led0Seq[counter], led0);
      seq(led1Seq[counter], led1);
      counter++;
      if (counter >= led0Size) {
        counter = 0;
      }
      //Serial.println(counter);
    }
  }
  
  if (currentState == 3) {
    seq(1, led0);
    seq(0, led1);
  }
  

  if (currentState == 2) {
    seq(0, led0);
    seq(1, led1);
  }

  if (currentState == 1) {
    seq(1, led0);
    seq(1, led1);

  }

  if (currentState == 0) {
    counter = 0;
    seq(0, led0);
    seq(0, led1);
  }
}


void seq(int highLow, int pin) {

  if (highLow == 1) {
    digitalWrite(pin, HIGH);
  } else {
    digitalWrite(pin, LOW);
  }
}

boolean timeCheck() {

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= delayTime) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
    return true;
  } else {
    return false;
  }

}

/*
  if (donePress) {
      for (int i = 0; i < led0Size; i++) {
        seq(led0Seq[i], led0);
        seq(led1Seq[i], led1);
        delay(delayTime);
      }
    }else{
      seq(0,led0);
      seq(0,led1);
    }

   */
/*
  if (donePress) {
    seq(led0Seq[i], led0);
    seq(led1Seq[i], led1);
  }
} else {
  seq(0, led0);
  seq(0, led1);
}

*/



