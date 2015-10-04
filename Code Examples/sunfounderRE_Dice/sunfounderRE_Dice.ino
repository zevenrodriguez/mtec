const int clkPin= 2;
const int dtPin= 3;
const int swPin= 4 ;//the number of the button
int toggleState = 0;

 
int encoderVal = 0;

int maxNumber = 6;
int minNumber = 0;

int roll = 0;
boolean pressing = false;

int pastValue = 0;
 
void setup()
{
  pinMode(clkPin, INPUT);//set clkPin as INPUT
  pinMode(dtPin, INPUT);
  pinMode(swPin, INPUT);
  digitalWrite(swPin, HIGH);
  Serial.begin(9600);
  
  randomSeed(analogRead(0)); // starts the psuedo random number generator based off the noise of A0

}
 
void loop()
{
  int change = getEncoderTurn();// Runs this function every loop
  encoderVal = encoderVal + change;

  if(encoderVal > 6){
    encoderVal = 6;
  }

  
  if(encoderVal < 0){
    encoderVal = 0;
  }

  if (encoderVal != pastValue){
    Serial.println(encoderVal);
    pastValue = encoderVal;
  }

  toggleState = digitalRead(swPin);

  if (toggleState == HIGH) {
    pressing = true;
  }

  if (toggleState == LOW && pressing == true) {
    pressing = false;
    
    // Your action goes here
    roll = random(minNumber, maxNumber+1);
   // Serial.println(roll);

   if(roll == encoderVal){
    Serial.println("You guessed correctly");
   }else{
    Serial.println("Try Again");
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
