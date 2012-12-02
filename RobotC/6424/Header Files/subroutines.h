#ifndef SUBROUTINES_H
#define SUBROUTINES_H



void sub_LiftToHeight(int height)
{
	if ( abs(height-Motor_GetEncoder(motor_lift)) > g_LiftAccuracyRough )
	{
		if ( Motor_GetEncoder(motor_lift)>height )
		{
			powerLift = -100;
			//powerLift = (-1) * g_FullLiftPower;
		}
		if ( Motor_GetEncoder(motor_lift)<height )
		{
			powerLift = 100;
			//powerLift = g_FullLiftPower;
		}
	}
	if ( abs(height-Motor_GetEncoder(motor_lift)) > g_LiftAccuracyFine )
	{
		if ( Motor_GetEncoder(motor_lift)>height )
		{
			powerLift = -20;
			//powerLift = (-1) * g_FullLiftPower / g_FineTuneFactor;
		}
		if ( Motor_GetEncoder(motor_lift)<height )
		{
			powerLift = 20;
			//powerLift = g_FullLiftPower / g_FineTuneFactor;
		}
	}
}


void sub_PutRingOn()
{
	Move_Forward(g_PutRingOnTime, g_FullDrivePower);
	Lift_Down(50, g_FullLiftPower);
}


void sub_TakeRingOff()
{
	//do stuff
}


task sub_WeighRings()
{
	// We might not implement this at all. Heh.
	EndTimeSlice();
}


task sub_MOO()
{
	PlaySoundFile("moo.rso");

	// Uncomment this next section if "moo.rso" won't play.
	while (bSoundActive)
	{
		Time_Wait(10);
		Joystick_UpdateData();
		EndTimeSlice();
	}

	StopTask(sub_MOO);
}


void sub_CowsWithGuns()
{
}



#endif
