#ifndef ENUMS_H
#define ENUMS_H

typedef enum JoystickButton	//the values are tentative, esp. start, select, menu, logo
{
	BUTTON_A = 2,
	BUTTON_B = 3,
	BUTTON_X = 1,
	BUTTON_Y = 4,
	BUTTON_LB = 5,
	BUTTON_RB = 6,
	BUTTON_LT = 7,
	BUTTON_RT = 8,
	BUTTON_START = 9,
	BUTTON_SELECT = 10,
	BUTTON_MENU = 11,
	BUTTON_LOGO = 12,	//the Logitech logo button-thingy
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
	DIRECTION_R = 0,
	DIRECTION_FR = 1,
	DIRECTION_F = 2,
	DIRECTION_FL = 3,
	DIRECTION_L = 4,
	DIRECTION_BL = 5,
	DIRECTION_B = 6,
	DIRECTION_BR = 7,
};

#endif
