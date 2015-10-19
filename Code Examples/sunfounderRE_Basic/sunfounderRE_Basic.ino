const int clkPin= 2;
const int dtPin= 3;
const int swPin= 4 ;//the number of the button
 
int encoderVal = 0;
 
void setup()
{
  pinMode(clkPin, INPUT);//set clkPin as INPUT
  pinMode(dtPin, INPUT);
  pinMode(swPin, INPUT);
  digitalWrite(swPin, HIGH); //using a pullup resistor
  Serial.begin(9600);
}
 
void loop()
{
  int change = getEncoderTurn();// Runs this function every loop
  encoderVal = encoderVal + change;
  if(digitalRead(swPin) == LOW)//if button pull down
  {
    encoderVal = 0;
  }
  Serial.println(encoderVal);
}
 
int getEncoderTurn()//This function will return an integer value
{
  //resetting everytime function runs
  static int oldA = HIGH;
  static int oldB = HIGH;
  int result = 0;
  
  //read encoder
  
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
