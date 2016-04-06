/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://www.arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */
int delayTime = 500;

const int led0 = 13; // constant int
#define led1 12 // define is used to set a constant variable 

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);

}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(led0, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(led1, HIGH);   // turn the LED on (HIGH is the voltage level)

  delay(delayTime);              // wait for a second
  digitalWrite(led0, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(led1, LOW);    // turn the LED off by making the voltage LOW

  delay(delayTime);              // wait for a second
}
