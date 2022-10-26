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

int incoming;
bool grip = false;

Dynamixel2Arduino dxl(DXL_SERIAL, DXL_DIR_PIN);

using namespace ControlTableItem;

void setup() {
  
  DEBUG_SERIAL.begin(115200);  
  
  dxl.begin(57600);
  dxl.setPortProtocolVersion(DXL_PROTOCOL_VERSION);

  dxl.torqueOff(254);
  dxl.setOperatingMode(254, OP_POSITION);
  dxl.writeControlTableItem(VELOCITY_LIMIT, 254, 0);

  dxl.writeControlTableItem(MAX_POSITION_LIMIT, 2, 3000);
  dxl.writeControlTableItem(MIN_POSITION_LIMIT, 2, 1000);

  dxl.writeControlTableItem(MAX_POSITION_LIMIT, 3, 3200);
  dxl.writeControlTableItem(MIN_POSITION_LIMIT, 3, 1600);

  dxl.writeControlTableItem(MAX_POSITION_LIMIT, 4, 3100);
  dxl.writeControlTableItem(MIN_POSITION_LIMIT, 4, 900);

  dxl.writeControlTableItem(MAX_POSITION_LIMIT, 5, 3000);
  dxl.writeControlTableItem(MIN_POSITION_LIMIT, 5, 2000);

  startPose();

  DEBUG_SERIAL.println("e to extend/retract, r to rotate, ");

}

void loop() {

rotation(analogRead(A0));

elevation(analogRead(A1));

extension(analogRead(A2));

angle(analogRead(A3));
  
}

void startPose() {

  DEBUG_SERIAL.println("Moving to Start Position");
  
  dxl.torqueOn(254);

  dxl.setGoalPosition(1, 1024);
  dxl.setGoalPosition(2, 3000);
  dxl.setGoalPosition(3, 1700);
  dxl.setGoalPosition(4, 3000);
  
  dxl.setGoalPosition(5, 2900);
  grip = false;
  
}

void rotation(int direction) {

  int magnitude = map(direction, 0, 1024, -200, 200);

  if ( direction <  700 && direction > 400) {
    magnitude = 0;
    return;
  }

  int newGoal = dxl.getPresentPosition(1) + (magnitude);
  dxl.setGoalPosition(1, newGoal);

}

void elevation(int direction) {

  int magnitude = map(direction, 0, 1024, 200, -200);

  if ( direction <  700 && direction > 400) {
    magnitude = 0;
    return;
  }

  int newGoal = dxl.getPresentPosition(2) + (magnitude);
  dxl.setGoalPosition(2, newGoal);

}

void extension(int direction) {

  int magnitude = map(direction, 0, 1024, 200, -200);

  if ( direction <  700 && direction > 400) {
    magnitude = 0;
    return;
  }

  int newGoal = dxl.getPresentPosition(3) + (magnitude);
  dxl.setGoalPosition(3, newGoal);

}

void angle(int direction) {

  int magnitude = map(direction, 0, 1024, 200, -200);

  if ( direction <  700 && direction > 400) {
    magnitude = 0;
    return;
  }

  int newGoal = dxl.getPresentPosition(4) + (magnitude);
  dxl.setGoalPosition(4, newGoal);

}

void gripper() {
  DEBUG_SERIAL.println(grip);

  if (grip) {
   dxl.setGoalPosition(5, 2900);
   grip = false;
    }
  else if (!grip) {
   dxl.setGoalPosition(5, 2100);
   grip = true;
    }

}
