#include "Arduino.h"

#ifndef Diagnostic_h
#define Diagnostic_h

class Diagnostic
{
    public:
        Diagnostic();
        void setAll(int protocol, int baudrate, int id, int model);
        static void setSerial(char serial);

        static void listAll();

        int getProtocol();
        int getBaudrate();
        int getID();
        int getModel();
        static int getCount();

    private:
        static char _serial;
        static int _count;

        int _protocol;
        int _baudrate;
        int _id;
        int _model;
};

#endif
