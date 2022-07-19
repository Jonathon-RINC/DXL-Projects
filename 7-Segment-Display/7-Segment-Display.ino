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

const uint16_t waitTime = 5000;
const uint16_t onPosition = 3073;
const uint16_t offPosition = 2048;
 
char inputArr[50];

Dynamixel2Arduino Actuators(DXL_SERIAL, DXL_DIR_PIN);
using namespace ControlTableItem;


void setup() {
  DEBUG_SERIAL.begin(115200); //Start Debug serial
  while(!DEBUG_SERIAL)         //Wait until the serial port is opened with a 5 second timeout

  Actuators.begin(57600); //Set DXL Baudrate
  Actuators.setPortProtocolVersion(2.0);
}

void loop() {
  Actuators.torqueOn(11);
  Actuators.torqueOn(12);
  Actuators.torqueOn(13);
  Actuators.torqueOn(14);
  Actuators.torqueOn(15);
  Actuators.torqueOn(16);
  Actuators.torqueOn(17);

for (uint8_t i; i <= 50; i++) {
inputArr[i] = '#';
   }

    DEBUG_SERIAL.println("Input String:");
    while (DEBUG_SERIAL.available() == 0) {
      delay(500);
   }
   while (Serial.available() > 0) {
   String input = Serial.readString();    
    input.toCharArray(inputArr,50);
   Serial.read();//Empty the read buffer
   }

for (uint8_t i; i <= 50; i++) {

if( inputArr[i] == '#')
break;

    switch (inputArr[i]) {
        case '0':
  Actuators.setGoalPosition(11, onPosition);
  Actuators.setGoalPosition(12, onPosition);
  Actuators.setGoalPosition(13, onPosition);
  Actuators.setGoalPosition(14, onPosition);
  Actuators.setGoalPosition(15, onPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, onPosition);
  break;

        case '1':
  Actuators.setGoalPosition(11, offPosition);
  Actuators.setGoalPosition(12, onPosition);
  Actuators.setGoalPosition(13, onPosition);
  Actuators.setGoalPosition(14, offPosition);
  Actuators.setGoalPosition(15, offPosition);
  Actuators.setGoalPosition(16, offPosition);
  Actuators.setGoalPosition(17, offPosition);
  break;

        case '2':
  Actuators.setGoalPosition(11, onPosition);
  Actuators.setGoalPosition(12, onPosition);
  Actuators.setGoalPosition(13, offPosition);
  Actuators.setGoalPosition(14, onPosition);
  Actuators.setGoalPosition(15, onPosition);
  Actuators.setGoalPosition(16, offPosition);
  Actuators.setGoalPosition(17, onPosition);
  break;

        case '3':
  Actuators.setGoalPosition(11, onPosition);
  Actuators.setGoalPosition(12, onPosition);
  Actuators.setGoalPosition(13, onPosition);
  Actuators.setGoalPosition(14, onPosition);
  Actuators.setGoalPosition(15, offPosition);
  Actuators.setGoalPosition(16, offPosition);
  Actuators.setGoalPosition(17, onPosition);
  break;

        case '4':
  Actuators.setGoalPosition(11, offPosition);
  Actuators.setGoalPosition(12, onPosition);
  Actuators.setGoalPosition(13, onPosition);
  Actuators.setGoalPosition(14, offPosition);
  Actuators.setGoalPosition(15, offPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, onPosition);
  break;

        case '5':
  Actuators.setGoalPosition(11, onPosition);
  Actuators.setGoalPosition(12, offPosition);
  Actuators.setGoalPosition(13, onPosition);
  Actuators.setGoalPosition(14, onPosition);
  Actuators.setGoalPosition(15, offPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, onPosition);
  break;

        case '6':
  Actuators.setGoalPosition(11, onPosition);
  Actuators.setGoalPosition(12, offPosition);
  Actuators.setGoalPosition(13, onPosition);
  Actuators.setGoalPosition(14, onPosition);
  Actuators.setGoalPosition(15, onPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, onPosition);
  break;

        case '7':
  Actuators.setGoalPosition(11, onPosition);
  Actuators.setGoalPosition(12, onPosition);
  Actuators.setGoalPosition(13, onPosition);
  Actuators.setGoalPosition(14, offPosition);
  Actuators.setGoalPosition(15, offPosition);
  Actuators.setGoalPosition(16, offPosition);
  Actuators.setGoalPosition(17, offPosition);
  break;

        case '8':
  Actuators.setGoalPosition(11, onPosition);
  Actuators.setGoalPosition(12, onPosition);
  Actuators.setGoalPosition(13, onPosition);
  Actuators.setGoalPosition(14, onPosition);
  Actuators.setGoalPosition(15, onPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, onPosition);
  break;

        case '9':
  Actuators.setGoalPosition(11, onPosition);
  Actuators.setGoalPosition(12, onPosition);
  Actuators.setGoalPosition(13, onPosition);
  Actuators.setGoalPosition(14, offPosition);
  Actuators.setGoalPosition(15, offPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, onPosition);
  break;

        case 'A':
  Actuators.setGoalPosition(11, onPosition);
  Actuators.setGoalPosition(12, onPosition);
  Actuators.setGoalPosition(13, onPosition);
  Actuators.setGoalPosition(14, offPosition);
  Actuators.setGoalPosition(15, onPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, onPosition);
  break;

        case 'B':
  Actuators.setGoalPosition(11, offPosition);
  Actuators.setGoalPosition(12, offPosition);
  Actuators.setGoalPosition(13, onPosition);
  Actuators.setGoalPosition(14, onPosition);
  Actuators.setGoalPosition(15, onPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, onPosition);
  break;

        case 'C':
  Actuators.setGoalPosition(11, onPosition);
  Actuators.setGoalPosition(12, offPosition);
  Actuators.setGoalPosition(13, offPosition);
  Actuators.setGoalPosition(14, onPosition);
  Actuators.setGoalPosition(15, onPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, onPosition);
  break;

        case 'D':
  Actuators.setGoalPosition(11, offPosition);
  Actuators.setGoalPosition(12, onPosition);
  Actuators.setGoalPosition(13, onPosition);
  Actuators.setGoalPosition(14, onPosition);
  Actuators.setGoalPosition(15, onPosition);
  Actuators.setGoalPosition(16, offPosition);
  Actuators.setGoalPosition(17, onPosition);
  break;

        case 'E':
  Actuators.setGoalPosition(11, onPosition);
  Actuators.setGoalPosition(12, offPosition);
  Actuators.setGoalPosition(13, offPosition);
  Actuators.setGoalPosition(14, onPosition);
  Actuators.setGoalPosition(15, onPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, onPosition);
  break;

        case 'F':
  Actuators.setGoalPosition(11, onPosition);
  Actuators.setGoalPosition(12, offPosition);
  Actuators.setGoalPosition(13, offPosition);
  Actuators.setGoalPosition(14, offPosition);
  Actuators.setGoalPosition(15, onPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, onPosition);
  break;

        case 'G':
  Actuators.setGoalPosition(11, onPosition);
  Actuators.setGoalPosition(12, offPosition);
  Actuators.setGoalPosition(13, onPosition);
  Actuators.setGoalPosition(14, onPosition);
  Actuators.setGoalPosition(15, onPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, offPosition);
  break;

        case 'H':
  Actuators.setGoalPosition(11, offPosition);
  Actuators.setGoalPosition(12, offPosition);
  Actuators.setGoalPosition(13, onPosition);
  Actuators.setGoalPosition(14, offPosition);
  Actuators.setGoalPosition(15, onPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, onPosition);
  break;

        case 'I':
  Actuators.setGoalPosition(11, offPosition);
  Actuators.setGoalPosition(12, offPosition);
  Actuators.setGoalPosition(13, offPosition);
  Actuators.setGoalPosition(14, offPosition);
  Actuators.setGoalPosition(15, onPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, offPosition);
  break;

        case 'J':
  Actuators.setGoalPosition(11, offPosition);
  Actuators.setGoalPosition(12, onPosition);
  Actuators.setGoalPosition(13, onPosition);
  Actuators.setGoalPosition(14, onPosition);
  Actuators.setGoalPosition(15, offPosition);
  Actuators.setGoalPosition(16, offPosition);
  Actuators.setGoalPosition(17, offPosition);
  break;

        case 'K':
  Actuators.setGoalPosition(11, onPosition);
  Actuators.setGoalPosition(12, offPosition);
  Actuators.setGoalPosition(13, onPosition);
  Actuators.setGoalPosition(14, offPosition);
  Actuators.setGoalPosition(15, onPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, onPosition);
  break;

        case 'L':
  Actuators.setGoalPosition(11, offPosition);
  Actuators.setGoalPosition(12, offPosition);
  Actuators.setGoalPosition(13, offPosition);
  Actuators.setGoalPosition(14, onPosition);
  Actuators.setGoalPosition(15, onPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, onPosition);
  break;

        case 'M':
  Actuators.setGoalPosition(11, onPosition);
  Actuators.setGoalPosition(12, offPosition);
  Actuators.setGoalPosition(13, onPosition);
  Actuators.setGoalPosition(14, offPosition);
  Actuators.setGoalPosition(15, onPosition);
  Actuators.setGoalPosition(16, offPosition);
  Actuators.setGoalPosition(17, offPosition);
  break;

        case 'N':
  Actuators.setGoalPosition(11, onPosition);
  Actuators.setGoalPosition(12, onPosition);
  Actuators.setGoalPosition(13, onPosition);
  Actuators.setGoalPosition(14, offPosition);
  Actuators.setGoalPosition(15, onPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, offPosition);
  break;

        case 'O':
  Actuators.setGoalPosition(11, onPosition);
  Actuators.setGoalPosition(12, onPosition);
  Actuators.setGoalPosition(13, onPosition);
  Actuators.setGoalPosition(14, onPosition);
  Actuators.setGoalPosition(15, onPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, offPosition);
  break;

        case 'P':
  Actuators.setGoalPosition(11, onPosition);
  Actuators.setGoalPosition(12, onPosition);
  Actuators.setGoalPosition(13, offPosition);
  Actuators.setGoalPosition(14, offPosition);
  Actuators.setGoalPosition(15, onPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, onPosition);
  break;

        case 'Q':
  Actuators.setGoalPosition(11, onPosition);
  Actuators.setGoalPosition(12, onPosition);
  Actuators.setGoalPosition(13, onPosition);
  Actuators.setGoalPosition(14, offPosition);
  Actuators.setGoalPosition(15, offPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, onPosition);
  break;

        case 'R':
  Actuators.setGoalPosition(11, onPosition);
  Actuators.setGoalPosition(12, onPosition);
  Actuators.setGoalPosition(13, offPosition);
  Actuators.setGoalPosition(14, offPosition);
  Actuators.setGoalPosition(15, onPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, offPosition);
  break;

        case 'S':
  Actuators.setGoalPosition(11, onPosition);
  Actuators.setGoalPosition(12, offPosition);
  Actuators.setGoalPosition(13, onPosition);
  Actuators.setGoalPosition(14, onPosition);
  Actuators.setGoalPosition(15, offPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, onPosition);
  break;

        case 'T':
  Actuators.setGoalPosition(11, offPosition);
  Actuators.setGoalPosition(12, offPosition);
  Actuators.setGoalPosition(13, offPosition);
  Actuators.setGoalPosition(14, onPosition);
  Actuators.setGoalPosition(15, onPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, onPosition);
  break;

        case 'U':
  Actuators.setGoalPosition(11, offPosition);
  Actuators.setGoalPosition(12, onPosition);
  Actuators.setGoalPosition(13, onPosition);
  Actuators.setGoalPosition(14, onPosition);
  Actuators.setGoalPosition(15, onPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, offPosition);
  break;

        case 'V':
  Actuators.setGoalPosition(11, offPosition);
  Actuators.setGoalPosition(12, onPosition);
  Actuators.setGoalPosition(13, onPosition);
  Actuators.setGoalPosition(14, onPosition);
  Actuators.setGoalPosition(15, offPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, offPosition);
  break;

        case 'W':
  Actuators.setGoalPosition(11, offPosition);
  Actuators.setGoalPosition(12, onPosition);
  Actuators.setGoalPosition(13, offPosition);
  Actuators.setGoalPosition(14, onPosition);
  Actuators.setGoalPosition(15, offPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, offPosition);
  break;

        case 'X':
  Actuators.setGoalPosition(11, offPosition);
  Actuators.setGoalPosition(12, onPosition);
  Actuators.setGoalPosition(13, onPosition);
  Actuators.setGoalPosition(14, offPosition);
  Actuators.setGoalPosition(15, onPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, onPosition);
  break;

        case 'Y':
  Actuators.setGoalPosition(11, offPosition);
  Actuators.setGoalPosition(12, onPosition);
  Actuators.setGoalPosition(13, onPosition);
  Actuators.setGoalPosition(14, onPosition);
  Actuators.setGoalPosition(15, offPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, onPosition);
  break;

        case 'Z':
  Actuators.setGoalPosition(11, onPosition);
  Actuators.setGoalPosition(12, onPosition);
  Actuators.setGoalPosition(13, offPosition);
  Actuators.setGoalPosition(14, onPosition);
  Actuators.setGoalPosition(15, offPosition);
  Actuators.setGoalPosition(16, offPosition);
  Actuators.setGoalPosition(17, onPosition);
  break;
}

delay(waitTime);

}
}
