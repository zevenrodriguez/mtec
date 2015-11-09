
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

File myFile;

File root;

String openFile = "testing.txt";


void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.print("Initializing SD card...");

  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  removeFile(openFile);
  delay(10);
  createFile(openFile);
  delay(10);


  root = SD.open("/");

  printDirectory(root, 0);

  for(int i = 0; i<10; i++){
  writeFile(String(i), openFile);
  delay(10);
  }
  readFile(openFile);

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
  if (SD.exists(_removeFile)){
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




