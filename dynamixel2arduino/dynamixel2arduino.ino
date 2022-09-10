#include <Dynamixel2Arduino.h>

#if defined(ARDUINO_AVR_UNO) || defined(ARDUINO_AVR_MEGA2560)
  #include <SoftwareSerial.h>
  SoftwareSerial soft_serial(7, 8);
  #define DXL_SERIAL   Serial
  #define DEBUG_SERIAL soft_serial
  const int DXL_DIR_PIN = 2;
#elif defined(ARDUINO_SAM_DUE)
  #define DXL_SERIAL   Serial
  #define DEBUG_SERIAL SerialUSB
  const int DXL_DIR_PIN = 2;
#elif defined(ARDUINO_SAM_ZERO)
  #define DXL_SERIAL   Serial1
  #define DEBUG_SERIAL SerialUSB
  const int DXL_DIR_PIN = 2;
#elif defined(ARDUINO_OpenCM904)
  #define DXL_SERIAL   Serial3 
  #define DEBUG_SERIAL Serial
  const int DXL_DIR_PIN = 22; 
#elif defined(ARDUINO_OpenCR)
  #define DXL_SERIAL   Serial3
  #define DEBUG_SERIAL Serial
  const int DXL_DIR_PIN = 84;
#elif defined(ARDUINO_OpenRB)
  #define DXL_SERIAL Serial1
  #define DEBUG_SERIAL Serial
  const int DXL_DIR_PIN = -1;
#else
  #define DXL_SERIAL   Serial1
  #define DEBUG_SERIAL Serial
  const int DXL_DIR_PIN = 2;
#endif
 

const uint8_t DXL_ID = 1;
const float DXL_PROTOCOL_VERSION = 2.0;

Dynamixel2Arduino dxl(DXL_SERIAL, DXL_DIR_PIN);

using namespace ControlTableItem;

void setup() {
  
  DEBUG_SERIAL.begin(115200);
  while(!DEBUG_SERIAL);  
  
  dxl.begin(57600);
  dxl.setPortProtocolVersion(DXL_PROTOCOL_VERSION);

}

void loop() {
  
  DEBUG_SERIAL.print("Current Port Baudrate:");
  DEBUG_SERIAL.println(dxl.getPortBaud());

  DEBUG_SERIAL.print("DYNAMIXEL Model Number:");
  DEBUG_SERIAL.println(dxl.getModelNumber(1));
  
  if( dxl.ping(DXL_ID) ) {
    DEBUG_SERIAL.print("DYNAMIXEL ");
    DEBUG_SERIAL.print(DXL_ID);
    DEBUG_SERIAL.println(" Found");
  } 
  else {
    DEBUG_SERIAL.print("DYNAMIXEL ");
    DEBUG_SERIAL.print(DXL_ID);
    DEBUG_SERIAL.println(" Not Found");
  }  
  
  if( dxl.scan() ) {
    DEBUG_SERIAL.print("DYNAMIXEL Scan Successful");
  } 
  else {
    DEBUG_SERIAL.print("DYNAMIXEL Scan Failed");
  }

  dxl.setID(DXL_ID, 2);
  
  if( dxl.ping(2) ) {
    DEBUG_SERIAL.print("DYNAMIXEL ");
    DEBUG_SERIAL.print(2);
    DEBUG_SERIAL.println(" Found");
  } 
  else {
    DEBUG_SERIAL.print("DYNAMIXEL ");
    DEBUG_SERIAL.print(2);
    DEBUG_SERIAL.println(" Not Found");
  }  
  
  if( dxl.scan() ) {
    DEBUG_SERIAL.print("DYNAMIXEL Scan Successful");
  } 
  else {
    DEBUG_SERIAL.print("DYNAMIXEL Scan Failed");
  }

  dxl.setProtocol(2, 1.0);
  DEBUG_SERIAL.println("DYNAMIXEL Protocol Mode Set to 1.0");

    if( dxl.scan() ) {
    DEBUG_SERIAL.print("DYNAMIXEL Scan Successful");
  } 
  else {
    DEBUG_SERIAL.print("DYNAMIXEL Scan Failed");
  }

  dxl.setProtocol(2, 2.0);
  DEBUG_SERIAL.println("DYNAMIXEL Protocol Mode Set to 2.0");

  dxl.ledOn();
  DEBUG_SERIAL.println("LED On");
  delay(1000);
  dxl.ledOff();
  DEBUG_SERIAL.println("LED Off");
  
  dxl.setOperatingMode(2, OP_VELOCITY);
  DEBUG_SERIAL.println("Operating Mode Set to Velocity Mode");
  dxl.setGoalVelocity(2, 50, UNIT_PERCENT);
  DEBUG_SERIAL.println("Set 50% Goal Velocity");
  delay(1000);

  dxl.torqueOn(2);
  DEBUG_SERIAL.println("Torque Enabled");
  dxl.setGoalVelocity(2, 50, UNIT_PERCENT);
  DEBUG_SERIAL.println("Set 50% Goal Velocity");
  delay(1000);
  DEBUG_SERIAL.print("Current Velocity: ");
  DEBUG_SERIAL.println(dxl.getPresentVelocity(2));
  delay(2000);
  

  dxl.setOperatingMode(2, OP_POSITION);
  DEBUG_SERIAL.println("Operating Mode Set to Position Mode Mode");
  dxl.setGoalPosition(2, 0, UNIT_DEGREE);
  DEBUG_SERIAL.println("Set Goal Position to 0 Degrees");
  delay(1000);

  dxl.torqueOff(2);
  DEBUG_SERIAL.println("Torque Disabled");
  dxl.torqueOn(2);
  DEBUG_SERIAL.println("Torque Enabled");
  dxl.setOperatingMode(2, OP_POSITION);
  DEBUG_SERIAL.println("Operating Mode Set to Position Mode Mode");
  dxl.setGoalPosition(2, 90, UNIT_DEGREE);
  DEBUG_SERIAL.println("Set Goal Position to 90 Degrees");
  delay(3000);

  DEBUG_SERIAL.print("Current Absolute DYNAMIXEL Position:");
  DEBUG_SERIAL.println(dxl.getPresentPosition(2));
  DEBUG_SERIAL.print("Current Degree DYNAMIXEL Position:");
  DEBUG_SERIAL.println(dxl.getPresentPosition(2, UNIT_DEGREE);
  delay(1000);
  

setGoalPWM()
getPresentPWM()
setGoalCurrent()
getPresentCurrent()
getTorqueEnableStat()
readControlTableItem()
writeControlTableItem()




}

//setBaudrate()  
