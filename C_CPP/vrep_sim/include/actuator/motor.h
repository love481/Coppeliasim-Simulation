/*******************
**Author:Love Panta
**Created:2020/10/11/
******************/
#pragma once
#ifndef _MOTOR_H_
#define _MOTOR_H_
#include "objectHandling.h"
#include "PID.h"
struct motor_config {
	float max_omega;
	float max_angle;
	objectHandling* motorHandle;
};
class Motor {
private:
	PID* pid;
	motor_config* _motor_config;
public:
	Motor() :_motor_config(0) { pid = new PID;}
	~Motor(){}
	void setConfig(motor_config* m) { _motor_config =m;}
	void setPIDConstrain(float kp, float ki, float kd, float Min, float Max,int pon= P_ON_E, int Mode = AUTOMATIC, int Direction = DIRECT)
	{
		pid->SetOutputLimits(Min, Max);
		pid->SetMode(Mode);
		pid->SetControllerDirection(Direction);
		pid->SetTunings(kp, ki, kd,pon);
	}
	float computeOmega(float setpoint, float input) { return pid->Compute(setpoint, input);}
	void setOmega(float);
	void setAngle(float);
};
#endif //!_MOTOR_H_
