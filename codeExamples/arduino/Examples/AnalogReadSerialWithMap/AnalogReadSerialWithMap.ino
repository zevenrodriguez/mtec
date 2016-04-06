/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

 This example code is in the public domain.
 */

// the setup routine runs once when you press reset:

const int led = 3;
int mappedValue = 0;
int highNumber = 325;
int lowNumber = 10;
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  if(sensorValue > highNumber){
    sensorValue = highNumber;
  }
  if(sensorValue < lowNumber){
    sensorValue = lowNumber;
  }
  mappedValue = map(sensorValue, lowNumber, highNumber, 255, 0);
  // print out the value you read:
  Serial.println(sensorValue);
  delay(1);        // delay in between reads for stability
  
  analogWrite(led, mappedValue);
  
}
