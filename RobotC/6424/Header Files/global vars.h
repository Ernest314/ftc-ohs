#ifndef GLOBAL_VARS_H
#define GLOBAL_VARS_H



// The mode the IR sensor is set at.
const tHTIRS2DSPMode g_IRsensorMode = DSP_1200;

// The threshold for IR values to count as detected.
const int g_IRthreshold = 10;


// The amount of motor movement time for the different sections of the
// autonomous period. For an explanation of the segment names, see our
// diagram in our engineering notebook (segments may be offset).
const int g_TurnTimeA = 40;
const int g_ForwardTimeA = 200;
const int g_TurnTimeB = 90;
const int g_ForwardTimeB = 120;
const int g_LiftTimeB = 200;
const int g_ForwardTimeC = 100;
const int g_TurnTimeD = 90;
const int g_ForwardTimeD = 120;
const int g_LiftTimeD = 200;
const int g_ForwardTimeE = 100;
const int g_TurnTimeF = 90;
const int g_ForwardTimeF = 120;
const int g_LiftTimeF = 200;


// The position the IR servo needs to be in (180 deg)
const int g_IRServoDefault = 0;
const int g_IRServoExtended = 220;
const int g_clawServoDefault = 100;
const int g_clawServoExtended = 250;
const int g_rampServoDefault = 185;
const int g_rampServoDeployed = 172;


// The threshold for joystick values to count (eliminates humming).
// The highest we've ever recorded is +-7.
const int g_JoystickThreshold = 10;


// The factor to divide by when fine-tuning motors.
const int g_FineTuneFactor = 4;


// The full speed the motors should be PID-regulated at.
const int g_FullMotorPower = 80;

// The speed motors should ve PID-regulated at for the autonomous period,
// since the movement needs to be much more accurate.
const int g_AccurateMotorPower = 65;


// Threshold for encoder target thingy.
const int g_LiftAccuracyRough = 50;
const int g_LiftAccuracyFine = 5;


// These angles are added onto the current encoder count of the
// lift motor (the "current" value varies at startup).
const int g_TopLiftAngle = 5000;		//TODO
const int g_MiddleLiftAngle = 2000;	//TODO
const int g_BottomLiftAngle = 1000;	//TODO


// (CONTROLLER_1):
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
const short g_ControllerMaskA = 3279;	//CONTROLLER_1

// (CONTROLLER_2):
// Masks for the "bitmap" values from the controller for everything
// we don't need (other than A/B/X/Y):
	//   0000 0000 0000 1111
	// & ???? ???? ???? ????
	// ---------------------
	//   0000 0000 0000 ????
// This information was gleaned from the definition of joy1Btn().
	//   2^0 + 2^1 + 2^2 + 2^3
	// = 1 + 2 + 4 + 8
	// = 15
// If it doesn't work, use the commented-out line:
//const short g_ControllerMask = 31;
const short g_ControllerMaskB = 15;	//CONTROLLER_2


#endif
