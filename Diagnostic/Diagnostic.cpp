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
        _model = 0;
        _count = 0;
};

void Diagnostic::setAll(int protocol, int baudrate, int id, int model) {
        _protocol = protocol;
        _baudrate = baudrate;
        _id = id;
        _model = model;
        _count++;
};

void Diagnostic::setActive(int active) {
        _active = active;
};

void Diagnostic::listActive(Diagnostic actuators[]) {
DEBUG_SERIAL.print(actuators[_active].getModel());
DEBUG_SERIAL.print(" with ID ");
DEBUG_SERIAL.print(actuators[_active].getID());
DEBUG_SERIAL.print(" using Protocol ");
DEBUG_SERIAL.print(actuators[_active].getProtocol());
DEBUG_SERIAL.print("@");
DEBUG_SERIAL.print(actuators[_active].getBaudrate());
DEBUG_SERIAL.println("baud selected");
};

void Diagnostic::listAll(Diagnostic actuators[]) {
for(int index = 0; index < Diagnostic::getCount(); index++) {
DEBUG_SERIAL.print(index);
DEBUG_SERIAL.print(") ");
DEBUG_SERIAL.print(actuators[index].getModel());
DEBUG_SERIAL.print(" ID: ");
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
DEBUG_SERIAL.print(actuators[Diagnostic::getActive()].getModel());
DEBUG_SERIAL.print(" ID: ");
DEBUG_SERIAL.print(actuators[Diagnostic::getActive()].getID());
DEBUG_SERIAL.println(" enabled");

};

void Diagnostic::testPosition(Diagnostic actuators[], Dynamixel2Arduino dxl) {

    dxl.torqueOff(actuators[Diagnostic::getActive()].getID());
  dxl.setOperatingMode(actuators[Diagnostic::getActive()].getID(), OP_POSITION);
  dxl.writeControlTableItem(PROFILE_VELOCITY, actuators[Diagnostic::getActive()].getID(), 30);

  Diagnostic::enableDXL(actuators, dxl);
    
  DEBUG_SERIAL.println("Goal Position: 0°");
  dxl.setGoalPosition(actuators[Diagnostic::getActive()].getID(), 0, UNIT_DEGREE);
  delay(3000);

  DEBUG_SERIAL.println("Goal Position: 180°");
  dxl.setGoalPosition(actuators[Diagnostic::getActive()].getID(), 180, UNIT_DEGREE);
  delay(3000);

  DEBUG_SERIAL.println("Goal Position: 90°");
  dxl.setGoalPosition(actuators[Diagnostic::getActive()].getID(), 90, UNIT_DEGREE);
  delay(3000);

  DEBUG_SERIAL.println("Goal Position: 270°");
  dxl.setGoalPosition(actuators[Diagnostic::getActive()].getID(), 270, UNIT_DEGREE);
  delay(3000);

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

char* Diagnostic::getModel() {

    switch (_model) {
        case 1020:
        return "XM430-W350-T";
        break;

};
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
