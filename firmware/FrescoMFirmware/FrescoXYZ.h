#ifndef FrescoXYZ_h
#define FrescoXYZ_h

#include "MotorController.h"
#include "Command.h"
#include "Point.h"

// Contains all motor controllers
class FrescoXYZ {

  private:
  
    MotorController* xMotorController;
    MotorController* yMotorController;
    MotorController* zMotorController;
    
    long xLeftPostition;
    long xRightPosition;
    long yTopPosition;
    long yBottomPosition;
    long xLength;
    long yLength;

  void saveBottomRightPosition();
  void saveTopLeftPosition();
  Point restoreBottomRightPosition();
  Point restoreTopLeftPosition();
  
  public:
  
  FrescoXYZ(MotorController* xMotorController, 
            MotorController* yMotorController, 
            MotorController* zMotorController);

  void setPosition(long x, 
                   long y, 
                   long z);
  
  void moveDelta(long x, 
                 long y, 
                 long z);

  void goToZero();
  long getXLength();
  long getYLength();
  Point getBottomRight();
  Point getTopLeft();
  long EEPROMReadlong(long address);
  void EEPROMWritelong(int address, long value);
  
  void perform(Command command);
  
};

#endif