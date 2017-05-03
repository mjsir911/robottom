#include "vex.h"

void marcoTest(vexStream *chp, int argc, char *argv[]);
void shellMove(vexStream *chp, int argc, char *argv[]);

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
  {"move",    shellMove},
   {NULL, NULL}
};

// configuration for the shell
static const ShellConfig shell_cfg1 = {
  (vexStream *)SD_CONSOLE,
  commands
};

void shellMonitor(Thread *shelltp);
