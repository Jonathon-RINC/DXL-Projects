#include "Arduino.h"
#include "Diagnostic.h"
#include "Definitions.h"
using namespace ControlTableItem;

char Diagnostic::_serial;
int Diagnostic::_count;
int Diagnostic::_active;

Diagnostic::Diagnostic() {
        _protocol = 0;
        _baudrate = 0;
        _id = 0;
        _count = 0;
};

void Diagnostic::setAll(int protocol, int baudrate, int id) {
        _protocol = protocol;
        _baudrate = baudrate;
        _id = id;
        _count++;
};

void Diagnostic::setActive(int active) {
        _active = active;
};

void Diagnostic::listActive(Diagnostic actuators[]) {
DEBUG_SERIAL.print("Selected ID ");
DEBUG_SERIAL.print(actuators[_active].getID());
DEBUG_SERIAL.print(" using Protocol ");
DEBUG_SERIAL.print(actuators[_active].getProtocol());
DEBUG_SERIAL.print(" at ");
DEBUG_SERIAL.print(actuators[_active].getBaudrate());
DEBUG_SERIAL.println("baud");
};

void Diagnostic::listAll(Diagnostic actuators[]) {
for(int index = 0; index < Diagnostic::getCount(); index++) {
DEBUG_SERIAL.print(index);
DEBUG_SERIAL.print(") ID: ");
DEBUG_SERIAL.print(actuators[index].getID());
DEBUG_SERIAL.print(" Protocol: ");
DEBUG_SERIAL.print(actuators[index].getProtocol());
DEBUG_SERIAL.print(" Baudrate: ");
DEBUG_SERIAL.println(actuators[index].getBaudrate());
};
};

void Diagnostic::enableDXL(Diagnostic actuators[], Dynamixel2Arduino dxl) {

  dxl.begin(actuators[Diagnostic::getActive()].getBaudrate());

  dxl.setPortProtocolVersion(actuators[Diagnostic::getActive()].getProtocol());

  dxl.torqueOn(actuators[Diagnostic::getActive()].getID());
DEBUG_SERIAL.print("ID ");
DEBUG_SERIAL.print(actuators[Diagnostic::getActive()].getID());
DEBUG_SERIAL.println(" enabled");

};

void Diagnostic::testEXPosition(Diagnostic actuators[], Dynamixel2Arduino dxl) {

    dxl.torqueOff(actuators[Diagnostic::getActive()].getID());
  dxl.setOperatingMode(actuators[Diagnostic::getActive()].getID(), OP_EXTENDED_POSITION);
  dxl.writeControlTableItem(PROFILE_VELOCITY, actuators[Diagnostic::getActive()].getID(), 0);
  dxl.writeControlTableItem(CURRENT_LIMIT, actuators[Diagnostic::getActive()].getID(), 0);
  dxl.writeControlTableItem(LED, actuators[Diagnostic::getActive()].getID(), 1);

  Diagnostic::enableDXL(actuators, dxl);

  int goal = random(8000);
    
  DEBUG_SERIAL.println("Testing Extended Positon.");

  DEBUG_SERIAL.print("Goal Position: ");
  DEBUG_SERIAL.println(goal);
  dxl.setGoalPosition(actuators[Diagnostic::getActive()].getID(), goal);
  delay(5000);

  goal = random(8000);
  goal = goal * -1;
  DEBUG_SERIAL.print("Goal Position: ");
  DEBUG_SERIAL.println(goal);
  dxl.setGoalPosition(actuators[Diagnostic::getActive()].getID(), goal);
  delay(5000);

  goal = random(8000);
  DEBUG_SERIAL.print("Goal Position: ");
  DEBUG_SERIAL.println(goal);
  dxl.setGoalPosition(actuators[Diagnostic::getActive()].getID(), goal);
  delay(5000);

  goal = random(8000);
  goal = goal * -1;
  DEBUG_SERIAL.print("Goal Position: ");
  DEBUG_SERIAL.println(goal);
  dxl.setGoalPosition(actuators[Diagnostic::getActive()].getID(), goal);
  delay(5000);

  dxl.writeControlTableItem(LED, actuators[Diagnostic::getActive()].getID(), 0);

};

void Diagnostic::testCompliance(Diagnostic actuators[], Dynamixel2Arduino dxl) {

    dxl.torqueOff(actuators[Diagnostic::getActive()].getID());
  dxl.setOperatingMode(actuators[Diagnostic::getActive()].getID(), OP_CURRENT_BASED_POSITION);
  dxl.writeControlTableItem(PROFILE_VELOCITY, actuators[Diagnostic::getActive()].getID(), 0);
  dxl.writeControlTableItem(CURRENT_LIMIT, actuators[Diagnostic::getActive()].getID(), 100);
  dxl.setGoalCurrent(actuators[Diagnostic::getActive()].getID(), 100);
  dxl.writeControlTableItem(LED, actuators[Diagnostic::getActive()].getID(), 1);

  Diagnostic::enableDXL(actuators, dxl);

    
  DEBUG_SERIAL.println("Testing Compliance.");
  dxl.setGoalPosition(actuators[Diagnostic::getActive()].getID(), 0);
  selection("Press any key to continue");

  dxl.writeControlTableItem(LED, actuators[Diagnostic::getActive()].getID(), 0);

};

