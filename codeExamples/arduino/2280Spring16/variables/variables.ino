int led1 = 12; // int +- ~32,000
long number = 400000; //longer for of int, 32bit in

float deci = 1.1; //Decimal number
double largeDeci = 1000010.1234; // Larger then a float

char character = 'a';
String words = "hello";

boolean answer = true; // or false
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello World!");

}

void loop() {
  // put your main code here, to run repeatedly:
 // Serial.print("This is a sentence with no hard return");
 // Serial.println("I am in the loop");

 //This won't work
 //Serial.println("Value: " + answer);

 Serial.print("Value: ");
 Serial.println(answer);
}
