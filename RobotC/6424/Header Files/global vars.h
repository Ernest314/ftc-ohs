#ifndef GLOBAL_VARS_H
#define GLOBAL_VARS_H


// The position the IR servo needs to be in (180 deg)
int g_IRServo = 230;

// The threshold for joystick values to count for driving/lift.
// The highest we've ever recorded is +-7.
int g_DriveThreshold = 10;
int g_LiftThreshold = 100;

// The factor to divide by when fine-tuning motors.
int g_FineTuneFactor = 4;

// The full speed the motors should be PID-regulated at.
int g_FullMotorPower = 80;

// These angles are added onto the current encoder count of the
// lift motor (the "current" value varies at startup).
int g_TopLiftAngle = 0;		//TODO
int g_MiddleLiftAngle = 0;	//TODO
int g_BottomLiftAngle = 0;	//TODO

// Mask for the "bitmap" values from the controller for everything
// we don't need (other than A/B/X/Y/JOYL/JOYR):
	//   0000 1100 0000 1111
	// & ???? ???? ???? ????
	// ---------------------
	//   0000 ??00 0000 ????
// This information was gleaned from the definition of joy1Btn().
	// 2^1 + 2^2 + 2^3 + 2^4 + 2^11 + 2^12 = 2+4+8+16+2048+4096 = 6174
// However, 6175 is the "working" value. ???
short g_ControllerMask= 6175;


#endif
