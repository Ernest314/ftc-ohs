#ifndef HIGH_LEVEL_FUNCTIONS_H
#define HIGH_LEVEL_FUNCTIONS_H

//void Move_Forward(int time, int power=100, bool brake=true)
//{
//	Motor_Forward(STEER_L, power);
//	Motor_Forward(STEER_R, power);
//	//Wait(time);
//	Motor_Stop(STEER_L, brake);
//	Motor_Stop(STEER_R, brake);
//}
//
//void Move_Backward(int time, int power=100, bool brake=true)
//{
//	Motor_Reverse(STEER_L, power);
//	Motor_Reverse(STEER_R, power);
//	//Wait(time);
//	Motor_Stop(STEER_L, brake);
//	Motor_Stop(STEER_R, brake);
//}
//
//void Move_Timed(int port, int time, int power=100, bool brake=true)
//{
//	Motor_Forward(port, power);
//	//Wait(time);
//	Motor_Stop(port, brake);
//}
//
//void Turn_inPlace(int direction, int power=100, int degrees=90, bool brake=true)
//{
//	int wait_time = TURN_IN_PLACE_TIME*(10.0/power)*(degrees/360.0);	//".0" added to force float division
//	switch(direction)
//	{
//		case DIRECTION_L:
//			Motor_Reverse(STEER_L, power);
//			Motor_Forward(STEER_R, power);
//			//Wait(wait_time);	//see definition of const
//			Motor_Stop(STEER_L, brake);
//			Motor_Stop(STEER_R, brake);
//			break;
//		case DIRECTION_R:
//			Motor_Forward(STEER_L, power);
//			Motor_Reverse(STEER_R, power);
//			//Wait(wait_time);	//see definition of const
//			Motor_Stop(STEER_L, brake);
//			Motor_Stop(STEER_R, brake);
//			break;
//	}
//}
//
////TODO! (add turn-ratio controlling, fix floating point division & algorithm)
//void Turn_Moving(int direction, int power=100, int degrees=90, bool brake=true)
//{
//	switch(direction)
//	{
//		case DIRECTION_L:
//			Motor_Forward(STEER_R, power);
//			//Wait(TURN_SWERVE_TIME*(power/10)*(degrees/360));	//see definition of const
//			Motor_Stop(STEER_R, brake);
//			break;
//		case DIRECTION_R:
//			Motor_Forward(STEER_L, power);
//			//Wait(TURN_SWERVE_TIME*(power/10)*(degrees/360));	//see definition of const
//			Motor_Stop(STEER_L, brake);
//			break;
//	}
//}

#endif