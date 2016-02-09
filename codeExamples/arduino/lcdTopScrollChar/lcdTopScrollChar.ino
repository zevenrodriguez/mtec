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
int lines = 0;
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(4, 6, 10, 11, 12, 13);
char top[16] = {};
char bottom[16] = {};
int columns = 16;

void setup() {
  // set up the LCD's number of columns and rows:
  Serial.begin(9600);
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
  lcd.clear();
  messageSize = strlen(message);
  lines = messageSize / 16;
  Serial.println(messageSize);
  lcd.noAutoscroll();

}

void loop() {

  for (int z = 0; z < lines; z++) {
    int multiplier = z * 16 * 2;
    for (int i = 0; i < columns; i++) {

      top[i] = message[i + multiplier];
      bottom[i] = message[i + 16 + multiplier];
      lcd.setCursor(0, 0);
      lcd.print(top);
      lcd.setCursor(0, 1);
      lcd.print(bottom);
      delay(300);
    }
  }

}



