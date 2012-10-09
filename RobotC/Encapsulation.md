# Encapsulation Scheme (RobotC)

## Original Functions/Variables
- __Motors__
    - `bool bFloatDuringInactiveMotorPWM` _(var)_
		- true is coast, false is brake
	- `bool bMotorReflected[tMotor motor]` _(var)_
		- whether that motor is reflected or not
	- `int motor[tMotor motor]` _(var)_
		- sets motor power level, from -100 to 100
	- `int nMaxRegulatedSpeedNXT` _(var)_
		- max speed for PID regulation (encoder counts/sec) 
		- default is 1000
	- `long nMotorEncoder[tMotor motor]` _(var)_
		- current value of encoder
		- wraps after about 90 turns
		- reset as often as possible to avoid overflow
	- `long nMotorEncoderTarget[tMotor motor]` _(var)_
		- after target is reached motor will stop, 0 means never stop
	- `TMotorRegulation nMotorPIDSpeedCtrl[tMotor motor]` _(var)_
		- whether PID is on; on by default
		- can be set in Motor & Sensor Setup
	- `TNxtRunState nMotorRunState[tMotor motor]` _(var)_
		- internal state of the motor:
			* 0x00 = `runStateIdle`
			* 0x10 = `runStateRampUp`
			* 0x20 = `runStateRunning`
			* 0x40 = `runStateRampDown`
			* 0x01 = `runStateHoldPosition`
	- `int nPidUpdateInterval` _(var)_
		- interval in ms to use for PID updates; default is 25
		- too short results in jerky motion
		- too high will seem unregulated (lag)
	- `TSynchedMotors nSyncedMotors` _(var)_
		- `=synchXY`, `X` is master, `Y` is slave
	- `int nSyncedTurnRatio` _(var)_
		- turn ratio for slave, from -100 to 100
- __Servos__
	- `short servoChangeRate[TServoIndex servo]` _(var)_
		- rate at which servo is changed, 0 is max speed
		- default is 10 positions/update
		- 20 milliseconds/update
	- `short servo[TServoIndex servo]` _(var)_
		- target position from 0 to 255
		- might take a couple updates to see effect
	- `short ServoValue[TServoIndex servo]` _(var)_
		- reads last position told to move to, not actual position
- __Sensors__
	- `word SensorRaw[tSensors sensor]` _(var)_
		- returns the un-normalized value, from 0 to 1023
	- `TSensorTypes SensorType[tSensors sensor]` _(var)_
		- sets the sensor type; try to use Sensor Setup instead
	- `word SensorValue[tSensors sensor]` _(var)_
		- returns the normalized/interpreted value
- __Joystick__
- __Buttons__
	- `TButtons nNxtButtonPressed` _(var)_
		- which button is currently pressed, only one at a time
			* -1 = `kNoButton`
			* 0 = `kExitButton`
			* 1 = `kRightButton`
			* 2 = `kLeftButton`
			* 3 = `kEnterButton`
	- `word nNxtButtonTask` _(var)_
		- has something to do with the program processing buttons
		- (no idea what this actually does)
	- `word nNxtExitClicks` _(var)_
		- how many "Exit Button" clicks until abort program
- __File Access__
- __Timing__
	- `void ClearTimer(TTimers theTimer)` _(fn)_
		- timers auto-start, always reset them; timer can be T1 to T4
	- `word nClockMinutes` _(var)_
		- a read/write var from 0 to 1439, wraps at 24 hours
	- `const long nPgmTime` _(var)_
		- program time; starts once program starts running
	- `const long nSysTime` _(var)_
		- system time; starts once NXT is turned on
	- `long time1[TTimers timer]` _(var)_
		- value of timer (T1 to T4) in units of 1 millisecond
	- `long time10[TTimers timer]` _(var)_
		- value of timer (T1 to T4) in units of 10 milliseconds
	- `long time100[TTimers timer]` _(var)_
		- value of timer (T1 to T4) in units of 100 milliseconds
	- `void wait1Msec(const long nMSec)` _(fn)_
		- does not consume CPU cycles
		- can be up to 32 milliseconds
		- nMSec is how many MSec to wait
	- `void wait10Msec(const long nTenMSec)` _(fn)_
		- does not consume CPU cycles
		- can be up to 320 milliseconds
		- nTenMSec is how many TenMSec to wait
- __Sound__
- __Display__
- __Bluetooth__
- __Miscellaneous__

## Custom Functions/Variables
- __Motors__
- __Servos__
- __Sensors__
- __Joystick__
- __Buttons__
- __File Access__
- __Timing__
- __Sound__
- __Display__
- __Bluetooth__
- __Miscellaneous__
