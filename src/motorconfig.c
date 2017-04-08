#include "motorconfig.h"
#include "vex.h"

// Digi IO configuration
extern vexDigiCfg dConfig[kVexDigital_Num];
vexDigiCfg dConfig[kVexDigital_Num] = {
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

extern vexMotorCfg mConfig[kVexMotorNum];
vexMotorCfg mConfig[kVexMotorNum] = {
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

void wheelMotion(signed char left, signed char right) {
  vexMotorSet(WHEEL_RIGHT, right);
  vexMotorSet(WHEEL_LEFT , left);
  
}

static signed char normalizeMotion(short motorspeed) {
  if      (motorspeed >   127) {motorspeed  =  127;}
  else if (motorspeed <  -127) {motorspeed  = -127;}
  return motorspeed;
}

void pollMotion(void) {
  short vert = VERT;  
  short hori = HORI;  
  short left  = vert + hori;
  short right = vert - hori;

  left = normalizeMotion(left);
  right = normalizeMotion(right);

  wheelMotion(left, right);
}

void buttonTestThingy(void) {
    if ( vexControllerGet(Btn5) ) {
      int i = 0;
      for (i = 0; i < 128; i++) {
        wheelMotion(i, 127-i);
        vexSleep(20);
      }
    }
}
