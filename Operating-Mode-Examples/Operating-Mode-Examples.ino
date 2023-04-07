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
#define DXL_SERIAL Serial1
#define DEBUG_SERIAL Serial
const int DXL_DIR_PIN = -1;


const uint8_t DXL = 1;
const float DXL_PROTOCOL_VERSION = 2.0;

Dynamixel2Arduino dxl(DXL_SERIAL, DXL_DIR_PIN);

//This namespace is required to use Control table item names
using namespace ControlTableItem;

void setup() {
  // put your setup code here, to run once:

  // Use UART port of DYNAMIXEL Shield to debug.
  DEBUG_SERIAL.begin(115200);
  while (!DEBUG_SERIAL)
    ;

  dxl.begin(57600);
  dxl.setPortProtocolVersion(DXL_PROTOCOL_VERSION);
  dxl.torqueOff(DXL);

  DEBUG_SERIAL.println("Setting default control table values...");
  dxl.writeControlTableItem(MIN_POSITION_LIMIT, DXL, 0);
  dxl.writeControlTableItem(MAX_POSITION_LIMIT, DXL, 4095);
  dxl.writeControlTableItem(PROFILE_VELOCITY, DXL, 0);
  dxl.writeControlTableItem(VELOCITY_LIMIT, DXL, 2047);
  dxl.writeControlTableItem(CURRENT_LIMIT, DXL, 1750);
}

void loop() {

  positionMode();

  extendedPositionMode();

  velocityMode();

  currentMode();

  currentPositionMode();

  pwmMode();

  exit(0);
}

void pause() {
  delay(2000);
}

void positionMode() {
  if (dxl.setOperatingMode(DXL, OP_POSITION))
    DEBUG_SERIAL.println("Operating Mode: Position Control");

  if (dxl.torqueOn(DXL))
    DEBUG_SERIAL.println("Torque Enabled");

  if (dxl.setGoalPosition(DXL, 1000))
    DEBUG_SERIAL.println("Moving to position: 1000");

  pause();

  if (dxl.setGoalPosition(DXL, 4000))
    DEBUG_SERIAL.println("Moving to position: 4000");

  pause();

  if (dxl.setGoalPosition(DXL, -1000))
    DEBUG_SERIAL.println("Moving to position: -1000");
  else
    DEBUG_SERIAL.println("Unable to Complete Move");

  pause();

  if (dxl.setGoalPosition(DXL, 5000))
    DEBUG_SERIAL.println("Moving to position: 5000");
  else
    DEBUG_SERIAL.println("Unable to Complete Move");

  pause();

  if (dxl.torqueOff(DXL))
    DEBUG_SERIAL.println("Torque off. Setting angle limits...");

  if (dxl.writeControlTableItem(MIN_POSITION_LIMIT, DXL, 1500))
    DEBUG_SERIAL.println("Minimum angle set to 1500");

  if (dxl.writeControlTableItem(MAX_POSITION_LIMIT, DXL, 3500))
    DEBUG_SERIAL.println("Maximum angle set to 3500");

  if (dxl.torqueOn(DXL))
    DEBUG_SERIAL.println("Torque on. Testing angle limits...");

  if (dxl.setGoalPosition(DXL, 1000)) {
    DEBUG_SERIAL.println("Moving to position: 1000");
  } else {
    DEBUG_SERIAL.println("Unable to Complete Move");
  }
  pause();

  if (dxl.setGoalPosition(DXL, 4000)) {
    DEBUG_SERIAL.println("Moving to position: 4000");
  } else {
    DEBUG_SERIAL.println("Unable to Complete Move");
  }
  pause();

  if (dxl.setGoalPosition(DXL, 2000))
    DEBUG_SERIAL.println("Moving to position: 2000");


  pause();

  if (dxl.setGoalPosition(DXL, 3000))
    DEBUG_SERIAL.println("Moving to position: 3000");

  pause();
}

