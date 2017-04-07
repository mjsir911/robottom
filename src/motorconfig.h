#include "hal.h"         // hardware abstraction layer header
#include "vex.h"

static vexDigiCfg  dConfig[kVexDigital_Num]__attribute__((unused));
static vexMotorCfg mConfig[kVexMotorNum]__attribute__((unused)); // WHAT THE EVERLIVING FUCK

void configMotors(void);

#define WHEEL_LEFT  kVexMotor_1
#define WHEEL_RIGHT kVexMotor_10
void wheelMotion(signed char left, signed char right);
#define VERT vexControllerGet(Ch1)
#define HORI vexControllerGet(Ch2)
void pollMotion(void);

