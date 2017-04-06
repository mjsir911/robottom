//#include <stdlib.h> # why is this even here
#include <stdbool.h>

#include "ch.h"          // needs for all ChibiOS programs
#include "hal.h"         // hardware abstraction layer header
#include "vex.h"        // vex library header

//Marco
#include "motorconfig.c"

/*-----------------------------------------------------------------------------*/
/** @brief      User setup                                                     */
/*-----------------------------------------------------------------------------*/
/** @details
 *  The digital and motor ports can (should) be configured here.
 */
void vexUserSetup() {
    vexDigitalConfigure( dConfig, DIG_CONFIG_SIZE( dConfig ) );
    vexMotorConfigure( mConfig, MOT_CONFIG_SIZE( mConfig ) );
}


/*-----------------------------------------------------------------------------*/
/** @brief      User initialize                                                */
/*-----------------------------------------------------------------------------*/
/** @details
 *  This function is called after all setup is complete and communication has
 *  been established with the master processor.
 *  Start other tasks and initialize user variables here
 */
 
  void vexUserInit(void) {
  vexAudioPlaySound(256, 100, 100); // say I'm awake
}
  
  
#define time  2500




void buttonTestThingy(void) {
    if ( vexControllerGet(Btn5) ) {
      int i = 0;
      for (i = 0; i < 128; i++) {
        safeMotorSet(MotorDriveL, i);
        safeMotorSet(MotorDriveR, 127-i);
      }
    }
}

/*-----------------------------------------------------------------------------*/
/** @brief      Autonomous                                                     */
/*-----------------------------------------------------------------------------*/
/** @details
 *  This thread is started when the autonomous period is started
 */
msg_t vexAutonomous( void *arg )
{
    (void)arg;

    // Must call this
    vexTaskRegister("auton");

    while(0)
        {
        // Don't hog cpu
        //
        vexSleep( 25 );
        }

    return (msg_t)0;
}


/*-----------------------------------------------------------------------------*/
/** @brief      Driver control                                                 */
/*-----------------------------------------------------------------------------*/
/** @details
 *  This thread is started when the driver control period is started
 */
msg_t vexOperator( void *arg )
{
    (void)arg;

    // Must call this
    vexTaskRegister("operator");

    // Run until asked to terminate

    while (!chThdShouldTerminate()) {
        
        pollMotion();

        // Don't hog cpu
        vexSleep( 25 );
        
        }

        if (Btn5) { vexMotorSet( MotorDriveR, 63); }
        if (Btn6) { vexMotorSet( MotorDriveL, 63); }
        

    return (msg_t)0;
}


/*-----------------------------------------------------------------------------*/
/** @brief      Manual mode control                                            */
/*-----------------------------------------------------------------------------*/
static WORKING_AREA(waModeControl,64);
msg_t modeControl( void *arg ) {
  (void)arg;
  vexTaskRegister("modeControl");

  while (TRUE) { 
    if (vexControllerGet(Ch3) > 0) {
      vexControllerCompetitionStateSet(1,1);
    }
    else if (vexControllerGet(Ch3) < 0) {
      vexControllerCompetitionStateSet(0,1);
    }
    vexSleep(25);
  }

  return (msg_t)0;

}