void extendedPositionMode() {
  if (dxl.torqueOff(DXL))
    DEBUG_SERIAL.println("Torque off. Changing operating mode...");

  if (dxl.setOperatingMode(DXL, OP_EXTENDED_POSITION))
    DEBUG_SERIAL.println("Operating Mode: Extended Position Control");

  if (dxl.torqueOn(DXL))
    DEBUG_SERIAL.println("Torque Enabled");

  if (dxl.setGoalPosition(DXL, -1000))
    DEBUG_SERIAL.println("Moving to position: -1000");
  else
    DEBUG_SERIAL.println("Unable to Complete Move");

  pause();

  if (dxl.setGoalPosition(DXL, 5000))
    DEBUG_SERIAL.println("Moving to position: 5000");
  else
    DEBUG_SERIAL.println("Unable to Complete Move");

  pause();

  if (dxl.torqueOff(DXL))
    DEBUG_SERIAL.println("Torque off. Setting angle limits...");

  if (dxl.writeControlTableItem(MIN_POSITION_LIMIT, DXL, 1500))
    DEBUG_SERIAL.println("Minimum angle set to 1500");

  if (dxl.writeControlTableItem(MAX_POSITION_LIMIT, DXL, 3500))
    DEBUG_SERIAL.println("Maximum angle set to 3500");

  if (dxl.torqueOn(DXL))
    DEBUG_SERIAL.println("Torque on. Testing angle limits...");

  if (dxl.setGoalPosition(DXL, 1000)) {
    DEBUG_SERIAL.println("Moving to position: 1000");
  } else {
    DEBUG_SERIAL.println("Unable to Complete Move");
  }
  pause();

  if (dxl.setGoalPosition(DXL, 4000)) {
    DEBUG_SERIAL.println("Moving to position: 4000");
  } else {
    DEBUG_SERIAL.println("Unable to Complete Move");
  }
  pause();

  if (dxl.setGoalPosition(DXL, -10000))
    DEBUG_SERIAL.println("Moving to position: -10000");

  pause();

  if (dxl.setGoalPosition(DXL, 10000))
    DEBUG_SERIAL.println("Moving to position: 10000");

  pause();
}

void velocityMode() {
  if (dxl.torqueOff(DXL))
    DEBUG_SERIAL.println("Torque off. Changing operating mode...");

  if (dxl.setOperatingMode(DXL, OP_VELOCITY))
    DEBUG_SERIAL.println("Operating Mode: Velocity Control");

  if (dxl.torqueOn(DXL))
    DEBUG_SERIAL.println("Torque Enabled");

  if (dxl.setGoalVelocity(DXL, 1000))
    DEBUG_SERIAL.println("Goal Velocity: 1000");
  else
    DEBUG_SERIAL.println("Unable to set velocity");

  pause();
  dxl.setGoalVelocity(DXL, 1000);
  pause();  

  if (dxl.setGoalVelocity(DXL, -1000))
    DEBUG_SERIAL.println("Goal Velocity: -1000");
  else
    DEBUG_SERIAL.println("Unable to set velocity");

  pause();

  if (dxl.torqueOff(DXL))
    DEBUG_SERIAL.println("Torque off. Setting velocity limit...");

  if (dxl.writeControlTableItem(VELOCITY_LIMIT, DXL, 500))
    DEBUG_SERIAL.println("Velocity limit set to 500");

  if (dxl.torqueOn(DXL))
    DEBUG_SERIAL.println("Torque on. Testing velocity limits...");

  if (dxl.setGoalVelocity(DXL, 1000)) {
    DEBUG_SERIAL.println("Goal Velocity: 1000");
  } else {
    DEBUG_SERIAL.println("Unable to set velocity");
  }
  pause();

  if (dxl.setGoalVelocity(DXL, -1000)) {
    DEBUG_SERIAL.println("Goal Velocity: -1000");
  } else {
    DEBUG_SERIAL.println("Unable to set velocity");
  }
  pause();
}

void currentMode() {
  if (dxl.torqueOff(DXL))
    DEBUG_SERIAL.println("Torque off. Changing operating mode...");

  if (dxl.setOperatingMode(DXL, OP_CURRENT))
    DEBUG_SERIAL.println("Operating Mode: Current Control");

  if (dxl.torqueOn(DXL))
    DEBUG_SERIAL.println("Torque Enabled");

  if (dxl.setGoalCurrent(DXL, 1000))
    DEBUG_SERIAL.println("Goal Current: 1000");
  else
    DEBUG_SERIAL.println("Unable to set current");

  pause();

  dxl.setGoalCurrent(DXL, 0);
  pause();

  if (dxl.setGoalCurrent(DXL, -1000))
    DEBUG_SERIAL.println("Goal Current: -1000");
  else
    DEBUG_SERIAL.println("Unable to set current");

  pause();

  if (dxl.torqueOff(DXL))
    DEBUG_SERIAL.println("Torque off. Setting current limit...");

  if (dxl.writeControlTableItem(CURRENT_LIMIT, DXL, 1000))
    DEBUG_SERIAL.println("Current limit set to 1000");

  if (dxl.torqueOn(DXL))
    DEBUG_SERIAL.println("Torque on. Testing current limits...");

  pause();

  if (dxl.setGoalCurrent(DXL, 1500)) {
    DEBUG_SERIAL.println("Goal Velocity: 1500");
  } else {
    DEBUG_SERIAL.println("Unable to set velocity");
  }
  pause();

  if (dxl.setGoalCurrent(DXL, -1500)) {
    DEBUG_SERIAL.println("Goal Velocity: -1500");
  } else {
    DEBUG_SERIAL.println("Unable to set velocity");
  }
  pause();

  if (dxl.setGoalCurrent(DXL, 100)) {
    DEBUG_SERIAL.println("Goal Velocity: 100");
  } else {
    DEBUG_SERIAL.println("Unable to set velocity");
  }

  delay(5000);
  dxl.setGoalCurrent(DXL, 0);
  pause();
}

