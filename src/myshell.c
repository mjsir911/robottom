#include "hal.h"
#include "chprintf.h"
#include "myshell.h"
#include "motorconfig.h"

// Custom commands go here
void marcoTest(vexStream *chp, int argc, char *argv[]) {
  (void)argc; // gotta stop dem errors
  (void)argv;
  chprintf(chp, "hello world\r\n");
}

void shellMove(vexStream *chp, int argc, char *argv[]) {
  (void)argc; // gotta stop dem errors
  move(&argv[0]);
}

void getInputs(vexStream *chp, int argc, char *argv[]) {
  (void)argc; // gotta stop dem errors
  (void)argv;
  chprintf(chp, "%i", vexDigitalPinGet(kVexDigital_11));
}

void shellMonitor( Thread *shelltp ) {
  while ( true ) {
    if ( !shelltp )
      shelltp = shellCreate(&shell_cfg1, SHELL_WA_SIZE, NORMALPRIO);
    else
      if ( chThdTerminated(shelltp) ) {
        chThdRelease(shelltp);    /* Recovers memory of the previous shell.   */
        shelltp = NULL;           /* Triggers spawning of a new shell.        */
      }
    chThdSleepMilliseconds(50);
  }
}
