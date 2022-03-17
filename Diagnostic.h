#include "Arduino.h"

#ifndef Actuators_h
#define Actuators_h

class Actuators
{
    public:
        Actuators();
        void setAll(int protocol, int baudrate, int id, int model);
        void startCount();
        int getProtocol();
        int getBaudrate();
        int getID();
        int getModel();
        static int getCount();
    private:
        int _protocol;
        int _baudrate;
        int _id;
        int _model;
        static int _count;
};

#endif
