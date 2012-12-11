#ifndef SUBROUTINES_H
#define SUBROUTINES_H



void sub_LiftToHeight(int height)
{
	// Implement PID control HERE. :D
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


void sub_CowsWithGuns()
{
	PlayTone(NOTE_A3, 19);		Time_Wait(20);
	PlayTone(NOTE_A3, 19);		Time_Wait(20);

	PlayTone(NOTE_F4, 39);		Time_Wait(40);
	PlayTone(NOTE_F4, 78);		Time_Wait(80);
	PlayTone(NOTE_G4, 19);		Time_Wait(20);
	PlayTone(NOTE_F4, 19);		Time_Wait(20);

	PlayTone(NOTE_E4, 39);		Time_Wait(40);
	PlayTone(NOTE_C4, 78);		Time_Wait(80);
	PlayTone(NOTE_D4, 39);		Time_Wait(40);

	PlayTone(NOTE_E4, 59);		Time_Wait(60);
	PlayTone(NOTE_G3s, 19);		Time_Wait(20);
	PlayTone(NOTE_G3s, 39);		Time_Wait(40);
	PlayTone(NOTE_G3s, 39);		Time_Wait(40);

	PlayTone(NOTE_A3, 117);		Time_Wait(120);


	PlayTone(NOTE_A3, 19);		Time_Wait(20);
	PlayTone(NOTE_A3, 19);		Time_Wait(20);

	PlayTone(NOTE_F4, 39);		Time_Wait(40);
	PlayTone(NOTE_F4, 78);		Time_Wait(80);
	PlayTone(NOTE_G4, 19);		Time_Wait(20);
	PlayTone(NOTE_F4, 19);		Time_Wait(20);

	PlayTone(NOTE_E4, 19);		Time_Wait(20);
	PlayTone(NOTE_D4, 19);		Time_Wait(20);
	PlayTone(NOTE_C4, 78);		Time_Wait(80);
	PlayTone(NOTE_D4, 39);		Time_Wait(40);

	PlayTone(NOTE_E4, 78);		Time_Wait(80);
	PlayTone(NOTE_G4s, 78);		Time_Wait(80);

	PlayTone(NOTE_B4, 78); 		Time_Wait(80);
	PlayTone(NOTE_REST, 39);	Time_Wait(40);
	PlayTone(NOTE_G3s, 19);		Time_Wait(20);
	PlayTone(NOTE_G3s, 19);		Time_Wait(20);

	PlayTone(NOTE_A3, 39);		Time_Wait(40);
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
