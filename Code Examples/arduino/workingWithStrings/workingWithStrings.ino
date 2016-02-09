String example1 = "    This not a not a string    ";
String example2 = "Sensor1:100";
int trigger = -1;
int setPin = 0;

void setup() {
  // put your setup code here, to run once:


  Serial.begin(9600);
  //example1.trim();

  Serial.println(example1);

  for (int i = 0; i < example2.length(); i++) {
    
    if (example2.charAt(i) == ':') {
      trigger = i;
      Serial.println(trigger);
    }

    //Serial.println(example2.charAt(i));
  }
  
  String numberString = example2.substring(trigger+1,example2.length());
  int numberA = numberString.toInt();
  Serial.println(numberString);
  Serial.println(numberA);

  
  String sensor = example2.substring(0, trigger);
  Serial.println(sensor);
  
  if (sensor.equals("Sensor1")){
    setPin = 3;
    Serial.println(setPin);

  }
  
  analogWrite(setPin, numberA);
}

void loop() {
  // put your main code here, to run repeatedly:

}
