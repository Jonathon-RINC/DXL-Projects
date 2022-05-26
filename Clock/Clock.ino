#include <Dynamixel2Arduino.h>
#include <RTClib.h>

#if defined(ARDUINO_AVR_UNO) || defined(ARDUINO_AVR_MEGA2560) // When using DynamixelShield
  #include <SoftwareSerial.h>
  SoftwareSerial soft_serial(7, 8); // DYNAMIXELShield UART RX/TX
  #define DXL_SERIAL   Serial
  #define DEBUG_SERIAL soft_serial
  const uint8_t DXL_DIR_PIN = 2; // DYNAMIXEL Shield DIR PIN
#elif defined(ARDUINO_SAM_DUE) // When using DynamixelShield
  #define DXL_SERIAL   Serial
  #define DEBUG_SERIAL SerialUSB
  const uint8_t DXL_DIR_PIN = 2; // DYNAMIXEL Shield DIR PIN
#elif defined(ARDUINO_SAM_ZERO) // When using DynamixelShield
  #define DXL_SERIAL   Serial1
  #define DEBUG_SERIAL SerialUSB
  const uint8_t DXL_DIR_PIN = 2; // DYNAMIXEL Shield DIR PIN
#elif defined(ARDUINO_OpenCM904) // When using official ROBOTIS board with DXL circuit.
  #define DXL_SERIAL   Serial3 //OpenCM9.04 EXP Board's DXL port Serial. (Serial1 for the DXL port on the OpenCM 9.04 board)
  #define DEBUG_SERIAL Serial
  const uint8_t DXL_DIR_PIN = 22; //OpenCM9.04 EXP Board's DIR PIN. (28 for the DXL port on the OpenCM 9.04 board)
#elif defined(ARDUINO_OpenCR) // When using official ROBOTIS board with DXL circuit.
  // For OpenCR, there is a DXL Power Enable pin, so you must initialize and control it.
  // Reference link : https://github.com/ROBOTIS-GIT/OpenCR/blob/master/arduino/opencr_arduino/opencr/libraries/DynamixelSDK/src/dynamixel_sdk/port_handler_arduino.cpp#L78
  #define DXL_SERIAL   Serial3
  #define DEBUG_SERIAL Serial
  const uint8_t DXL_DIR_PIN = 84; // OpenCR Board's DIR PIN.    
#else // Other boards when using DynamixelShield
  #define DXL_SERIAL   Serial1
  #define DEBUG_SERIAL Serial
  const uint8_t DXL_DIR_PIN = A6; // DYNAMIXEL Shield DIR PIN
#endif

RTC_DS3231 Clock;
 
Dynamixel2Arduino Actuators(DXL_SERIAL, DXL_DIR_PIN);
using namespace ControlTableItem;

const int Position[] = {0, -400, -800, -1200, -1600, -2000, -2400, -2800, -3200, -3600};
const int DXL_Hours[] = {1, 2};
const int DXL_Minutes[] = {3, 4};
const int DXL_Seconds[] = {5, 6};

int CTime[] = {0, 0, 0};

int Hours[] = {0, 0};
int Minutes[] = {0, 0};
int Seconds[]= {0, 0};


