/*
  LiquidCrystal Library - Autoscroll

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch demonstrates the use of the autoscroll()
 and noAutoscroll() functions to make new text scroll or not.

 The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalAutoscroll

 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
String test = "World Wildlife Fund  Followers 653,644  Tweets 9,232  Total contributions $165,268,587  President/CEO salary $637,686";

String left = "";
String right = "";
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(8, 2);
  test = test + "                ";
}

void loop() {

  //Serial.println(test.length());
  for (int i = 0; i < test.length(); i++) {
    //Serial.println(i);
    left = test.substring(i, 8 + i);
    lcd.setCursor(0, 0);
    lcd.print(left);
    lcd.setCursor(0, 1);
    right = test.substring(8 + i, 17 + i);
    lcd.print(right);
    delay(100);
  }


}

