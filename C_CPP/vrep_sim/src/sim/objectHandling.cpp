#include"objectHandling.h"
void objectHandling::setHandle(const char* _objectName)
{   
	simxGetObjectHandle(connection::ClientId, _objectName, &handle, simx_opmode_oneshot_wait);
}
void objectHandling::setSignalName(const char* signalName,const unsigned char* signalValue,int strlength)
{   
	simxSetStringSignal(connection::ClientId, signalName, signalValue,strlength, simx_opmode_oneshot_wait);
}
float objectHandling::getfloatParameter(int parameterId)
{
	float value;
	simxGetObjectFloatParameter(connection::ClientId,handle, parameterId, &value, simx_opmode_oneshot_wait);
	return value;
}
float objectHandling::getJointPosition()
{
	float angle;
	simxGetJointPosition(connection::ClientId, handle, &angle, simx_opmode_oneshot_wait);
	return angle;
}
void objectHandling::setMotorVelocity(float value)
{
	simxSetJointTargetVelocity(connection::ClientId, handle, value, simx_opmode_oneshot_wait);
}
void objectHandling::setMotorAngle(float value)
{
	simxSetJointPosition(connection::ClientId, handle, value, simx_opmode_oneshot_wait);
}
void objectHandling::getRobotPose(float& x,float& y,float& theta)
{
	float position[3];
	float orientation[3];
	simxGetObjectPosition(connection::ClientId, handle, -1, position, simx_opmode_oneshot_wait);
	simxGetObjectOrientation(connection::ClientId, handle, -1, orientation, simx_opmode_oneshot_wait);
	x = position[0];
	y= position[1];
	theta = orientation[2];
}