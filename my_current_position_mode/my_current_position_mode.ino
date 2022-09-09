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
 
  dxl.torqueOff(DXL_ID);
  dxl.setOperatingMode(DXL_ID, OP_CURRENT_BASED_POSITION);
  dxl.torqueOn(DXL_ID);
}

void loop() {

   delay(5000);

for (int i; true; i++) {
  int current = i*2;

  dxl.setGoalPosition(DXL_ID, dxl.getPresentPosition(DXL_ID));
  dxl.setGoalCurrent(DXL_ID, current, UNIT_PERCENT);
  DEBUG_SERIAL.print("Current Based Position Mode: ");
  DEBUG_SERIAL.print( current );
  DEBUG_SERIAL.println("%");
  delay(5000);

  dxl.torqueOff(DXL_ID);
  delay(500);
  dxl.setOperatingMode(DXL_ID, OP_CURRENT);
  dxl.torqueOn(DXL_ID);
  dxl.setGoalCurrent(DXL_ID, current, UNIT_PERCENT);
  
  DEBUG_SERIAL.print("Current Mode: ");
  DEBUG_SERIAL.print( current );
  DEBUG_SERIAL.println("%");
  delay(5000);

  dxl.torqueOff(DXL_ID);
  dxl.setOperatingMode(DXL_ID, OP_CURRENT_BASED_POSITION);
  dxl.torqueOn(DXL_ID);
  }
}
