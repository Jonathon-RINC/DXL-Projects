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
#else // Other boards when using DynamixelShield
  #define DXL_SERIAL   Serial1
  #define DEBUG_SERIAL Serial
  const uint8_t DXL_DIR_PIN = 2; // DYNAMIXEL Shield DIR PIN
#endif
 
Dynamixel2Arduino Actuators(DXL_SERIAL, DXL_DIR_PIN);
using namespace ControlTableItem;

const int Position[] = {0, -401, -815, -1246, -1645, -2058, -2441, -2841, -3229, -3648};
const int DXL_Hours[] = {1, 2};
const int DXL_Minutes[] = {3, 4};
const int DXL_Seconds[] = {5, 6};

int Hours[] = {0, 0, 0};
int Minutes[] = {0, 0, 0};
int Seconds[]= {0, 0, 0};

void setup() {
  
  DEBUG_SERIAL.begin(115200); //Start Debug serial
  while(!DEBUG_SERIAL); //Hold for debug serial

  Actuators.begin(57600); //Set DXL Baudrate
  Actuators.setPortProtocolVersion(2.0);

  for (int i = 0; i < 2; i++)
  {
  Actuators.torqueOff(DXL_Hours[i]);
  Actuators.setOperatingMode(DXL_Hours[i], OP_EXTENDED_POSITION);
  Actuators.torqueOn(DXL_Hours[i]);
  Actuators.writeControlTableItem(PROFILE_VELOCITY, DXL_Hours[i], 500);

  Actuators.torqueOff(DXL_Minutes[i]);
  Actuators.setOperatingMode(DXL_Minutes[i], OP_EXTENDED_POSITION);
  Actuators.torqueOn(DXL_Minutes[i]);
  Actuators.writeControlTableItem(PROFILE_VELOCITY, DXL_Minutes[i], 1000);

  Actuators.torqueOff(DXL_Seconds[i]);
  Actuators.setOperatingMode(DXL_Seconds[i], OP_EXTENDED_POSITION);
  Actuators.torqueOn(DXL_Seconds[i]);
  Actuators.writeControlTableItem(PROFILE_VELOCITY, DXL_Seconds[i], 0);
  }

}

void loop() {


//Set time randomly for testing
Hours[0] = random(24);
Minutes[0] = random(60);
Seconds[0]= random(60);
  
//Divide by 10 to get 10s place
Hours[1] = Hours[0]/10;
Minutes[1] = Minutes[0]/10;
Seconds[1]= Seconds[0]/10;

//Modulus 10 to get 1s place
Hours[2] = Hours[0]%10;
Minutes[2] = Minutes[0]%10;
Seconds[2]= Seconds[0]%10;

DEBUG_SERIAL.print(Hours[1]);
DEBUG_SERIAL.print(Hours[2]);
DEBUG_SERIAL.print(":");
DEBUG_SERIAL.print(Minutes[1]);
DEBUG_SERIAL.print(Minutes[2]);
DEBUG_SERIAL.print(":");
DEBUG_SERIAL.print(Seconds[1]);
DEBUG_SERIAL.println(Seconds[2]);
    
Actuators.setGoalPosition(DXL_Hours[0], Position[Hours[1]]);
Actuators.setGoalPosition(DXL_Hours[1], Position[Hours[2]]);
Actuators.setGoalPosition(DXL_Minutes[0], Position[Minutes[1]]);
Actuators.setGoalPosition(DXL_Minutes[1], Position[Minutes[2]]);
Actuators.setGoalPosition(DXL_Seconds[0], Position[Seconds[1]]);
Actuators.setGoalPosition(DXL_Seconds[1], Position[Seconds[2]]);

delay(5000);
}
