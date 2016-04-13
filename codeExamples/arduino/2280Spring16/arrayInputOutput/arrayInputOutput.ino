const int bArrayLength = 2; 
const int lArrayLength = 2;
const int oArrayLength = 2;

int buttonArray[bArrayLength] = {2,3};
int ledArray[lArrayLength] = {12,13};
int outputArray[oArrayLength] = {0,0};

void setup() {
  // put your setup code here, to run once:

  for(int i = 0; i < bArrayLength; i++){
    pinMode(buttonArray[i], INPUT);
  }

  for(int i = 0; i < lArrayLength; i++){
    pinMode(ledArray[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  for(int i = 0; i < bArrayLength; i++){
    int buttonRead = digitalRead(buttonArray[i]);
    outputArray[i] = buttonRead;
    Serial.print(i);
    Serial.print(" : ");
    Serial.println(buttonRead);
  }

    for(int i = 0; i < lArrayLength; i++){
    digitalWrite(ledArray[i],outputArray[i]);
  }

}
