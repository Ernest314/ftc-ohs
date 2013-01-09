#ifndef HIGH_LEVEL_FUNCTIONS_H
#define HIGH_LEVEL_FUNCTIONS_H



void Move_Forward(int time, int power=g_FullDrivePower)
{
	if ( (time>=g_RampDownLength) && (power>=10) )
	{
		Motor_Forward(motor_L, power);
		Motor_Forward(motor_R, power);
		Time_Wait(time - g_RampDownLength);
		Motor_Forward(motor_L, 10);
		Motor_Forward(motor_R, 10);
		Time_Wait(2);
		Motor_Forward(motor_L, 5);
		Motor_Forward(motor_R, 5);
		Time_Wait(4);
		Motor_Forward(motor_L, 3);
		Motor_Forward(motor_R, 3);
		Time_Wait(8);
		Motor_Forward(motor_L, 2);
		Motor_Forward(motor_R, 2);
		Time_Wait(4);
		Motor_Forward(motor_L, 1);
		Motor_Forward(motor_R, 1);
		Time_Wait(2);
		Motor_Stop(motor_L);
		Motor_Stop(motor_R);
	}
	else
	{
		Motor_Forward(motor_L, power);
		Motor_Forward(motor_R, power);
		Time_Wait(time);
		Motor_Stop(motor_L);
		Motor_Stop(motor_R);
	}
}


void Move_Backward(int time, int power=g_FullDrivePower)
{
	if ( (time>=g_RampDownLength) && (power>=10) )
	{
		Motor_Reverse(motor_L, power);
		Motor_Reverse(motor_R, power);
		Time_Wait(time - g_RampDownLength);
		Motor_Reverse(motor_L, 10);
		Motor_Reverse(motor_R, 10);
		Time_Wait(2);
		Motor_Reverse(motor_L, 5);
		Motor_Reverse(motor_R, 5);
		Time_Wait(4);
		Motor_Reverse(motor_L, 3);
		Motor_Reverse(motor_R, 3);
		Time_Wait(8);
		Motor_Reverse(motor_L, 2);
		Motor_Reverse(motor_R, 2);
		Time_Wait(4);
		Motor_Reverse(motor_L, 1);
		Motor_Reverse(motor_R, 1);
		Time_Wait(2);
		Motor_Stop(motor_L);
		Motor_Stop(motor_R);
	}
	else
	{
		Motor_Reverse(motor_L, power);
		Motor_Reverse(motor_R, power);
		Time_Wait(time);
		Motor_Stop(motor_L);
		Motor_Stop(motor_R);
	}
}

void Turn_Right(int time, int steerL, int steerR)
{
	//if ( (time>=g_RampDownLength) && (steerL>=10) )
	//{
	//	Motor_Forward(motor_L, steerL);
	//	Motor_Reverse(motor_R, steerR);
	//	Time_Wait(time - g_RampDownLength);
	//	Motor_Forward(motor_L, 10);
	//	Motor_Reverse(motor_R, 10);
	//	Time_Wait(2);
	//	Motor_Forward(motor_L, 5);
	//	Motor_Reverse(motor_R, 5);
	//	Time_Wait(4);
	//	Motor_Forward(motor_L, 3);
	//	Motor_Reverse(motor_R, 3);
	//	Time_Wait(8);
	//	Motor_Forward(motor_L, 2);
	//	Motor_Reverse(motor_R, 2);
	//	Time_Wait(4);
	//	Motor_Forward(motor_L, 1);
	//	Motor_Reverse(motor_R, 1);
	//	Time_Wait(2);
	//	Motor_Stop(motor_L);
	//	Motor_Stop(motor_R);
	//}
	//else
	//{
		Motor_Forward(motor_L, steerL);
		Motor_Reverse(motor_R, steerR);
		Time_Wait(time);
		Motor_Stop(motor_L);
		Motor_Stop(motor_R);
	//}
}

void Turn_Left(int time, int steerL, int steerR)
{
	//if ( (time>=g_RampDownLength) && (steerL>=10) )
	//{
	//	Motor_Reverse(motor_L, steerL);
	//	Motor_Forward(motor_R, steerR);
	//	Time_Wait(time - g_RampDownLength);
	//	Motor_Reverse(motor_L, 10);
	//	Motor_Forward(motor_R, 10);
	//	Time_Wait(2);
	//	Motor_Reverse(motor_L, 5);
	//	Motor_Forward(motor_R, 5);
	//	Time_Wait(4);
	//	Motor_Reverse(motor_L, 3);
	//	Motor_Forward(motor_R, 3);
	//	Time_Wait(8);
	//	Motor_Reverse(motor_L, 2);
	//	Motor_Forward(motor_R, 2);
	//	Time_Wait(4);
	//	Motor_Reverse(motor_L, 1);
	//	Motor_Forward(motor_R, 1);
	//	Time_Wait(2);
	//	Motor_Stop(motor_L);
	//	Motor_Stop(motor_R);
	//}
	//else
	//{
		Motor_Reverse(motor_L, steerL);
		Motor_Forward(motor_R, steerR);
		Time_Wait(time);
		Motor_Stop(motor_L);
		Motor_Stop(motor_R);
	//}
}

void Lift_Up(int time, int power)
{
	Motor_Forward(motor_lift, power);
	Time_Wait(time);
	Motor_Stop(motor_lift);
}

void Lift_Down(int time, int power)
{
	Motor_Forward(motor_lift, (-1) * power);
	Time_Wait(time);
	Motor_Stop(motor_lift);
}



#endif
