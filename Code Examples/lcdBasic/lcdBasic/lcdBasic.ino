/*
  LiquidCrystal Library - Hello World

  The circuit:
 * LCD RS pin to digital pin 4
 * LCD Enable pin to digital pin 6
 * LCD D4 pin to digital pin 10
 * LCD D5 pin to digital pin 11
 * LCD D6 pin to digital pin 12 
 * LCD D7 pin to digital pin 13
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
*/
// include the library code:
#include <LiquidCrystal.h>
char message[] = {"The Gunfight at the O.K. Corral was a 30-second gunfight between outlaw Cowboys and lawmen that is generally regarded as the most famous shootout in the history of the American Wild West. "};
int messageSize = 0;
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(4, 6, 10, 11, 12, 13);
char top[16]={};
char bottom[16]={};

void setup() {
  // set up the LCD's number of columns and rows:
  Serial.begin(9600);
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
  lcd.clear();
  messageSize = strlen(message);
  Serial.println(messageSize);
}

void loop() {
  // set the cursor to column 0, line 0
  lcd.setCursor(0, 0);
  lcd.print("Time Elapsed");
    
   // set the cursor to column 0, line 1
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis() / 1000);
  
}

