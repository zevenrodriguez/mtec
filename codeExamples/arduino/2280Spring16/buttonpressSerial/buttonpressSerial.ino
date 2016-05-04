#define toggleSwitch 2
#define toggleSwitch2 3


int toggleState = 0;
int toggleState2 = 0;


boolean pressing = false;
boolean pressing2 = false;


void setup() {
  Serial.begin(9600);
  pinMode(toggleSwitch, INPUT);
  pinMode(toggleSwitch2, INPUT);

}

void loop() {

  toggleState = digitalRead(toggleSwitch);
  toggleState2 = digitalRead(toggleSwitch2);


  if (toggleState == HIGH) {
    pressing = true;
  }

  if (toggleState == LOW && pressing == true) {
    pressing = false;
    Serial.println("button1");
  }

  if (toggleState2 == HIGH) {
    pressing2 = true;
  }

  if (toggleState2 == LOW && pressing2 == true) {
    pressing2 = false;
    Serial.println("button2");
  }

}
