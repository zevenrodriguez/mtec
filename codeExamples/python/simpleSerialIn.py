import serial
import time
ser = serial.Serial('COM3', 9600, timeout=0)

msg = ""

while 1:
    try:
        msg = ser.readline()
        msg = msg.strip()
        msg = str(msg, encoding="UTF-8")
        print(msg)
        if(msg == "Hello world"):
            print("working")
        time.sleep(1)
    except ser.SerialTimeoutException:
        print('Data could not be read')
        time.sleep(1)

'''
void setup() {
  // Open serial connection.
  Serial.begin(9600);

}

void loop() {
  Serial.println("Hello world");
  delay(1000); // ms

}

'''
