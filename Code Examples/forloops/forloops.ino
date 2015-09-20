void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(3,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 /* 
   for(int i=0;i<10;i++){
    Serial.println(i);
    delay(1000);
  }
  */
  
  /*
  for(int i=0;i<10;i = i+2){
    Serial.println(i);
    delay(1000);
  }
  */
  /*
   for(int i=10;i>0;i--){
    Serial.println(i);
    delay(1000);
  }
  
  */
   for (int i = 0; i < 255; i++) {
    analogWrite(3,i);
    delay(10);
  }
  for (int i = 255; i > 0; i--) {
    analogWrite(3,i);
    delay(10);
  }
  

}
