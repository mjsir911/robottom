#include "motorconfig.h"
#include "vex.h"
#include "complex.h"

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
        { kVexMotor_1,      kVexMotor393T,               kVexMotorNormal,       kVexSensorNone,        0 },
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

void drive(short vert, short hori) {
  short left  = vert + hori;
  short right = vert - hori;

  left = normalizeMotion(left);
  right = normalizeMotion(right);

  wheelMotion(left, right);
}

/*
void newSetMotorFunction(short vert, short hori) {
  float e = 2.718281828459045;
  int angle = creal(e**(X*1j)) / cimag(e**(X*1j));
  //int angle = atan(vert/hori);
  char speed = sqrt((hori*hori)+(vert*vert));
  char setLeft = 0;
  char setRight = 0;
  
  if      ((  0 < angle) && (angle <  90)) { setLeft =  127; }
  else if (( 90 < angle) && (angle < 180)) { setLeft = (-0.031358 * x*x) + (5.64444 * x) -  127; } 
  else if ((180 < angle) && (angle < 270)) { setLeft = -127; }
  else if ((270 < angle) && (angle < 360)) { setLeft = (-0.031358 * x*x) + (22.5778 * x) - 3937; } 

  if      ((  0 < angle) && (angle <  90)) { setRight =  127; }
  else if (( 90 < angle) && (angle < 180)) { setRight = (-0.031358 * x*x) + (5.64444 * x) - 127; }
  else if ((180 < angle) && (angle < 270)) { setRight = -127; }
  else if ((270 < angle) && (angle < 360)) { setRight = (-0.031358 * x*x) + (11.2889 * x) - 889; }
  wheelMotion(setLeft*speed+10, setRight*speed+10);
}
*/

void pollMotion(void) {
  short vert = VERT;  
  short hori = HORI;

  drive(vert, hori);
  //newSetMotorFunction(vert, hori);

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

void autoMove(int steps) {
  int i = 0;
  while (i < steps) {
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
    degrees *= -1
    turn = 127
  } else {
    turn = 0
  }
  wheelMotion(turn, turn);
  vexSleep(DEG2SEC(degrees));
  wheelMotion(0, 0); 
}

void runAutonomous(void) {
  //autoMove(25);
  autoTurn(90);
}
