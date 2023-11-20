/*PAW
 * 
 * Printable Arduino-based Wheel logger
 * 
 * PAW was created by Dylan Terstege, a PhD candidate studying under the supervision of Dr Jonathan Epp
 * 
 * This file is part of PAW.
 * PAW is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 * PAW is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License along with Foobar. If not, see <https://www.gnu.org/licenses/>.

  This script is to be used to track the timing of wheel rotations in the running wheel projects
  The circuit:
    Hall Sensor (KY-003):
      1: GND
      2: 5V
      3: (s-side) pin A5
    RTC (DS3231):
      GND: GND
      VCC: 5V
      SDA: A4
      SCL: A3
    MicroSD Card Adapter:
      CS: pin 4
      SCK: pin 13
      MOSI: pin 11
      MISO: pin 12
      VCC: 5V
      GND: GND

      created  Aug 2020
      by Dylan J. Terstege
      Epp Lab
 */
 
// Packages to Include
#include <DS3231.h>                                       //load RTC packages
#include <SPI.h>                                          //load SD module packages
#include <SD.h>                                           //load SD module packages

// Init the DS3231 using the hardware interface
DS3231  rtc(A4, A3);                                      //defined RTC pins, init variable

// Init storage variables
int const sensor = A5;                                    //hall effect sensor pin
int hallState;                                            //numeric variable for hall field intensity
int wheelcount = 0;                                       //number of wheel rotations
char filename[] = "00000.CSV";                            //CSV file name, char vector
File myFile;                                              //variable for indexing into CSV file

// INITIAL CODE SETUP
void setup() {
  // Setup RTC
  rtc.begin();                                            //start the RTC
  rtc.setTime(23, 59, 30);                                //SET THE TIME TO HH:MM:SS (24hr format, no zero-padding)
  rtc.setDate(2, 9, 2023);                               //SET THE DATE TO DD, MM, YYYY (no zero-padding)
  
  //Write initial output file
  getFileName();                                          //assess date
  SD.begin(4);                                            //microSD CS pin
  myFile = SD.open(filename, FILE_WRITE);                 //open CSV file
  myFile.println("Rotation, Time");                 //column header init
  myFile.close();                                         //close CSV file

  Serial.begin(9600);
}

// MAIN CODE LOOP
void loop() {
  //temp
  Serial.print("filename: ");
  Serial.println(filename);

  // Reading Hall State
  int hallState = analogRead(sensor);                     //Read hall sensor
  if(hallState > 50)                                      //when magnetic field is not detected
  {
                                                          //do nothing, field is above threshold
  }
  else                                                    //when magnetic field is detected, write to csv
  {
    wheelcount++;                                         //add rotation count
    while(hallState < 51)                                 //field falls below threshold, init write procedures
    {
      hallState = analogRead(sensor);                     //Read hall sensor
                                                          //do nothing - prevents writing while stationary
    }
    // CSV Writing
    getFileName();                                        //potentially update current date, if new day
    
    // Check the Date
    if (SD.exists(filename)) {
                                                          //do nothing - file is already there
    } else {
      //New Day - Start New File                          //START A NEW CSV FILE
      myFile = SD.open(filename, FILE_WRITE);             //open CSV file
      myFile.println("Rotation, Time");             //column header init
      myFile.close();                                     //close CSV file
      wheelcount = 1;                                     //reset wheelcount
    }

    myFile = SD.open(filename, FILE_WRITE);               //open CSV file
    myFile.print(wheelcount);                             //number of rotations
    myFile.print(",");                                    //comma delineator
    myFile.println(rtc.getTimeStr());                     //print time of day
    myFile.close();                                       //close CSV file
    delay(500);                                           //min time between rotations in ms, users may choose to edit this
  }      
}


// FUNCTION FOR DATE RETRIEVAL
void getFileName() {
  //Current working CSV file name                         //CURRENT WORKING CSV FILE
  String monthtemp = rtc.getMonthStr(1);                  //current month
  String daytemp = rtc.getDateStr();                      //current date
  daytemp = daytemp.substring(0,2);                       //isolate date from string
  sprintf(filename, "%s%s.csv", monthtemp.c_str(), daytemp.c_str()); //combine strings
}
