/*******************************************************************************
* Copyright 2016 ROBOTIS CO., LTD.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

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
 

const float DXL_PROTOCOL_VERSION = 2.0;
const int Position[] = {0, -401, -815, -1246, -1645, -2058, -2441, -2841, -3229, -3648};
const int DXL_Hours[] = {1, 2};
const int DXL_Minutes[] = {3, 4};
const int DXL_Seconds[] = {5, 6};

Dynamixel2Arduino dxl(DXL_SERIAL, DXL_DIR_PIN);

//This namespace is required to use Control table item names
using namespace ControlTableItem;

void setup() {
  // put your setup code here, to run once:
  
  // Use UART port of DYNAMIXEL Shield to debug.
  DEBUG_SERIAL.begin(115200);
  while(!DEBUG_SERIAL);

  // Set Port baudrate to 57600bps. This has to match with DYNAMIXEL baudrate.
  dxl.begin(57600);
  // Set Port Protocol Version. This has to match with DYNAMIXEL protocol version.
  dxl.setPortProtocolVersion(DXL_PROTOCOL_VERSION);

  // Set correct position mode and enable torque
  for (int i = 0; i < 2; i++)
  {
  dxl.torqueOff(DXL_Hours[i]);
  dxl.setOperatingMode(DXL_Hours[i], OP_EXTENDED_POSITION);
  dxl.torqueOn(DXL_Hours[i]);
  dxl.writeControlTableItem(PROFILE_VELOCITY, DXL_Hours[i], 500);

  dxl.torqueOff(DXL_Minutes[i]);
  dxl.setOperatingMode(DXL_Minutes[i], OP_EXTENDED_POSITION);
  dxl.torqueOn(DXL_Minutes[i]);
  dxl.writeControlTableItem(PROFILE_VELOCITY, DXL_Minutes[i], 1000);

  dxl.torqueOff(DXL_Seconds[i]);
  dxl.setOperatingMode(DXL_Seconds[i], OP_EXTENDED_POSITION);
  dxl.torqueOn(DXL_Seconds[i]);
  dxl.writeControlTableItem(PROFILE_VELOCITY, DXL_Seconds[i], 0);
  }

}

void loop() {
  
  for (int i = 0; i < 10; i++)
  {
    dxl.setGoalPosition(DXL_Hours[0], Position[i]);
    dxl.setGoalPosition(DXL_Hours[1], Position[i]);
    dxl.setGoalPosition(DXL_Minutes[0], Position[i]);
    dxl.setGoalPosition(DXL_Minutes[1], Position[i]);
    dxl.setGoalPosition(DXL_Seconds[0], Position[i]);
    dxl.setGoalPosition(DXL_Seconds[1], Position[i]);
    DEBUG_SERIAL.print("Position ");
    DEBUG_SERIAL.println(Position[i]);
  delay(1000);
  }
}
