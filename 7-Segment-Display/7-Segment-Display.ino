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
  // For OpenCR, there is a DXL Power Enable pin, so you must initialize and control it.
  // Reference link : https://github.com/ROBOTIS-GIT/OpenCR/blob/master/arduino/opencr_arduino/opencr/libraries/DynamixelSDK/src/dynamixel_sdk/port_handler_arduino.cpp#L78
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
  const uint8_t DXL_DIR_PIN = A6; // Arduino MKR Direction pin
#endif

bool DEBUG = true;

const int onPosition = 3073;
const int offPosition = 2048;
 
Dynamixel2Arduino Actuators(DXL_SERIAL, DXL_DIR_PIN);
using namespace ControlTableItem;


void setup() {
  DEBUG_SERIAL.begin(115200); //Start Debug serial

  unsigned long start = millis();
  while(!DEBUG_SERIAL)         //Wait until the serial port is opened with a 5 second timeout
  {
    if (millis() - start > 5000){
    DEBUG = false;
      break;
      }
  }
    if (DEBUG)
    DEBUG_SERIAL.println("START");

  Actuators.begin(57600); //Set DXL Baudrate
  Actuators.setPortProtocolVersion(2.0);

  

}

void loop() {

for( uint8_t i = 1; i <= 7; i++) {
  Actuators.torqueOn(i + 10);
}

if (DEBUG)
DEBUG_SERIAL.println("0");

  Actuators.setGoalPosition(11, offPosition);
  Actuators.setGoalPosition(12, offPosition);
  Actuators.setGoalPosition(13, offPosition);
  Actuators.setGoalPosition(14, offPosition);
  Actuators.setGoalPosition(15, offPosition);
  Actuators.setGoalPosition(16, offPosition);
  Actuators.setGoalPosition(17, offPosition);

delay(5000);

if (DEBUG)
DEBUG_SERIAL.println("1");

  Actuators.setGoalPosition(11, onPosition);
  Actuators.setGoalPosition(12, offPosition);
  Actuators.setGoalPosition(13, offPosition);
  Actuators.setGoalPosition(14, onPosition);
  Actuators.setGoalPosition(15, onPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, onPosition);

delay(5000);

if (DEBUG)
DEBUG_SERIAL.println("2");

  Actuators.setGoalPosition(11, onPosition);
  Actuators.setGoalPosition(12, onPosition);
  Actuators.setGoalPosition(13, offPosition);
  Actuators.setGoalPosition(14, onPosition);
  Actuators.setGoalPosition(15, onPosition);
  Actuators.setGoalPosition(16, offPosition);
  Actuators.setGoalPosition(17, onPosition);

delay(5000);

}

