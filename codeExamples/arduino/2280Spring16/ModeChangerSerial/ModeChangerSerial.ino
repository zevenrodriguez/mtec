
String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete


int ledPin = 3;
int mode = 0;

//Mode 2 Variables
int counter = 0;

long pMillis = 0;

int interval = 100;

boolean flipFlop = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  inputString.reserve(200);

}

void loop() {

  serialEvent(); //call the function
  // print the string when a newline arrives:
  if (stringComplete) {
    Serial.println(inputString);
    mode = inputString.toInt();
    Serial.println(mode);

    // clear the string:
    inputString = "";
    stringComplete = false;
  }

  if (mode == 0) {
    //Reset of Off Condition
    digitalWrite(ledPin, LOW);
    Serial.println("Mode 0");
  }
  else if (mode == 1) {
    digitalWrite(ledPin, HIGH);
    Serial.println("Mode 1");

  } else if (mode == 2) {
    //run Mode program
    Serial.println("Mode 2");
       if (millis() - pMillis >= interval) {
      pMillis = millis();
      if (flipFlop == false) {
        counter++;
      } else {
        counter--;
      }
      Serial.println(counter);
    }

    analogWrite(ledPin, counter);

    if (counter >= 255) {
      flipFlop = true;
    }

    if (counter <= 0) {
      flipFlop = false;
    }


  } else {
    mode = 0;
  }

}

void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }else{
      inputString += inChar;
    }
  }
}
