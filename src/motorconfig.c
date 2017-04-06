#include "motorconfig.h"

void wheelMotion(signed char left, signed char right) {
  vexMotorSet(WHEEL_RIGHT, right);
  vexMotorSet(WHEEL_LEFT , left);
  
}

void pollMotion(void) {
  short vert = VERT;  
  short hori = HORI;  
  short left  = vert - hori;
  short right = vert + hori;

  if      (left >   127) {left  =  127;}
  else if (left <  -127) {left  = -127;}

  if      (right >  127) {right =  127;}
  else if (right < -127) {right = -127;}
  
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
