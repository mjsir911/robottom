#include "hal.h"         // hardware abstraction layer header
#include "vex.h"

// Digi IO configuration
static  vexDigiCfg  dConfig[kVexDigital_Num] = {
        { kVexDigital_1,    kVexSensorDigitalOutput, kVexConfigOutput,      0 },
        { kVexDigital_2,    kVexSensorDigitalOutput, kVexConfigOutput,      0 },
        { kVexDigital_3,    kVexSensorDigitalInput,  kVexConfigInput,       0 },
        { kVexDigital_4,    kVexSensorDigitalInput,  kVexConfigInput,       0 },
        { kVexDigital_5,    kVexSensorDigitalInput,  kVexConfigInput,       0 },
        { kVexDigital_6,    kVexSensorDigitalInput,  kVexConfigInput,       0 },
        { kVexDigital_7,    kVexSensorDigitalInput,  kVexConfigInput,       0 },
        { kVexDigital_8,    kVexSensorDigitalInput,  kVexConfigInput,       0 },
        { kVexDigital_9,    kVexSensorDigitalInput,  kVexConfigInput,       0 },
        { kVexDigital_10,   kVexSensorDigitalInput,  kVexConfigInput,       0 },
        { kVexDigital_11,   kVexSensorDigitalInput,  kVexConfigInput,       0 },
        { kVexDigital_12,   kVexSensorDigitalInput,  kVexConfigInput,       0 }
};

static  vexMotorCfg mConfig[kVexMotorNum] = {
        { kVexMotor_1,      kVexMotor393T,               kVexMotorReversed,       kVexSensorNone,        0 },
        { kVexMotor_2,      kVexMotorUndefined,          kVexMotorNormal,       kVexSensorNone,        0 },
        { kVexMotor_3,      kVexMotorUndefined,          kVexMotorNormal,       kVexSensorNone,        0 },
        { kVexMotor_4,      kVexMotorUndefined,          kVexMotorNormal,       kVexSensorNone,        0 },
        { kVexMotor_5,      kVexMotorUndefined,          kVexMotorNormal,       kVexSensorNone,        0 },
        { kVexMotor_6,      kVexMotorUndefined,          kVexMotorNormal,       kVexSensorNone,        0 },
        { kVexMotor_7,      kVexMotorUndefined,          kVexMotorNormal,       kVexSensorNone,        0 },
        { kVexMotor_8,      kVexMotorUndefined,          kVexMotorNormal,       kVexSensorNone,        0 },
        { kVexMotor_9,      kVexMotor393T,               kVexMotorNormal,       kVexSensorNone,        0 },
        { kVexMotor_10,     kVexMotor393T,               kVexMotorNormal,       kVexSensorNone,        0 }
};

#define WHEEL_LEFT  kVexMotor_1
#define WHEEL_RIGHT kVexMotor_10
void wheelMotion(signed char left, signed char right);
#define VERT vexControllerGet(Ch1)
#define HORI vexControllerGet(Ch2)
void pollMotion(void);
