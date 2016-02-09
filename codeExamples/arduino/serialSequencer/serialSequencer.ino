/*
  Reading a serial ASCII-encoded string.

 This sketch demonstrates the Serial parseInt() function.
 It looks for an ASCII string of comma-separated values.
 It parses them into ints, and uses those to fade an RGB LED.

 Circuit: Common-anode RGB LED wired like so:
 * Red cathode: digital pin 3
 * Green cathode: digital pin 5
 * blue cathode: digital pin 6
 * anode: +5V

 created 13 Apr 2012
 by Tom Igoe

 This example code is in the public domain.
 */

// pins for the LEDs:
const int ledPin = 3;

int seq1 = 0;
int seq2 = 0;
int seq3 = 0;


void setup() {
  // initialize serial:
  Serial.begin(9600);
  // make the pins outputs:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // if there's any serial available, read it:
  while (Serial.available() > 0) {

    // look for the next valid integer in the incoming serial stream:
    seq1 = Serial.parseInt();
    // do it again:
    seq2 = Serial.parseInt();
    // do it again:
    seq3 = Serial.parseInt();

    // look for the newline. That's the end of your
    // sentence:
    if (Serial.read() == '\n') {
      // constrain the values to 0 - 255 and invert
      // if you're using a common-cathode LED, just use "constrain(color, 0, 255);"
      seq1 = constrain(seq1, 0, 255);
      seq2 = constrain(seq2, 0, 255);
      seq3 = constrain(seq3, 0, 255);



      // print the three numbers in one string :
      Serial.print(seq1);
      Serial.print(',');
      Serial.print(seq2);
      Serial.print(',');
      Serial.println(seq3);
    }
  }

  analogWrite(ledPin, seq1);
  delay(1000);
  analogWrite(ledPin, seq2);
  delay(1000);
  analogWrite(ledPin, seq3);
  delay(1000);
}








