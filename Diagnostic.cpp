#include "Arduino.h"
#include "Actuators.h"

Actuators::Actuators() {
        _protocol = 0;
        _baudrate = 0;
        _id = 0;
        _model = 0;
        _count = 0;
};

void Actuators::setAll(int protocol, int baudrate, int id, int model) {
        _protocol = protocol;
        _baudrate = baudrate;
        _id = id;
        _model = model;
        _count++;
};

void Actuators::startCount() {
       int _count = 0;
};

int Actuators::getProtocol() {
        return _protocol;
};
int Actuators::getBaudrate() {
        return _baudrate;
};
int Actuators::getID() {
        return _id;
};
int Actuators::getModel() {
        return _model;
};
int Actuators::getCount() {
        return _count;
};
