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
        { kVexMotor_1,      kVexMotor393T,               kVexMotorNormal,       kVexSensorNone,        0 }, //Left  Wheel
        { kVexMotor_2,      kVexMotorUndefined,          kVexMotorNormal,       kVexSensorNone,        0 }, //Left  Arm Lower
        { kVexMotor_3,      kVexMotorUndefined,          kVexMotorNormal,       kVexSensorNone,        0 }, //Left  Arm Upper
        { kVexMotor_4,      kVexMotorUndefined,          kVexMotorNormal,       kVexSensorNone,        0 },
        { kVexMotor_5,      kVexMotorUndefined,          kVexMotorNormal,       kVexSensorNone,        0 },
        { kVexMotor_6,      kVexMotorUndefined,          kVexMotorNormal,       kVexSensorNone,        0 },
        { kVexMotor_7,      kVexMotorUndefined,          kVexMotorNormal,       kVexSensorNone,        0 },
        { kVexMotor_8,      kVexMotorUndefined,          kVexMotorReversed,     kVexSensorNone,        0 }, //Right Arm Upper
        { kVexMotor_9,      kVexMotor393T,               kVexMotorReversed,     kVexSensorNone,        0 }, //Right Arm Lower
        { kVexMotor_10,     kVexMotor393T,               kVexMotorNormal,       kVexSensorNone,        0 }  //Right Wheel
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

void drive(short vert, short hori) {
  short left  = vert + hori;
  short right = vert - hori;

  left = normalizeMotion(left);
  right = normalizeMotion(right);

  wheelMotion(left, right);
}

void pollMotion(void) {
  short vert = VERT;  
  short hori = HORI;

  drive(vert, hori);

}

//11 is left, 12 is right

void move(signed int inches) {
  int i = 0;
  while (i < inches) {
    drive( 127, 0 );
    i++;
  }
}

#define DEG2SEC(d) 1000 * d / 125
void turn(signed int degrees) {
  signed short turn;

  if ( degrees > 0 ) {
    turn = -127;
  } else if ( degrees < 0 ) {
    degrees *= -1;
    turn = 127;
  } else {
    turn = 0;
  }
  wheelMotion(turn, turn);
  vexSleep(DEG2SEC(degrees));
  wheelMotion(0, 0); 
}

void runAutonomous(void) {
  //autoMove(25);
  //turn(90);
}


void triggerButtons(void) {
  signed char left  = 0;
  signed char right = 0;
        if (vexControllerGet(Btn5D)) {
          //turn(90);
          left = -127;
        }
        if (vexControllerGet(Btn6D)) {
          //turn(-90);
          right = -127;
        }

        if (vexControllerGet(Btn5U)) {
          //turn(1);
          left = 127;
        }
        if (vexControllerGet(Btn6U)) {
          //turn(-1);
          right = 127;
        }

        if (left  != 0) {vexMotorSet(WHEEL_LEFT ,  left );}
        if (right != 0) {vexMotorSet(WHEEL_RIGHT, -right);}
}

#define ARM_LEFT_LOWER  kVexMotor_2
#define ARM_RIGHT_LOWER kVexMotor_9
#define ARM_LEFT_UPPER  kVexMotor_3
#define ARM_RIGHT_UPPER kVexMotor_8

void pollArm() {
  signed char vert = vexControllerGet(3);
  signed char hori = vexControllerGet(4);
  moveArm(vert);
}

void moveArm(signed char position) {
  vexMotorSet(ARM_LEFT_LOWER,   position);
  vexMotorSet(ARM_RIGHT_LOWER,  position);
  vexMotorSet(ARM_LEFT_UPPER,  -position);
  vexMotorSet(ARM_RIGHT_UPPER, -position);
}
