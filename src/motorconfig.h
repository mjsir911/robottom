#include "hal.h"         // hardware abstraction layer header
#include "vex.h"

extern vexDigiCfg  dConfig[kVexDigital_Num];
extern vexMotorCfg mConfig[kVexMotorNum];

void configMotors(void);

#define WHEEL_LEFT  kVexMotor_1
#define WHEEL_RIGHT kVexMotor_10
void wheelMotion(signed char left, signed char right);
#define VERT vexControllerGet(Ch1)
#define HORI vexControllerGet(Ch2)
void pollMotion(void);

