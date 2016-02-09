String action[] = {"Punch", "Run", "Hoopla"};
String reaction[] = {"Block", "Screem", "You fell in a hole"};
int currentMessage = 0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
randomSeed(A0);
}

void loop() {
  // put your main code here, to run repeatedly:
currentMessage = random(0,3);
Serial.println(action[currentMessage]);
Serial.println(reaction[currentMessage]);

}
