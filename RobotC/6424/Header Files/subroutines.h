#ifndef SUBROUTINES_H
#define SUBROUTINES_H


task sub_PutRingOn()
{
	//do stuff
	EndTimeSlice();
}

task sub_TakeRingOff()
{
	//do stuff
	EndTimeSlice();
}

task sub_LiftToTop()
{
	// Might add a fine-tune section to this.
	Motor_ExactRotation(motor_lift, g_TopLiftAngle, g_FullMotorPower);
	while( Motor_GetEncoder(motor_lift) != g_TopLiftAngle)
	{
		Time_Wait(50);
	}
	EndTimeSlice();
}

task sub_LiftToMiddle()
{
	// Might add a fine-tune section to this.
	Motor_ExactRotation(motor_lift, g_MiddleLiftAngle, g_FullMotorPower);
	while( Motor_GetEncoder(motor_lift) != g_MiddleLiftAngle)
	{
		Time_Wait(50);
	}
	EndTimeSlice();
}

task sub_LiftToBottom()
{
	// Might add a fine-tune section to this.
	Motor_ExactRotation(motor_lift, g_BottomLiftAngle, g_FullMotorPower);
	while( Motor_GetEncoder(motor_lift) != g_BottomLiftAngle)
	{
		Time_Wait(50);
	}
	EndTimeSlice();
}

task sub_WeighRings()
{
	// We might not implement this at all. Heh.
	EndTimeSlice();
}

task sub_DeployRamp()
{
	//do stuff
	//EndTimeSlice();
}


#endif
