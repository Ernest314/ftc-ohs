#ifndef ENUMS_H
#define ENUMS_H

typedef enum LiftState
{
	LIFT_JOYSTICK = 0,
	LIFT_BOTTOM = 1,
	LIFT_MIDDLE = 2,
	LIFT_TOP = 3,
};

typedef enum MotorState
{
	MOTOR_JOYSTICK = 0,
};

typedef enum JoystickButton
{
	BUTTON_A = 2,
	BUTTON_B = 3,
	BUTTON_X = 1,
	BUTTON_Y = 4,
	BUTTON_LB = 5,
	BUTTON_RB = 6,
	BUTTON_LT = 7,
	BUTTON_RT = 8,
	BUTTON_BACK = 9,
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
	DIRECTION_BR = 3,
	DIRECTION_B = 4,
	DIRECTION_BL = 5,
	DIRECTION_L = 6,
	DIRECTION_FL = 7,
};

#endif
