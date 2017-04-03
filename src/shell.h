#include <vexcompat.h>
// Custom commands go here
void marcoTest(vexStream *chp, int argc, char *argv[]) {
  chprintf("hello world\r\n");
}

/*-----------------------------------------------------------------------------*/
/* Command line related.                                                       */
/*-----------------------------------------------------------------------------*/

#define SHELL_WA_SIZE   THD_WA_SIZE(512)

// Shell command
static const ShellCommand commands[] = {
  {"adc",     vexAdcDebug },
  {"spi",     vexSpiDebug },
  {"motor",   vexMotorDebug},
  {"lcd",     vexLcdDebug},
  {"enc",     vexEncoderDebug},
  {"son",     vexSonarDebug},
  {"ime",     vexIMEDebug},
  {"test",    vexTestDebug},
  {"marco",   marcoTest},
   {NULL, NULL}
};

// configuration for the shell
static const ShellConfig shell_cfg1 = {
  (vexStream *)SD_CONSOLE,
   commands
};

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