void currentPositionMode() {
  if (dxl.torqueOff(DXL))
    DEBUG_SERIAL.println("Torque off. Changing operating mode...");

  if (dxl.setOperatingMode(DXL, OP_CURRENT_BASED_POSITION))
    DEBUG_SERIAL.println("Operating Mode: Current Based Position Control");

  if (dxl.torqueOn(DXL))
    DEBUG_SERIAL.println("Torque Enabled");

  if (dxl.setGoalCurrent(DXL, 1000))
    DEBUG_SERIAL.println("Goal Current: 1000");
  else
    DEBUG_SERIAL.println("Unable to set current");

  if (dxl.setGoalPosition(DXL, 1000))
    DEBUG_SERIAL.println("Goal Position: 1000");
  else
    DEBUG_SERIAL.println("Unable to set position");

  delay(5000);

  if (dxl.setGoalCurrent(DXL, 100))
    DEBUG_SERIAL.println("Goal Current: 100");
  else
    DEBUG_SERIAL.println("Unable to set current");
  delay(5000);

  if (dxl.torqueOff(DXL))
    DEBUG_SERIAL.println("Torque off. Setting angle limits...");

  if (dxl.writeControlTableItem(MIN_POSITION_LIMIT, DXL, 1500))
    DEBUG_SERIAL.println("Minimum angle set to 1500");

  if (dxl.writeControlTableItem(MAX_POSITION_LIMIT, DXL, 3500))
    DEBUG_SERIAL.println("Maximum angle set to 3500");

  if (dxl.torqueOn(DXL))
    DEBUG_SERIAL.println("Torque on. Testing angle limits...");

  if (dxl.setGoalPosition(DXL, 0)) {
    DEBUG_SERIAL.println("Moving to position: 0");
  } else {
    DEBUG_SERIAL.println("Unable to Complete Move");
  }
  pause();

  if (dxl.setGoalCurrent(DXL, 1000))
    DEBUG_SERIAL.println("Goal Current: 1000");

  if (dxl.setGoalPosition(DXL, 4000)) {
    DEBUG_SERIAL.println("Moving to position: 4000");
  } else {
    DEBUG_SERIAL.println("Unable to Complete Move");
  }
  pause();
}

void pwmMode() {
  if (dxl.torqueOff(DXL))
    DEBUG_SERIAL.println("Torque off. Changing operating mode...");

  if (dxl.setOperatingMode(DXL, OP_PWM))
    DEBUG_SERIAL.println("Operating Mode: PWM");

  if (dxl.torqueOn(DXL))
    DEBUG_SERIAL.println("Torque Enabled");

  if (dxl.setGoalPWM(DXL, 800))
    DEBUG_SERIAL.println("Goal PWM: 800");
  else
    DEBUG_SERIAL.println("Unable to set PWM");

  pause();

  if (dxl.setGoalPWM(DXL, -800))
    DEBUG_SERIAL.println("Goal PWM: -800");
  else
    DEBUG_SERIAL.println("Unable to set PWM");

  pause();

  if (dxl.torqueOff(DXL))
    DEBUG_SERIAL.println("Torque off. Setting PWM limit...");

  if (dxl.writeControlTableItem(PWM_LIMIT, DXL, 500))
    DEBUG_SERIAL.println("Maximum PWM set to 500");

  if (dxl.torqueOn(DXL))
    DEBUG_SERIAL.println("Torque on. Testing PWM limit...");

  if (dxl.setGoalPosition(DXL, 0)) {
    DEBUG_SERIAL.println("Moving to position: 0");
  } else {
    DEBUG_SERIAL.println("Unable to Complete Move");
  }
  pause();

  if (dxl.setGoalPWM(DXL, 1000)) {
    DEBUG_SERIAL.println("Goal PWM: 1000");
  } else {
    DEBUG_SERIAL.println("Unable to Complete Move");
  }
  pause();
}