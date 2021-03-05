/*******************
**Author:Love Panta
**Created:2020/10/11/
******************/
#pragma once
#ifndef _DEFINES_H_
#define _DEFINES_H_
#define PI (3.1415)
#include "connection.h"
inline float normalizeAngle(float dx)
{
	if (dx >= 0)
		dx = fmodf(dx + (float)PI, 2 * (float)PI) - (float)PI;
	else
		dx = fmodf(dx - (float)PI, 2 * (float)PI) + (float)PI;
	return dx;
}

#endif //!_DEFINES_H_s