#ifndef HIGH_LEVEL_FUNCTIONS_H
#define HIGH_LEVEL_FUNCTIONS_H



void Move_Forward(int time, int power=g_FullDrivePower)
{
	Motor_Forward(motor_L, power);
	Motor_Forward(motor_R, power);
	Time_Wait(time);
	Motor_Stop(motor_L);
	Motor_Stop(motor_R);
}


void Move_Backward(int time, int power=g_FullDrivePower)
{
	Motor_Reverse(motor_L, power);
	Motor_Reverse(motor_R, power);
	Time_Wait(time);
	Motor_Stop(motor_L);
	Motor_Stop(motor_R);
}

void Turn_Right(int time, int steerL, int steerR)
{
	Motor_Forward(motor_L, steerL);
	Motor_Reverse(motor_R, steerR);
	Time_Wait(time);
	Motor_Stop(motor_L);
	Motor_Stop(motor_R);
}

void Turn_Left(int time, int steerL, int steerR)
{
	Motor_Reverse(motor_L, steerL);
	Motor_Forward(motor_R, steerR);
	Time_Wait(time);
	Motor_Stop(motor_L);
	Motor_Stop(motor_R);
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
