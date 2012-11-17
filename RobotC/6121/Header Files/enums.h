#ifndef ENUMS_H
#define ENUMS_H

typedef enum JoystickButton	//the values are NOT final
{
	// Comment out the line after when debugging. See main program.
	// BUTTON_A = 2,

	BUTTON_A = 02,
	BUTTON_B = 03,
	BUTTON_X = 01,
	BUTTON_Y = 04,
	BUTTON_LB = 05,
	BUTTON_RB = 06,
	BUTTON_LT = 07,
	BUTTON_RT = 08,
	BUTTON_BACK = 09,
	BUTTON_START = 10,
	BUTTON_JOYL = 11,	//"floating-D technology"
	BUTTON_JOYR = 12,	//"floating-D technology"
};

typedef enum JoystickController
{
	CONTROLLER_1 = 1,
	CONTROLLER_2 = 2,
};

typedef enum JoystickAxis
{
	AXIS_X = 0,
	AXIS_Y = 1,
};

typedef enum JoystickJoystick
{
	JOYSTICK_L = 0,
	JOYSTICK_R = 1,
};

typedef enum JoystickDirection	//need one more definitive test
{
	DIRECTION_NONE = -1,
	DIRECTION_F = 0,
	DIRECTION_FR = 1,
	DIRECTION_R = 2,
	DIRECTION_BR = 7,
	DIRECTION_B = 6,
	DIRECTION_BL = 5,
	DIRECTION_L = 4,
	DIRECTION_FL = 3,
};

#endif
