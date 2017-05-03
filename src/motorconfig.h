#include "hal.h"         // hardware abstraction layer header
#include "vex.h"

extern vexDigiCfg  dConfig[kVexDigital_Num];
extern vexMotorCfg mConfig[kVexMotorNum];

#define WHEEL_LEFT  kVexMotor_1
#define WHEEL_RIGHT kVexMotor_10
void wheelMotion(signed char left, signed char right);
static signed char normalizeMotion(short motorspeed);

void drive(short vert, short hori);
//void newSetMotorFunction(short vert, short hori);

#define VERT vexControllerGet(Ch1)
#define HORI vexControllerGet(Ch2)
void pollMotion(void);

void pickup(void);
void load(void);
void move(signed int inches);

void throwStar(void);

void autoMove(int steps);
void autoTurn(int steps);
void runAutonomous(void);
