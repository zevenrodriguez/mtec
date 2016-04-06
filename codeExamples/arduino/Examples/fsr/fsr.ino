const int led = 3;
const int fsr = A0;

int sensor0 = 0;
void setup() {
  // put your setup code here, to run once:
pinMode(led, OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensor0 = analogRead(fsr);
  sensor0 = map(sensor0, 0,1010, 0,1024);
  
  if(sensor0 > 1024){
    sensor0 = 1023;
  }  
  Serial.print("Sensor0: ");
  Serial.println(sensor0);
  
  analogWrite(led, sensor0/4);
}