void Diagnostic::testPosition(Diagnostic actuators[], Dynamixel2Arduino dxl) {

    dxl.torqueOff(actuators[Diagnostic::getActive()].getID());
  dxl.setOperatingMode(actuators[Diagnostic::getActive()].getID(), OP_POSITION);
  dxl.writeControlTableItem(PROFILE_VELOCITY, actuators[Diagnostic::getActive()].getID(), 0);
  dxl.writeControlTableItem(CURRENT_LIMIT, actuators[Diagnostic::getActive()].getID(), 0);
  dxl.writeControlTableItem(LED, actuators[Diagnostic::getActive()].getID(), 1);

  Diagnostic::enableDXL(actuators, dxl);

  int goal = random(4096);

  DEBUG_SERIAL.println("Testing Positon.");
    
  DEBUG_SERIAL.print("Goal Position: ");
  DEBUG_SERIAL.println(goal);
  dxl.setGoalPosition(actuators[Diagnostic::getActive()].getID(), goal);
  delay(5000);

  goal = random(4096);
  DEBUG_SERIAL.print("Goal Position: ");
  DEBUG_SERIAL.println(goal);
  dxl.setGoalPosition(actuators[Diagnostic::getActive()].getID(), goal);
  delay(5000);

  goal = random(4096);
  DEBUG_SERIAL.print("Goal Position: ");
  DEBUG_SERIAL.println(goal);
  dxl.setGoalPosition(actuators[Diagnostic::getActive()].getID(), goal);
  delay(5000);

  goal = random(4096);
  DEBUG_SERIAL.print("Goal Position: ");
  DEBUG_SERIAL.println(goal);
  dxl.setGoalPosition(actuators[Diagnostic::getActive()].getID(), goal);
  delay(5000);

  dxl.writeControlTableItem(LED, actuators[Diagnostic::getActive()].getID(), 0);

};

void Diagnostic::testVelocity(Diagnostic actuators[], Dynamixel2Arduino dxl) {

    dxl.torqueOff(actuators[Diagnostic::getActive()].getID());
  dxl.setOperatingMode(actuators[Diagnostic::getActive()].getID(), OP_VELOCITY);
  dxl.writeControlTableItem(PROFILE_VELOCITY, actuators[Diagnostic::getActive()].getID(), 0);
  dxl.writeControlTableItem(CURRENT_LIMIT, actuators[Diagnostic::getActive()].getID(), 0);
  dxl.writeControlTableItem(LED, actuators[Diagnostic::getActive()].getID(), 1);

  Diagnostic::enableDXL(actuators, dxl);

  DEBUG_SERIAL.println("Testing Velocity.");
    
  DEBUG_SERIAL.println("Forward");
  dxl.setGoalVelocity(actuators[Diagnostic::getActive()].getID(), 100);
  delay(3000);

  DEBUG_SERIAL.println("Reverse");
  dxl.setGoalVelocity(actuators[Diagnostic::getActive()].getID(), -100);
  delay(3000);

  DEBUG_SERIAL.println("Forward");
  dxl.setGoalVelocity(actuators[Diagnostic::getActive()].getID(), 100);
  delay(3000);

  DEBUG_SERIAL.println("Reverse");
  dxl.setGoalVelocity(actuators[Diagnostic::getActive()].getID(), -100);
  delay(3000);

  dxl.setGoalVelocity(actuators[Diagnostic::getActive()].getID(), 0);

  dxl.writeControlTableItem(LED, actuators[Diagnostic::getActive()].getID(), 0);

};

int Diagnostic::getProtocol() {
        return _protocol;
};

int Diagnostic::getBaudrate() {
        return _baudrate;
};
int Diagnostic::getID() {
        return _id;
};

int Diagnostic::getActive() {
        return _active;
};
        
int Diagnostic::getCount() {
        return _count;
};

int timedSelection(char prompt[], int timer) {
    DEBUG_SERIAL.println(prompt);
    while (DEBUG_SERIAL.available() == 0 && timer > 0) {
      DEBUG_SERIAL.print(timer);
      DEBUG_SERIAL.print("... ");
      delay(1000);
      timer--;
   }
   while (Serial.available() > 0) {
   int input = Serial.parseInt();    
   Serial.read();//Empty the read buffer
     return input;
   }
};

int selection(char prompt[]) {
    DEBUG_SERIAL.println(prompt);
    while (DEBUG_SERIAL.available() == 0) {
      delay(500);
   }
   while (Serial.available() > 0) {
   int input = Serial.parseInt();    
   Serial.read();//Empty the read buffer
     return input;
   }
};
