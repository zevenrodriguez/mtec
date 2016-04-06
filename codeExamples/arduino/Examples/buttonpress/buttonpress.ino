#define toggleSwitch 2

int toggleState = 0;

boolean pressing = false;

void setup() {
  Serial.begin(9600);
  pinMode(toggleSwitch, INPUT);
}

void loop() {

  toggleState = digitalRead(toggleSwitch);

  if (toggleState == HIGH) {
    pressing = true;
  }

  if (toggleState == LOW && pressing == true) {
    pressing = false;
    
    // Your action goes here
  }
  
}
