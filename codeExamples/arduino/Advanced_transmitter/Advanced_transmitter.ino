// ask_transmitter.pde
// -*- mode: C++ -*-
// Simple example of how to use RadioHead to transmit messages
// with a simple ASK transmitter in a very simple way.
// Implements a simplex (one-way) transmitter with an TX-C1 module


// transmitter pin 
#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver;
//Connect data to pin 12

int sensorData = 0;
void setup()
{
    Serial.begin(4800);	  // Debugging only
    if (!driver.init())
         Serial.println("init failed");
}

void loop()
{
    sensorData++;
    String sensorMsg = "Sensor1:" + String(sensorData);
    //Serial.println(test);
    char charBuf[sensorMsg.length()+1];
    sensorMsg.toCharArray(charBuf, sensorMsg.length()+1);
    //char *msg = charBuf;   
    driver.send((uint8_t *)charBuf, strlen(charBuf));
    driver.waitPacketSent();
    delay(200);
    
   
}
