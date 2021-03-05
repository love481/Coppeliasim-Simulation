#include"encoder.h"
#include "defines.h"
void encoder::encoderInitilize()
{
	prevAngle = _encoder->encHandle->getJointPosition();
	angle=0;
}
float encoder::getAngle()
{
	float newAngle = _encoder->encHandle->getJointPosition();
	float dx=newAngle-prevAngle;
	dx = normalizeAngle(dx);
	angle+= dx;
	prevAngle = newAngle;
	return angle;
}
float encoder::getOmega()
{
	omega = _encoder->encHandle->getfloatParameter(2012);
	return omega;
}