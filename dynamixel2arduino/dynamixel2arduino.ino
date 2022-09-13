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
  
  DEBUG_SERIAL.print("Present Port Baudrate: ");
  DEBUG_SERIAL.println(dxl.getPortBaud());

  DEBUG_SERIAL.print("DYNAMIXEL Model Number: ");
  DEBUG_SERIAL.println(dxl.getModelNumber(DXL_ID));
  
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
    DEBUG_SERIAL.println("DYNAMIXEL Scan Successful");
  } 
  else {
    DEBUG_SERIAL.println("DYNAMIXEL Scan Failed");
  }

  delay(2000);

  dxl.setID(DXL_ID, 2);
  DEBUG_SERIAL.println("DYNAMIXEL ID Set to 2");
  
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
    DEBUG_SERIAL.println("DYNAMIXEL Scan Successful");
  } 
  else {
    DEBUG_SERIAL.println("DYNAMIXEL Scan Failed");
  }
  dxl.setID(2, DXL_ID);
  DEBUG_SERIAL.println("DYNAMIXEL ID Set to 1");
  delay(5000);

  dxl.ledOn(DXL_ID);
  DEBUG_SERIAL.println("LED On");
  delay(2000);
  dxl.ledOff(DXL_ID);
  DEBUG_SERIAL.println("LED Off");
  
  if( dxl.setOperatingMode(DXL_ID, OP_VELOCITY) ) {
  DEBUG_SERIAL.println("Operating Mode Set to Velocity Mode");
  delay(1000);
  dxl.setGoalVelocity(DXL_ID, 100, UNIT_PERCENT);
  DEBUG_SERIAL.println("Set 100% Goal Velocity");
  delay(1000);
   }
   else {
    DEBUG_SERIAL.println("Could Not Change to Velocity Mode");
  }

  dxl.torqueOn(DXL_ID);
  DEBUG_SERIAL.println("Torque Enabled");
  delay(1000);
  dxl.setGoalVelocity(DXL_ID, 50, UNIT_PERCENT);
  DEBUG_SERIAL.println("Set 50% Goal Velocity");
  delay(1000);
  DEBUG_SERIAL.print("Present Velocity: ");
  DEBUG_SERIAL.print(dxl.getPresentVelocity(DXL_ID, UNIT_RPM));
  DEBUG_SERIAL.println("RPM");
  delay(2000);

  dxl.setOperatingMode(DXL_ID, OP_POSITION);
  DEBUG_SERIAL.println("Operating Mode Set to Position Mode");
  dxl.setGoalPosition(DXL_ID, 0, UNIT_DEGREE);
  DEBUG_SERIAL.println("Set Goal Position to 0 Degrees");
  delay(1000);

  dxl.torqueOff(DXL_ID);
  DEBUG_SERIAL.println("Torque Disabled");
  dxl.torqueOn(DXL_ID);
  DEBUG_SERIAL.println("Torque Enabled");
  dxl.setOperatingMode(DXL_ID, OP_POSITION);
  DEBUG_SERIAL.println("Operating Mode Set to Position Mode");
  dxl.setGoalPosition(DXL_ID, 90, UNIT_DEGREE);
  DEBUG_SERIAL.println("Set Goal Position to 90 Degrees");
  delay(3000);

  DEBUG_SERIAL.print("Present Absolute DYNAMIXEL Position:");
  DEBUG_SERIAL.println(dxl.getPresentPosition(DXL_ID));
  DEBUG_SERIAL.print("Present Degree DYNAMIXEL Position:");
  DEBUG_SERIAL.println(dxl.getPresentPosition(DXL_ID, UNIT_DEGREE));
  delay(1000);

  dxl.torqueOff(DXL_ID);
  DEBUG_SERIAL.println("Torque Disabled");
  dxl.torqueOn(DXL_ID);
  DEBUG_SERIAL.println("Torque Enabled");
  dxl.setOperatingMode(DXL_ID, OP_CURRENT);
  DEBUG_SERIAL.println("Operating Mode Set to Present Mode");
  dxl.setGoalCurrent(DXL_ID, 20);
  DEBUG_SERIAL.println("Set Goal Present to 20 DYNAMIXEL Units");
  delay(1000);
  DEBUG_SERIAL.print("Present Velocity: ");
  DEBUG_SERIAL.print(dxl.getPresentVelocity(DXL_ID, UNIT_PERCENT));
  DEBUG_SERIAL.println("%");
  DEBUG_SERIAL.print("Present Current: ");
  DEBUG_SERIAL.print(dxl.getPresentCurrent(DXL_ID, UNIT_MILLI_AMPERE));
  DEBUG_SERIAL.println("mA");
  delay(2000);

  dxl.torqueOff(DXL_ID);
  DEBUG_SERIAL.println("Torque Disabled");
  dxl.torqueOn(DXL_ID);
  DEBUG_SERIAL.println("Torque Enabled");
  dxl.setOperatingMode(DXL_ID, OP_PWM);
  DEBUG_SERIAL.println("Operating Mode Set to PWM Mode");
  dxl.setGoalPWM(DXL_ID, 100);
  DEBUG_SERIAL.println("Set Goal PWM to 100 DYNAMIXEL Units");
  delay(1000);
  DEBUG_SERIAL.print("Present PWM: ");
  DEBUG_SERIAL.print(dxl.getPresentVelocity(DXL_ID, UNIT_PERCENT));
  DEBUG_SERIAL.println("%");
  DEBUG_SERIAL.print("Present Current: ");
  DEBUG_SERIAL.print(dxl.getPresentCurrent(DXL_ID, UNIT_PERCENT));
  DEBUG_SERIAL.println("%");
  delay(2000);
  dxl.setGoalPWM(DXL_ID, -100);
  DEBUG_SERIAL.println("Set Goal PWM to -100 DYNAMIXEL Units");
  delay(1000);
  DEBUG_SERIAL.print("Present PWM: ");
  DEBUG_SERIAL.print(dxl.getPresentVelocity(DXL_ID, UNIT_PERCENT));
  DEBUG_SERIAL.println("%");
  DEBUG_SERIAL.print("Present Current: ");
  DEBUG_SERIAL.print(dxl.getPresentCurrent(DXL_ID, UNIT_PERCENT));
  DEBUG_SERIAL.println("%");
  delay(2000);

  if( dxl.getTorqueEnableStat(DXL_ID) ) {
    DEBUG_SERIAL.print("DYNAMIXEL Torque On");
  } 
  else {
    DEBUG_SERIAL.print("DYNAMIXEL Torque Off");
  }
  delay(1000);
  dxl.torqueOff(DXL_ID);
  if( dxl.getTorqueEnableStat(DXL_ID) ) {
    DEBUG_SERIAL.print("DYNAMIXEL Torque On");
  } 
  else {
    DEBUG_SERIAL.print("DYNAMIXEL Torque Off");
  }

  dxl.writeControlTableItem(OPERATING_MODE, DXL_ID, 3);
  dxl.writeControlTableItem(TORQUE_ENABLE, DXL_ID, 1);
  dxl.writeControlTableItem(116, DXL_ID, 0);
  delay(2000);
  
  dxl.readControlTableItem(GOAL_POSITION, DXL_ID);

}
