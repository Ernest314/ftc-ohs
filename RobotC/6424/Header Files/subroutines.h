#ifndef SUBROUTINES_H
#define SUBROUTINES_H

void sub_PutRingOn()
{
	//do stuff
}

void sub_TakeRingOff()
{
	//do stuff
}

void sub_LiftToTop()
{
	// `-10` for a bit more precision. Might even break this up into
	// a fast section and a slower section (to fine-tune position).
	Motor_ExactRotation(motor_lift, g_TopLiftAngle, g_FullMotorPower-10);
}

void sub_LiftToMiddle()
{
	// `-10` for a bit more precision. Might even break this up into
	// a fast section and a slower section (to fine-tune position).
	Motor_ExactRotation(motor_lift, g_MiddleLiftAngle, g_FullMotorPower-10);
}

void sub_LiftToBottom()
{
	// `-10` for a bit more precision. Might even break this up into
	// a fast section and a slower section (to fine-tune position).
	Motor_ExactRotation(motor_lift, g_BottomLiftAngle, g_FullMotorPower-10);
}

void sub_WeighRings()
{
	//I have no idea how to implement this yet.
}

void sub_DeployRamp()
{
	//do stuff
}

#endif
