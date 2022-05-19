#include "Arduino.h"
#include <Dynamixel2Arduino.h>


#ifndef Diagnostic_h
#define Diagnostic_h

class Diagnostic
{
    public:
        Diagnostic();
        void setAll(int protocol, int baudrate, int id);
        static void setActive(int active);

        static void listActive(Diagnostic actuators[]);
        static void listAll(Diagnostic actuator[]);

        static void enableDXL(Diagnostic actuators[], Dynamixel2Arduino dxl);

        static void testPosition(Diagnostic actuators[], Dynamixel2Arduino dxl);
        static void testVelocity(Diagnostic actuators[], Dynamixel2Arduino dxl);
        static void testEXPosition(Diagnostic actuators[], Dynamixel2Arduino dxl);
        static void testCompliance(Diagnostic actuators[], Dynamixel2Arduino dxl);

        int getProtocol();
        int getBaudrate();
        int getID();
        static int getActive();
        static int getCount();

    private:
        static char _serial;
        static int _count;

        int _protocol;
        int _baudrate;
        int _id;

        static int _active;
};

int timedSelection(char prompt[], int timer);

int selection(char prompt[]);

#endif
