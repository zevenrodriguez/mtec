// This comment is one line

/*
This is a paragraph 
more info to come....

*/

/*
if statment here
some variables
*/

int led = 1; //-32768 to 32767
int led2 = 2;
long number = 32800; //-2,147,483,648 to 2,147,483,647
float decimalNumber = 1.2; //3.4028235E+38 and as low as -3.4028235E+38
double decimalNumber2 = 2.2;
boolean answer = false;
char letter = 'a';
String words = "This is a sentence";
void setup(){
  Serial.begin(9600);
  Serial.print("This is led divided by led2: ");
  Serial.println(led / led2);
  Serial.println(decimalNumber / decimalNumber2);
  Serial.println(decimalNumber + led);
  led = decimalNumber + decimalNumber2;
  Serial.println(led);
  Serial.println(letter);
  Serial.println(letter + 1); // not type casted returns a number
  Serial.println(char(letter + 1)); //type casting forcing variables (returns a char)
  
}

void loop(){
  
}


