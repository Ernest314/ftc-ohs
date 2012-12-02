#ifndef ENUMS_H
#define ENUMS_H

typedef enum LiftState
{
	LIFT_JOYSTICK = 0,
	LIFT_BOTTOM = 1,
	LIFT_MIDDLE = 2,
	LIFT_TOP = 3,
	LIFT_FETCH = 4,
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

typedef enum JoystickDirection	//needs one more definitive test
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

// These frequencies are all in hertz, rounded to the nearest int.
typedef enum SoundNotes
{
	NOTE_C3 = 131,	NOTE_C4 = 262,	NOTE_C5 = 523,
	NOTE_D3 = 147,	NOTE_D4 = 294,	NOTE_D5 = 587,
	NOTE_E3 = 165,	NOTE_E4 = 330,	NOTE_E5 = 659,
	NOTE_F3 = 175,	NOTE_F4 = 349,	NOTE_F5 = 698,
	NOTE_G3 = 196,	NOTE_G4 = 392,	NOTE_G5 = 784,
	NOTE_A3 = 220,	NOTE_A4 = 440,	NOTE_A5 = 880,
	NOTE_B3 = 247,	NOTE_B4 = 494,	NOTE_B5 = 988,
};

#endif
