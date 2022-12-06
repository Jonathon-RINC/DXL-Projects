#include <Dynamixel2Arduino.h>

#if defined(ARDUINO_AVR_UNO) || defined(ARDUINO_AVR_MEGA2560)
  #include <SoftwareSerial.h>
  SoftwareSerial soft_serial(7, 8);
  #define DXL_SERIAL   Serial
  #define DEBUG_SERIAL soft_serial
  const int DXL_DIR_PIN = 2;
#elif defined(ARDUINO_SAM_DUE)
  #define DXL_SERIAL   Serial
  #define DEBUG_SERIAL SerialUSB
  const int DXL_DIR_PIN = 2;
#elif defined(ARDUINO_SAM_ZERO)
  #define DXL_SERIAL   Serial1
  #define DEBUG_SERIAL SerialUSB
  const int DXL_DIR_PIN = 2;
#elif defined(ARDUINO_OpenCM904)
  #define DXL_SERIAL   Serial3 
  #define DEBUG_SERIAL Serial
  const int DXL_DIR_PIN = 22; 
#elif defined(ARDUINO_OpenCR)
  #define DXL_SERIAL   Serial3
  #define DEBUG_SERIAL Serial
  const int DXL_DIR_PIN = 84;
#elif defined(ARDUINO_OpenRB)
  #define DXL_SERIAL Serial1
  #define DEBUG_SERIAL Serial
  const int DXL_DIR_PIN = -1;
#else
  #define DXL_SERIAL   Serial1
  #define DEBUG_SERIAL Serial
  const int DXL_DIR_PIN = 2;
#endif

const float DXL_PROTOCOL_VERSION = 2.0;

Dynamixel2Arduino dxl(DXL_SERIAL, DXL_DIR_PIN);

using namespace ControlTableItem;

//Human readable names for servo IDs and other important magic numbers
const uint8_t BASE = 1;
const uint8_t SHOULDER = 2;
const uint8_t ELBOW = 3;
const uint8_t WRIST = 4;
const uint8_t GRIP = 5;

const uint8_t BROADCAST = 254;

const uint8_t JOINTS = 5;
const uint8_t MAX_FRAMES = 3;

int positions[MAX_FRAMES][JOINTS];

void setup()
{
  // For Uno, Nano, Mini, and Mega, use UART port of DYNAMIXEL Shield to debug.
  DEBUG_SERIAL.begin(115200);
  while(!DEBUG_SERIAL);   

  // Set Port baudrate to 57600bps. This has to match with DYNAMIXEL baudrate.
  dxl.begin(57600);
  // Set Port Protocol Version. This has to match with DYNAMIXEL protocol version.
  dxl.setPortProtocolVersion(DXL_PROTOCOL_VERSION);

  

  dxl.torqueOff(BASE);
  dxl.setOperatingMode(BASE, OP_CURRENT_BASED_POSITION);
  dxl.setOperatingMode(SHOULDER, OP_CURRENT_BASED_POSITION);
  dxl.setOperatingMode(ELBOW, OP_CURRENT_BASED_POSITION);
  dxl.setOperatingMode(WRIST, OP_CURRENT_BASED_POSITION);
 
  dxl.setOperatingMode(GRIP, OP_CURRENT_BASED_POSITION);

}

void loop()
{
  for (int frame = 0; frame < MAX_FRAMES; frame++)
  {
    DEBUG_SERIAL.print("Snapshotting frame ");
    DEBUG_SERIAL.print(frame);
    DEBUG_SERIAL.println(" in:");

    for (int countdown = 5; countdown > 0 ; countdown--)
    {
      DEBUG_SERIAL.print(countdown);
      DEBUG_SERIAL.println("...");
      delay(1000);
    }

    savePositions(frame);
  }

  DEBUG_SERIAL.println("Motion replay will begin in 10 seconds, please ensure you are clear of the arm before motion playback.");
  for (int countdown = 10; countdown > 0 ; countdown--)
    {
      DEBUG_SERIAL.print(countdown);
      DEBUG_SERIAL.println("...");
      delay(1000);
    }
    
  playMotion(positions);
}

void savePositions(int frame)
{
  DEBUG_SERIAL.print("Saving frame ");
  DEBUG_SERIAL.print(frame);
  DEBUG_SERIAL.println(" positions...");


  positions[frame][BASE] = dxl.getPresentPosition(BASE);
  DEBUG_SERIAL.print("Base: ");
  DEBUG_SERIAL.println(positions[frame][BASE]);

  positions[frame][SHOULDER] = dxl.getPresentPosition(SHOULDER);
  DEBUG_SERIAL.print("Shoulder: ");
  DEBUG_SERIAL.println(positions[frame][SHOULDER]);

  positions[frame][ELBOW] = dxl.getPresentPosition(ELBOW);
  DEBUG_SERIAL.print("Elbow: ");
  DEBUG_SERIAL.println(positions[frame][ELBOW]);

  positions[frame][WRIST] = dxl.getPresentPosition(WRIST);
  DEBUG_SERIAL.print("Wrist: ");
  DEBUG_SERIAL.println(positions[frame][WRIST]);
  

  DEBUG_SERIAL.print("Frame ");
  DEBUG_SERIAL.print(frame);
  DEBUG_SERIAL.println(" saved.");
}

void playMotion(int motion[MAX_FRAMES][JOINTS])
{

  DEBUG_SERIAL.println("Enabling torque...");
  
  dxl.torqueOn(BASE);
  dxl.torqueOn(SHOULDER);
  dxl.torqueOn(ELBOW);
  dxl.torqueOn(WRIST);
  
  DEBUG_SERIAL.println("Torque enabled.");

  DEBUG_SERIAL.println("Motion start...");
  for (int frame = 0; frame < MAX_FRAMES; ++frame)
  {
    DEBUG_SERIAL.print("Playing frame ");
    DEBUG_SERIAL.print(frame);
    DEBUG_SERIAL.println(".");

    dxl.setGoalPosition(BASE, motion[frame][BASE]);
    dxl.setGoalPosition(SHOULDER, motion[frame][SHOULDER]);
    dxl.setGoalPosition(ELBOW, motion[frame][ELBOW]);
    dxl.setGoalPosition(WRIST, motion[frame][WRIST]);

    DEBUG_SERIAL.print("Advancing frame in...");
  for (int countdown = 3; countdown > 0 ; countdown--)
    {
      DEBUG_SERIAL.print(countdown);
      DEBUG_SERIAL.println("...");
      delay(1000);
    }

  }
  DEBUG_SERIAL.println("Motion complete.");

  dxl.torqueOff(BASE);
  dxl.torqueOff(SHOULDER);
  dxl.torqueOff(ELBOW);
  dxl.torqueOff(WRIST);
}