#ifndef ENUMS_H
#define ENUMS_H

typedef enum JoystickButton	//the values are tentative, esp. start, select, menu, logo
{
	BUTTON_A = 1,
	BUTTON_B = 2,
	BUTTON_X = 0,
	BUTTON_Y = 3,
	BUTTON_LB = 4,
	BUTTON_RB = 5,
	BUTTON_LT = 6,
	BUTTON_RT = 7,
	BUTTON_BACK = 8,
	BUTTON_START = 9,
	BUTTON_JOYL = 10,
	BUTTON_JOYR = 11,	//the Logitech logo button-thingy
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

typedef enum JoystickDirection
{
	DIRECTION_NONE = -1,
	DIRECTION_F = 2,
	DIRECTION_FR = 1,
	DIRECTION_R = 0,
	DIRECTION_BR = 7,
	DIRECTION_B = 6,
	DIRECTION_BL = 5,
	DIRECTION_L = 4,
	DIRECTION_FL = 3,
};

#endif
