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


// Might add a fine-tune section to this.
task sub_LiftToTop()
{
	Motor_Target(motor_lift, g_TopLiftAngle);
	Motor_SetPower(motor_lift, g_FullMotorPower);
	while ( Motor_GetEncoder(motor_lift) != g_TopLiftAngle )
	{
		Time_Wait(50);
		EndTimeSlice();
	}
	Motor_Stop(motor_lift);
	StopTask(sub_LiftToTop);
}


// Might add a fine-tune section to this.
task sub_LiftToMiddle()
{
	Motor_Target(motor_lift, g_MiddleLiftAngle);
	Motor_SetPower(motor_lift, g_FullMotorPower);
	while ( Motor_GetEncoder(motor_lift) != g_MiddleLiftAngle)
	{
		Time_Wait(50);
		EndTimeSlice();
	}
	Motor_Stop(motor_lift);
	StopTask(sub_LiftToMiddle);
}


// Might add a fine-tune section to this.
task sub_LiftToBottom()
{
	Motor_Target(motor_lift, g_BottomLiftAngle);
	while ( Motor_GetEncoder(motor_lift) != g_BottomLiftAngle)
	{
		Time_Wait(50);
		EndTimeSlice();
	}
	Motor_Stop(motor_lift);
	StopTask(sub_LiftToBottom);
}


task sub_WeighRings()
{
	// We might not implement this at all. Heh.
	EndTimeSlice();
}


task sub_DeployRamp()
{
	Servo_Rotate(servo_ramp, g_rampServoDeployed);
	EndTimeSlice();
}


task sub_MOO()
{
	PlaySoundFile("moo.rso");

	//// Uncomment this next section if "moo.rso" won't play.
	//while (bSoundActive)
	//{
	//	Time_Wait(10);
	//	EndTimeSlice();
	//}

	StopTask(sub_MOO);
}



#endif
