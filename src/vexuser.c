//#include <stdlib.h> # why is this even here
#include <stdbool.h>

#include "ch.h"          // needs for all ChibiOS programs
#include "hal.h"         // hardware abstraction layer header
#include "vex.h"        // vex library header

//Marco
#include "motorconfig.h"

//Vince
#include "meCompetitionControlSpoof.c"

void identifyOperator(int time) {
      vexDigitalPinSet(kVexDigital_1, kVexDigitalHigh);
      vexSleep(time);
      vexDigitalPinSet(kVexDigital_1, kVexDigitalLow);
      vexSleep(time);
}


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
  chThdCreateStatic(waModeControl, sizeof(waModeControl), NORMALPRIO-1, modeControl, NULL);
}
  

/*-----------------------------------------------------------------------------*/
/** @brief      Autonomous                                                     */
/*-----------------------------------------------------------------------------*/
/** @details
 *  This thread is started when the autonomous period is started
 */
msg_t vexAutonomous( void *arg ) {
    (void)arg;

    // Must call this
    vexTaskRegister("auton");

    while( TRUE ) {
        identifyOperator(25);

        runAutonomous();

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
msg_t vexOperator( void *arg ) {
    (void)arg;

    // Must call this
    vexTaskRegister("operator");

    // Run until asked to terminate
    while (!chThdShouldTerminate()) {
        
        pollMotion();

        if (vexControllerGet(Btn5)) {
          turn(90);
        }
        if (vexControllerGet(Btn6)) {
          turn(-90);
        }



        // Don't hog cpu
        vexSleep( 25 );
        
        }

    return (msg_t)0;
}

