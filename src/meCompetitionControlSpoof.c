#include "hal.h"
#include "vex.h"
#include "stdbool.h"

/*-----------------------------------------------------------------------------*/
/** @brief      Manual mode control                                            */
/*  https://www.vexforum.com/index.php/10069-convex-open-source-firmware-for-the-cortex/0?search=active+last+%3F+days
 *  */
/*-----------------------------------------------------------------------------*/
WORKING_AREA(waModeControl,64);
msg_t modeControl( void *arg ) {
  (void)arg;
  vexTaskRegister("modeControl");

  //vexControllerCompetitionStateSet(1, kFlagDisabled);

  while (TRUE) { 
    //if (vexControllerGet(Ch3) > 0) {
    if (true) {
      /*
      *   (value, mask)
      *   mask is which controller flag you're changing
      *   value is what you're setting it to
      *   kFlagAutonomousMode = 0x40
      *   0 is driver control mode
      *   1 is autonomous mode
      */
      vexControllerCompetitionStateSet(0, kFlagAutonomousMode | kFlagDisabled); 
      // ABOVE ENABLES CONTROLLER MODE
    }
    else if (vexControllerGet(Ch3) < 0) {
      vexControllerCompetitionStateSet(kFlagAutonomousMode, kFlagAutonomousMode | kFlagAutonomousMode);
      // ABOVE ENABLES AUTONOMOUS MODE
    }
    vexSleep(25);
  }

  return (msg_t)0;

}
