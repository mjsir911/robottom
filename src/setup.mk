# uncomment these if running from default project location
# Path to ChibiOS
CHIBIOS    = include/ChibiOS
# Path to convex
CONVEX     = include/cortex

PROJECT = robos
BUILDDIR = build
INCDIR = src
#USE_VERBOSE_COMPILE = yes
# uncomment to use the optional code like the smart motor library
CONVEX_OPT  = yes

# User C code files
VEXUSERSRC = src/vexuser.c

# Uncomment and add/modify user include files
VEXUSERINC = src/ src/conf/

# MARCO - User dependency files(source files)
USERDEPS := $(wildcard src/*.h)
USERDEPS := $(USERDEPS:.h=.c)
