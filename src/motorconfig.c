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

  if   (left >   127) {left  =  127;}
  elif (left <  -127) {left  = -127;}

  if   (right >  127) {right =  127;}
  elif (right < -127) {right = -127;}
  
  wheelMotion(left, right);
}
