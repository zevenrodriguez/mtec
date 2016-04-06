
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(4, 6, 10, 11, 12, 13);

String test;
String top;
String bottom;

int characters = 0;
int lines = 0;
int remainder = 0;
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  Serial.begin(9600);
  test.reserve(200);
  top.reserve(30);
  bottom.reserve(30);
  test = {"The Gunfight at the O.K. Corral was a 30-second gunfight between outlaw Cowboys and lawmen that is generally regarded as the most famous shootout in the history of the American Wild West.     "};
  characters = test.length();
  lines = (test.length() / 16)/2;
  remainder = test.length() % 16;
  Serial.println(characters);
  Serial.println(lines);
  Serial.println(remainder);
}

void loop() {

  //Serial.println(test.length());
  for (int i = 0; i < lines; i++) {
    Serial.println(i);
    top = test.substring((16 * i) * 2, 16 + ((16 * i) * 2));
    lcd.setCursor(0, 0);
    lcd.print(top);
    lcd.setCursor(0, 1);
    bottom = test.substring((16 + ((16 * i) * 2)), 32 + (16 + ((16 * i) * 2)));
    lcd.print(bottom);
    delay(1000);
  }

}

