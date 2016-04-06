

/*
  SD card read/write

  This example shows how to read and write data to and from an SD card file
  The circuit:
   SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4

  created   Nov 2010
  by David A. Mellis
  modified 9 Apr 2012
  by Tom Igoe

  This example code is in the public domain.

*/

#include <SPI.h>
#include <SD.h>
//#include <ArduinoJson.h>


File myFile;

File root;

String openFile = "JSON.txt";
String message;
String jsonMessage;


//StaticJsonBuffer<200> jsonBuffer;
char json[200];

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  message.reserve(200);

  Serial.print("Initializing SD card...");

  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  message = "{\"sensor\":\"gps\",\"time\":1351824120,\"data\":[48.756080,2.302038]}";


  removeFile(openFile);
  delay(10);
  createFile(openFile);

  root = SD.open("/");

  printDirectory(root, 0);

  //  for(int i = 0; i<10; i++){
  //  writeFile(String(i), openFile);
  //  delay(10);
  //  }
  writeFile(message, openFile);
  //readFile(openFile);
  readJson(openFile);
  Serial.println("done!");



}

void loop() {
  // nothing happens after setup
}


void readFile(String _readFile) {
  // re-open the file for reading:
  myFile = SD.open(_readFile);
  if (myFile) {
    Serial.println(_readFile);

    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening");
  }
}

void readJson(String _readFile) {

  // re-open the file for reading:
  myFile = SD.open(_readFile);
  if (myFile) {
    Serial.println(_readFile);
    int counter = 0;
    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      json[counter] = char(myFile.read());
      counter++;
      //Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
    counter = 0;
    Serial.println(json);
    //const int strLen = jsonMessage.length();
    //char json[strLen];
    //jsonMessage.toCharArray(json, strLen);
//    JsonObject& root = jsonBuffer.parseObject(json);
//
//    const char* sensor = root["sensor"];
//    long time          = root["time"];
//    double latitude    = root["data"][0];
//    double longitude   = root["data"][1];
//
//    Serial.print("Sensor: ");
//    Serial.println(sensor);
//    
//    Serial.print("time: ");
//    Serial.println(time);
//
//    Serial.print("latitude: ");
//    Serial.println(latitude);
//
//    Serial.print("longitude: ");
//    Serial.println(longitude);


  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening");
  }


}

void writeFile(String _writeText, String _file) {
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile = SD.open(_file, FILE_WRITE);

  // if the file opened okay, write to it:
  if (myFile) {
    Serial.print("Writing...");
    myFile.println(_writeText);
    // close the file:
    myFile.close();
    Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening");
  }


}

void createFile(String _createFile) {
  Serial.println("Creating");
  myFile = SD.open(_createFile, FILE_WRITE);
  myFile.close();
}

void removeFile(String _removeFile) {

  // Check to see if the file exists:
  if (SD.exists(_removeFile)) {
    Serial.print(_removeFile);
    Serial.println(" exists.");
  } else {
    Serial.print(_removeFile);
    Serial.println("doesn't exist.");
  }

  // delete the file:
  Serial.println("Removing...");
  SD.remove(_removeFile);

  // Check to see if the file exists:
  if (SD.exists(_removeFile)) {
    Serial.print(_removeFile);
    Serial.println(" exists.");
  } else {
    Serial.print(_removeFile);
    Serial.println("doesn't exist.");
  }

}

void printDirectory(File dir, int numTabs) {
  while (true) {

    File entry =  dir.openNextFile();
    if (! entry) {
      // no more files
      break;
    }
    for (uint8_t i = 0; i < numTabs; i++) {
      Serial.print('\t');
    }
    Serial.print(entry.name());
    if (entry.isDirectory()) {
      Serial.println("/");
      printDirectory(entry, numTabs + 1);
    } else {
      // files have sizes, directories do not
      Serial.print("\t\t");
      Serial.println(entry.size(), DEC);
    }
    entry.close();
  }
}




