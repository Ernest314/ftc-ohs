#ifndef SUBROUTINES_H
#define SUBROUTINES_H


task sub_PutRingOn()
{
	//do stuff
	//EndTimeSlice();
}

task sub_TakeRingOff()
{
	//do stuff
	//EndTimeSlice();
}

task sub_LiftToTop()
{
	// `-10` for a bit more precision. Might even break this up into
	// a fast section and a slower section (to fine-tune position).
	Motor_ExactRotation(motor_lift, g_TopLiftAngle, g_FullMotorPower);
	while( Motor_GetEncoder(motor_lift) != g_TopLiftAngle)
	{
		Time_Wait(50);
	}
	//EndTimeSlice();
}

task sub_LiftToMiddle()
{
	// `-10` for a bit more precision. Might even break this up into
	// a fast section and a slower section (to fine-tune position).
	Motor_ExactRotation(motor_lift, g_MiddleLiftAngle, g_FullMotorPower);
	while( Motor_GetEncoder(motor_lift) != g_MiddleLiftAngle)
	{
		Time_Wait(50);
	}
	//EndTimeSlice();
}

task sub_LiftToBottom()
{
	// `-10` for a bit more precision. Might even break this up into
	// a fast section and a slower section (to fine-tune position).
	Motor_ExactRotation(motor_lift, g_BottomLiftAngle, g_FullMotorPower);
	while( Motor_GetEncoder(motor_lift) != g_BottomLiftAngle)
	{
		Time_Wait(50);
	}
	//EndTimeSlice();
}

task sub_WeighRings()
{
	//I have no idea how to implement this yet.
	//EndTimeSlice();
}

task sub_DeployRamp()
{
	//do stuff
	//EndTimeSlice();
}


#endif
