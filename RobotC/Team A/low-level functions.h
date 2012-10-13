#ifndef LOW_LEVEL_FUNCTIONS_H
#define LOW_LEVEL_FUNCTIONS_H


/////////////////////////////
//    "namespace" Motor    //
/////////////////////////////

void Motor_Forward(int motor_name, int power=75)
{
	motor[motor_name] = power;
}

void Motor_Reverse(int motor_name, int power=75)
{
	motor[motor_name] = -1 * power;
}

void Motor_Stop(int motor_name, bool brake=true)
{
	int motor[motor_name] = 0;
	bFloatDuringInactiveMotorPWM = !(brake);
}

void Motor_ExactRotation(int motor_name, int angle, int power=75, bool brake=true)
{
	//RotateMotor(port, power, angle);
	switch(brake)
	{
		case true:
			//Off(port);
			break;
		case false:
			//Coast(port);
			break;
	}
}

void Motor_GetRotation(int motor_name)
{
	//MotorRotationCount(port);
}

void Motor_ResetRotation(int motor_name, bool relative)
{
	switch(relative)
	{
		case true:
			//ResetBlockTachoCount(port);
			break;
		case false:
			//ResetRotationCount(port);
			break;
	}
}


/////////////////////////////
//    "namespace" Servo    //
/////////////////////////////


/////////////////////////////
//    "namespace" Sensor   //
/////////////////////////////


/////////////////////////////
//   "namespace" Joystick  //
/////////////////////////////


/////////////////////////////
//   "namespace" Buttons   //
/////////////////////////////


/////////////////////////////
//     "namespace" File    //
/////////////////////////////


/////////////////////////////
//     "namespace" Time    //
/////////////////////////////

void Time_Wait(int milliseconds)
{
	//use % to breakdown time-to-wait
}


/////////////////////////////
//    "namespace" Sound    //
/////////////////////////////


/////////////////////////////
//   "namespace" Display   //
/////////////////////////////


/////////////////////////////
//  "namespace" Bluetooth  //
/////////////////////////////


/////////////////////////////
//     "namespace" Misc    //
/////////////////////////////

#endif