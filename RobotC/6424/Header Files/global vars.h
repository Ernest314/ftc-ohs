#ifndef GLOBAL_VARS_H
#define GLOBAL_VARS_H

#pragma systemFile



// The mode the IR sensor is set at.
const tHTIRS2DSPMode g_IRsensorMode = DSP_1200;

// The threshold for IR values to count as detected.
const int g_IRthreshold = 10;


// Time to drive forward to put a ring on.
const int g_PutRingOnTime = 10;

// The various positions of the various servos.
const int g_IRServoLowered		= 0;
const int g_IRServoExtended		= 220;
const int g_clawServoFolded		= 0;
const int g_clawServoExtended	= 250;
const int g_rampServoDefault	= 50;	// TODO!
const int g_rampServoHold		= 40;	// TODO!
const int g_rampServoDeployed	= 15;	// TODO!


// The threshold for joystick values to count (eliminates humming).
// The highest we've ever recorded is +-7.
const int g_JoystickThreshold = 10;


int powerLift = 0;
LiftState isLiftState = LIFT_JOYSTICK;


// The factor to divide by when fine-tuning motors.
const int g_FineTuneFactor = 4;


const int g_FullPower = 100;
const int g_FullRegulatedPower = 80;
const int g_FullDrivePower = 80;
const int g_FullLiftPower = 80;

// The speed motors should ve PID-regulated at for the autonomous period,
// since the movement needs to be much more accurate.
const int g_AccurateMotorPower = 65;


// Threshold for encoder target thingy.
const int g_LiftAccuracyRough = 50;
const int g_LiftAccuracyFine = 10;


// Tolerance for lift (so that lift can still put rings on; for PID).
const int g_LiftTolerance = 10;

// These angles are added onto the current encoder count of the
// lift motor (the "current" value varies at startup).
const int g_TopLiftAngle = 6 *1000;		//TODO
const int g_MiddleLiftAngle = 5 *1000;	//TODO
const int g_BottomLiftAngle = 3 *1000;	//TODO
const int g_FetchLiftAngle = 2 *1000;	//TODO



//// We might not use masking at all to increase spped--we're not sure.

//// (CONTROLLER_1):
//// Mask for the "bitmap" values from the controller for everything
//// we don't need (other than A/B/X/Y/LT/RT/JOYL/JOYR):
//	//   0000 1100 1100 1111
//	// & ???? ???? ???? ????
//	// ---------------------
//	//   0000 ??00 ??00 ????
//// This information was gleaned from the definition of joy1Btn().
//	//   2^0 + 2^1 + 2^2 + 2^3 + 2^6 + 2^7 + 2^10 + 2^11
//	// = 1 + 2 + 4 + 8 + 64 + 128 + 1024 + 2048
//	// = 3279
//// If it doesn't work, use the commented-out line:
////const short g_ControllerMask = 6559;
//const short g_ControllerMaskA = 3279;	//CONTROLLER_1

//// (CONTROLLER_2):
//// Masks for the "bitmap" values from the controller for everything
//// we don't need (other than A/B/X/Y):
//	//   0000 0000 0000 1111
//	// & ???? ???? ???? ????
//	// ---------------------
//	//   0000 0000 0000 ????
//// This information was gleaned from the definition of joy1Btn().
//	//   2^0 + 2^1 + 2^2 + 2^3
//	// = 1 + 2 + 4 + 8
//	// = 15
//// If it doesn't work, use the commented-out line:
////const short g_ControllerMask = 31;
//const short g_ControllerMaskB = 15;	//CONTROLLER_2



#endif
