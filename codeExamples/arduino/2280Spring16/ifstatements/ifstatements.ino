int one = 1;
int two = 2;
boolean check = false;

int potValue = 0;

void setup() {
  Serial.begin(9600);
  if (one > two) {
  }
  if (one < two) {
  }
  if (one >= two) {
  }
  if (one <= two) {
  }
  if (one == two) { //equals
  }
  if (one != two) { //not equals
  }

  if (one < two && check == true) { // this condition is false
  }

  if (one < two || check == true) { // this condition is true
  }

  if (potValue < 512) {
    //run statement 1
  } else if (potValue == 512) {
  // run statment 2
  } else if (potValue > 512 && potValue < 1000) {
// run statement 3
  } else {
    //if no conditions are met then this is the default
  }



}

void loop() {
  // put your main code here, to run repeatedly:

}
