#ifndef LOW_LEVEL_FUNCTIONS_H
#define LOW_LEVEL_FUNCTIONS_H


/////////////////////////////
//    "namespace" Motor    //
/////////////////////////////

void Motor_Forward(tMotor motor_name, int power=75)
{
	motor[motor_name] = power;
}

void Motor_Reverse(tMotor motor_name, int power=75)
{
	motor[motor_name] = -1 * power;
}

void Motor_Stop(tMotor motor_name, bool brake=true)
{
	motor[motor_name] = 0;
	bFloatDuringInactiveMotorPWM = !(brake);
}

void Motor_ExactRotation(tMotor motor_name, int angle, int power=75, bool brake=true)
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

void Motor_GetRotation(tMotor motor_name)
{
	//MotorRotationCount(port);
}

void Motor_ResetRotation(tMotor motor_name, bool relative)
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

void Joystick_UpdateData()
{
	getJoystickSettings(joystick);
}

bool Joystick_Button(	JoystickButton button,
						JoystickController controller = CONTROLLER_1)
{
	bool isPressed = false;

	switch (controller)
	{
		case CONTROLLER_1:
			isPressed = joy1Btn(button);
			break;
		case CONTROLLER_2:
			isPressed = joy2Btn(button);
			break;
	}

	return isPressed;
}

// Takes an input of "Joystick" instead of "joystick" to
// avoid conflict with name of built-in struct "joystick";
// "TJoystick" variable type does NOT support the second controller,
// forced to use "joystick.joy2_x1" etc. instead of "joy2_x1" etc.
int JoyStick_Joystick(	JoystickJoystick Joystick,	//best line of code ever
						JoystickAxis axis,
						JoystickController controller = CONTROLLER_1)
{
	int axisValue = 0;


	switch (controller)
	{
		case CONTROLLER_1:
			switch (Joystick)
			{
				case JOYSTICK_L:
					switch (axis)
					{
						case AXIS_X:	//controller 1, joystick L, X-axis
							axisValue = joy1_x1;
							break;
						case AXIS_Y:	//controller 1, joystick L, Y-axis
							axisValue = joy1_y1;
							break;
					}
				case JOYSTICK_R:
					switch (axis)
					{
						case AXIS_X:	//controller 1, joystick L, X-axis
							axisValue = joy1_x2;
							break;
						case AXIS_Y:	//controller 1, joystick L, Y-axis
							axisValue = joy1_y2;
							break;
					}
			}
			break;

		case CONTROLLER_2:
			switch (joy)
			{
				case JOYSTICK_L:
					switch (axis)
					{
						case AXIS_X:	//controller 2, joystick L, X-axis
							//"TJoystick" doesn't support "joy2..." data type
							axisValue = joystick.joy2_x1;
							break;
						case AXIS_Y:	//controller 2, joystick L, Y-axis
							//"TJoystick" doesn't support "joy2..." data type
							axisValue = joystick.joy2_y1;
							break;
					}
				case JOYSTICK_R:
					switch (axis)
					{
						case AXIS_X:	//controller 2, joystick L, X-axis
							//"TJoystick" doesn't support "joy2..." data type
							axisValue = joystick.joy2_x2;
							break;
						case AXIS_Y:	//controller 2, joystick L, Y-axis
							//"TJoystick" doesn't support "joy2..." data type
							axisValue = joystick.joy2_y2;
							break;
					}
			}
			break;
	}


	return axisValue;
}


/////////////////////////////
//   "namespace" Buttons   //
/////////////////////////////


/////////////////////////////
//     "namespace" File    //
/////////////////////////////


/////////////////////////////
//     "namespace" Time    //
/////////////////////////////

// breaks down time to wait into 10ms and 1ms chunks
void Time_Wait(int ms)
{
	int waitTime10ms = (ms - (ms%320)) / 320;
	int waitTime1ms = (ms - (ms%32)) / 32;

	for (int i=0; i<waitTime10ms; i++)
	{
		wait10Msec(320);
	}
	for (int i=0; i<waitTime1ms; i++)
	{
		wait1Msec(32);
	}
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
