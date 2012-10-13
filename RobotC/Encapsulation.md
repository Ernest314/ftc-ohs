# Encapsulation Scheme (RobotC)

NOTE: The "natural language" advertised by RobotC is actually very limited.  
Its only useful function is the `void wait(float waitTime)` function.

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
	- `getJoystickSettings(joystick)` _(fn)_
		- gets newest data from joysticks
		- joysticks send data every 50 to 100 ms
		- argument is always `joystick`
	- `TPCJoystick joy1_Buttons` _(var)_
		- returns a "bitmap" of which buttons are pressed
		- COMPLICATED mechanism I haven't figured out yet
		- involves two undocumented functions
	- `TPCJoystick joy1_TopHat` _(var)_
		- returns octant "direction pad" is in
		- -1 when nothing pressed, 0 to 7 for the octants
	- `TPCJoystick joy1_x1` _(var)_
		- value of x-axis on left joystick, from -128 to 127
	- `TPCJoystick joy1_y1` _(var)_
		- value of y-axis on left joystick, from -128 to 127
	- `TPCJoystick joy1_x2` _(var)_
		- value of x-axis on right joystick, from -128 to 127
	- `TPCJoystick joy1_y2` _(var)_
		- value of y-axis on right joystick, from -128 to 127
	- `TPCJoystick joy2_Buttons` _(var)_
		- returns a "bitmap" of which buttons are pressed
		- COMPLICATED mechanism I haven't figured out yet
		- involves two undocumented functions
	- `TPCJoystick joy2_TopHat` _(var)_
		- returns octant "direction pad" is in
		- -1 when nothing pressed, 0 to 7 for the octants
	- `TPCJoystick joy2_x1` _(var)_
		- value of x-axis on left joystick, from -128 to 127
	- `TPCJoystick joy2_y1` _(var)_
		- value of y-axis on left joystick, from -128 to 127
	- `TPCJoystick joy2_x2` _(var)_
		- value of x-axis on right joystick, from -128 to 127
	- `TPCJoystick joy2_y2` _(var)_
		- value of y-axis on right joystick, from -128 to 127
- __NXT Buttons__
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
	- According to what I see on the API, this is pretty unnecessary.
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
	- `word bPlaySounds` _(var)_
		- bool flag indicating whether new sounds should be accepted
		- `true` or `false` value
	- `const bool bSoundActive` _(var)_
		- flag indicating if system is playing a sound
	- `const bool bSoundQueueAvailable` _(var)_
		- flag indicating whether sound queue space is available
	- `void ClearSounds()` _(fn)_
		- clears existing and buffered sound commands
	- `void MuteSound()` _(fn)_
		- mutes all subsequent sound commands
	- `word nVolume` _(var)_
		- sets volume, from 0 to 4 (loudest)
	- `void PlayImmediateTone(const int x, const int y)` _(fn)_
		- _variable clarification_:
			* "x" = `frequency`
			* "y" = `durationIn10MsecTicks`
		- plays tone ahead of other queued requests
	- `void PlaySound(TSounds sound)` _(fn)_
		- plays a system predefined sound
			* 0 = `soundBlip`
			* 1 = `soundBeepBeep`
			* 2 = `soundDownwardTones`
			* 3 = `soundUpwardTones`
			* 4 = `soundLowBuzz`
			* 5 = `soundFastUpwardTones`
			* 6 = `soundShortBlip`
			* 7 = `soundException`
			* 8 = `soundLowBuzzShort`
	- `void PlaySoundFile(const string &sFileName)` _(fn)_
		- plays a sound file present on the NXT file system
	- `void PlayTone(const int x, const int y)` _(fn)_
		- _variable clarification_:
			* "x" = `frequency`
			* "y" = `durationIn10MsecTicks`
		- plays a constant tone
	- `void UnmuteSound()` _(fn)_
		- restores sound playback to volume before mute
- __Display__
- __Bluetooth__
- __Miscellaneous__

## Custom Functions/Variables
_These are all functions. Duh._
- __Motors__
	- `Motor_Forward(int port, int power=75)`
	- `Motor_Reverse(int port, int power=75)`
	- `Motor_Stop(int port, bool brake=true)`
	- `Motor_ExactRotation(int port, int a, int p, bool brake=true)`
		- variable clarification:
			* `int a` is the angle in degrees
			* `int p` is the power; default is 75
	- `Motor_GetRotation(int port)`
	- `Motor_ClearRotation(int port, bool relative)`
		- ??? `relative` to what? program? function?
- __Servos__
- __Sensors__
- __Joystick__
- __NXT Buttons__
- __File Access__
- __Timing__
- __Sound__
- __Display__
- __Bluetooth__
- __Miscellaneous__
