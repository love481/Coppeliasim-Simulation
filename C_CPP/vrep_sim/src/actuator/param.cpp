#include"param.h"
void param::setAllParameters()
{
	float minXYZ, maxXYZ;
	//get value dimension
	minXYZ = handle_->wheelHandle->getfloatParameter(15);
	maxXYZ = handle_->wheelHandle->getfloatParameter(18);
	wheelDiameter = maxXYZ - minXYZ;
	minXYZ = handle_->bodyHandle->getfloatParameter(16);
	maxXYZ = handle_->bodyHandle->getfloatParameter(19);
	bodyDiameter = maxXYZ - minXYZ;
	interWheelDist = float(sqrt(2) * bodyDiameter);
	cout << bodyDiameter << "\t" << wheelDiameter << "\t" << interWheelDist << endl;
}