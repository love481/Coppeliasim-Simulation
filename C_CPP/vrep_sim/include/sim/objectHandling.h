/*******************
**Author:Love Panta
**Created:2020/10/11/
******************/
#pragma once
#ifndef _OBJECT_HANDLING_H_
#define _OBJECT_HANDLING_H_
#include"connection.h"
class objectHandling {
private:
	int handle;
	float minX, maxX;
public:
	objectHandling():handle(0),minX(0),maxX(0) {}
	~objectHandling(){}
	void setHandle(const char* );
	void setSignalName(const char*,const unsigned char*, int);
	float getfloatParameter(int);
	float getJointPosition(void);
	void setMotorVelocity(float);
	void setMotorAngle(float);
	void getRobotPose(float&,float&,float&);

};
#endif //!_OBJECT_HANDLING_H_