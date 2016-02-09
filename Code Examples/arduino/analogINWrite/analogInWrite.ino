int led = 2;
int led2 = 3;
int potValue = 0;
void setup(){
  pinMode(led,OUTPUT);
  pinMode(led2,OUTPUT);
  Serial.begin(9600);
}

void loop(){

  potValue = analogRead(A0);
  Serial.println(potValue);
  
  potValue = potValue/4;
  
analogWrite(led2,potValue);
}

