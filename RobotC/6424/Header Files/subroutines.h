#ifndef SUBROUTINES_H
#define SUBROUTINES_H



void sub_PutRingOn()
{
	Move_Forward(g_PutRingOnTime, g_FullDrivePower);
	Lift_Down(50, g_FullLiftPower);
}


task sub_TakeRingOff()
{
	//do stuff
	EndTimeSlice();
}


//// Might add a fine-tune section to this.
//task sub_LiftToTop()
//{
//	//Motor_Target(motor_lift, g_TopLiftAngle);
//	for (int i = 0; i < 2; i++)
//	{
//		if ( Motor_GetEncoder(motor_lift)>g_TopLiftAngle )
//		{
//			Motor_SetPower(motor_lift, (-1)*g_FullDrivePower);
//			while ( Motor_GetEncoder(motor_lift) > g_TopLiftAngle)
//			{
//				Time_Wait(10);
//				EndTimeSlice();
//			}
//		}
//		if ( Motor_GetEncoder(motor_lift)<g_TopLiftAngle )
//		{
//			Motor_SetPower(motor_lift, g_FullDrivePower);
//			while ( Motor_GetEncoder(motor_lift) < g_TopLiftAngle)
//			{
//				Time_Wait(10);
//				EndTimeSlice();
//			}
//		}
//		Motor_Stop(motor_lift);
//	}
//	StopTask(sub_LiftToTop);
//}


//task sub_LiftToMiddle()
//{
//	//Motor_Target(motor_lift, g_MiddleLiftAngle);
//	for (int i = 0; i < 2; i++)
//	{
//		if ( Motor_GetEncoder(motor_lift)>g_MiddleLiftAngle )
//		{
//			Motor_SetPower(motor_lift, -1*g_FullDrivePower);
//			while ( Motor_GetEncoder(motor_lift) > g_MiddleLiftAngle)
//			{
//				Time_Wait(10);
//				EndTimeSlice();
//			}
//		}
//		if ( Motor_GetEncoder(motor_lift)<g_MiddleLiftAngle )
//		{
//			Motor_SetPower(motor_lift, g_FullDrivePower);
//			while ( Motor_GetEncoder(motor_lift) < g_MiddleLiftAngle)
//			{
//				Time_Wait(10);
//				EndTimeSlice();
//			}
//		}
//		Motor_Stop(motor_lift);
//	}
//	StopTask(sub_LiftToMiddle);
//}


//// Might add a fine-tune section to this.
//task sub_LiftToBottom()
//{
//	//Motor_Target(motor_lift, g_BottomLiftAngle);
//	for (int i = 0; i < 2; i++)
//	{
//		if ( Motor_GetEncoder(motor_lift)>g_BottomLiftAngle )
//		{
//			Motor_SetPower(motor_lift, -1*g_FullDrivePower);
//			while ( Motor_GetEncoder(motor_lift) > g_BottomLiftAngle)
//			{
//				Time_Wait(10);
//				EndTimeSlice();
//			}
//		}
//		if ( Motor_GetEncoder(motor_lift)<g_BottomLiftAngle )
//		{
//			Motor_SetPower(motor_lift, g_FullDrivePower);
//			while ( Motor_GetEncoder(motor_lift) < g_BottomLiftAngle)
//			{
//				Time_Wait(10);
//				EndTimeSlice();
//			}
//		}
//		Motor_Stop(motor_lift);
//	}
//	StopTask(sub_LiftToBottom);
//}


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



//-----------------------------------------------------------
void sub_LiftToBottom()
{
	if (isLiftState == LIFT_BOTTOM)
	{
		if ( abs(g_BottomLiftAngle-Motor_GetEncoder(motor_lift)) > g_LiftAccuracyRough )
		{
			if ( Motor_GetEncoder(motor_lift)>g_BottomLiftAngle )
			{
				powerLift = -100;
				//powerLift = (-1) * g_FullLiftPower;
			}
			if ( Motor_GetEncoder(motor_lift)<g_BottomLiftAngle )
			{
				powerLift = 100;
				//powerLift = g_FullLiftPower;
			}
		}
		if ( abs(g_BottomLiftAngle-Motor_GetEncoder(motor_lift)) > g_LiftAccuracyFine )
		{
			if ( Motor_GetEncoder(motor_lift)>g_BottomLiftAngle )
			{
				powerLift = -20;
				//powerLift = (-1) * g_FullLiftPower / g_FineTuneFactor;
			}
			if ( Motor_GetEncoder(motor_lift)<g_BottomLiftAngle )
			{
				powerLift = 20;
				//powerLift = g_FullLiftPower / g_FineTuneFactor;
			}
		}
	}
}


void sub_LiftToMiddle()
{
	if (isLiftState == LIFT_MIDDLE)
	{
		if ( abs(g_MiddleLiftAngle-Motor_GetEncoder(motor_lift)) > g_LiftAccuracyRough )
		{
			if ( Motor_GetEncoder(motor_lift)>g_MiddleLiftAngle )
			{
				powerLift = (-1) * g_FullLiftPower;
			}
			if ( Motor_GetEncoder(motor_lift)<g_MiddleLiftAngle )
			{
				powerLift = g_FullLiftPower;
			}
		}
		if ( abs(g_MiddleLiftAngle-Motor_GetEncoder(motor_lift)) > g_LiftAccuracyFine )
		{
			if ( Motor_GetEncoder(motor_lift)>g_MiddleLiftAngle )
			{
				powerLift = (-1) * g_FullLiftPower / g_FineTuneFactor;
			}
			if ( Motor_GetEncoder(motor_lift)<g_MiddleLiftAngle )
			{
				powerLift = g_FullLiftPower / g_FineTuneFactor;
			}
		}
	}
}


void sub_LiftToTop()
{
	if (isLiftState == LIFT_TOP)
	{
		if ( abs(g_TopLiftAngle-Motor_GetEncoder(motor_lift)) > g_LiftAccuracyRough )
		{
			if ( Motor_GetEncoder(motor_lift)>g_TopLiftAngle )
			{
				powerLift = (-1) * g_FullLiftPower;
			}
			if ( Motor_GetEncoder(motor_lift)<g_TopLiftAngle )
			{
				powerLift = g_FullLiftPower;
			}
		}
		if ( abs(g_TopLiftAngle-Motor_GetEncoder(motor_lift)) > g_LiftAccuracyFine )
		{
			if ( Motor_GetEncoder(motor_lift)>g_TopLiftAngle )
			{
				powerLift = (-1) * g_FullLiftPower / g_FineTuneFactor;
			}
			if ( Motor_GetEncoder(motor_lift)<g_TopLiftAngle )
			{
				powerLift = g_FullLiftPower / g_FineTuneFactor;
			}
		}
	}
}
//-------------------------------------------------------------------------------



void sub_CowsWithGuns()
{
}



#endif
