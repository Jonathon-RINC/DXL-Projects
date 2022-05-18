/*******************************************************************************
* Copyright 2016 ROBOTIS CO., LTD.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#include <Dynamixel2Arduino.h>
#include "Diagnostic.h"
#include "Definitions.h"

#if defined(ARDUINO_OpenCR)
  pinMode(BDPIN_DXL_PWR_EN, OUTPUT);
  digitalWrite(BDPIN_DXL_PWR_EN, HIGH); 
#endif

const int32_t baud[] = {57600, 115200, 1000000, 2000000, 3000000};

Dynamixel2Arduino Actuators(DXL_SERIAL, DXL_DIR_PIN);

//This namespace is required to use Control table item names
using namespace ControlTableItem;

//Create the array that will hold any detected DYNAMIXELs. 253 is the maximum of unique DYNAMIXEL IDs able to be connected at once. Smaller arrays are fine as well.
Diagnostic connected[253];

void setup() {

  // put your setup code here, to run once:
  int8_t index = 0;
  int8_t found_dynamixel = 0;


  // Use UART port of DYNAMIXEL Shield to debug.
  DEBUG_SERIAL.begin(115200);   //set debugging port baudrate to 115200bps
  while(!DEBUG_SERIAL);         //Wait until the serial port is opened
    
  for(int8_t protocol = 1; protocol < 3; protocol++) {
    // Set Port Protocol Version. This has to match with DYNAMIXEL protocol version.
    Actuators.setPortProtocolVersion((float)protocol);
    DEBUG_SERIAL.print("SCAN PROTOCOL ");
    DEBUG_SERIAL.println(protocol);
    
    for(index = 0; index < 5; index++) {
      // Set Port baudrate.
      DEBUG_SERIAL.print("SCAN BAUDRATE ");
      DEBUG_SERIAL.println(baud[index]);
      Actuators.begin(baud[index]);
      for(int id = 0; id < DXL_BROADCAST_ID; id++) {
        //iterate until all IDs and baudradtes have been scanned
        if(Actuators.ping(id)) {
          DEBUG_SERIAL.print("ID : ");
          DEBUG_SERIAL.print(id);
          DEBUG_SERIAL.print(", Model Number: ");
          DEBUG_SERIAL.println(Actuators.getModelNumber(id));

        //After finding a DYNAMIXEL, write all of it's needed information to the object array
        connected[found_dynamixel].setAll( protocol, baud[index], id, Actuators.getModelNumber(id));


          found_dynamixel++;
        }
      }
    }
  }
  
  DEBUG_SERIAL.print(found_dynamixel);
  DEBUG_SERIAL.println(" DYNAMIXEL(s) found!");


Diagnostic::listAll(connected);


}

void loop() {
int choice = -1;
choice = int(selection("Please select the servo you would like to test"));

   while(Diagnostic::getActive() > Diagnostic::getCount() || Diagnostic::getActive() < 0) {
        DEBUG_SERIAL.println("Please Choose a valid option.");
        delay(1000);
        Diagnostic::listAll(connected);
        choice = selection("Please select the servo you would like to test");
   };
   
   //Save the chosen servo as active, then clear the choice
   Diagnostic::setActive(choice); 
   Diagnostic::listActive(connected);


  DEBUG_SERIAL.println("1) Positon Control");
choice = int(selection("Please select the test you would like to perform:"));

switch (choice){
case 1:
Diagnostic::testPosition(connected, Actuators);
}




}

