#include "pitch.h"

int counter = 0;

long pMillis = 0;

int interval = 500;

const int tonePin = 13;

const int seqLength = 5;
int toneSequence[seqLength]= {NOTE_A6,NOTE_B6,NOTE_C6,NOTE_E6,NOTE_F6};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(tonePin,OUTPUT);

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
