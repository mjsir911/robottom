#include <stdlib.h>
#include <stbool.h>

#include "ch.h"          // needs for all ChibiOS programs
#include "hal.h"         // hardware abstraction layer header
#include "vex.h"        // vex library header

//Marco
#include "motorconfig.h"

void vexUserInit(void) {
  vexAudioPlaySound(256, 100, 100); // say im awake

  while (TRUE) {
    pollMotion();
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
msg_t
vexOperator( void *arg )
{
    (void)arg;

    // Must call this
    vexTaskRegister("operator");

    // Run until asked to terminate
    while( !chThdShouldTerminate() ) {
        }

    return (msg_t)0;
}
