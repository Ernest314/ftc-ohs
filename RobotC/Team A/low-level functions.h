#ifndef LOW_LEVEL_FUNCTIONS_H
#define LOW_LEVEL_FUNCTIONS_H


/////////////////////////////
//    "namespace" Motor    //
/////////////////////////////

void Motor_Forward(int port, int power=75)
{
	//OnFwd(port, power);
}

void Motor_Reverse(int port, int power=75)
{
	//OnRev(port, power);
}

void Motor_Stop(int port, bool brake=true)
{

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

void Motor_ExactRotation(int port, int angle, int power=75, bool brake=true)
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

void Motor_GetRotation(int port)
{
	//MotorRotationCount(port);
}

void Motor_ResetRotation(int port, bool relative)
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