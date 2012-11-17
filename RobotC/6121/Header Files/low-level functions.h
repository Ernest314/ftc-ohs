#ifndef LOW_LEVEL_FUNCTIONS_H
#define LOW_LEVEL_FUNCTIONS_H


/////////////////////////////
//    "namespace" Motor    //
/////////////////////////////

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
	// Using this flag instead of `Motor_SetBrakes` since this is low-level.
	bFloatDuringInactiveMotorPWM = !(brake);
}

// This function does NOT reset the encoder, in case that is being
// used elsewhere. Reset the encoder periodically to prevent overflow.
void Motor_ExactRotation(	tMotor motorName,	int angle,
							int power=75,		bool brake=true)
{
	// Using some variables directly since this code is low-level.
	int originalAngle = 0;
	originalAngle = nMotorEncoder[motorName];
	nMotorEncoderTarget[motorName] = angle + originalAngle;
	motor[motorName] = power;
	//motor[motorName] = 0;	//uncomment if nMotorEncoderTarget[] doesn't work
	bFloatDuringInactiveMotorPWM = !(brake);
}

void Motor_SetPower(tMotor motorName, int power)
{
	motor[motorName] = power;
}

int Motor_GetEncoder(tMotor motorName)
{
	int encoder = 0;
	encoder = nMotorEncoder[motorName];
	return encoder;
}

void Motor_ResetEncoder(tMotor motorName)
{
	nMotorEncoder[motorName] = 0;
}

void Motor_SetBrakes(bool isOn=true)
{
	bFloatDuringInactiveMotorPWM = !isOn;
}

void Motor_SetMaxSpeed(int speed=750)
{
	nMaxRegulatedSpeedNxt = speed;
}

void Motor_SetPIDInterval(int interval=20)
{
	nPidUpdateInterval = interval;
}


/////////////////////////////
//    "namespace" Servo    //
/////////////////////////////

void Servo_ExactRotation(	TServoIndex servoName,	short angle,
							int power=75,			bool brake=true)
{
	servo[servoName] = angle;
	// Braking & power are not implemented.
	// Implementation of power will require calibration.
}

void Servo_Forward(tMotor motorName, int power=75)
{
	// No idea how to work this yet. Will wait until robot is done.
	// May or may not be implemented.
}

void Servo_Reverse(tMotor motorName, int power=75)
{
	// No idea how to work this yet. Will wait until robot is done.
	// May or may not be implemented.
}

void Servo_Stop(tMotor motorName, bool brake=true)
{
	// No idea how to work this yet. Will wait until robot is done.
	// May or may not be implemented.
}

short Servo_GetPosition(TServoIndex servoName)
{
	short rotation = 0;
	rotation = ServoValue[servoName];
	return rotation;
}

void Servo_SetUpdateInterval(TServoIndex servoName, int rate)
{
	servoChangeRate[servoName] = rate;
}


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
			isPressed = (bool)(joy1Btn(button));
			break;
		case CONTROLLER_2:
			isPressed = (bool)(joy2Btn(button));
			break;
	}

	return isPressed;
}

// Takes an input of "Joystick" instead of "joystick" to
// avoid conflict with name of built-in struct "joystick";
int Joystick_Joystick(	JoystickJoystick Joystick,	//best line of code ever
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
							axisValue = joystick.joy1_x1;
							break;
						case AXIS_Y:	//controller 1, joystick L, Y-axis
							axisValue = joystick.joy1_y1;
							break;
					}
					break;
				case JOYSTICK_R:
					switch (axis)
					{
						case AXIS_X:	//controller 1, joystick L, X-axis
							axisValue = joystick.joy1_x2;
							break;
						case AXIS_Y:	//controller 1, joystick L, Y-axis
							axisValue = joystick.joy2_y2;
							break;
					}
					break;
			}
			break;

		case CONTROLLER_2:
			switch (Joystick)
			{
				case JOYSTICK_L:
					switch (axis)
					{
						case AXIS_X:	//controller 2, joystick L, X-axis
							axisValue = joystick.joy2_x1;
							break;
						case AXIS_Y:	//controller 2, joystick L, Y-axis
							axisValue = joystick.joy2_y1;
							break;
					}
					break;
				case JOYSTICK_R:
					switch (axis)
					{
						case AXIS_X:	//controller 2, joystick L, X-axis
							axisValue = joystick.joy2_x2;
							break;
						case AXIS_Y:	//controller 2, joystick L, Y-axis
							axisValue = joystick.joy2_y2;
							break;
					}
					break;
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
			direction = (JoystickDirection)joystick.joy1_TopHat;
			break;
		case CONTROLLER_2:
			direction = (JoystickDirection)joystick.joy2_TopHat;
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
