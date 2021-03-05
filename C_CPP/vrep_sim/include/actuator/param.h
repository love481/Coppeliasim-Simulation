/*******************
**Author:Love Panta
**Created:2020/10/11/
******************/
#pragma once
#ifndef _PARAM_H_
#define _PARAM_H_
#include"objectHandling.h"
struct param_config {
	objectHandling* wheelHandle;
	objectHandling* bodyHandle;
};
class param {
private:
	float bodyDiameter, wheelDiameter, interWheelDist;
	param_config* handle_;
public:
	param() :bodyDiameter(0), wheelDiameter(0), interWheelDist(0) { handle_ = new param_config();}
	~param() {}
	void setConfig(param_config* h) { handle_ = h; }
	float get_bodyDiameter() { return bodyDiameter; }
	float get_wheelDiameter() { return wheelDiameter; }
	float get_interWheelDist() { return interWheelDist; }
	void setAllParameters();
};
#endif //!_PARAM_H_