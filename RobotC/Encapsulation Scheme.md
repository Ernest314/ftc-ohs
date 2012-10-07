# Encapsulation Scheme (RobotC)

## Original Functions/Variables
- Motors
    - `bool bFloatDuringInactiveMotorPWM`
      - true is coast, false is brake
    - `bool bMotorReflected[tMotor motor]`
      - whether that motor is reflected or not
    - `int motor[tMotor motor]`
      - sets motor power level, from -100 to 100
    - `int nMaxRegulatedSpeedNXT`
      - max speed for PID regulation, default is 1000
    - `long nMotorEncoder[tMotor motor]`
      - current value of encoder, wraps after about 90 turns
    - `long nMotorEncoderTarget[tMotor motor]`
      - after target is reached motor will stop, 0 means never stop
    - `TMotorRegulation nMotorPIDSpeedCtrl[tMotor motor]`
      - whether PID is on; on by default
    - `TNxtRunState nMotorRunState[tMotor motor]`
      - what the motor is doing; running, stopped, etc.
    - `int nPidUpdateInterval`
      - default is 25; too high = unregulated; too low = unsmooth
    - `TSynchedMotors nSyncedMotors`
      - `=synchXY`, `X` is master, `Y` is slave
    - `int nSyncedTurnRatio`
      - turn ratio for slave, from -100 to 100
- Sensors
- Joystick
- Buttons
- File Access
- Timing
- Sound
- Display
- Bluetooth
- Miscellaneous

## New Functions
- Motors
- Sensors
- Joystick
- Buttons
- File Access
- Timing
- Sound
- Display
- Bluetooth
- Miscellaneous
