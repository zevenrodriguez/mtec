const int clkPin = 2;
const int dtPin = 3;
const int swPin = 4 ; //the number of the button
int toggleState = 0;


int encoderVal = 0;
int currentVal = 0;

int maxNumber = 6;
int minNumber = 0;

int roll = 0;
int currentRoll = 0;
boolean pressing = false;

int pastValue = 0;

int STATE = 0;

boolean typeStart = false;
boolean enterSelection = false;


String inputString = "";
boolean stringComplete = false;
/*
 State 1 : Roll
 State 2 : Select
 State 3 : Check

 */

void setup()
{
  pinMode(clkPin, INPUT);//set clkPin as INPUT
  pinMode(dtPin, INPUT);
  pinMode(swPin, INPUT);
  digitalWrite(swPin, HIGH);
  Serial.begin(9600);

  randomSeed(analogRead(0)); // starts the psuedo random number generator based off the noise of A0

  STATE = 0;

}

void loop()
{
 // Serial.print("StringComplete :");
 // Serial.println(stringComplete);
  if (STATE == 0) {

    if (typeStart == false) {
      Serial.println("Type start to begin");
      typeStart = true;
    }

    if (stringComplete == true) {
      if (inputString.equals("start")) {
        STATE = 1;
        inputString = "";
        stringComplete == false;
      } else {
        inputString = "";
        stringComplete == false;
        Serial.println("Please enter start");
      }
    }

  }
  if (STATE == 1) {
    //Rolling
    currentRoll = rolling();
    Serial.print("Rolling: ");
    Serial.println(currentRoll);
    enterSelection = false;
    stringComplete = false;

  }

  if (STATE == 2) {
    //Selecting
    if (enterSelection == false) {
      Serial.println("Enter your guess");
      enterSelection = true;
    }

    if (stringComplete == true) {
      currentVal = inputString.toInt();
      if (currentVal >= minNumber && currentVal <= maxNumber) {
        STATE = 3;
        inputString = "";
        stringComplete = false;
      } else {
        enterSelection = true;
        stringComplete = false;
        inputString = "";
        STATE == 2;
        Serial.println("Wrong Input please try again");
      }
    }


  }

  if (STATE == 3) {

    check(currentRoll, currentVal);

  }

}

int rolling() {
  roll = random(minNumber, maxNumber + 1);
  // Serial.println(roll);
  STATE = 2;

  return (roll);
}

int check(int _currentRoll, int _currentVal) {

  if (_currentRoll == _currentVal) {
    Serial.println("You guessed correctly");
    STATE = 1;
  } else {
    Serial.println("Try Again");
    STATE = 2;
    enterSelection = false;
  }

}


void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    //inputString += inChar;


    if (inChar != '\n') {
      inputString += inChar;
    }

    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
