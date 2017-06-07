#include <SPI.h>
#include <SD.h>
int val=0;
const int chipSelect = 4;

void setup() 
{
 
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.print("Initializing SD card...");

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  Serial.println("card initialized.");
}

void loop() {
   {

  val=1024-analogRead(A0);

  delay(60000); 
  }
  // make a string for assembling the data to log:
  String dataString = "";
  // read three sensors and append to the string:
    int analogPin = A0; {
    int sensor = analogRead(analogPin);
    dataString += 1024-analogRead(A0);{
    dataString += " ";
    }
  }
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File dataFile = SD.open("datalog.txt", FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
    // print to the serial port too:
    Serial.println(dataString);
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  }
}
