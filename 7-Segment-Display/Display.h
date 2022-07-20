#include "Arduino.h"
#include <Dynamixel2Arduino.h>


#ifndef Display_h
#define Display_h

class Display
{
    public:
        Display();
        static void printChar(char character);

    private:
};

Display::Display(){
    uint16_t displayTime = 5000;
};

void Display::printChar(char character) {
    switch (character) {
        case 0:
  Actuators.setGoalPosition(11, onPosition);
  Actuators.setGoalPosition(12, onPosition);
  Actuators.setGoalPosition(13, onPosition);
  Actuators.setGoalPosition(14, onPosition);
  Actuators.setGoalPosition(15, onPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, onPosition);
  break;

        case 1:
  Actuators.setGoalPosition(11, offPosition);
  Actuators.setGoalPosition(12, onPosition);
  Actuators.setGoalPosition(13, onPosition);
  Actuators.setGoalPosition(14, offPosition);
  Actuators.setGoalPosition(15, offPosition);
  Actuators.setGoalPosition(16, offPosition);
  Actuators.setGoalPosition(17, offPosition);
  break;

        case 2:
  Actuators.setGoalPosition(11, onPosition);
  Actuators.setGoalPosition(12, onPosition);
  Actuators.setGoalPosition(13, offPosition);
  Actuators.setGoalPosition(14, onPosition);
  Actuators.setGoalPosition(15, onPosition);
  Actuators.setGoalPosition(16, offPosition);
  Actuators.setGoalPosition(17, onPosition);
  break;

        case 3:
  Actuators.setGoalPosition(11, onPosition);
  Actuators.setGoalPosition(12, onPosition);
  Actuators.setGoalPosition(13, onPosition);
  Actuators.setGoalPosition(14, onPosition);
  Actuators.setGoalPosition(15, offPosition);
  Actuators.setGoalPosition(16, offPosition);
  Actuators.setGoalPosition(17, onPosition);
  break;

        case 4:
  Actuators.setGoalPosition(11, offPosition);
  Actuators.setGoalPosition(12, onPosition);
  Actuators.setGoalPosition(13, onPosition);
  Actuators.setGoalPosition(14, offPosition);
  Actuators.setGoalPosition(15, offPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, onPosition);
  break;

        case 5:
  Actuators.setGoalPosition(11, onPosition);
  Actuators.setGoalPosition(12, offPosition);
  Actuators.setGoalPosition(13, onPosition);
  Actuators.setGoalPosition(14, onPosition);
  Actuators.setGoalPosition(15, offPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, onPosition);
  break;

        case 6:
  Actuators.setGoalPosition(11, onPosition);
  Actuators.setGoalPosition(12, offPosition);
  Actuators.setGoalPosition(13, onPosition);
  Actuators.setGoalPosition(14, onPosition);
  Actuators.setGoalPosition(15, onPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, onPosition);
  break;

        case 7:
  Actuators.setGoalPosition(11, onPosition);
  Actuators.setGoalPosition(12, onPosition);
  Actuators.setGoalPosition(13, onPosition);
  Actuators.setGoalPosition(14, offPosition);
  Actuators.setGoalPosition(15, offPosition);
  Actuators.setGoalPosition(16, offPosition);
  Actuators.setGoalPosition(17, offPosition);
  break;

        case 8:
  Actuators.setGoalPosition(11, onPosition);
  Actuators.setGoalPosition(12, onPosition);
  Actuators.setGoalPosition(13, onPosition);
  Actuators.setGoalPosition(14, onPosition);
  Actuators.setGoalPosition(15, onPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, onPosition);
  break;

        case 9:
  Actuators.setGoalPosition(11, onPosition);
  Actuators.setGoalPosition(12, onPosition);
  Actuators.setGoalPosition(13, onPosition);
  Actuators.setGoalPosition(14, offPosition);
  Actuators.setGoalPosition(15, offPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, onPosition);
  break;

        case A:
  Actuators.setGoalPosition(11, onPosition);
  Actuators.setGoalPosition(12, onPosition);
  Actuators.setGoalPosition(13, onPosition);
  Actuators.setGoalPosition(14, offPosition);
  Actuators.setGoalPosition(15, onPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, onPosition);
  break;

        case B:
  Actuators.setGoalPosition(11, offPosition);
  Actuators.setGoalPosition(12, offPosition);
  Actuators.setGoalPosition(13, onPosition);
  Actuators.setGoalPosition(14, onPosition);
  Actuators.setGoalPosition(15, onPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, onPosition);
  break;

        case C:
  Actuators.setGoalPosition(11, onPosition);
  Actuators.setGoalPosition(12, offPosition);
  Actuators.setGoalPosition(13, offPosition);
  Actuators.setGoalPosition(14, onPosition);
  Actuators.setGoalPosition(15, onPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, onPosition);
  break;

        case D:
  Actuators.setGoalPosition(11, offPosition);
  Actuators.setGoalPosition(12, onPosition);
  Actuators.setGoalPosition(13, onPosition);
  Actuators.setGoalPosition(14, onPosition);
  Actuators.setGoalPosition(15, onPosition);
  Actuators.setGoalPosition(16, offPosition);
  Actuators.setGoalPosition(17, onPosition);
  break;

        case E:
  Actuators.setGoalPosition(11, onPosition);
  Actuators.setGoalPosition(12, offPosition);
  Actuators.setGoalPosition(13, offPosition);
  Actuators.setGoalPosition(14, onPosition);
  Actuators.setGoalPosition(15, onPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, onPosition);
  break;

        case F:
  Actuators.setGoalPosition(11, onPosition);
  Actuators.setGoalPosition(12, offPosition);
  Actuators.setGoalPosition(13, offPosition);
  Actuators.setGoalPosition(14, offPosition);
  Actuators.setGoalPosition(15, onPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, onPosition);
  break;

        case G:
  Actuators.setGoalPosition(11, onPosition);
  Actuators.setGoalPosition(12, offPosition);
  Actuators.setGoalPosition(13, onPosition);
  Actuators.setGoalPosition(14, onPosition);
  Actuators.setGoalPosition(15, onPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, offPosition);
  break;

        case H:
  Actuators.setGoalPosition(11, offPosition);
  Actuators.setGoalPosition(12, offPosition);
  Actuators.setGoalPosition(13, onPosition);
  Actuators.setGoalPosition(14, offPosition);
  Actuators.setGoalPosition(15, onPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, onPosition);
  break;

        case I:
  Actuators.setGoalPosition(11, offPosition);
  Actuators.setGoalPosition(12, offPosition);
  Actuators.setGoalPosition(13, offPosition);
  Actuators.setGoalPosition(14, offPosition);
  Actuators.setGoalPosition(15, onPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, offPosition);
  break;

        case J:
  Actuators.setGoalPosition(11, offPosition);
  Actuators.setGoalPosition(12, onPosition);
  Actuators.setGoalPosition(13, onPosition);
  Actuators.setGoalPosition(14, onPosition);
  Actuators.setGoalPosition(15, offPosition);
  Actuators.setGoalPosition(16, offPosition);
  Actuators.setGoalPosition(17, offPosition);
  break;

        case K:
  Actuators.setGoalPosition(11, onPosition);
  Actuators.setGoalPosition(12, offPosition);
  Actuators.setGoalPosition(13, onPosition);
  Actuators.setGoalPosition(14, offPosition);
  Actuators.setGoalPosition(15, onPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, onPosition);
  break;

        case L:
  Actuators.setGoalPosition(11, offPosition);
  Actuators.setGoalPosition(12, offPosition);
  Actuators.setGoalPosition(13, offPosition);
  Actuators.setGoalPosition(14, onPosition);
  Actuators.setGoalPosition(15, onPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, onPosition);
  break;

        case M:
  Actuators.setGoalPosition(11, onPosition);
  Actuators.setGoalPosition(12, offPosition);
  Actuators.setGoalPosition(13, onPosition);
  Actuators.setGoalPosition(14, offPosition);
  Actuators.setGoalPosition(15, onPosition);
  Actuators.setGoalPosition(16, offPosition);
  Actuators.setGoalPosition(17, offPosition);
  break;

        case N:
  Actuators.setGoalPosition(11, onPosition);
  Actuators.setGoalPosition(12, onPosition);
  Actuators.setGoalPosition(13, onPosition);
  Actuators.setGoalPosition(14, offPosition);
  Actuators.setGoalPosition(15, onPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, offPosition);
  break;

        case O:
  Actuators.setGoalPosition(11, onPosition);
  Actuators.setGoalPosition(12, onPosition);
  Actuators.setGoalPosition(13, onPosition);
  Actuators.setGoalPosition(14, onPosition);
  Actuators.setGoalPosition(15, onPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, offPosition);
  break;

        case P:
  Actuators.setGoalPosition(11, onPosition);
  Actuators.setGoalPosition(12, onPosition);
  Actuators.setGoalPosition(13, offPosition);
  Actuators.setGoalPosition(14, offPosition);
  Actuators.setGoalPosition(15, onPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, onPosition);
  break;

        case Q:
  Actuators.setGoalPosition(11, onPosition);
  Actuators.setGoalPosition(12, onPosition);
  Actuators.setGoalPosition(13, onPosition);
  Actuators.setGoalPosition(14, offPosition);
  Actuators.setGoalPosition(15, offPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, onPosition);
  break;

        case R:
  Actuators.setGoalPosition(11, onPosition);
  Actuators.setGoalPosition(12, onPosition);
  Actuators.setGoalPosition(13, offPosition);
  Actuators.setGoalPosition(14, offPosition);
  Actuators.setGoalPosition(15, onPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, offPosition);
  break;

        case S:
  Actuators.setGoalPosition(11, onPosition);
  Actuators.setGoalPosition(12, offPosition);
  Actuators.setGoalPosition(13, onPosition);
  Actuators.setGoalPosition(14, onPosition);
  Actuators.setGoalPosition(15, offPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, onPosition);
  break;

        case T:
  Actuators.setGoalPosition(11, offPosition);
  Actuators.setGoalPosition(12, offPosition);
  Actuators.setGoalPosition(13, offPosition);
  Actuators.setGoalPosition(14, onPosition);
  Actuators.setGoalPosition(15, onPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, onPosition);
  break;

        case U:
  Actuators.setGoalPosition(11, offPosition);
  Actuators.setGoalPosition(12, onPosition);
  Actuators.setGoalPosition(13, onPosition);
  Actuators.setGoalPosition(14, onPosition);
  Actuators.setGoalPosition(15, onPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, offPosition);
  break;

        case V:
  Actuators.setGoalPosition(11, offPosition);
  Actuators.setGoalPosition(12, onPosition);
  Actuators.setGoalPosition(13, onPosition);
  Actuators.setGoalPosition(14, onPosition);
  Actuators.setGoalPosition(15, offPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, offPosition);
  break;

        case W:
  Actuators.setGoalPosition(11, offPosition);
  Actuators.setGoalPosition(12, onPosition);
  Actuators.setGoalPosition(13, offPosition);
  Actuators.setGoalPosition(14, onPosition);
  Actuators.setGoalPosition(15, offPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, offPosition);
  break;

        case X:
  Actuators.setGoalPosition(11, offPosition);
  Actuators.setGoalPosition(12, onPosition);
  Actuators.setGoalPosition(13, onPosition);
  Actuators.setGoalPosition(14, offPosition);
  Actuators.setGoalPosition(15, onPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, onPosition);
  break;

        case Y:
  Actuators.setGoalPosition(11, offPosition);
  Actuators.setGoalPosition(12, onPosition);
  Actuators.setGoalPosition(13, onPosition);
  Actuators.setGoalPosition(14, onPosition);
  Actuators.setGoalPosition(15, offPosition);
  Actuators.setGoalPosition(16, onPosition);
  Actuators.setGoalPosition(17, onPosition);
  break;

        case Z:
  Actuators.setGoalPosition(11, onPosition);
  Actuators.setGoalPosition(12, onPosition);
  Actuators.setGoalPosition(13, offPosition);
  Actuators.setGoalPosition(14, onPosition);
  Actuators.setGoalPosition(15, offPosition);
  Actuators.setGoalPosition(16, offPosition);
  Actuators.setGoalPosition(17, onPosition);
  break;

}

}

#endif
