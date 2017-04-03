// Digi IO configuration
static  vexDigiCfg  dConfig[kVexDigital_Num] = {
        { kVexDigital_1,    kVexSensorDigitalOutput, kVexConfigOutput,      0 },
        { kVexDigital_2,    kVexSensorDigitalOutput, kVexConfigOutput,      0 },
        { kVexDigital_3,    kVexSensorDigitalInput,  kVexConfigInput,       0 },
        { kVexDigital_4,    kVexSensorDigitalInput,  kVexConfigInput,       0 },
        { kVexDigital_5,    kVexSensorDigitalInput,  kVexConfigInput,       0 },
        { kVexDigital_6,    kVexSensorDigitalInput,  kVexConfigInput,       0 },
        { kVexDigital_7,    kVexSensorDigitalInput,  kVexConfigInput,       0 },
        { kVexDigital_8,    kVexSensorDigitalInput,  kVexConfigInput,       0 },
        { kVexDigital_9,    kVexSensorDigitalInput,  kVexConfigInput,       0 },
        { kVexDigital_10,   kVexSensorDigitalInput,  kVexConfigInput,       0 },
        { kVexDigital_11,   kVexSensorDigitalInput,  kVexConfigInput,       0 },
        { kVexDigital_12,   kVexSensorDigitalInput,  kVexConfigInput,       0 }
};

static  vexMotorCfg mConfig[kVexMotorNum] = {
        { kVexMotor_1,      kVexMotor393T,               kVexMotorReversed,       kVexSensorNone,        0 },
        { kVexMotor_2,      kVexMotorUndefined,          kVexMotorNormal,       kVexSensorNone,        0 },
        { kVexMotor_3,      kVexMotorUndefined,          kVexMotorNormal,       kVexSensorNone,        0 },
        { kVexMotor_4,      kVexMotorUndefined,          kVexMotorNormal,       kVexSensorNone,        0 },
        { kVexMotor_5,      kVexMotorUndefined,          kVexMotorNormal,       kVexSensorNone,        0 },
        { kVexMotor_6,      kVexMotorUndefined,          kVexMotorNormal,       kVexSensorNone,        0 },
        { kVexMotor_7,      kVexMotorUndefined,          kVexMotorNormal,       kVexSensorNone,        0 },
        { kVexMotor_8,      kVexMotorUndefined,          kVexMotorNormal,       kVexSensorNone,        0 },
        { kVexMotor_9,      kVexMotor393T,               kVexMotorNormal,       kVexSensorNone,        0 },
        { kVexMotor_10,     kVexMotor393T,               kVexMotorNormal,       kVexSensorNone,        0 }
};

/*-----------------------------------------------------------------------------*/
/** @brief      User setup                                                     */
/*-----------------------------------------------------------------------------*/
/** @details
 *  The digital and motor ports can (should) be configured here.
 */
void
vexUserSetup()
{
    vexDigitalConfigure( dConfig, DIG_CONFIG_SIZE( dConfig ) );
    vexMotorConfigure( mConfig, MOT_CONFIG_SIZE( mConfig ) );
}

void wheelMotion(unsigned char left, unsigned char right) {
  #define WHEEL_LEFT  kVexMotor_1
  #define WHEEL_RIGHT kVexMotor_10
  vexMotorSet( WHEEL_RIGHT, right );
  vexMotorSet( WHEEL_LEFT , left  );
}

void pollMotion(void) {
  #define VERT vexControllerGet(Ch1)
  #define HORI vexControllerGet(Ch2)
  wheelMotion( VERT - HORI, VERT + HORI );
}
