int counter = 0;

long pMillis = 0;

int interval = 500;

const int ledPin = 11;

const int seqLength = 100;
int ledSequence[seqLength];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);

  for(int i = 0; i < seqLength; i++){
      ledSequence[i] = random(0,255);
      Serial.println(ledSequence[i]);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  if (millis() - pMillis >= interval) {
    pMillis = millis();
    counter++;
    Serial.println(counter);
  }

  if(counter >= seqLength){
    counter = 0;
  }

  analogWrite(ledPin, ledSequence[counter]);

  

}
