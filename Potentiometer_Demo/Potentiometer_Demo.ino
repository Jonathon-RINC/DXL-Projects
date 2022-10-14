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
int analogVal;


Dynamixel2Arduino dxl(DXL_SERIAL, DXL_DIR_PIN);

using namespace ControlTableItem;

void setup() {
  dxl.begin(57600);
  dxl.setPortProtocolVersion(DXL_PROTOCOL_VERSION);
  dxl.torqueOff(DXL_ID);
  
  DEBUG_SERIAL.begin(115200);
  //while(!DEBUG_SERIAL); 
}

void loop() {

  analogVal = analogRead(A6);


  if ( analogVal < 300 ) {
    dxl.setOperatingMode(DXL_ID, OP_POSITION);
    DEBUG_SERIAL.println("Position Mode");
    delay(1000);

    dxl.torqueOn(DXL_ID);
    while (true) {
      analogVal = analogRead(A6);
      int goal = map(analogVal,0 , 1024, 0, 4096);

      DEBUG_SERIAL.print("Goal Position: ");
      DEBUG_SERIAL.println(goal);
      dxl.setGoalPosition(DXL_ID, goal);
    }
  }
  else if ( analogVal > 700 ) {
    dxl.setOperatingMode(DXL_ID, 0);
    DEBUG_SERIAL.println("Current Mode");
    delay(1000);

    dxl.torqueOn(DXL_ID);
    while (true) {
      analogVal = analogRead(A6);
      int goal = map(analogVal,0 , 1024, -100, 100);

      DEBUG_SERIAL.print("Goal Velocity: ");
      DEBUG_SERIAL.print(goal);
      DEBUG_SERIAL.println("%");

      dxl.setGoalCurrent(DXL_ID, goal, UNIT_PERCENT);
    }
   }
  else {
    dxl.setOperatingMode(DXL_ID, OP_CURRENT_BASED_POSITION);
    DEBUG_SERIAL.println("Current Based Position Mode");
    delay(1000);

    while (true) {
      analogVal = analogRead(A6);
      int goal = map(analogVal,0 , 1024, 100, 0);

      dxl.setGoalPosition(DXL_ID, 2048);
    
      DEBUG_SERIAL.print("Goal Current: ");
      DEBUG_SERIAL.print(goal);
      DEBUG_SERIAL.println("%");
    
      dxl.setGoalCurrent(DXL_ID, goal, UNIT_PERCENT);
    }
 } 
}
