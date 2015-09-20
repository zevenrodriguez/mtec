// Maurice Ribble
// 8-30-2009
// http://www.glacialwanderer.com/hobbyrobotics
// Used Arduino 0017
// This is a simple test app for some cheap RF transmitter and receiver hardware.
// RF Transmitter: http://www.sparkfun.com/commerce/product_info.php?products_id=8945
// RF Receiver: http://www.sparkfun.com/commerce/product_info.php?products_id=8948

// This says whether you are building the transmistor or reciever.
// Only one of these should be defined.
//#define TRANSMITTER // pin tx
#define RECEIVER // pin rx

// Arduino digital pins
#define buttonPin  2
#define LED_PIN     13

boolean pressing = false;
int currentState = 0;

void setup()
{
  pinMode(buttonPin, INPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  Serial.begin(1200);  // Hardware supports up to 2400, but 1200 gives longer range
}

#ifdef TRANSMITTER
void loop()
{
  int toggleState = digitalRead(buttonPin);
  //Serial.println(toggleState);
  if (toggleState == HIGH) {
    pressing = true;
  }
  if (toggleState == LOW && pressing == true) {
    pressing = false;
    writeUInt(currentState);
    currentState++; // currentState = currentState + 1;
    //Serial.println(currentState);
    delay(50);

  }
  // writeUInt(currentState);
  //  currentState++; // currentState = currentState + 1;
}
#endif //TRANSMITTER

#ifdef RECEIVER
void loop()
{
  Serial.println(readUInt(true));
}
#endif //RECEIVER


