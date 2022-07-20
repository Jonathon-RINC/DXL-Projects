//ZENBOT 14-Servo Tongue Drum Player
//David Covarrubias
//fxmech@cammotion.net

#include <Dynamixel2Arduino.h>
#if defined(ARDUINO_AVR_UNO) || defined(ARDUINO_AVR_MEGA2560) // When using DynamixelShield
#include <SoftwareSerial.h>
SoftwareSerial soft_serial(7, 8); // DYNAMIXELShield UART RX/TX
#define DXL_SERIAL   Serial
#define DEBUG_SERIAL soft_serial
const uint8_t DXL_DIR_PIN = 2; // DYNAMIXEL Shield DIR PIN
#elif defined(ARDUINO_SAM_DUE) // When using DynamixelShield
#define DXL_SERIAL   Serial
#define DEBUG_SERIAL SerialUSB
const uint8_t DXL_DIR_PIN = 2; // DYNAMIXEL Shield DIR PIN
#elif defined(ARDUINO_SAM_ZERO) // When using DynamixelShield
#define DXL_SERIAL   Serial1
#define DEBUG_SERIAL SerialUSB
const uint8_t DXL_DIR_PIN = 2; // DYNAMIXEL Shield DIR PIN
#elif defined(ARDUINO_OpenCM904) // When using official ROBOTIS board with DXL circuit.
#define DXL_SERIAL   Serial3 //OpenCM9.04 EXP Board's DXL port Serial. (Serial1 for the DXL port on the OpenCM 9.04 board)
#define DEBUG_SERIAL Serial
const uint8_t DXL_DIR_PIN = 22; //OpenCM9.04 EXP Board's DIR PIN. (28 for the DXL port on the OpenCM 9.04 board)
#elif defined(ARDUINO_OpenCR) // When using official ROBOTIS board with DXL circuit.
#define DXL_SERIAL   Serial3
#define DEBUG_SERIAL Serial
const uint8_t DXL_DIR_PIN = 84; // OpenCR Board's DIR PIN.
#elif defined(ARDUINO_OpenRB)  // When using OpenRB-150
  //OpenRB does not require the DIR control pin.
  #define DXL_SERIAL Serial1
  #define DEBUG_SERIAL Serial
  const int DXL_DIR_PIN = -1;
#else // Other boards when using DynamixelShield
    #define DXL_SERIAL   Serial1
    #define DEBUG_SERIAL Serial
const uint8_t DXL_DIR_PIN = 2; // DYNAMIXEL Shield DIR PIN
#endif

const float DXL_PROTOCOL_VERSION = 2.0;

int malletRotateLowNote[8] = {0, 1975, 1975, 1975, 1975, 1975, 1975, 1997};//low octave
int malletRotateHighNote[8] = {0, 1776, 1776, 1795, 1730, 1753, 1800, 1731};//high octave
const int malletUp = 1625;
const int malletDown = 2121;
const int time2Move = 150; //millis that mallet spends dropping before it reverses direction

const uint8_t ringTime = 125; // time for note to ring. 125 is 1 sixtenth note at 2 measures per second

const char scale[17][7] ={           {'0', '0', '0', '0', '0', '0', '0'}, {'c', '0', '0', '0', '0', '0', '0'}, {'0', 'd', '0', '0', '0', '0', '0'}, {'0', '0', 'e', '0', '0', '0', '0'},
{'0', '0', '0', 'f', '0', '0', '0'}, {'0', '0', '0', '0', 'g', '0', '0'}, {'0', '0', '0', '0', '0', 'a', '0'}, {'0', '0', '0', '0', '0', '0', 'b'}, {'C', '0', '0', '0', '0', '0', '0'}, 
{'C', '0', '0', '0', '0', '0', '0'}, {'0', '0', '0', '0', '0', '0', 'b'}, {'0', '0', '0', '0', '0', 'a', '0'}, {'0', '0', '0', '0', 'g', '0', '0'}, {'0', '0', '0', 'f', '0', '0', '0'},
{'0', '0', 'e', '0', '0', '0', '0'}, {'0', 'd', '0', '0', '0', '0', '0'}, {'c', '0', '0', '0', '0', '0', '0'} };

Dynamixel2Arduino dxl(DXL_SERIAL, DXL_DIR_PIN);

//This namespace is required to use Control table item names
using namespace ControlTableItem;

void setup() {


  /* Use UART port of DYNAMIXEL Shield to debug.
  DEBUG_SERIAL.begin(115200);
  while(!DEBUG_SERIAL);
  DEBUG_SERIAL.println("START");
  */

  dxl.begin(1000000);
  // Set Port Protocol Version. This has to match with DYNAMIXEL protocol version.
  dxl.setPortProtocolVersion(DXL_PROTOCOL_VERSION);

delay(5000); // delay to allow me to plug in the actuators

  // Turn off torque when configuring items in EEPROM area
  for (int i = 1; i < 8; i++) {
    dxl.torqueOff(i);
    dxl.setOperatingMode(i, OP_POSITION);
    dxl.torqueOn(i);
    dxl.torqueOff(i + 10);
    dxl.setOperatingMode(i + 10, OP_POSITION);
    dxl.torqueOn(i + 10);
    delay(100);
  }

  // Limit the maximum velocity in Position Control Mode. Use 0 for Max speed
  for (int i = 1; i < 8; i++) {
    dxl.writeControlTableItem(PROFILE_VELOCITY, i, 0);
    dxl.writeControlTableItem(PROFILE_VELOCITY, i + 10, 0);
    dxl.writeControlTableItem(PROFILE_ACCELERATION, i, 0);
    dxl.writeControlTableItem(PROFILE_ACCELERATION, i + 10, 0);
    dxl.setGoalPosition(i, 2024);
    dxl.setGoalPosition(i + 10, 1750);
    delay(100);
  }
  delay(500);
}

void loop() {

for (int x = 0; x < 16; x++) {

for (int y = 1; y < 8; y++) {
if ( scale[x][y] != '0' ){
    dxl.setGoalPosition(y + 10, malletDown);
}
}
delay(time2Move);
for (int y = 1; y < 8; y++) {
    dxl.setGoalPosition(y + 10, malletUp);
}

for (int y = 1; y < 8; y++) {
if ( scale[x + 1][y] > 95 ){ //lowercase ASCI letters all have higher values than 95, this lets me quickly check which octave is needed for next note
    dxl.setGoalPosition(y, malletRotateHighNote[y] );
}
else {
    dxl.setGoalPosition(y, malletRotateLowNote[y] );
}

delay(50);

}

}
}
