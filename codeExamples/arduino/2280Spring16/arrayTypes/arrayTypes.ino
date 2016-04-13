int numberArray[] = {0,0,0};

int numberArray2[2];

int numberArray3[2] = {0,0};

char charArray[] = "hello"; //String "hello" = when you use double quotes means, array of characters
char charArray2[] = {'a','b'};

boolean booleanArray[] = {true,false,true};

const int bArrayLength = 2; 
const int lArrayLength = 2;

int buttonArray[bArrayLength] = {2,3};
int ledArray[lArrayLength] = {12,13};

void setup() {
  // put your setup code here, to run once:

  for(int i = 0; i < bArrayLength; i++){
    pinMode(buttonArray[i], INPUT);
  }

  for(int i = 0; i < lArrayLength; i++){
    pinMode(ledArray[i], OUTPUT);
  }
  Serial.begin(9600);
  Serial.println(sizeof(ledArray))
}

void loop() {
  // put your main code here, to run repeatedly:

}
