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
	Lift_Up(20, g_AccurateMotorPower);
}


task sub_WeighRings()
{
	// We might not implement this at all. Heh.
	EndTimeSlice();
}


void sub_CowsWithGuns()
{
	PlayTone(220, 195);	Time_Wait(200);
	PlayTone(220, 195);	Time_Wait(200);

	PlayTone(349, 390);	Time_Wait(400);
	PlayTone(349, 780);	Time_Wait(800);
	PlayTone(392, 195);	Time_Wait(200);
	PlayTone(349, 195);	Time_Wait(200);

	PlayTone(330, 195);	Time_Wait(200);
	PlayTone(294, 195);	Time_Wait(200);
	PlayTone(262, 780);	Time_Wait(800);
	PlayTone(294, 390);	Time_Wait(400);

	PlayTone(330, 585);	Time_Wait(600);
	PlayTone(208, 195);	Time_Wait(200);
	PlayTone(208, 390);	Time_Wait(400);
	PlayTone(208, 390);	Time_Wait(400);

	PlayTone(220, 1170);Time_Wait(1200);


	PlayTone(220, 195);	Time_Wait(200);
	PlayTone(220, 195);	Time_Wait(200);

	PlayTone(349, 390);	Time_Wait(400);
	PlayTone(349, 780);	Time_Wait(800);
	PlayTone(392, 195);	Time_Wait(200);
	PlayTone(349, 195);	Time_Wait(200);

	PlayTone(330, 195);	Time_Wait(200);
	PlayTone(294, 195);	Time_Wait(200);
	PlayTone(262, 780);	Time_Wait(800);
	PlayTone(294, 390);	Time_Wait(400);

	PlayTone(330, 780);	Time_Wait(800);
	PlayTone(415, 780);	Time_Wait(800);

	PlayTone(494, 780); Time_Wait(800);
	PlayTone(0, 390);	Time_Wait(400);
	PlayTone(208, 195);	Time_Wait(200);
	PlayTone(208, 195);	Time_Wait(200);

	PlayTone(220, 390);	Time_Wait(400);
}


//// We aren't using this function at all--therefore, it is commented out.
//task sub_MOO()
//{
//	PlaySoundFile("moo.rso");
//
//	// Uncomment this next section if "moo.rso" won't play.
//	while (bSoundActive)
//	{
//		Time_Wait(10);
//		Joystick_UpdateData();
//		EndTimeSlice();
//	}
//
//	StopTask(sub_MOO);
//}



#endif
