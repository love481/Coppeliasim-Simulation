/*******************
**Author:Love Panta
**Created:2020/10/11/
******************/
#pragma once
#ifndef _ROBOT_STATE_
#define _ROBOT_STATE_
#include"PID.h"
class robo_state {
private:
	PID* pid;
public:
	float x, y, theta;
	float velocity, omega, direction;
	robo_state():pid(new PID())
	{ 
		setRobotPositionState(0,0,0);
		setRobotVelocityState(0, 0, 0);

	}
	~robo_state(){}
	void setRobotPositionState(float x_, float y_, float theta_)
	{
		x = x_;
		y = y_;
		theta = theta_;
	}
	void setRobotVelocityState(float velocity_, float omega_, float direction_)
	{
		velocity = velocity_;
		omega = omega_;
		direction = direction_;
	}
	void setPIDConstrain(float kp, float ki, float kd, float Min, float Max, int pon = P_ON_E, int Mode = AUTOMATIC, int Direction = DIRECT)
	{
		pid->SetOutputLimits(Min, Max);
		pid->SetMode(Mode);
		pid->SetControllerDirection(Direction);
		pid->SetTunings(kp, ki, kd, pon);
	}
	float computeOmegaBasedOnPose(float setpoint, float input) { return pid->Compute(setpoint, input); }

};
#endif