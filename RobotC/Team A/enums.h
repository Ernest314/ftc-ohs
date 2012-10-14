#ifndef ENUMS_H
#define ENUMS_H

typedef enum Direction
{
	DIRECTION_L = 0,
	DIRECTION_R = 1,
};

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

#endif
