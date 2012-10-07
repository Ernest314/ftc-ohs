#ifndef GLOBAL_VARS_H
#define GLOBAL_VARS_H

const int STEER_L = OUT_B;
const int STEER_R = OUT_C;

//for turning timing, calibrate at:
		//10% power for each motor,
		//time to turn a full circle (360 degrees)
const int TURN_IN_PLACE_TIME = 16*1000;
const int TURN_MOVING_TIME = 32*1000;

#endif
