#pragma config(Sensor, S1,     touch_B,        sensorTouch)
#pragma config(Sensor, S2,     touch_A,        sensorTouch)
#pragma config(Sensor, S3,     color,          sensorCOLORFULL)
#pragma config(Sensor, S4,     sonar,          sensorSONAR)
#pragma config(Motor,  motorA,          motor_scissor, tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          motor_L,       tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,          motor_R,       tmotorNXT, PIDControl, encoder)


#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.


void initializeRobot()
{
  // Place code here to init servos to starting positions.
  // Sensors are auto-config'ed and setup by RobotC. They may need to stabilize.
  return;
}


task main()
{
  initializeRobot();
  waitForStart(); // Wait for the beginning of autonomous phase.

  while (true)
  {}
}
