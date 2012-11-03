#ifndef GLOBAL_VARS_H
#define GLOBAL_VARS_H

// Mask for the "bitmap" values from the controller for everything
// we don't need (other than A/B/X/Y/JOYL/JOYR):
	//   0000 1100 0000 1111
	// & ???? ???? ???? ????
	// ---------------------
	//   0000 ??00 0000 ????
// This information was gleaned from the definition of joy1Btn().
	// 2^1 +2^2 +2^3 +2^4 +2^11 +2^12 = 2+4+8+16+2048+4096 = 6174
short CONTROLLER_MASK = 6174;

#endif
