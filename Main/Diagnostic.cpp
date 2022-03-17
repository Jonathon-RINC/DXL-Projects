#include "Arduino.h"
#include "Diagnostic.h"

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

void Diagnostic::setSerial(char serial) {
        _serial = serial;
};

void Diagnostic::listAll() {
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
int Diagnostic::getModel() {
        return _model;
};
int Diagnostic::getCount() {
        return _count;
};