void setup() {
  
  DEBUG_SERIAL.begin(115200); //Start Debug serial


while(!DEBUG_SERIAL)

if(DEBUG_SERIAL){
  if(!Clock.begin()) {
        DEBUG_SERIAL.println("Couldn't find RTC!");
        DEBUG_SERIAL.flush();
        while (1) delay(10);
    }

  DEBUG_SERIAL.print("RTC Time: "); //Print current RTC time
  DEBUG_SERIAL.print(Clock.now().hour());
  DEBUG_SERIAL.print(":");
  DEBUG_SERIAL.print(Clock.now().minute());
  DEBUG_SERIAL.print(":");
  DEBUG_SERIAL.println(Clock.now().second());

  DEBUG_SERIAL.println("Set RTC Clock");

  DEBUG_SERIAL.print("Enter Year (2022): ");
  while (!DEBUG_SERIAL.available());
    int year = Serial.parseInt();
    Serial.read();
  DEBUG_SERIAL.println(year);

  DEBUG_SERIAL.print("Enter Month (1-12): ");
  while (!DEBUG_SERIAL.available());
    int month = Serial.parseInt();
    Serial.read();
  DEBUG_SERIAL.println(month);

  DEBUG_SERIAL.print("Enter Day (1-31): ");
  while (!DEBUG_SERIAL.available());
    int day = Serial.parseInt();
    Serial.read();
  DEBUG_SERIAL.println(day);

  DEBUG_SERIAL.print("Enter Hour (0-23): ");
  while (!DEBUG_SERIAL.available());
    int hour = Serial.parseInt();
    Serial.read();
  DEBUG_SERIAL.println(hour);

  DEBUG_SERIAL.print("Enter Minute (0-59): ");
  while (!DEBUG_SERIAL.available());
    int minute = Serial.parseInt();
    Serial.read();
  DEBUG_SERIAL.println(minute);

  DEBUG_SERIAL.print("Enter Second (0-59): ");
  while (!DEBUG_SERIAL.available());
    int second = Serial.parseInt();
    Serial.read();
  DEBUG_SERIAL.println(second);

  Clock.adjust(DateTime(year, month, day, hour, minute, second));

  DEBUG_SERIAL.print("RTC Time Set: "); //Print current RTC time
  DEBUG_SERIAL.print(Clock.now().hour());
  DEBUG_SERIAL.print(":");
  DEBUG_SERIAL.print(Clock.now().minute());
  DEBUG_SERIAL.print(":");
  DEBUG_SERIAL.println(Clock.now().second());
}

  Actuators.begin(57600); //Set DXL Baudrate
  Actuators.setPortProtocolVersion(2.0);

  for (int i = 0; i < 2; i++)
  {
  Actuators.torqueOff(DXL_Hours[i]);
  Actuators.setOperatingMode(DXL_Hours[i], OP_EXTENDED_POSITION);
  Actuators.torqueOn(DXL_Hours[i]);
  Actuators.writeControlTableItem(PROFILE_VELOCITY, DXL_Hours[i], 500);

  Actuators.torqueOff(DXL_Minutes[i]);
  Actuators.setOperatingMode(DXL_Minutes[i], OP_EXTENDED_POSITION);
  Actuators.torqueOn(DXL_Minutes[i]);
  Actuators.writeControlTableItem(PROFILE_VELOCITY, DXL_Minutes[i], 1000);

  Actuators.torqueOff(DXL_Seconds[i]);
  Actuators.setOperatingMode(DXL_Seconds[i], OP_EXTENDED_POSITION);
  Actuators.torqueOn(DXL_Seconds[i]);
  Actuators.writeControlTableItem(PROFILE_VELOCITY, DXL_Seconds[i], 0);
  }

}

void loop() {


//Fetch times for clock
CTime[0] = Clock.now().hour();
CTime[1] = Clock.now().minute();
CTime[2] = Clock.now().second();
  
//Divide by 10 to get 10s place
Hours[0] = CTime[0]/10;
Minutes[0] = CTime[1]/10;
Seconds[0]= CTime[2]/10;

//Modulus 10 to get 1s place
Hours[1] = CTime[0]%10;
Minutes[1] = CTime[1]%10;
Seconds[1]= CTime[2]%10;

DEBUG_SERIAL.print(CTime[0]);
DEBUG_SERIAL.print(":");
DEBUG_SERIAL.print(CTime[1]);
DEBUG_SERIAL.print(":");
DEBUG_SERIAL.println(CTime[2]);
    
  for (int i = 0; i < 2; i++)
  {
    Actuators.setGoalPosition(DXL_Hours[i], Position[Hours[i]]);
    Actuators.setGoalPosition(DXL_Minutes[i], Position[Minutes[i]]);
    Actuators.setGoalPosition(DXL_Seconds[i], Position[Seconds[i]]);
}

}

