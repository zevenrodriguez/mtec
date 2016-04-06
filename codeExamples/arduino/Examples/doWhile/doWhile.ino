int i = 0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //will always run once
  do{
    Serial.println(i);
    i++;
    delay(1000);
  }while(i<=10);
  
  i = 0;

}
