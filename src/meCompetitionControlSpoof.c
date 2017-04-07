#include "hal.h"
#include "vex.h"

/*-----------------------------------------------------------------------------*/
/** @brief      Manual mode control                                            */
/*-----------------------------------------------------------------------------*/
WORKING_AREA(waModeControl,64);
msg_t modeControl( void *arg ) {
  (void)arg;
  vexTaskRegister("modeControl");

  vexControllerCompetitionStateSet(0, kFlagDisabled);

  while (TRUE) { 
    if (vexControllerGet(Ch3) > 0) {
      /*
      *   (value, mask)
      *   mask is which controller flag you're changing
      *   value is what you're setting it to
      *   kFlagAutonomousMode = 0x40
      *   0 is driver control mode
      *   1 is autonomous mode
      */
      vexControllerCompetitionStateSet(0, kFlagAutonomousMode);
    }
    else if (vexControllerGet(Ch3) < 0) {
      vexControllerCompetitionStateSet(1, kFlagAutonomousMode);
    }
    vexSleep(25);
  }

  return (msg_t)0;

}
