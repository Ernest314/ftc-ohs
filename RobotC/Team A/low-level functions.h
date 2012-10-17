#ifndef LOW_LEVEL_FUNCTIONS_H
#define LOW_LEVEL_FUNCTIONS_H


/////////////////////////////
//    "namespace" Motor    //
/////////////////////////////

void Motor_SetBrakes(bool isOn=true)
{
	bFloatDuringInactiveMotorPWM = !isOn;
}

void Motor_SetMaxSpeed(int speed=750)
{
	nMaxRegulatedSpeedNXT = speed;
}

void Motor_SetPIDInterval(int interval=20)
{
	nPidUpdateInterval = interval;
}

// The good stuff starts here.-------------------------

void Motor_Forward(tMotor motorName, int power=75)
{
	motor[motorName] = power;
}

void Motor_Reverse(tMotor motorName, int power=75)
{
	motor[motorName] = -1 * power;
}

void Motor_Stop(tMotor motorName, bool brake=true)
{
	motor[motorName] = 0;
	bFloatDuringInactiveMotorPWM = !(brake);
}

void Motor_ExactRotation(tMotor motorName, int angle, int power=75, bool brake=true)
{
	// Rotate specified amount (int angle).
	switch(brake)
	{
		case true:
			// Turn motor off.
			break;
		case false:
			// Turn motor on.
			break;
	}
}

void Motor_GetRotation(tMotor motorName)
{
	//MotorRotationCount(port);
}

void Motor_ResetRotation(tMotor motorName, bool relative)
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
			switch (Joystick)
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

JoystickDirection Joystick_Direction(JoystickController controller =
															CONTROLLER_1)
{
	JoystickDirection direction = DIRECTION_NONE;

	switch (controller)
	{
		case CONTROLLER_1:
			direction = joy1_TopHat;
			break;
		case CONTROLLER_2:
			// Using the struct since "joy2..." isn't a data type
			direction = joystick.joy2_TopHat;
			break;
	}

	return direction;
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
