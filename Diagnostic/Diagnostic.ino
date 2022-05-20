#include <Dynamixel2Arduino.h>
#include "Diagnostic.h"
#include "Definitions.h"

#if defined(ARDUINO_OpenCR)
  pinMode(BDPIN_DXL_PWR_EN, OUTPUT);
  digitalWrite(BDPIN_DXL_PWR_EN, HIGH); 
#endif

const int32_t baud[5] = {57600, 115200, 1000000, 2000000, 3000000};

Dynamixel2Arduino dxl(DXL_SERIAL, DXL_DIR_PIN);

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
  unsigned long start = millis();
  while(!DEBUG_SERIAL)         //Wait until the serial port is opened with a 5 second timeout
  {
    if (millis() - start > 5000)
      break;
  }
    
  for(int8_t protocol = 2; protocol < 3; protocol++) {
    // Set Port Protocol Version. This has to match with DYNAMIXEL protocol version.
    dxl.setPortProtocolVersion((float)protocol);
    DEBUG_SERIAL.print("SCAN PROTOCOL ");
    DEBUG_SERIAL.println(protocol);
    
    for(index = 0; index < 5; index++) {
      // Set Port baudrate.
      DEBUG_SERIAL.print("SCAN BAUDRATE ");
      DEBUG_SERIAL.println(baud[index]);
      dxl.begin(baud[index]);
      for(int id = 0; id < DXL_BROADCAST_ID; id++) {
        //iterate until all ID in each baudrate is scanned.
        if(dxl.ping(id)) {
          DEBUG_SERIAL.print("ID ");
          DEBUG_SERIAL.println(id);

        //After finding a DYNAMIXEL, write all of it's needed information to the object array
        connected[found_dynamixel].setAll( protocol, baud[index], id);


          found_dynamixel++;
        }
      }
    }
  }
  
  DEBUG_SERIAL.print(found_dynamixel);
  DEBUG_SERIAL.println(" DYNAMIXEL(s) found!");

    if (!DEBUG_SERIAL)
    Diagnostic::testAutomated(connected, dxl);
      



}

void loop() {

Diagnostic::listAll(connected);

int choice = -1;
choice = int(selection("Please select the servo you would like to test"));

   while(Diagnostic::getActive() > Diagnostic::getCount() || Diagnostic::getActive() < 0) {
        DEBUG_SERIAL.println("Please Choose a valid option.");
        Diagnostic::listAll(connected);
        delay(1000);
        choice = selection("Please select the servo you would like to test");
   };
   
   //Save the chosen servo as active, then clear the choice
   Diagnostic::setActive(choice); 
   Diagnostic::listActive(connected);

    Diagnostic::testPosition(connected, dxl);
    Diagnostic::testVelocity(connected, dxl);
    Diagnostic::testEXPosition(connected, dxl);
    Diagnostic::testCompliance(connected, dxl);

}
