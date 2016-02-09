const int clkPin = 2;
const int dtPin = 3;

//button variables
const int swPin = 4 ; //the number of the button
int toggleState = 0;
boolean pressing = false;

int encoderVal = 0;

int maxNumber = 6;
int minNumber = 1;
int roll = 0;
int pastValue = 0;

int STATE = 0;

int currentRoll = 0;
int currentVal = 0;

void setup()
{
  pinMode(clkPin, INPUT);//set clkPin as INPUT
  pinMode(dtPin, INPUT);
  pinMode(swPin, INPUT);
  digitalWrite(swPin, HIGH);
  Serial.begin(9600);

  randomSeed(analogRead(0)); // starts the psuedo random number generator based off the noise of A0
  STATE = 1;
}

void loop()
{

  //Rolling
  if (STATE == 1) {
    currentRoll = rolling();
    Serial.print("Rolling: ");
    Serial.println(currentRoll);
    STATE = 2;
  }
  //select
  if (STATE == 2) {
    currentVal = select();
    Serial.print("Select: ");
    Serial.println(currentVal);
    buttonCheck();
  }
  //confirmation/Ouput
  if (STATE == 3) {
    check(currentRoll, currentVal);
  }

}

}

int getEncoderTurn(void)
{
  static int oldA = HIGH;
  static int oldB = HIGH;
  int result = 0;
  int newA = digitalRead(clkPin);//read the value of clkPin to newA
  int newB = digitalRead(dtPin);//read the value of dtPin to newB

  /*
   If newA = 1 and newB = 0 You are turning the nob CLOCKWISE.
   If newA = 0 and newB = 1 nob turning COUNTERCLOCKWISE
   */

  /*
    Serial.print("newA: ");
    Serial.println(newA);
    Serial.print("newB: ");
    Serial.println(newB);

   */

  if (newA != oldA || newB != oldB)
  {
    // something has changed
    if (oldA == HIGH && newA == LOW)
    {
      /*
      Serial.print("oldB: ");
      Serial.println(oldB);
      */
      //when oldB = 1 is CLOCKWISE, oldB = 0 is COUNTERCLOCKWISe
      result = (oldB * 2 - 1);

    }
  }
  oldA = newA;
  oldB = newB;
  return result;
}


int rolling() {
  roll = random(minNumber, maxNumber + 1);
  // Serial.println(roll);
  return (roll);
}

int select() {

  int change = getEncoderTurn();// Runs this function every loop
  encoderVal = encoderVal + change;

  if (encoderVal > maxNumber) {
    encoderVal = maxNumber;
  }
  if (encoderVal < minNumber) {
    encoderVal = minNumber;
  }
  // Print when change happens
  if (encoderVal != pastValue) {
    Serial.println(encoderVal);
    pastValue = encoderVal;
  }

  return (encoderValue);
}

void buttonCheck() {
  toggleState = digitalRead(swPin);

  if (toggleState == LOW) {
    pressing = true;
  }

  if (toggleState == HIGH && pressing == true) {
    pressing = false;
    STATE = 3;
  }
}

void check(int _currentRoll, int _currentVal){
    if (_currentRoll == _currentVal) {
    Serial.println("You guessed correctly");
    STATE = 1;
  } else {
    Serial.println("Try Again");
    STATE = 2;
  }
}
