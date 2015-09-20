const int arraySize = 6;
int seq[arraySize] = {1, 1, 1, 0, 1, 0};
int counter = 0;
const int led = 2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  //Serial.println(seq[counter]);
  for (int i = 0; i < arraySize; i++ ) {
    // stuff we want to loop through
    if (seq[i] == 1) {
      digitalWrite(led, HIGH);
    } else {
      digitalWrite(led, LOW);
    }
    delay(500);
  }
}
