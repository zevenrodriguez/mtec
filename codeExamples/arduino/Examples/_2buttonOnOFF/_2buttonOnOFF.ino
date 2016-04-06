const int led0 = 12;
const int led1 = 13;

const int switch0 = 2;
const int switch1 = 3;

int buttonState0 = 0;
int buttonState1 = 0;

boolean pressed0 = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(switch0, INPUT);
  pinMode(switch1, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //digitalWrite(led0, HIGH);
  //digitalWrite(led1, HIGH);
  
  buttonState0 = digitalRead(switch0);
  buttonState1 = digitalRead(switch1);
  
  Serial.print("Switch0: ");
  Serial.print(buttonState0);
  Serial.print("   Switch1: ");
  Serial.println(buttonState1);
  
  if(buttonState0 == HIGH){
    pressed0 = true;
  }
  
  if(buttonState0 == LOW && pressed0 == true){
   pressed0 = false;
   digitalWrite(led0,HIGH); 
   delay(1000);
   digitalWrite(led0,LOW);
  }

  
  if(buttonState1 == HIGH){
  digitalWrite(led1,HIGH);
  }else{
   digitalWrite(led1, LOW); 
  }

}
