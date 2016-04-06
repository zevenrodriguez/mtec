int led = 2;
int led2 = 3;
int potValue = 0;
int highRange = 890;
int lowRange = 70;
void setup(){
  pinMode(led,OUTPUT);
  pinMode(led2,OUTPUT);
  Serial.begin(9600);
}

void loop(){

  potValue = analogRead(A0);
  
  if(potValue>highRange){
    potValue = highRange;
  }
  
  if(potValue<lowRange){
    potValue = lowRange;
  }

  potValue = map(potValue,highRange,lowRange, 255,0);
  Serial.println(potValue);


  analogWrite(led2,potValue);
}


