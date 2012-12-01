#pragma config(Hubs,  S1, HTServo,  HTMotor,  HTMotor,  none)
#pragma config(Sensor, S2,     infrared,       sensorI2CCustom)
#pragma config(Sensor, S3,     color,          sensorCOLORFULL)
#pragma config(Sensor, S4,     ultrasonic,     sensorSONAR)
#pragma config(Motor,  motorA,          motor_popcorn, tmotorNXT, openLoop)
#pragma config(Motor,  motorB,          motor_B,       tmotorNXT, openLoop)
#pragma config(Motor,  motorC,          motor_C,       tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     motor_L,       tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     motor_R,       tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S1_C3_1,     motor_lift,    tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C3_2,     motor_G,       tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C1_1,    servo_IR,             tServoStandard)
#pragma config(Servo,  srvo_S1_C1_2,    servo_claw,           tServoStandard)
#pragma config(Servo,  srvo_S1_C1_3,    servo_ramp,           tServoStandard)
#pragma config(Servo,  srvo_S1_C1_4,    servo_D,              tServoNone)
#pragma config(Servo,  srvo_S1_C1_5,    servo_E,              tServoNone)
#pragma config(Servo,  srvo_S1_C1_6,    servo_F,              tServoNone)
// Code generated by the 'ROBOTC' configuration wizard.
#include "JoystickDriver.c"
#include "hitechnic-irseeker-v2.h"
#include "enums.h"
#include "typedefs.h"
#include "global vars.h"
#include "structs.h"
#include "low-level functions.h"
#include "high-level functions.h"
#include "subroutines.h"



void initializeRobot()
{
	// Sensors are config'ed and setup by RobotC (need to stabalize).

	// The IR sensor needs this command (it seems like RobotC doesn't
	// initialize third-party sensors automatically.
	HTIRS2setDSPMode(infrared, g_IRsensorMode);

	Servo_SetSpeed(servo_IR, 10);		// maximum speed!
	Servo_SetSpeed(servo_claw, 10);		// maximum speed!
	Servo_SetSpeed(servo_ramp, 100);	// slowly update so ramp doesn't release.

	Servo_Rotate(servo_IR, g_IRServoExtended);		// will fold back up in tele-op
	Servo_Rotate(servo_claw, g_clawServoExtended);	// will be folded in tele-op
	Servo_Rotate(servo_ramp, g_rampServoDefault);	// stops ramp from deploying

	Motor_SetMaxSpeed(g_FullRegulatedPower);

	Motor_ResetEncoder(motor_L);
	Motor_ResetEncoder(motor_R);
	Motor_ResetEncoder(motor_lift);

	// Wait this long so the claw & IR servos get to update.
	// The ramp-release servo shouldn't move; the long update time
	// is to prevent sudden jerks that might release the ramp.
	// We don't need to wait for the IR sensor to stabalize since
	// the robot doesn't read from it until it's at the first column,
	// which should be ample time for RobotC to setup the sensor.
	Time_Wait(10);

	return;
}



task main()
{
	// The IR signal strengh in all 5 directions.
	int IRdirA = 0;
	int IRdirB = 0;
	int IRdirC = 0;
	int IRdirD = 0;
	int IRdirE = 0;



	waitForStart();

	initializeRobot();



	// The amount of time the robot...
	const int forwardTimeAA	= 25;
	const int turnTimeA 	= 50;

	const int forwardTimeA 	= 170;
	const int turnTimeB 	= 110;
	const int forwardTimeB 	= 100;
	const int liftTimeB 	= 45;

	const int forwardTimeC 	= 150;
	const int turnTimeD 	= 152;
	const int forwardTimeD 	= 110;
	const int liftTimeD 	= 135;

	const int forwardTimeE 	= 95;	//TODO
	const int turnTimeF 	= 112;	//TODO
	const int forwardTimeF 	= 80;	//TODO
	const int liftTimeF 	= 47;	//TODO

	const int liftTimeG		= 30;	//TODO
	const int backwardTimeG	= 100;	//TODO
	const int turnTimeG		= 70;	//TODO
	const int forwardTimeG	= 20;	//TODO

	const int liftTimeH		= 50;	//TODO
	const int backwardTimeH	= 90;	//TODO
	const int turnTimeH		= 100;	//TODO
	const int forwardTimeH	= 70;	//TODO

	const int liftTimeI		= 30;	//TODO
	const int backwardTimeI	= 130;	//TODO
	const int turnTimeI		= 70;	//TODO
	const int forwardTimeI	= 170;	//TODO



	Move_Forward(forwardTimeAA, g_AccurateMotorPower);
	Turn_Left(turnTimeA, g_AccurateMotorPower, g_AccurateMotorPower);
	Move_Forward(forwardTimeA, g_AccurateMotorPower);
	Time_Wait(50);
	HTIRS2readAllDCStrength(infrared, IRdirA, IRdirB, IRdirC, IRdirD, IRdirE);
	//IRdirA = 100;
	if ( (IRdirA+IRdirB+IRdirC+IRdirD+IRdirE) > g_IRthreshold )
	{
		Turn_Right		(turnTimeB, g_AccurateMotorPower, g_AccurateMotorPower);
		Lift_Up			(liftTimeB, g_AccurateMotorPower);
		Move_Forward	(forwardTimeB, g_AccurateMotorPower);

		Lift_Down		(liftTimeG, g_AccurateMotorPower);
		Move_Backward	(backwardTimeG, g_AccurateMotorPower);
		Turn_Right		(turnTimeG, g_AccurateMotorPower, g_AccurateMotorPower);

		Move_Forward	(forwardTimeG, g_AccurateMotorPower);
	}
	else
	{
		Move_Forward(forwardTimeC, g_AccurateMotorPower);
		Time_Wait(50);
		HTIRS2readAllACStrength(infrared, IRdirA, IRdirB, IRdirC, IRdirD, IRdirE);
		if ( (IRdirA+IRdirB+IRdirC+IRdirD+IRdirE) > g_IRthreshold )
		{
			Turn_Right		(turnTimeD, g_AccurateMotorPower, g_AccurateMotorPower);
			Lift_Up			(liftTimeD, g_AccurateMotorPower);
			Move_Forward	(forwardTimeD, g_AccurateMotorPower);

			Lift_Down		(liftTimeH, g_AccurateMotorPower);
			Move_Backward	(backwardTimeH, g_AccurateMotorPower);
			Turn_Right		(turnTimeH, g_AccurateMotorPower, g_AccurateMotorPower);

			Move_Forward	(forwardTimeH, g_AccurateMotorPower);
		}
		else
		{
			Move_Forward	(forwardTimeE, g_AccurateMotorPower);

			Turn_Right		(turnTimeF, g_AccurateMotorPower, g_AccurateMotorPower);
			Lift_Up			(liftTimeF, g_AccurateMotorPower);
			Move_Forward	(forwardTimeF, g_AccurateMotorPower);

			Lift_Down		(liftTimeI, g_AccurateMotorPower);
			Move_Backward	(backwardTimeI, g_AccurateMotorPower);
			Turn_Right		(turnTimeI, g_AccurateMotorPower, g_AccurateMotorPower);

			Move_Forward	(forwardTimeI, g_AccurateMotorPower);
		}
	}



	while (true)
	{
		PlaySoundFile("moo.rso");
		while(bSoundActive == true)
		{
			Time_Wait(1);
		}
	}
}
