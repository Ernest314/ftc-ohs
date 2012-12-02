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
	PlayTone(NOTE_A3, 195);		Time_Wait(200);
	PlayTone(NOTE_A3, 195);		Time_Wait(200);

	PlayTone(NOTE_F4, 390);		Time_Wait(400);
	PlayTone(NOTE_F4, 780);		Time_Wait(800);
	PlayTone(NOTE_G4, 195);		Time_Wait(200);
	PlayTone(NOTE_F4, 195);		Time_Wait(200);

	PlayTone(NOTE_E4, 195);		Time_Wait(200);
	PlayTone(NOTE_D4, 195);		Time_Wait(200);
	PlayTone(NOTE_C4, 780);		Time_Wait(800);
	PlayTone(NOTE_D4, 390);		Time_Wait(400);

	PlayTone(NOTE_E4, 585);		Time_Wait(600);
	PlayTone(208, 195);			Time_Wait(200);	// G#3
	PlayTone(208, 390);			Time_Wait(400);	// G#3
	PlayTone(208, 390);			Time_Wait(400);	// G#3

	PlayTone(NOTE_A3, 1170);	Time_Wait(1200);


	PlayTone(NOTE_A3, 195);		Time_Wait(200);
	PlayTone(NOTE_A3, 195);		Time_Wait(200);

	PlayTone(NOTE_F4, 390);		Time_Wait(400);
	PlayTone(NOTE_F4, 780);		Time_Wait(800);
	PlayTone(NOTE_G4, 195);		Time_Wait(200);
	PlayTone(NOTE_F4, 195);		Time_Wait(200);

	PlayTone(NOTE_E4, 195);		Time_Wait(200);
	PlayTone(NOTE_D4, 195);		Time_Wait(200);
	PlayTone(NOTE_C4, 780);		Time_Wait(800);
	PlayTone(NOTE_D4, 390);		Time_Wait(400);

	PlayTone(NOTE_E4, 780);		Time_Wait(800);
	PlayTone(415, 780);			Time_Wait(800);	// G#4

	PlayTone(NOTE_B4, 780); 	Time_Wait(800);
	PlayTone(NOTE_REST, 390);	Time_Wait(400);
	PlayTone(208, 195);			Time_Wait(200);	// G#3
	PlayTone(208, 195);			Time_Wait(200);	// G#3

	PlayTone(NOTE_A4, 390);		Time_Wait(400);
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
