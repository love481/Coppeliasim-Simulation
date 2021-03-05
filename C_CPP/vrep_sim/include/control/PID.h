/*******************
**Author:Love Panta
**Created:2020/10/11/
******************/
#pragma once
#ifndef _PID_H_
#define _PID_H_
#include"connection.h"
//define necessary global varibles for PID constrain
#define P_ON_M 0
#define P_ON_E 1
#define MANUAL 0
#define AUTOMATIC 1
#define DIRECT 0
#define REVERSE 1
class PID {
private:
	float kp, ki, kd;
	float lastInput,currInput, ITerm,Output;
	float outMin, outMax;
	unsigned long lastTime, SampleTime;
	bool pOnE, inAuto;
	int controllerDirection;
	
public:
	PID():Output(0),currInput(0),SampleTime(10),inAuto(false)
	{
		SetOutputLimits(-255, 255);
		SetMode(AUTOMATIC);
		SetControllerDirection(DIRECT);
		SetTunings(0, 0, 0, P_ON_E);
		lastTime = extApi_getTimeInMs();

	}
	void SetTunings(float, float, float, int);
	void SetSampleTime(int);
	void SetOutputLimits(float, float);
	void SetMode(int);
	void Initialize(void);
	void SetControllerDirection(int);
	float Compute(float,float);

};
#endif