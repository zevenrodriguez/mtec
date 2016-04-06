const int led = 12;
const int led1 = 13;

const int switch0 = 2;
const int switch1 = 3;

int buttonState0 = 0;
int buttonState1 = 0;

void setup() {
  // put your setup code here, to run once:
pinMode(led,OUTPUT);
pinMode(led1,OUTPUT);

pinMode(switch0, INPUT);
pinMode(switch1,INPUT);

Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led,HIGH);
  digitalWrite(led1,HIGH);
  
  buttonState0 = digitalRead(switch0);
  buttonState1 = digitalRead(switch1);
  
  Serial.print("switch0: ");
  Serial.println(buttonState0);
  
  //Serial.print("switch1: ");
  //Serial.println(buttonState1);

}
