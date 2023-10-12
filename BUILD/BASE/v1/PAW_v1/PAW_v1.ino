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
 
#include <DS3231.h>
#include <SPI.h>
#include <SD.h>

// Init the DS3231 using the hardware interface
DS3231  rtc(A4, A3);
File myFile;

int const sensor = A5; //hall effect sensor pin
int hallState; //numeric variable
int wheelcount = 0;

void setup()
{
  // Setup Serial connection
  Serial.begin(9600);

  //Initialize CSV file
  SD.begin(4); //microSD CS pin
  myFile = SD.open("wheel.csv", FILE_WRITE);
  myFile.println("Rotation, Date, Time");
  myFile.close();
  
  // Initialize the rtc object
  rtc.begin();
  
  // The following lines can be uncommented to set the date and time
  rtc.setTime(17, 30, 00);     // Set the time to hh:mm:ss (24hr format)
  rtc.setDate(21, 9, 2023);   // Set the date to dd, mm, yyyy

  pinMode(sensor, INPUT); //set hall effect sensor pin as input

  wheelcount = 0; //Initializes the wheel rotation count
}

void loop()
{
  int hallState = analogRead(sensor); //Read hall sensor
  if(hallState > 50) //when magnetic field is not detected
  {
    //do nothing
  }
  else //when magnetic field is detected, write to csv
  {
    wheelcount++; //add rotation count
    while(hallState < 51)
    {
      hallState = analogRead(sensor); //Read hall sensor
      //do nothing - prevents writing while stationary
    }
    //write to csv
    myFile = SD.open("WHEEL.csv", FILE_WRITE);
    myFile.print(wheelcount);
    myFile.print(",");
    myFile.print(rtc.getDateStr());
    myFile.print(",");
    myFile.println(rtc.getTimeStr());
    myFile.close();
    delay(500); //min time between rotations in ms
  }
  
  //using serial monitor to check build
  Serial.print("hallState: ");
  Serial.println(hallState);
}
