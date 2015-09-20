int led = 2;
int delayTime = 500;

int button = 3;
int buttonRead = 0;

boolean toggle = false;

void setup(){
  Serial.begin(9600);
   pinMode(led, OUTPUT);
   pinMode(button, INPUT);
}

void loop(){
  buttonRead = digitalRead(button);
  Serial.print("This is button1: ");
  Serial.println(buttonRead);
  
  if (buttonRead == HIGH){
    toggle = true;
  }else{
   toggle = false; 
  }
  
  if (toggle == true){
    digitalWrite(led,HIGH);
  }
  else{
   digitalWrite(led,LOW); 
  }
  
  
  //blink code
  /*
  digitalWrite(led, HIGH);
  delay(delayTime);
  digitalWrite(led,LOW);
  delay(delayTime);
  */
}
