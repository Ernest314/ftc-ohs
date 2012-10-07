#ifndef LOW_LEVEL_FUNCTIONS_H
#define LOW_LEVEL_FUNCTIONS_H


//"namespace" Motor
inline void Motor_Forward(int port, int power=100)
{
	OnFwd(port, power);
}

inline void Motor_Reverse(int port, int power=100)
{
	OnRev(port, power);
}

inline void Motor_Stop(int port, bool brake=true)
{
 switch(brake)
 {
  case true:
       Off(port);
       break;
  case false:
       Coast(port);
       break;
 }
}

inline void Motor_ExactRotation(int port, int angle, int power=100, bool brake=true)
{
	RotateMotor(port, power, angle);
	switch(brake)
 {
  case true:
       Off(port);
       break;
  case false:
       Coast(port);
       break;
 }
}

inline void Motor_GetRotation(int port)
{
	MotorRotationCount(port);
}

inline void Motor_ResetRotation(int port, bool relative)
{
 switch(relative)
 {
  case true:
       ResetBlockTachoCount(port);
       break;
  case false:
       ResetRotationCount(port);
       break;
 }
}


#endif
