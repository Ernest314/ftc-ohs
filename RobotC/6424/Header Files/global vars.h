#ifndef GLOBAL_VARS_H
#define GLOBAL_VARS_H


// The position the IR servo needs to be in (180 deg)
const int g_IRServoDefault = 0;
const int g_IRServoExtended = 230;
const int g_clawServoDefault = 100;
const int g_clawServoExtended = 250;


// The threshold for joystick values to count (eliminates humming).
// The highest we've ever recorded is +-7.
const int g_JoystickThreshold = 10;


// The factor to divide by when fine-tuning motors.
const int g_FineTuneFactor = 4;


// The full speed the motors should be PID-regulated at.
const int g_FullMotorPower = 80;


// These angles are added onto the current encoder count of the
// lift motor (the "current" value varies at startup).
const int g_TopLiftAngle = 0;		//TODO
const int g_MiddleLiftAngle = 0;	//TODO
const int g_BottomLiftAngle = 0;	//TODO


// Mask for the "bitmap" values from the controller for everything
// we don't need (other than A/B/X/Y/LT/RT/JOYL/JOYR):
	//   0000 1100 1100 1111
	// & ???? ???? ???? ????
	// ---------------------
	//   0000 ??00 ??00 ????
// This information was gleaned from the definition of joy1Btn().
	//   2^0 + 2^1 + 2^2 + 2^3 + 2^6 + 2^7 + 2^10 + 2^11
	// = 1 + 2 + 4 + 8 + 64 + 128 + 1024 + 2048
	// = 3279

// If it doesn't work, use the commented-out line:
//const short g_ControllerMask = 6559;
const short g_ControllerMask = 3279;


#endif
