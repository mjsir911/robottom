#include "hal.h"
#include "vex.h"
#include "stdbool.h"

/*-----------------------------------------------------------------------------*/
/** @brief      Manual mode control                                            */
/*  https://www.vexforum.com/index.php/10069-convex-open-source-firmware-for-the-cortex/0?search=active+last+%3F+days
 *  */
/*-----------------------------------------------------------------------------*/
void setAutoOn(void) {
  vexControllerCompetitionStateSet(kFlagAutonomousMode, kFlagAutonomousMode | kFlagAutonomousMode);
}
void setContOn(void) {
  vexControllerCompetitionStateSet(0, kFlagAutonomousMode | kFlagDisabled); 
}


WORKING_AREA(waModeControl,64);
msg_t modeControl( void *arg ) {
  (void)arg;
  vexTaskRegister("modeControl");

  setAutoOn();
  vexSleep(15 * 10);
  setContOn();
  //vexControllerCompetitionStateSet(1, kFlagDisabled);


    //if (vexControllerGet(Ch3) > 0) {
      /*
      *   (value, mask)
      *   mask is which controller flag you're changing
      *   value is what you're setting it to
      *   kFlagAutonomousMode = 0x40
      *   0 is driver control mode
      *   1 is autonomous mode
      */
      // ABOVE ENABLES CONTROLLER MODE
      // ABOVE ENABLES AUTONOMOUS MODE

  return (msg_t)0;

}
