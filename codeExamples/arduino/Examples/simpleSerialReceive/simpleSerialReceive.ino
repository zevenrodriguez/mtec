int incomingByte = 0;
String msg = "";

void setup() {
  // Open serial connection.
  Serial.begin(9600);

}

void loop() {
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
    msg += char(incomingByte);
    // say what you got:
    Serial.print("I got: "); // ASCII printable characters
    Serial.println(incomingByte);
    Serial.println(msg);
    }
//  else{
//    Serial.print("Current msg: ");
//    Serial.println(msg);
//    msg = "";
//  }

}


