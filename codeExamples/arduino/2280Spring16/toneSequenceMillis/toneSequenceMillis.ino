int counter = 0;

long pMillis = 0;

int interval = 500;

const int tonePin = 13;

const int seqLength = 100;
int toneSequence[seqLength];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(tonePin,OUTPUT);

  for(int i = 0; i < seqLength; i++){
      toneSequence[i] = random(300,1000);
      Serial.println(toneSequence[i]);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  if (millis() - pMillis >= interval) {
    pMillis = millis();
    counter++;
    Serial.println(counter);
    tone(tonePin, toneSequence[counter], 100);
  }

  if(counter >= seqLength){
    counter = 0;
  }
  

}
