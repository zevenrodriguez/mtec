int sensorValue = 0;
int highRange = 850;
int lowRange = 360;
int mapped = 0;

const int ledPin = 3;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(A0);
  if(sensorValue>highRange){
    sensorValue = highRange;
  }
  if(sensorValue<lowRange){
    sensorValue = lowRange;
  }
  Serial.print("sensorvalue: ");
  Serial.print(sensorValue);
  mapped = map(sensorValue,highRange,lowRange,255,0);
   Serial.print("    mapped: ");
  Serial.println(mapped);
  analogWrite(ledPin, mapped);
  
}
