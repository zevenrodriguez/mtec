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

  if(potValue <=512){
    digitalWrite(led,HIGH);
    digitalWrite(led2,LOW);
  }else{
    digitalWrite(led,LOW);
    digitalWrite(led2,HIGH);
  }


}

