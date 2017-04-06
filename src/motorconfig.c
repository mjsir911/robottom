#include "motorconfig.h"
void wheelMotion(unsigned char left, unsigned char right) {
  vexMotorSet( WHEEL_RIGHT, right );
  vexMotorSet( WHEEL_LEFT , left  );
}

void pollMotion(void) {
  wheelMotion( VERT - HORI, VERT + HORI );
}
